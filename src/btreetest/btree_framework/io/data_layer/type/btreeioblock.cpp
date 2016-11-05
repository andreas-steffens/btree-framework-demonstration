/************************************************************
**
** file:	btreeioblock.cpp
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
** This file contains code for the b-tree framework's
** block IO data layer class.
**
************************************************************/

#ifndef	BTREEIOBLOCK_CPP
#define	BTREEIOBLOCK_CPP

#include "io/data_layer/type/btreeioblock.h"

// block [0]
// |- node desciption[0]         -|- maintainence vector-|-algnm-|--- data[0][] ---|-algnm-|--- sub node numbers[0][] ---|-algnm-|--- serVector[0][] ---|-algnm-|	<-- node[0]
// |- node desciption[1]         -|- maintainence vector-|-algnm-|--- data[1][] ---|-algnm-|--- sub node numbers[1][] ---|-algnm-|--- serVector[1][] ---|-algnm-|	<-- node[1]
// |- node desciption[2]         -|- maintainence vector-|...
// ...
// |- node desciption[(2^n) - 1] -|- maintainence vector-|...
// data layer block alignment
// block [1]
// |- node desciption[2^n]       -|- maintainence vector-|-algnm-|--- data[0][] ---|-algnm-|--- sub node numbers[0][] ---|-algnm-|--- serVector[0][] ---|-algnm-|	<-- node[0]

template<class _t_datalayerproperties>
CBTreeBlockIO<_t_datalayerproperties>::CBTreeBlockIO
(
	sub_node_iter_type nNodeSize, 
	uint32_t nNumDataPools, 
	CBTreeIOperBlockPoolDesc_t *psDataPools
)
	:	CBTreeIO<_t_datalayerproperties> (nNumDataPools, psDataPools)
	,	m_nNodeSize (nNodeSize)
	,	m_pnPerNodePoolOffset (NULL)
	,	m_psDescriptorVector (NULL)
	,	m_nDescriptorVectorSize (0)
	,	m_nPrevRootNode (~0)
	,	m_nMaxAccessCtr (127)
{
	m_pnPerNodePoolOffset = new offset_type [this->m_nNumDataPools];

	BTREEDATA_ASSERT (m_pnPerNodePoolOffset != NULL, "CBTreeIO::CBTreeIO: insufficient memory!");
	
	m_nAlignedNodeSize = generate_pool_offsets ();
}

template<class _t_datalayerproperties>
CBTreeBlockIO<_t_datalayerproperties>::~CBTreeBlockIO ()
{
	if (m_pnPerNodePoolOffset != NULL)
	{
		delete [] m_pnPerNodePoolOffset;
	}

	if (m_psDescriptorVector != NULL)
	{
		free ((void *) m_psDescriptorVector);
	}
}

template<class _t_datalayerproperties>
typename _t_datalayerproperties::node_iter_type CBTreeBlockIO<_t_datalayerproperties>::get_maxNodes ()
{
	return (this->m_nMaxNodes);
}

template<class _t_datalayerproperties>
typename _t_datalayerproperties::offset_type CBTreeBlockIO<_t_datalayerproperties>::get_dataAlignment ()
{
	// The keyword 'long' has been purposely choosen, since it will make the compiler to return 4 bytes on 32 bit builds and 8 bytes on 64 bit builds, as oppose to uint32_t and uint64_t.
	return ((offset_type) (sizeof (long)));
}

template<class _t_datalayerproperties>
typename _t_datalayerproperties::offset_type CBTreeBlockIO<_t_datalayerproperties>::get_alignedOffset (typename _t_datalayerproperties::offset_type nOffset)
{
	nOffset += get_dataAlignment () - 1;
	nOffset /= get_dataAlignment ();
	nOffset *= get_dataAlignment ();

	return (nOffset);
}

template<class _t_datalayerproperties>
void CBTreeBlockIO<_t_datalayerproperties>::set_root_node (typename _t_datalayerproperties::node_iter_type nRootNode)
{
	uint32_t		nCurrentRootContainingDesc;
	uint32_t		nNewRootContainingDesc = convert_node_to_descriptor (nRootNode);

	if (m_nPrevRootNode != ~0)
	{
		nCurrentRootContainingDesc = convert_node_to_descriptor (m_nPrevRootNode);
	}
	else
	{
		nCurrentRootContainingDesc = ~nNewRootContainingDesc;
	}

	if (nCurrentRootContainingDesc != nNewRootContainingDesc)
	{
#if defined (_DEBUG)

		BTREE_ASSERT (nNewRootContainingDesc < m_nDescriptorVectorSize, "CBTreeBlockIO<_t_datalayerproperties>::set_root_node: requested new root exceeds descriptor vector size!");

#endif

		m_nPrevRootNode = nRootNode;
	}
}

template<class _t_datalayerproperties>
typename CBTreeBlockIO<_t_datalayerproperties>::address_type CBTreeBlockIO<_t_datalayerproperties>::get_blockAddr (typename _t_datalayerproperties::node_iter_type nNode)
{
	address_type		nRetval;

	nRetval = (address_type) ((nNode >> m_nNodesPerBlockVectorSize) * m_nBlockSize);

	return (nRetval);
}

template<class _t_datalayerproperties>
typename CBTreeBlockIO<_t_datalayerproperties>::offset_type CBTreeBlockIO<_t_datalayerproperties>::get_poolOffset ()
{
	return ((offset_type) 0);
}

template<class _t_datalayerproperties>
typename CBTreeBlockIO<_t_datalayerproperties>::address_type CBTreeBlockIO<_t_datalayerproperties>::get_node_offset (typename _t_datalayerproperties::node_iter_type nNode)
{
	address_type		nRetval;

	nRetval = (nNode & (m_nNodesPerBlock - 1)) * m_nAlignedNodeSize;

	return (nRetval);
}

template<class _t_datalayerproperties>
typename CBTreeBlockIO<_t_datalayerproperties>::address_type CBTreeBlockIO<_t_datalayerproperties>::get_nodeAddr (typename _t_datalayerproperties::node_iter_type nNode)
{
	address_type		nRetval;

	nRetval = get_blockAddr (nNode);
	nRetval += get_node_offset (nNode);

	return (nRetval);
}

template<class _t_datalayerproperties>
typename CBTreeBlockIO<_t_datalayerproperties>::offset_type CBTreeBlockIO<_t_datalayerproperties>::get_per_node_pool_offset (uint32_t nPool)
{
#if defined (_DEBUG)

	BTREEDATA_ASSERT (nPool < this->m_nNumDataPools, "CBTreeBlockIO::get_per_node_pool_offset: nPool exceeds available block pools!");

#endif

	return (m_pnPerNodePoolOffset[nPool]);
}

template<class _t_datalayerproperties>
typename CBTreeBlockIO<_t_datalayerproperties>::address_type CBTreeBlockIO<_t_datalayerproperties>::get_pool_address (uint32_t nPool, typename _t_datalayerproperties::node_iter_type nNode)
{
	address_type		nAddr = get_nodeAddr (nNode);

	nAddr += get_per_node_pool_offset (nPool);

	return (nAddr);
}

template<class _t_datalayerproperties>
typename CBTreeBlockIO<_t_datalayerproperties>::offset_type CBTreeBlockIO<_t_datalayerproperties>::generate_pool_offsets ()
{
	offset_type		nBase = this->get_poolOffset ();
	uint32_t		ui32;

	nBase = get_alignedOffset (nBase);

	for (ui32 = 0; ui32 < this->m_nNumDataPools; ui32++)
	{
		m_pnPerNodePoolOffset[ui32] = nBase;

		nBase += this->get_pool_total_size (ui32);

		nBase = get_alignedOffset (nBase);
	}

	return (nBase);
}

template<class _t_datalayerproperties>
void CBTreeBlockIO<_t_datalayerproperties>::realloc_descriptor_vector (typename _t_datalayerproperties::node_iter_type nMaxNodes)
{
	uint32_t	nOldDescriptorVectorSize = m_nDescriptorVectorSize;
	uint32_t	nNewDescriptorVectorSize;
	uint32_t	u;

	nNewDescriptorVectorSize = (uint32_t) ((nMaxNodes + m_nNodesPerBlock - 1) >> m_nNodesPerBlockVectorSize);

	if (m_psDescriptorVector == NULL)
	{
#if defined (_DEBUG)

		BTREE_ASSERT (m_nDescriptorVectorSize == 0, "CBTreeBlockIO::realloc_descriptor_vector: on descriptor vector initialisation, vector size ought to be zero length!");

#endif

		m_psDescriptorVector = (btree_block_io_descriptor_t *) malloc (nNewDescriptorVectorSize * sizeof (btree_block_io_descriptor_t));

		BTREE_ASSERT (m_psDescriptorVector != NULL, "CBTreeBlockIO::realloc_descriptor_vector: insufficient memory!");
	}
	else if (nNewDescriptorVectorSize != nOldDescriptorVectorSize)
	{
		m_psDescriptorVector = (btree_block_io_descriptor_t *) realloc ((void *) m_psDescriptorVector, nNewDescriptorVectorSize * sizeof (btree_block_io_descriptor_t));

		BTREE_ASSERT (m_psDescriptorVector != NULL, "CBTreeBlockIO::realloc_descriptor_vector: insufficient memory! (realloc)");
	}

	for (u = nOldDescriptorVectorSize; u < nNewDescriptorVectorSize; u++)
	{
		m_psDescriptorVector[u].pBlockData = NULL;
		m_psDescriptorVector[u].nAccessCtr = 0;
		m_psDescriptorVector[u].bMarkedForUnmap = false;
	}

	m_nDescriptorVectorSize = nNewDescriptorVectorSize;
}

template<class _t_datalayerproperties>
uint32_t CBTreeBlockIO<_t_datalayerproperties>::convert_node_to_descriptor (typename _t_datalayerproperties::node_iter_type nNode, bool bRoundUp)
{
#if defined (_DEBUG)

	const uint32_t		uMask = ~0;
	node_iter_type		uRevNodeMask = (node_iter_type) uMask;

	uRevNodeMask = ~uRevNodeMask;

#endif

	uint32_t			nRslt;

	nNode >>= this->m_nNodesPerBlockVectorSize;

#if defined (_DEBUG)

	BTREE_ASSERT ((nNode & uRevNodeMask) == 0x0, "CBTreeBlockIO<_t_datalayerproperties>::convert_node_to_descriptor: node value exceeds maximum descriptor vector size!");

#endif

	nRslt = (uint32_t) nNode;

	if (bRoundUp)
	{
		nRslt++;

#if defined (_DEBUG)

		BTREE_ASSERT (nRslt != 0, "CBTreeBlockIO<_t_datalayerproperties>::convert_node_to_descriptor: requested size exceeds maximum descriptor vector size!");

#endif
	}

	return (nRslt);
}

template<class _t_datalayerproperties>
void CBTreeBlockIO<_t_datalayerproperties>::setup (typename CBTreeBlockIO<_t_datalayerproperties>::address_type nBlockSize)
{
	uint32_t	nMultiple = 1;
	uint32_t	ui32;

	BTREE_ASSERT (nBlockSize > 0, "CBTreeBlockIO<_t_datalayerproperties>::setup: desired minimum block is zero!");

	m_nBlockSize = nBlockSize * nMultiple;

	while ((nMultiple * nBlockSize) < generate_pool_offsets ())
	{
		nMultiple++;

		m_nBlockSize = nBlockSize * nMultiple;
	}

	m_nNodesPerBlock = (uint32_t) (m_nBlockSize / generate_pool_offsets ());

	// make sure m_nNodesPerBlock is part of the 2^n series
	for (ui32 = 32; ui32 != 0x0; )
	{
		ui32--;

		if ((m_nNodesPerBlock & (1 << ui32)) == (1 << ui32))
		{
			m_nNodesPerBlock = 1 << ui32;
			m_nNodesPerBlockVectorSize = ui32;

			break;
		}
	}
}

template<class _t_datalayerproperties>
void CBTreeBlockIO<_t_datalayerproperties>::increment_access_counter (uint32_t nDescriptor)
{
	this->m_psDescriptorVector[nDescriptor].nAccessCtr++;

	if (this->m_psDescriptorVector[nDescriptor].nAccessCtr >= this->m_nMaxAccessCtr)
	{
		uint32_t	ui32;

		for (ui32 = 0; ui32 < this->m_nDescriptorVectorSize; ui32++)
		{
			this->m_psDescriptorVector[nDescriptor].nAccessCtr >>= 1;
		}
	}
}

#endif // BTREEIOBLOCK_CPP


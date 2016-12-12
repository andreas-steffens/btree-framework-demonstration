/************************************************************
**
** file:	btreetestarray.cpp
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
** This file contains array application class code derived
** from the b-tree framework's array data class to allow
** for the array data class being tested by having
** the array application class act as a wrapper.
**
************************************************************/

#ifndef BTREETESTARRAY_CPP
#define	BTREETESTARRAY_CPP

#include "testbench/application_classes/regression/btreetestarray.h"

template<class _t_datalayerproperties>
CBTreeTestArray<_t_datalayerproperties>::CBTreeTestArray 
	(
		_t_datalayerproperties &rDataLayerProperties, 
		typename _t_datalayerproperties::sub_node_iter_type nNodeSize, 
		typename CBTreeTestArray<_t_datalayerproperties>::reference_t *pClRef
	)
	:	CBTreeTestBaseLinear
			<
				CBTreeArray <arrayEntry_t, _t_datalayerproperties>, 
				::std::list<arrayEntry_t>, 
				arrayEntry_t, 
				_t_datalayerproperties
			>
		(
			rDataLayerProperties, 
			nNodeSize, 
			pClRef, 
			true
		)
{
}

template<class _t_datalayerproperties>
CBTreeTestArray<_t_datalayerproperties>::CBTreeTestArray (const CBTreeTestArray<_t_datalayerproperties> &rContainer, const bool bAssign)
	:	CBTreeTestBaseLinear
			<
				CBTreeArray <arrayEntry_t, _t_datalayerproperties>, 
				::std::list<arrayEntry_t>, 
				arrayEntry_t, 
				_t_datalayerproperties
			>
		(
			dynamic_cast <const CBTreeTestBaseLinear
				<
					CBTreeArray <arrayEntry_t, _t_datalayerproperties>, 
					::std::list<arrayEntry_t>, 
					arrayEntry_t, 
					_t_datalayerproperties
				> &> (rContainer), 
				false
		)
{
	if (bAssign)
	{
		this->_assign (rContainer);
	}

	this->set_atomic_testing (true);
}

template<class _t_datalayerproperties>
CBTreeTestArray<_t_datalayerproperties>::CBTreeTestArray (CBTreeTestArray<_t_datalayerproperties> &&rRhsContainer)
	:	CBTreeTestBaseLinear
			<
				CBTreeArray <arrayEntry_t, _t_datalayerproperties>, 
				::std::list<arrayEntry_t>, 
				arrayEntry_t, 
				_t_datalayerproperties
			>
		(
			dynamic_cast<CBTreeTestBaseLinear
				<
					CBTreeArray <arrayEntry_t, _t_datalayerproperties>, 
					::std::list<arrayEntry_t>, 
					arrayEntry_t, 
					_t_datalayerproperties
				> &&> (rRhsContainer)
		)
{
	this->test ();
}

template<class _t_datalayerproperties>
CBTreeTestArray<_t_datalayerproperties>::~CBTreeTestArray ()
{
}

template<class _t_datalayerproperties>
template<class _t_iterator>
void CBTreeTestArray<_t_datalayerproperties>::assign (_t_iterator sItFirst, _t_iterator sItLast)
{
	CBTreeArray_t::assign (sItFirst, sItLast);
}

template<class _t_datalayerproperties>
void CBTreeTestArray<_t_datalayerproperties>::assign (const typename _t_datalayerproperties::size_type nNewSize, const typename CBTreeTestArray<_t_datalayerproperties>::value_type& rVal)
{
	CBTreeArray_t::assign (nNewSize, rVal);

	this->test ();
}

template<class _t_datalayerproperties>
void CBTreeTestArray<_t_datalayerproperties>::push_back (const typename CBTreeTestArray<_t_datalayerproperties>::value_type& rData)
{
	CBTreeArray_t::push_back (rData);

	this->test ();
}

template<class _t_datalayerproperties>
void CBTreeTestArray<_t_datalayerproperties>::pop_back ()
{
	CBTreeArray_t::pop_back ();

	this->test ();
}

template<class _t_datalayerproperties>
template<class _t_iterator>
typename CBTreeTestArray<_t_datalayerproperties>::iterator
	CBTreeTestArray<_t_datalayerproperties>::insert
	(
		typename CBTreeTestArray<_t_datalayerproperties>::const_iterator	sCIterPos, 
		_t_iterator															sItFirst, 
		_t_iterator															sItLast
	)
{
	iterator		sRetval = CBTreeArray_t::insert (sCIterPos, sItFirst, sItLast);

	return (sRetval);
}	

template<class _t_datalayerproperties>
typename CBTreeTestArray<_t_datalayerproperties>::iterator
	CBTreeTestArray<_t_datalayerproperties>::insert
	(
		typename CBTreeTestArray<_t_datalayerproperties>::const_iterator sCIterPos, 
		const typename CBTreeTestArray<_t_datalayerproperties>::value_type& rData
	)
{
	iterator		sRetval = CBTreeArray_t::insert (sCIterPos, rData);

	this->test ();

	return (sRetval);
}

template<class _t_datalayerproperties>
typename CBTreeTestArray<_t_datalayerproperties>::iterator
	CBTreeTestArray<_t_datalayerproperties>::insert
	(
		typename CBTreeTestArray<_t_datalayerproperties>::const_iterator sCIterPos, 
		const typename _t_datalayerproperties::size_type nLen, 
		const typename CBTreeTestArray<_t_datalayerproperties>::value_type& rData
	)
{
	iterator		sRetval = CBTreeArray_t::insert (sCIterPos, nLen, rData);

	this->test ();

	return (sRetval);
}

template<class _t_datalayerproperties>
typename CBTreeTestArray<_t_datalayerproperties>::iterator
	CBTreeTestArray<_t_datalayerproperties>::erase
	(
		typename CBTreeTestArray<_t_datalayerproperties>::const_iterator sCIterPos
	)
{
	iterator		sRetval = CBTreeArray_t::erase (sCIterPos);

	this->test ();

	return (sRetval);
}

template<class _t_datalayerproperties>
typename CBTreeTestArray<_t_datalayerproperties>::iterator
	CBTreeTestArray<_t_datalayerproperties>::erase
	(
		typename CBTreeTestArray<_t_datalayerproperties>::const_iterator sCIterFirst, 
		typename CBTreeTestArray<_t_datalayerproperties>::const_iterator sCIterLast
	)
{
	iterator		sRetval = CBTreeArray_t::erase (sCIterFirst, sCIterLast);

	this->test ();

	return (sRetval);
}

template<class _t_datalayerproperties>
void CBTreeTestArray<_t_datalayerproperties>::swap
	(
		CBTreeTestArray<_t_datalayerproperties> &rContainer
	)
{
	if (this != &rContainer)
	{
		CBTreeTestArray_t::_swap (rContainer);

		this->test ();
	}
}

template<class _t_datalayerproperties>
void CBTreeTestArray<_t_datalayerproperties>::clear ()
{
	CBTreeBaseDefaults_t::clear ();

	this->test ();
}

template<class _t_datalayerproperties>
bool CBTreeTestArray<_t_datalayerproperties>::operator== (const CBTreeTestArray &rArray) const
{
	if (this == &rArray)
	{
		return (true);
	}

	if (this->size () != rArray.size ())
	{
		return (false);
	}

	const_iterator		sCIterThis = this->cbegin ();
	const_iterator		sCIterArray = rArray.cbegin ();

	while (sCIterThis != this->cend ())
	{
		if ((*sCIterThis).nData != (*sCIterArray).nData)
		{
			return (false);
		}

		sCIterThis++;
		sCIterArray++;
	}

	return (true);
}

template<class _t_datalayerproperties>
bool CBTreeTestArray<_t_datalayerproperties>::operator!= (const CBTreeTestArray &rArray) const
{
	return ( ! (*this == rArray));
}

template<class _t_datalayerproperties>
CBTreeTestArray<_t_datalayerproperties> &CBTreeTestArray<_t_datalayerproperties>::operator=
	(const CBTreeTestArray<_t_datalayerproperties> &rContainer)
{
	if (this != &rContainer)
	{
		*(this->m_pClRef) = *(rContainer.m_pClRef);

		CBTreeTestBaseLinear_t				&rThisArray = reinterpret_cast <CBTreeTestBaseLinear_t &> (*this);
		const CBTreeTestBaseLinear_t		&rContainerArray = reinterpret_cast <const CBTreeTestBaseLinear_t &> (rContainer);

		rThisArray = rContainerArray;

		this->test ();
	}

	return (*this);
}

template<class _t_datalayerproperties>
CBTreeTestArray<_t_datalayerproperties> &CBTreeTestArray<_t_datalayerproperties>::operator=
	(CBTreeTestArray<_t_datalayerproperties> &&rRhsContainer)
{
	CBTreeTestBaseLinear_t		&rArrayThis = dynamic_cast<CBTreeTestBaseLinear_t &> (*this);
	CBTreeTestBaseLinear_t		&rArrayContainer = dynamic_cast<CBTreeTestBaseLinear_t &> (rRhsContainer);

	rArrayThis = ::std::move (rArrayContainer);

	this->test ();

	return (*this);
}

template<class _t_datalayerproperties>
bool CBTreeTestArray<_t_datalayerproperties>::show_data (std::ofstream &ofs, std::stringstream &rstrData, std::stringstream &rszMsg, const typename _t_datalayerproperties::node_iter_type nNode, const typename _t_datalayerproperties::sub_node_iter_type nSubPos) const
{
	uint32_t			nData;
	value_type			*psData;
	
	try
	{
		psData = this->get_data (nNode, nSubPos);
		
		nData = psData->nData;
		nData = (nData >> 16) | (nData << 16);
		nData = ((nData >> 8) & 0xFF00FF) | ((nData << 8) & 0xFF00FF00);

		if (ofs.is_open ())
		{
			rstrData.clear ();
			rstrData << "<table border=\"0\" cellspacing=\"1\" width=\"220\"><tr><td>";
			rstrData << "data: " << ::std::hex << ::std::setfill ('0') << ::std::setw (8) << nData << ::std::dec << "<br>debug: " << psData->nDebug;
			rstrData << "</td>";

			rstrData << "<td align=\"top\">";
		}

		size_type		nOffset;
		node_iter_type	nTmpNode = nNode;

		if (this->is_leaf (nNode))
		{
			nOffset = nSubPos;
		}
		else
		{
			size_type		*pnSerVector = this->get_serVector (nNode);

			nOffset = pnSerVector[nSubPos];
		}
		
		while (nTmpNode != this->m_nRootNode)
		{
			node_iter_type		nParentNode = this->get_parent (nTmpNode);
			sub_node_iter_type	nTmpSubPos = this->find_sub_node_offset (nParentNode, nTmpNode);

			if (nTmpSubPos > 0)
			{
				size_type		*pnSerVector = this->get_serVector (nParentNode);

				nOffset += pnSerVector[nTmpSubPos - 1] + 1;
			}

			nTmpNode = nParentNode;
		}

		if (nOffset < this->m_pClRef->size ())
		{
			typename reference_t::const_iterator	sCIter = this->m_pClRef->cbegin ();
			value_type								sData;

			::std::advance (sCIter, nOffset);

			sData = *sCIter;

			nData = sData.nData;
			nData = (nData >> 16) | (nData << 16);
			nData = ((nData >> 8) & 0xFF00FF) | ((nData << 8) & 0xFF00FF00);

			if (ofs.is_open ())
			{
				if (psData->nData != sData.nData)
				{
					rstrData << "<font color=\"#FF0000\">";
				}
				else
				{
					rstrData << "<font color=\"#00BB00\">";
				}

				rstrData << "data: " << ::std::hex << ::std::setfill ('0') << ::std::setw (8) << nData << ::std::dec << "<br>debug: " << sData.nDebug;
				rstrData << "</font>";
			}
		}
		else
		{
			if (ofs.is_open ())
			{
				rstrData << "<font color=\"#FF0000\">";
				rstrData << "reference<br>";
				rstrData << "out of<br>";
				rstrData << "range";
				rstrData << "</font>";
			}
		}

		if (ofs.is_open ())
		{
			rstrData << "</td></tr>";
			rstrData << "</table>" << ::std::endl;
		}
	}
	catch (::std::exception *pE)
	{
		if (!ofs.is_open ())
		{
			return (false);
		}
		else
		{
			rszMsg << "<br>data: corruption (" << pE->what () << ")";

			rstrData.clear ();
			rstrData << "data: ---<br>debug: ---";
		}
	}

	return (true);
}

template<class _t_datalayerproperties>
bool CBTreeTestArray<_t_datalayerproperties>::set_at (const typename _t_datalayerproperties::size_type nPos, const typename CBTreeTestArray<_t_datalayerproperties>::value_type &rData)
{
	bool								bRslt;
	typename reference_t::iterator		itRef = this->m_pClRef->begin ();
	size_type							nFForward;

	for (nFForward = 0; nFForward < nPos; nFForward++)
	{
		itRef++;
	}

	(*itRef) = rData;

	bRslt = CBTreeArray_t::set_at (nPos, rData);

	this->test ();

	return (bRslt);
}

template<class _t_datalayerproperties>
bool CBTreeTestArray<_t_datalayerproperties>::get_at (const typename _t_datalayerproperties::size_type nPos, typename CBTreeTestArray<_t_datalayerproperties>::value_type &rData) const
{
	return (CBTreeArray_t::get_at (nPos, rData));
}

template<class _t_datalayerproperties>
void CBTreeTestArray<_t_datalayerproperties>::_swap (CBTreeTestArray<_t_datalayerproperties> &rContainer)
{
	CBTreeTestBaseLinear_t		&rBaseLinearContainer = dynamic_cast<CBTreeTestBaseLinear_t &> (rContainer);

	CBTreeTestBaseLinear_t::_swap (rBaseLinearContainer);
}

#endif // BTREETESTARRAY_CPP

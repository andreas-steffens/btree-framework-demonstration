/************************************************************
**
** file:	btreetestmultimap.cpp
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
** This file contains multi map application class code derived
** from the b-tree framework's multi map class to allow
** for the multi map class being tested by having
** the multi map application class act as a wrapper.
**
************************************************************/

#ifndef BTREETESTMULTIMAP_CPP
#define	BTREETESTMULTIMAP_CPP

#include "testbench/application_classes/regression/btreetestmultimap.h"

template<class _t_datalayerproperties>
CBTreeTestMultiMap<_t_datalayerproperties>::CBTreeTestMultiMap
	(
		_t_datalayerproperties &rDataLayerProperties, 
		typename _t_datalayerproperties::sub_node_iter_type nNodeSize, 
		typename CBTreeTestMultiMap<_t_datalayerproperties>::reference_t *pClRefData
	)
	:	CBTreeTestBaseAssociative
			<
				CBTreeMultiMap<uint32_t, multiMapMap_t, _t_datalayerproperties>, 
				::std::multimap<uint32_t, multiMapMap_t>, 
				::std::pair<uint32_t, multiMapMap_t>, 
				uint32_t, 
				_t_datalayerproperties
			>
		(
			rDataLayerProperties, 
			nNodeSize, 
			pClRefData, 
			true
		)
{
}

template<class _t_datalayerproperties>
CBTreeTestMultiMap<_t_datalayerproperties>::CBTreeTestMultiMap
	(const CBTreeTestMultiMap<_t_datalayerproperties> &rContainer, const bool bAssign)
	:	CBTreeTestBaseAssociative
			<
				CBTreeMultiMap<uint32_t, multiMapMap_t, _t_datalayerproperties>, 
				::std::multimap<uint32_t, multiMapMap_t>, 
				::std::pair<uint32_t, multiMapMap_t>, 
				uint32_t, 
				_t_datalayerproperties
			>
	(
		dynamic_cast<const CBTreeTestBaseAssociative
						<
							CBTreeMultiMap<uint32_t, multiMapMap_t, _t_datalayerproperties>, 
							::std::multimap<uint32_t, multiMapMap_t>, 
							::std::pair<uint32_t, multiMapMap_t>, 
							uint32_t, 
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
CBTreeTestMultiMap<_t_datalayerproperties>::CBTreeTestMultiMap
	(CBTreeTestMultiMap<_t_datalayerproperties> &&rRhsContainer)
	:	CBTreeTestBaseAssociative
			<
				CBTreeMultiMap<uint32_t, multiMapMap_t, _t_datalayerproperties>, 
				::std::multimap<uint32_t, multiMapMap_t>, 
				::std::pair<uint32_t, multiMapMap_t>, 
				uint32_t, 
				_t_datalayerproperties
			>
	(
		dynamic_cast<CBTreeTestBaseAssociative
						<
							CBTreeMultiMap<uint32_t, multiMapMap_t, _t_datalayerproperties>, 
							::std::multimap<uint32_t, multiMapMap_t>, 
							::std::pair<uint32_t, multiMapMap_t>, 
							uint32_t, 
							_t_datalayerproperties
						> &&> (rRhsContainer)
	)
{
	this->test ();
}

template<class _t_datalayerproperties>
CBTreeTestMultiMap<_t_datalayerproperties>::~CBTreeTestMultiMap ()
{
}

template<class _t_datalayerproperties>
CBTreeTestMultiMap<_t_datalayerproperties>&
	CBTreeTestMultiMap<_t_datalayerproperties>::operator=
	(
		const CBTreeTestMultiMap<_t_datalayerproperties> &rContainer
	)
{
	if (this != &rContainer)
	{
		CBTreeTestBaseAssociative_t			&rAssociativeThis = dynamic_cast<CBTreeTestBaseAssociative_t &> (*this);
		const CBTreeTestBaseAssociative_t	&rAssociativeContainer = dynamic_cast<const CBTreeTestBaseAssociative_t &> (rContainer);

		rAssociativeThis = rAssociativeContainer;

		this->test ();
	}

	return (*this);
}

template<class _t_datalayerproperties>
CBTreeTestMultiMap<_t_datalayerproperties>&
	CBTreeTestMultiMap<_t_datalayerproperties>::operator=
	(
		CBTreeTestMultiMap<_t_datalayerproperties> &&rRhsContainer
	)
{
	CBTreeTestBaseAssociative_t		&rAssociativeThis = dynamic_cast<CBTreeTestBaseAssociative_t &> (*this);
	CBTreeTestBaseAssociative_t		&rAssociativeContainer = dynamic_cast<CBTreeTestBaseAssociative_t &> (rRhsContainer);

	rAssociativeThis = ::std::move (rAssociativeContainer);

	this->test ();

	return (*this);
}

template<class _t_datalayerproperties>
template<class _t_iterator>
void CBTreeTestMultiMap<_t_datalayerproperties>::insert (_t_iterator sItFirst, _t_iterator sItLast)
{
	CBTreeMultiMap_t::insert (sItFirst, sItLast);

	this->test ();
}

template<class _t_datalayerproperties>
template<class _t_iterator, class _t_ref_iterator>
void CBTreeTestMultiMap<_t_datalayerproperties>::insert (_t_iterator sItFirst, _t_iterator sItLast)
{
	_t_ref_iterator		sCItFirst (sItFirst);
	_t_ref_iterator		sCItLast (sItLast);

	CBTreeMultiMap_t::insert (sItFirst, sItLast);

	this->test ();
}

template<class _t_datalayerproperties>
typename CBTreeTestMultiMap<_t_datalayerproperties>::iterator
	CBTreeTestMultiMap<_t_datalayerproperties>::insert
	(
		const typename CBTreeTestMultiMap<_t_datalayerproperties>::value_type &rData
	)
{
	iterator		sIter;
	value_type		sData = rData;

	sIter = CBTreeMultiMap_t::insert (sData);

	if (this->m_pClRef != NULL)
	{
		if (CBTreeMultiMap_t::count (sData.first) != this->m_pClRef->count (sData.first))
		{
			::std::cerr << ::std::endl;
			::std::cerr << "CBTreeTestMultiMap<>::insert: ERROR: multi key size mismatch!" << ::std::endl;
			::std::cerr << "key: ";
			::std::cerr << std::setfill ('0') << std::hex << std::setw (8);
			{
				::std::cerr << sData.first;
			}
			::std::cerr << std::setfill (' ') << std::dec << std::setw (0);
			::std::cerr << "reference: " << this->m_pClRef->count (sData.first) << ::std::endl;
			::std::cerr << "container: " << CBTreeMultiMap_t::count (sData.first) << ::std::endl;
			
			::std::cerr << "creating count.html... ";

			this->show_integrity ("count.html");

			::std::cerr << "finished" << ::std::endl;

			exit (-1);
		}
	}

	this->test ();

	return (sIter);
}

template<class _t_datalayerproperties>
typename CBTreeTestMultiMap<_t_datalayerproperties>::iterator
	CBTreeTestMultiMap<_t_datalayerproperties>::insert
	(
		typename CBTreeTestMultiMap<_t_datalayerproperties>::const_iterator sCIterHint, 
		const typename CBTreeTestMultiMap<_t_datalayerproperties>::value_type &rData
	)
{
	iterator					sIter;

	sIter = CBTreeMultiMap_t::insert (sCIterHint, rData);

	this->test ();

	return (sIter);
}

template<class _t_datalayerproperties>
typename CBTreeTestMultiMap<_t_datalayerproperties>::iterator
	CBTreeTestMultiMap<_t_datalayerproperties>::erase
	(
		typename CBTreeTestMultiMap<_t_datalayerproperties>::const_iterator sCIterPos
	)
{
	iterator		sRslt;

	sRslt = CBTreeMultiMap_t::erase (sCIterPos);

	this->test ();

	return (sRslt);
}

template<class _t_datalayerproperties>
typename _t_datalayerproperties::size_type CBTreeTestMultiMap<_t_datalayerproperties>::erase (const uint32_t &rKey)
{
	size_type		nRslt;

	nRslt = CBTreeMultiMap_t::erase (rKey);

	this->test ();

	return (nRslt);
}

template<class _t_datalayerproperties>
typename CBTreeTestMultiMap<_t_datalayerproperties>::iterator
	CBTreeTestMultiMap<_t_datalayerproperties>::erase
	(
		typename CBTreeTestMultiMap<_t_datalayerproperties>::const_iterator sCIterFirst, 
		typename CBTreeTestMultiMap<_t_datalayerproperties>::const_iterator sCIterLast
	)
{
	iterator	sRslt = CBTreeMultiMap_t::erase (sCIterFirst, sCIterLast);

	this->test ();
		
	return (sRslt);
}

template<class _t_datalayerproperties>
void CBTreeTestMultiMap<_t_datalayerproperties>::swap (CBTreeTestMultiMap_t &rContainer)
{
	if (this != &rContainer)
	{
		CBTreeTestMultiMap_t::_swap (rContainer);

		this->test ();
	}
}

template<class _t_datalayerproperties>
void CBTreeTestMultiMap<_t_datalayerproperties>::clear ()
{
	CBTreeMultiMap_t::clear ();

	this->test ();
}

template<class _t_datalayerproperties>
bool CBTreeTestMultiMap<_t_datalayerproperties>::operator== (const CBTreeTestMultiMap_t &rTMM) const
{
	if (this == &rTMM)
	{
		return (true);
	}

	if (this->size () != rTMM.size ())
	{
		return (false);
	}

	const_iterator		sCIterThis;
	const_iterator		sCIterThisBegin;
	const_iterator		sCIterThisEnd;
	const_iterator		sCIterRTMM;
	const_iterator		sCIterRTMMbegin;
	value_type			sThisVal;
	value_type			sTMMval;

	sCIterThisBegin = this->cbegin ();
	sCIterThisEnd = this->cend ();

	sCIterRTMMbegin = rTMM.cbegin ();

	for (sCIterThis = sCIterThisBegin, sCIterRTMM = sCIterRTMMbegin; sCIterThis != sCIterThisEnd; sCIterThis++, sCIterRTMM++)
	{
		sThisVal = *sCIterThis;
		sTMMval = *sCIterRTMM;

		if ((sThisVal.first != sTMMval.first) ||
			(sThisVal.second.nData != sThisVal.second.nData) ||
			(sThisVal.second.nDebug != sTMMval.second.nDebug))
		{
			return (false);
		}
	}

	return (true);
}

template<class _t_datalayerproperties>
bool CBTreeTestMultiMap<_t_datalayerproperties>::operator!= (const CBTreeTestMultiMap_t &rTMM) const
{
	return (! ((*this) == rTMM));
}

template<class _t_datalayerproperties>
void CBTreeTestMultiMap<_t_datalayerproperties>::_swap (CBTreeTestMultiMap<_t_datalayerproperties> &rContainer)
{
	CBTreeTestBaseAssociative_t		&rAssociative = dynamic_cast<CBTreeTestBaseAssociative_t &> (*this);

	CBTreeTestBaseAssociative_t::_swap (rAssociative);
}

#endif // !BTREETESTMULTIMAP_CPP


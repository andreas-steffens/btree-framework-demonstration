/************************************************************
**
** file:	btreetestkeysort.cpp
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
** This file contains key sort application class code derived
** from the b-tree framework's key sort data class to allow
** for the key sort data class being tested by having
** the key sort application class act as a wrapper.
**
************************************************************/

#ifndef	BTREETESTKEYSORT_CPP
#define	BTREETESTKEYSORT_CPP

#include "testbench/application_classes/regression/btreetestkeysort.h"

template<class _t_data, class _t_key, class _t_datalayerproperties>
CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::CBTreeKeySortTest
	(
		_t_datalayerproperties &rDataLayerProperties, 
		typename _t_datalayerproperties::sub_node_iter_type nNodeSize, 
		typename CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::reference_t *pClRefData
	)
	:	CBTreeTestBaseAssociative
			<
				CBTreeKeySort<_t_data, _t_key, _t_datalayerproperties>, 
				::std::multimap<_t_key, keySortMap_t>, 
				_t_data, 
				_t_key, 
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

template<class _t_data, class _t_key, class _t_datalayerproperties>
CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::CBTreeKeySortTest
	(
		const CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties> &rContainer, 
		const bool bAssign
	)
	:	CBTreeTestBaseAssociative
			<
				CBTreeKeySort<_t_data, _t_key, _t_datalayerproperties>,
				::std::multimap<_t_key, keySortMap_t>, 
				_t_data, 
				_t_key, 
				_t_datalayerproperties
			>
		(
			dynamic_cast<const CBTreeTestBaseAssociative
							<
								CBTreeKeySort<_t_data, _t_key, _t_datalayerproperties>, 
								::std::multimap<_t_key, keySortMap_t>, 
								_t_data, 
								_t_key, 
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

template<class _t_data, class _t_key, class _t_datalayerproperties>
CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::CBTreeKeySortTest
	(
		CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties> &&rRhsContainer
	)
	:	CBTreeTestBaseAssociative
				<
					CBTreeKeySort<_t_data, _t_key, _t_datalayerproperties>, 
					::std::multimap<_t_key, keySortMap_t>, 
					_t_data, 
					_t_key, 
					_t_datalayerproperties
				>
		(
			dynamic_cast<CBTreeTestBaseAssociative
							<
								CBTreeKeySort<_t_data, _t_key, _t_datalayerproperties>, 
								::std::multimap<_t_key, keySortMap_t>, 
								_t_data, 
								_t_key, 
								_t_datalayerproperties
							> &&> (rRhsContainer)
		)
{
	this->test ();
}

template<class _t_data, class _t_key, class _t_datalayerproperties>
CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::~CBTreeKeySortTest ()
{
}

template<class _t_data, class _t_key, class _t_datalayerproperties>
template<class _t_iterator>
void CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::insert (_t_iterator sItFirst, _t_iterator sItLast)
{
	this->insert_via_iterator (sItFirst, sItLast);

	this->test ();
}

template<class _t_data, class _t_key, class _t_datalayerproperties>
typename CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::iterator
	CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::insert
	(
		const typename CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::value_type &rData
	)
{
	iterator					sIter;

	sIter = CBTreeKeySort_t::insert (rData);

	this->test ();

	return (sIter);
}

template<class _t_data, class _t_key, class _t_datalayerproperties>
template<class ..._t_va_args>
typename CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::iterator
	CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::insert
	(
		typename CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::const_iterator sCIterHint, 
		_t_va_args && ... rrArgs
	)
{
	iterator					sIter;

	sIter = CBTreeKeySort_t::insert (sCIterHint, ::std::forward<_t_va_args> (rrArgs) ...);

	this->test ();

	return (sIter);
}

template<class _t_data, class _t_key, class _t_datalayerproperties>
typename CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::iterator
	CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::erase
	(
		typename CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::const_iterator sCIterPos
	)
{
	iterator		sIter;
	
	sIter = CBTreeKeySort_t::erase (sCIterPos);

	this->test ();

	return (sIter);
}

template<class _t_data, class _t_key, class _t_datalayerproperties>
typename _t_datalayerproperties::size_type CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::erase (const typename CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::key_type &rKey)
{
	size_type		nRetval;

	nRetval = CBTreeKeySort_t::erase (rKey);

	this->test ();

	return (nRetval);
}

template<class _t_data, class _t_key, class _t_datalayerproperties>
typename CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::iterator
	CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::erase
	(
		typename CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::const_iterator sCIterFirst, 
		typename CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::const_iterator sCIterLast
	)
{
	typedef typename reference_t::iterator			itmmap_t;

	const_iterator		sCIterRetval;
	const_iterator		sCIter;
	itmmap_t			sItMMapLower;
	itmmap_t			sItMMapUpper;
	itmmap_t			sItMMap;
	iterator			sIter;

	sIter = CBTreeKeySort_t::erase (sCIterFirst, sCIterLast);

	this->test ();

	return (sIter);
}

template<class _t_data, class _t_key, class _t_datalayerproperties>
void CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::swap
	(
		CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties> &rContainer
	)
{
	if (this != &rContainer)
	{
		CBTreeKeySortTest_t::_swap (rContainer);

		this->test ();
	}
}

template<class _t_data, class _t_key, class _t_datalayerproperties>
void CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::clear ()
{
	CBTreeKeySort_t::clear ();

	this->test ();
}

template<class _t_data, class _t_key, class _t_datalayerproperties>
typename CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::value_type CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::get_data_reference
	(
		typename CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::const_iterator &rCIter
	)
{
	typedef typename reference_t::const_iterator		mmap_citer_t;

	return (this->template get_data_reference<const_iterator, mmap_citer_t> (rCIter));
}

template<class _t_data, class _t_key, class _t_datalayerproperties>
typename CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::value_type CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::get_data_reference
	(
		typename CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::const_reverse_iterator &rCRIter
	)
{
	typedef typename reference_t::const_reverse_iterator		mmap_criter_t;

	return (this->template get_data_reference<const_reverse_iterator, mmap_criter_t> (rCRIter));
}

template<class _t_data, class _t_key, class _t_datalayerproperties>
CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties> &CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::operator=
	(const CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties> &rContainer)
{
	if (this != &rContainer)
	{
		CBTreeTestBaseAssociative_t			&rBaseAssociativeThis = dynamic_cast <CBTreeTestBaseAssociative_t &> (*this);
		const CBTreeTestBaseAssociative_t	&rBaseAssociativeContainer = dynamic_cast <const CBTreeTestBaseAssociative_t &> (rContainer);

		rBaseAssociativeThis = rBaseAssociativeContainer;

		this->test ();
	}

	return (*this);
}

template<class _t_data, class _t_key, class _t_datalayerproperties>
CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties> &CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::operator=
	(CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties> &&rRhsContainer)
{
	CBTreeTestBaseAssociative_t		&rBaseAssociativeThis = dynamic_cast <CBTreeTestBaseAssociative_t &> (*this);
	CBTreeTestBaseAssociative_t		&rBaseAssociativeContainer = dynamic_cast <CBTreeTestBaseAssociative_t &> (rRhsContainer);

	rBaseAssociativeThis = ::std::move (rBaseAssociativeContainer);

	this->test ();
	
	return (*this);
}

template<class _t_data, class _t_key, class _t_datalayerproperties>
int CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::comp (const typename CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::key_type &rKey0, const typename CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::key_type &rKey1) const
{
	if (rKey0 < rKey1)
	{
		return (-1);
	}
	else if (rKey0 > rKey1)
	{
		return (1);
	}

	return (0);
}

template<class _t_data, class _t_key, class _t_datalayerproperties>
template<class _t_iterator, class _t_ref_iterator>
typename CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::value_type CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::get_data_reference (_t_iterator &rIter)
{
	_t_iterator			sIterBegin;
	_t_ref_iterator		sMMapCIter;

	get_begin (this, sIterBegin);
	
	get_begin (this->m_pClRef, sMMapCIter);

	size_type			nOffset = ::std::distance (sIterBegin, rIter);

	::std::advance (sMMapCIter, nOffset);

	return ((value_type) *sMMapCIter);
}

template<class _t_data, class _t_key, class _t_datalayerproperties>
void CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::_swap (CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties> &rContainer)
{
	CBTreeTestBaseAssociative_t		&rAssociative = dynamic_cast<CBTreeTestBaseAssociative_t &> (rContainer);

	CBTreeTestBaseAssociative_t::_swap (rAssociative);
}

template<class _t_data, class _t_key, class _t_datalayerproperties>
bool CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>::show_data (std::ofstream &ofs, std::stringstream &rstrData, std::stringstream &rszMsg, const typename _t_datalayerproperties::node_iter_type nNode, const typename _t_datalayerproperties::sub_node_iter_type nSubPos) const
{
	typedef typename reference_t::const_iterator		mmap_citer_t;
	typedef typename reference_t::value_type			value_ref_t;

	value_type				*psData;
	key_type				rData;

	try
	{
		psData = this->get_data (nNode, nSubPos);

		rData = get_entry_key (*psData);
		rData = (rData >> 16) | (rData << 16);
		rData = ((rData >> 8) & 0xFF00FF) | ((rData << 8) & 0xFF00FF00);
		
		rstrData.clear ();
		rstrData << "<table border=\"0\" cellspacing=\"1\" width=\"220\"><tr><td>";
		rstrData << "key: " << ::std::hex << ::std::setfill ('0') << ::std::setw (8) << rData << "<br>";
		rstrData << "data: " << get_entry_data (*psData) << ::std::dec << "<br>";
		rstrData << "debug: " << get_entry_debug (*psData) << "<br>";
		rstrData << "instance: " << this->get_instancePos (nNode, nSubPos);
		rstrData << "</td>";

		size_type		nDiff = this->lower_bound (get_entry_key (*psData)) - this->cbegin ();
		size_type		nOffset = nDiff + this->get_instancePos (nNode, nSubPos);

		rstrData << "<td align=\"top\">";

		if (nOffset < this->m_pClRef->size ())
		{
			mmap_citer_t		sItMMap;

			sItMMap = this->m_pClRef->cbegin ();

			::std::advance (sItMMap, nOffset);

			rData = get_entry_key ((value_ref_t) *sItMMap);
			rData = (rData >> 16) | (rData << 16);
			rData = ((rData >> 8) & 0xFF00FF)| ((rData << 8) & 0xFF00FF00);

			if (get_entry_key (*psData) != get_entry_key ((value_ref_t) *sItMMap))
			{
				if (ofs.is_open ())
				{
					rstrData << "<font color=\"#FF0000\">";
				}
				else
				{
					return (false);
				}
			}
			else
			{
				rstrData << "<font color=\"#00BB00\">";
			}
			
			rstrData << "key: " << ::std::hex << ::std::setfill ('0') << ::std::setw (8) << rData << "<br>";
			rstrData << "</font>";

			if (get_entry_data (*psData) != get_entry_data ((value_ref_t) *sItMMap))
			{
				if (ofs.is_open ())
				{
					rstrData << "<font color=\"#AAAA00\">";
				}
				else
				{
					return (false);
				}
			}
			else
			{
				rstrData << "<font color=\"#00BB00\">";
			}
			
			rstrData << "data: " << get_entry_data ((value_ref_t) *sItMMap) << ::std::dec << "<br>";
			rstrData << "</font>";

			if (get_entry_debug (*psData) != get_entry_debug ((value_ref_t) *sItMMap))
			{
				rstrData << "<font color=\"#AAAA00\">";
			}
			else
			{
				rstrData << "<font color=\"#00BB00\">";
			}
			
			rstrData << "debug: " << get_entry_debug ((value_ref_t) *sItMMap) << "<br>";
			rstrData << "</font>";
			rstrData << "-";
		}
		else
		{
			rstrData << "<font color=\"#FF0000\">";
			rstrData << "reference<br>";
			rstrData << "out of<br>";
			rstrData << "range";
			rstrData << "</font>";
		}

		rstrData << "</td></tr>";
		rstrData << "</table>" << ::std::endl;
	}
	catch (::std::exception *pE)
	{
		if (!ofs.is_open ())
		{
			return (false);
		}

		rszMsg.clear ();
		rszMsg << "<br>data: corruption (" << pE->what () << ")";

		rData = get_entry_key (*psData);
		rData = (rData >> 16) | (rData << 16);
		rData = ((rData >> 8) & 0xFF00FF)| ((rData << 8) & 0xFF00FF00);
		
		rstrData.clear ();
		rstrData << "key: " << ::std::hex << ::std::setfill ('0') << ::std::setw (8) << rData << ::std::dec << "<br>debug: " << get_entry_debug (*psData) << "<br>instance: ---";
	}

	return (true);
}

#endif // BTREETESTKEYSORT_CPP


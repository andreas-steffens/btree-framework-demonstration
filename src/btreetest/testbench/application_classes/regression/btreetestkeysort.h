/************************************************************
**
** file:	btreetestkeysort.h
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

#ifndef	BTREETESTKEYSORT_H
#define	BTREETESTKEYSORT_H

#include <stdint.h>

#include <map>
#include <list>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "testbench/common/btreetestcommon.h"
#include "testbench/application_classes/regression/base/btreetestbaseassociative.h"

#include "btreekeysort.h"

template<class _t_key>
class multiMapMemCmp
{
public:

	bool	operator () (const _t_key &rLhs, const _t_key &rRhs)
	{
		return (memcmp ((const void *) &rLhs, (const void *) &rRhs, sizeof (rLhs)) < 0);
	};
};

typedef struct keySortEntry_s
{
	uint32_t		nKey;
	uint32_t		nData;
	uint32_t		nDebug;

	keySortEntry_s ()
	{
	}
		
	keySortEntry_s (uint32_t _nKey, uint32_t _nData, uint32_t _nDebug)
	{
		nKey = _nKey;
		nData = _nData;
		nDebug = _nDebug;
	}

	operator		const uint32_t ()
	{
		return (nKey);
	}

	bool	operator== (const struct keySortEntry_s &rRhs) const
	{
		return ((this->nKey == rRhs.nKey) && (this->nData == rRhs.nData));
	}

	bool	operator!= (const struct keySortEntry_s &rRhs) const
	{
		return ((this->nKey != rRhs.nKey) || (this->nData != rRhs.nData));
	}
} keySortEntry_t;

typedef struct keySortMap_s
{
	uint32_t		nData;
	uint32_t		nDebug;

	bool	operator== (const struct keySortMap_s &rRhs) const
	{
		return (this->nData == rRhs.nData);
	}

	bool	operator!= (const struct keySortMap_s &rRhs) const
	{
		return (this->nData != rRhs.nData);
	}
} keySortMap_t;

/************************************************************************************/

template<class _t_iterator, class _t_data>
struct btree_key_sort_test_insert_reference_via_iterator_arbiter
{
	static void btree_key_sort_test_insert_reference_via_iterator (_t_iterator &sItFirst, _t_iterator &sItLast, typename ::std::multimap<const uint32_t, keySortMap_t> *pClRefData)
	{
		pClRefData->insert<_t_iterator> (sItFirst, sItLast);
	}
};

template<class _t_iterator>
struct btree_key_sort_test_insert_reference_via_iterator_arbiter<_t_iterator, keySortEntry_t>
{
	static void btree_key_sort_test_insert_reference_via_iterator (_t_iterator &sItFirst, _t_iterator &sItLast, typename ::std::multimap<const uint32_t, keySortMap_t> *pClRefData)
	{
		::std::pair<uint32_t, keySortMap_t>		sValue;
		_t_iterator								sIt;

		for (sIt = sItFirst; sIt != sItLast; sIt++)
		{
			sValue.first = ((keySortEntry_t) (*sIt)).nKey;
			sValue.second.nData = ((keySortEntry_t) (*sIt)).nData;
			sValue.second.nDebug = ((keySortEntry_t) (*sIt)).nDebug;

			pClRefData->insert (sValue);
		}
	}
};

/************************************************************************************/

template<class _t_data, class _t_key, class _t_datalayerproperties = CBTreeIOpropertiesRAM <> >
class CBTreeKeySortTest
	:	public CBTreeTestBaseAssociative
				<
					CBTreeKeySort<_t_data, _t_key, _t_datalayerproperties>, 
					::std::multimap<_t_key, keySortMap_t>, 
					_t_data, 
					_t_key, 
					_t_datalayerproperties
				>
{
public:

	typedef CBTreeKeySortTest										CBTreeKeySortTest_t;

	typedef CBTreeTestBaseAssociative
		<
			CBTreeKeySort<_t_data, _t_key, _t_datalayerproperties>, 
			::std::multimap<_t_key, keySortMap_t>, 
			_t_data, 
			_t_key, 
			_t_datalayerproperties
		>															CBTreeTestBaseAssociative_t;

	typedef _t_data													value_type;
	typedef	keySortMap_t											map_type;
	typedef _t_key													key_type;
	typedef typename _t_datalayerproperties::size_type				size_type;
	typedef typename _t_datalayerproperties::node_iter_type			node_iter_type;
	typedef typename _t_datalayerproperties::sub_node_iter_type		sub_node_iter_type;
	typedef _t_datalayerproperties									data_layer_properties_type;
	typedef typename _t_datalayerproperties::data_layer_type		data_layer_type;
	
	typedef value_type&												reference;
	typedef const value_type&										const_reference;
	typedef value_type*												pointer;
	typedef const value_type*										const_pointer;
	typedef	typename ::std::make_signed<size_type>::type			difference_type;

	typedef CBTreeKeySort<_t_data, _t_key, _t_datalayerproperties>	CBTreeKeySort_t;

	typedef typename CBTreeKeySort_t::iterator						iterator;
	typedef typename CBTreeKeySort_t::const_iterator				const_iterator;
	typedef typename CBTreeKeySort_t::reverse_iterator				reverse_iterator;
	typedef typename CBTreeKeySort_t::const_reverse_iterator		const_reverse_iterator;

	typedef ::std::multimap<key_type, keySortMap_t>					reference_t;

						CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>
													(_t_datalayerproperties &rDataLayerProperties, sub_node_iter_type nNodeSize, reference_t *pClRefData);

						CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>
													(const CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties> &rContainer, const bool bAssign = true);

						CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>
													(CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties> &&rRhsContainer);

	virtual				~CBTreeKeySortTest<_t_data, _t_key, _t_datalayerproperties>
													();

	template<class _t_iterator>
	void				insert						(_t_iterator sItFirst, _t_iterator sItLast);
	iterator			insert						(const value_type &rData);

	template<class ..._t_va_args>
	iterator			insert						(const_iterator sCIterHint, _t_va_args && ... rrArgs);

	iterator			erase						(const_iterator sCIterPos);
	size_type			erase						(const key_type &rKey);
	iterator			erase						(const_iterator sCIterFirst, const_iterator sCIterLast);

	void				swap						(CBTreeKeySortTest &rKeySort);

	void				clear						();

	value_type			get_data_reference			(const_iterator &rCIter);
	value_type			get_data_reference			(const_reverse_iterator &rCRIter);
	
	CBTreeKeySortTest	&operator=					(const CBTreeKeySortTest &rContainer);
	CBTreeKeySortTest	&operator=					(CBTreeKeySortTest &&rRhsContainer);

protected:

	int					comp						(const key_type &rKey0, const key_type &rKey1) const;

	template<class _t_iterator>
	void				insert_via_iterator			(_t_iterator sItFirst, _t_iterator sItLast)
	{
		CBTreeKeySort<_t_data, _t_key, _t_datalayerproperties>::insert (sItFirst, sItLast);
	}

	template<class _t_iterator, class _t_ref_iterator>
	_t_data				get_data_reference			(_t_iterator &rIter);

	void				_swap						(CBTreeKeySortTest_t &rContainer);

	bool				show_data					(std::ofstream &ofs, std::stringstream &rstrData, std::stringstream &rszMsg, const node_iter_type nNode, const sub_node_iter_type nSubPos) const;
};

#endif // BTREETESTKEYSORT_H

#include "btreetestkeysort.cpp"

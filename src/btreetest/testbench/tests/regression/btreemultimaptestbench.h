/************************************************************
**
** file:	btreemultimaptestbench.h
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
** This file contains code for the b-tree framework's test bench
** exercising functional, code coverage and regression tests
** for the multi map application class.
**
************************************************************/

#ifndef BTREEMULTIMAPTESTBENCH_H
#define	BTREEMULTIMAPTESTBENCH_H

#include <stdint.h>

#include <map>
#include <list>
#include <vector>

#include "testbench/application_classes/regression/btreetestmultimap.h"

#include "testbench/primitives/btreecommonprimitives.h"

#include "testbench/common/btreetestcommon.h"

#include "testbench/tests/regression/btreemaptestbench.h"

#include "testbench/wrapper_classes/btreemultimaptestwrapper.h"

#include "specific_data_classes/btreemultimap.h"

template<class _t_key, class _t_map>
class CBTreeTestBenchMultiMap	:	public ::std::multimap<_t_key, _t_map>
{
public:

				CBTreeTestBenchMultiMap<_t_key, _t_map> ()	
					:	::std::multimap<_t_key, _t_map> () 
				{};

				CBTreeTestBenchMultiMap<_t_key, _t_map> (const CBTreeTestBenchMultiMap &rMap)	
					:	::std::multimap<_t_key, _t_map> (rMap) 
				{};

	explicit	CBTreeTestBenchMultiMap<_t_key, _t_map> (const ::std::map<_t_key, _t_map> &rMap)	
					:	::std::multimap<_t_key, _t_map> (rMap) 
				{};

				~CBTreeTestBenchMultiMap<_t_key, _t_map> ()	
				{};

	template<class _t_iterator>
	void insert (const typename ::std::multimap<_t_key, _t_map>::iterator &rDummyIter, _t_iterator &rIterFirst, _t_iterator &rIterLast)
	{
		rDummyIter;

		::std::multimap<_t_key, _t_map>::insert (rIterFirst, rIterLast);
	};

	template<class _t_iterator>
	void insert (const typename ::std::multimap<_t_key, _t_map>::const_iterator &rDummyIter, _t_iterator &rIterFirst, _t_iterator &rIterLast)
	{
		rDummyIter;

		::std::multimap<_t_key, _t_map>::insert (rIterFirst, rIterLast);
	};

	template<class _t_iterator>
	void insert (_t_iterator &rIterFirst, _t_iterator &rIterLast)
	{
		::std::multimap<_t_key, _t_map>::insert (rIterFirst, rIterLast);
	};

	typename ::std::multimap<_t_key, _t_map>::iterator insert (const typename ::std::multimap<_t_key, _t_map>::value_type &rVal)
	{
		return (::std::multimap<_t_key, _t_map>::insert (rVal));
	};
};

typedef CBTreeTestBenchMultiMap<uint32_t, multiMapMap_t>				multimap_reference_t;

typedef enum
{
	BTREETEST_MULTIMAP_ASSIGNMENT_OPERATOR, 
	BTREETEST_MULTIMAP_STL_IF_INSERT = 1000, 
	BTREETEST_MULTIMAP_STL_IF_INSERT_VIA_ITERATOR, 
	BTREETEST_MULTIMAP_STL_IF_ERASE_VIA_ITERATOR, 
	BTREETEST_MULTIMAP_STL_IF_ERASE_VIA_KEY, 
	BTREETEST_MULTIMAP_STL_IF_ERASE_VIA_ITERATOR_MULTIPLE, 
	BTREETEST_MULTIMAP_STL_IF_KEY_COMP, 
	BTREETEST_MULTIMAP_STL_IF_VALUE_COMP, 
	BTREETEST_MULTIMAP_STL_IF_SWAP, 
	BTREETEST_MULTIMAP_STL_IF_FIND, 
	BTREETEST_MULTIMAP_STL_IF_LOWER_BOUND_UPPER_BOUND, 
	BTREETEST_MULTIMAP_STL_IF_EMPLACE, 
	BTREETEST_MULTIMAP_STL_IF_EMPLACE_HINT, 
	BTREETEST_MULTIMAP_STL_IF_EMPLACE_HINT_MINOR, 
	BTREETEST_MULTIMAP_STL_IF_EMPLACE_HINT_SIGNIFICANT, 
	BTREETEST_MULTIMAP_STL_IF_EMPLACE_HINT_LARGE, 
	BTREETEST_MULTIMAP_STL_IF_INSERT_HINT, 
	BTREETEST_MULTIMAP_STL_IF_INSERT_HINT_MINOR, 
	BTREETEST_MULTIMAP_STL_IF_INSERT_HINT_SIGNIFICANT, 
	BTREETEST_MULTIMAP_STL_IF_INSERT_HINT_LARGE, 
	BTREETEST_MULTIMAP_STL_IF_EMPLACE_VIA_CTOR, 
	BTREETEST_MULTIMAP_STL_IF_EMPLACE_HINT_VIA_CTOR, 
	BTREETEST_MULTIMAP_STL_IF_EQUAL_RANGE, 
} btreetest_multimap_t;

template<class _t_container>
void TestBTreeSTLmultiMap (uint32_t nTestNum, uint32_t nNodeSize, uint32_t nPageSize, _t_container *pMMapWrapper);

#endif // !BTREEMULTIMAPTESTBENCH_H

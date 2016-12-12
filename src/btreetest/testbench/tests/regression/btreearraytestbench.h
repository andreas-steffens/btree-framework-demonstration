/************************************************************
**
** file:	btreearraytestbench.h
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
** This file contains code for the b-tree framework's test bench
** exercising functional, code coverage and regression tests
** for the array data class.
**
************************************************************/

#ifndef	BTREEARRAYTESTBENCH_H
#define	BTREEARRAYTESTBENCH_H

#include <stdint.h>

#include <iostream>
#include <sstream>
#include <string>

#include <list>
#include <vector>

#include "testbench/common/btreetestcommon.h"
#include "testbench/application_classes/regression/btreetestarray.h"
#include "testbench/primitives/btreearraytestprimitive.h"

#include "testbench/wrapper_classes/btreearraytestwrapper.h"

typedef enum
{
	BTREETEST_ARRAY_BASIC_FIFO, 
	BTREETEST_ARRAY_BASIC_FIFO_SMALL, 
	BTREETEST_ARRAY_BASIC_LILO, 
	BTREETEST_ARRAY_BASIC_LILO_SMALL, 
	BTREETEST_ARRAY_BASIC_RANDOM, 
	BTREETEST_ARRAY_BASIC_RANDOM_SMALL, 
	BTREETEST_ARRAY_CLEAR, 
	BTREETEST_ARRAY_REPLACE, 
	BTREETEST_ARRAY_UNLOAD, 
	BTREETEST_ARRAY_HTML_OUTPUT, 
	BTREETEST_ARRAY_COPY_CONSTRUCTOR, 
	BTREETEST_ARRAY_OPERATOR_OVERLOAD_ASSIGN, 
	BTREETEST_ARRAY_OPERATOR_OVERLOAD_SUBSCRIPT, 
	BTREETEST_ARRAY_SERLIALIZE_ALL, 
	BTREETEST_ARRAY_SERLIALIZE_HALF_NODE, 
	BTREETEST_ARRAY_SERLIALIZE_PART_NODE, 
	BTREETEST_ARRAY_SERLIALIZE_INCOMPLETE, 
	BTREETEST_ARRAY_SELF_REFERENCE_VIA_SUBSCRIPT_WRAPPER, 
	BTREETEST_ARRAY_SERLIALIZE_ZERO_LENGTH, 
	BTREETEST_ARRAY_MOVE_CONSTRUCTOR_AND_ASSIGNMENT, 
	BTREETEST_ARRAY_STL_IF_ASSIGN_FILL = 1000, 
	BTREETEST_ARRAY_STL_IF_ASSIGN_VIA_ITERATOR, 
	BTREETEST_ARRAY_STL_IF_PUSH_BACK_POP_BACK, 
	BTREETEST_ARRAY_STL_IF_INSERT_MULTIPLE, 
	BTREETEST_ARRAY_STL_IF_INSERT_VIA_ITERATOR, 
	BTREETEST_ARRAY_STL_IF_INSERT_VIA_ITERATOR_LARGE_ITER,
	BTREETEST_ARRAY_STL_IF_INSERT_VIA_ITERATOR_LARGE_CITER,
	BTREETEST_ARRAY_STL_IF_INSERT_VIA_ITERATOR_LARGE_RITER,
	BTREETEST_ARRAY_STL_IF_INSERT_VIA_ITERATOR_LARGE_CRITER,
	BTREETEST_ARRAY_STL_IF_ERASE_SINGLE, 
	BTREETEST_ARRAY_STL_IF_ERASE_MULTIPLE, 
	BTREETEST_ARRAY_STL_IF_SWAP, 
	BTREETEST_ARRAY_STL_IF_EMPLACE, 
	BTREETEST_ARRAY_STL_IF_EMPLACE_BACK, 
	BTREETEST_ARRAY_CODE_COVERAGE_ROOT_MERGE_WITH_LOWER_RIGHT = 2000
} btreetest_array_e;

typedef enum
{
	BTREETEST_ARRAY_STL_IF_ASSIGN_VIA_ITERATOR_FULL, 
	BTREETEST_ARRAY_STL_IF_ASSIGN_VIA_ITERATOR_FULL_EXTERN, 
	BTREETEST_ARRAY_STL_IF_ASSIGN_VIA_ITERATOR_SELF_REFERENCE, 
	BTREETEST_ARRAY_STL_IF_ASSIGN_VIA_ITERATOR_EQUIVALENT_OR_SAME, 
	BTREETEST_ARRAY_STL_IF_ASSIGN_VIA_ITERATOR_PART_SELF_REFERENCE, 
} btreetest_array_stl_if_assign_via_iterator_e;

typedef enum
{
	BTREETEST_ARRAY_STL_IF_INSERT_VIA_ITERATOR_HALF_WAY, 
	BTREETEST_ARRAY_STL_IF_INSERT_VIA_ITERATOR_HALF_WAY_EXTERN, 
	BTREETEST_ARRAY_STL_IF_INSERT_VIA_ITERATOR_SELF_REFERENCE, 
	BTREETEST_ARRAY_STL_IF_INSERT_VIA_ITERATOR_INEFFECTIVE, 
	BTREETEST_ARRAY_STL_IF_INSERT_VIA_ITERATOR_PART_SELF_REFERENCE, 
} btreetest_array_stl_if_insert_via_iterator_e;

template<class _t_container>
void TestBTreeArray (uint32_t nTest, uint32_t nNodeSize, uint32_t nPageSize, _t_container *pArrayWrapper);

#endif // BTREEARRAYTESTBENCH_H

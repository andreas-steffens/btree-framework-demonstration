/************************************************************
**
** file:	btreecommonprimitives.h
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
** This file contains primitive code for the b-tree framework's
** test bench to support any application class testing.
**
************************************************************/

#ifndef BTREECOMMONPRIMITIVES_H
#define BTREECOMMONPRIMITIVES_H

#include <stdint.h>

#include <iostream>

#include "testbench/application_classes/regression/btreetestkeysort.h"

#include "testbench/primitives/btreeprimitivedefinitions.h"
#include "testbench/primitives/btreekeysorttestprimitive.h"
#include "testbench/common/btreetestcommon.h"

typedef enum
{
	ASSOCIATIVE_ADD_METHOD_INSERT, 
	ASSOCIATIVE_ADD_METHOD_INSERT_HINT, 
	ASSOCIATIVE_ADD_METHOD_EMPLACE, 
	ASSOCIATIVE_ADD_METHOD_EMPLACE_HINT, 
	ASSOCIATIVE_ADD_METHOD_ABSTRACT_EMPLACE, 
	ASSOCIATIVE_ADD_METHOD_ABSTRACT_EMPLACE_HINT, 
} associative_add_method_e;

template<class _t_container>
void associative_container_add_primitive (_t_container *pContainer, typename _t_container::size_type nEntries, uint32_t &nFromWhereOrSeed, btreetest_key_generation_e eGenerator);

template<class _t_container>
void associative_container_add_primitive (_t_container *pContainer, typename _t_container::size_type nEntries, typename _t_container::size_type nHintVariation, uint32_t &nFromWhereOrSeed, btreetest_key_generation_e eGenerator, associative_add_method_e eMethod = ASSOCIATIVE_ADD_METHOD_INSERT);

template<class _t_container>
void associative_container_remove_primitive (_t_container *pContainer, typename _t_container::size_type nEntries, uint32_t nInstance, uint32_t &nFromWhereOrSeed, btreetest_key_generation_e eGenerator);

template<class _t_container>
bool associative_container_compare_primitive (_t_container *pContainer0, _t_container *pContainer1);

#endif // BTREECOMMONPRIMITIVES_H

#include "btreecommonprimitives.cpp"

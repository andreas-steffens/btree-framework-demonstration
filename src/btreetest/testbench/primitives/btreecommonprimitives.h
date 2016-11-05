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

template<class _t_container>
void associative_container_add_primitive (_t_container *pContainer, typename _t_container::size_type nEntries, uint32_t &nFromWhereOrSeed, btreetest_key_generation_e eGenerator);

template<class _t_container>
void associative_container_insert_hint_primitive (_t_container *pContainer, typename _t_container::size_type nEntries, typename _t_container::size_type nHintVariation, uint32_t &nFromWhereOrSeed, btreetest_key_generation_e eGenerator);

template<class _t_container>
void associative_container_emplace_primitive (_t_container *pContainer, typename _t_container::size_type nEntries, uint32_t &nFromWhereOrSeed, btreetest_key_generation_e eGenerator);

template<class _t_container>
void associative_container_emplace_hint_primitive (_t_container *pContainer, typename _t_container::size_type nEntries, typename _t_container::size_type nHintVariation, uint32_t &nFromWhereOrSeed, btreetest_key_generation_e eGenerator);

template<class _t_container>
void associative_container_remove_primitive (_t_container *pContainer, typename _t_container::size_type nEntries, uint32_t nInstance, uint32_t &nFromWhereOrSeed, btreetest_key_generation_e eGenerator);

template<class _t_container>
bool associative_container_compare_primitive (_t_container *pContainer0, _t_container *pContainer1);

#endif // BTREECOMMONPRIMITIVES_H

#include "btreecommonprimitives.cpp"

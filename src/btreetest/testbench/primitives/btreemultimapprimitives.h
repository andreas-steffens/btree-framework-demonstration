/************************************************************
**
** file:	btreemultimapprimitives.h
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
** This file contains primitive code for the b-tree framework's
** test bench to support multi map application class testing.
**
************************************************************/

#ifndef BTREEMULTIMAPPRIMITIVES_H
#define	BTREEMULTIMAPPRIMITIVES_H

#include <stdint.h>

#include <type_traits>

#include "testbench/application_classes/regression/btreetestmap.h"
#include "testbench/application_classes/regression/btreetestmultimap.h"

#include "specific_data_classes/btreemultimap.h"

typedef CBTreePairTest<const uint32_t, mapMap_t>										mapPair_t;

typedef CBTreePairTest<const uint32_t, multiMapMap_t>									multiMapPair_t;

#endif // !BTREEMULTIMAPPRIMITIVES_H

#include "btreemultimapprimitives.cpp"

#ifndef	BTREEMULTIMAPPERFTESTBENCH_H
#define	BTREEMULTIMAPPERFTESTBENCH_H

#include <stdint.h>

#include <chrono>
#include <iostream>
#include <sstream>
#include <string>

#include <map>
#include <vector>

#include "testbench/common/btreetestcommon.h"
#include "testbench/common/btreeperftestcommon.h"

#include "specific_data_classes/btreemultimap.h"


typedef enum
{
	BTREETEST_MULTIMAP_PERF_INSERT_SINGLE,
	BTREETEST_MULTIMAP_PERF_INSERT_SINGLE_ACCURATE_HINT, 
	BTREETEST_MULTIMAP_PERF_INSERT_SINGLE_INACCURATE_HINT, 
	BTREETEST_MULTIMAP_PERF_INSERT_ITERATOR, 
	BTREETEST_MULTIMAP_PERF_ERASE_ITERATOR_SINGLE, 
	BTREETEST_MULTIMAP_PERF_ERASE_KEY, 
	BTREETEST_MULTIMAP_PERF_ERASE_ITERATOR_RANGE, 
} btreetest_multimap_perf_e;

void TestMultiMapPerf (uint32_t nTestNum, uint64_t nProblemSize, uint64_t nProblemBias);

#endif // BTREEMULTIMAPPERFTESTBENCH_H


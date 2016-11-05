
#ifndef	BTREEARRAYPERFTESTBENCH_H
#define	BTREEARRAYPERFTESTBENCH_H

#include <stdint.h>

#include <chrono>
#include <iostream>
#include <sstream>
#include <string>

#include <list>
#include <vector>

#include "testbench/common/btreetestcommon.h"
#include "testbench/common/btreeperftestcommon.h"

#include "testbench/application_classes/performance/btreetestarrayperf.h"

#include "btreeioram.h"

typedef enum
{
	BTREETEST_ARRAY_PERF_INSERT_SINGLE, 
	BTREETEST_ARRAY_PERF_INSERT_ARRAY_COPY, 
	BTREETEST_ARRAY_PERF_INSERT_ITERATOR, 
	BTREETEST_ARRAY_PERF_ERASE_SINGLE,
	BTREETEST_ARRAY_PERF_ERASE_ITERATOR,
	BTREETEST_ARRAY_PERF_ASSIGN_SET,
	BTREETEST_ARRAY_PERF_ASSIGN_ITERATOR, 
	BTREETEST_ARRAY_PERF_POP_BACK, 
	BTREETEST_ARRAY_PERF_PUSH_BACK, 
} btreetest_array_perf_e;

void TestArrayPerf (uint32_t nTestNum, uint64_t nProblemSize, uint32_t nProblemBias);

#endif

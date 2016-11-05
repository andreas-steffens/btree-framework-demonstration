
// #ifndef	BTREEARRAYPERFTESTBENCH_CPP
// #define	BTREEARRAYPERFTESTBENCH_CPP

#include "testbench/tests/performance/btreearrayperftestbench.h"

template<class _t_sizetype, class _t_type>
void InitTestType (_t_type &rType, _t_sizetype nProblemSizeBias)
{
	nProblemSizeBias;

	rType = _t_type(0);
}

template<class _t_container, class _t_iterator, class _t_sizetype, class _t_type>
void RunInsert (_t_container *pContainer, _t_iterator &rIter, _t_type &rType, _t_sizetype nProblemSizeBias)
{
	if (nProblemSizeBias == 1)
	{
		pContainer->insert (rIter, rType);
	}
	else
	{
		pContainer->insert (rIter, nProblemSizeBias, rType);
	}
}



template<class _t_sizetype>
void InitTestType (::std::vector<uint32_t> &rType, _t_sizetype nProblemSizeBias)
{
	rType.assign (typename ::std::vector<uint32_t>::size_type (nProblemSizeBias), typename ::std::vector<uint32_t>::value_type (0));
}

template<class _t_container, class _t_iterator, class _t_sizetype>
void RunInsert (_t_container *pContainer, _t_iterator &rIter, ::std::vector<uint32_t> &rType, _t_sizetype nProblemSizeBias)
{
	auto		sIterBegin = rType.cbegin ();
	auto		sIterEnd = rType.cend ();

	nProblemSizeBias;

	pContainer->insert (rIter, sIterBegin, sIterEnd);
}



template<class _t_container, class _t_type>
void TestArrayPerfInsertSingleRun (const char *pszTitle, _t_container *pContainer, _t_type &rType, uint32_t nOperation, uint64_t nProblemSize, typename _t_container::size_type nProblemSizeBias, CResultList_t *pClResultList)
{
	typedef typename _t_container::const_iterator	citer_t;

	uint64_t		i;
	uint64_t		nCnt = 0;
	double			dblTimeSpan;
	auto			sClkStart = ::std::chrono::high_resolution_clock::now ();
	citer_t			sCIter;

	do
	{
		pContainer->clear ();

		for (i = 0; i < nProblemSize; i++)
		{
			switch (nOperation)
			{
			case	0	:	sCIter = pContainer->cbegin ();

							break;

			case	1	:	sCIter = pContainer->cend ();

							break;
			
			case	2	:	sCIter = pContainer->cbegin ();

							auto nSize = pContainer->size ();

							if (nSize > 0)
							{
								nSize = generate_rand32 () % nSize;

								::std::advance (sCIter, nSize);
							}

							break;
			}

			RunInsert (pContainer, sCIter, rType, nProblemSizeBias);

			nCnt += nProblemSizeBias;
		}

		auto		sClkEnd = ::std::chrono::high_resolution_clock::now ();

		dblTimeSpan = convert_chrono_duration_to_seconds (sClkStart, sClkEnd);
	} while (dblTimeSpan < 1.0);

	add_perf_result (*pClResultList, dblTimeSpan, nCnt, pszTitle);
}

template<class _t_type>
void TestArrayPerfInsertSingleSelectOperation (uint32_t nOperation, uint64_t nProblemSize, uint32_t nProblemSizeBias, _t_type &rType)
{
	btree_ram_io_properties_66565_t	sRAMproperties66565;
	btree_ram_io_properties_66555_t	sRAMproperties66555;
	btree_ram_io_properties_65555_t	sRAMproperties65555;
	btree_ram_io_properties_55555_t	sRAMproperties55555;
	btree_ram_io_properties_55455_t	sRAMproperties55455;
	CResultList_t					sResultList (sRAMproperties55555, 16);
	::std::list<uint32_t>			sList32;
	::std::vector<uint32_t>			sVector32;
	CBTreeArray<uint32_t, btree_ram_io_properties_66565_t>
									sBtrArray32_66565_16 (sRAMproperties66565, 16);
	CBTreeArray<uint32_t, btree_ram_io_properties_66565_t>
									sBtrArray32_66565_256 (sRAMproperties66565, 256);
	CBTreeArray<uint32_t, btree_ram_io_properties_66565_t>
									sBtrArray32_66565_1024 (sRAMproperties66565, 1024);
	
	CBTreeArray<uint32_t, btree_ram_io_properties_66555_t>
									sBtrArray32_66555_16 (sRAMproperties66555, 16);
	CBTreeArray<uint32_t, btree_ram_io_properties_66555_t>
									sBtrArray32_66555_256 (sRAMproperties66555, 256);
	CBTreeArray<uint32_t, btree_ram_io_properties_66555_t>
									sBtrArray32_66555_1024 (sRAMproperties66555, 1024);
	
	CBTreeArray<uint32_t, btree_ram_io_properties_65555_t>
									sBtrArray32_65555_16 (sRAMproperties65555, 16);
	CBTreeArray<uint32_t, btree_ram_io_properties_65555_t>
									sBtrArray32_65555_256 (sRAMproperties65555, 256);
	CBTreeArray<uint32_t, btree_ram_io_properties_65555_t>
									sBtrArray32_65555_1024 (sRAMproperties65555, 1024);
	
	CBTreeArray<uint32_t, btree_ram_io_properties_55555_t>
									sBtrArray32_55555_16 (sRAMproperties55555, 16);
	CBTreeArray<uint32_t, btree_ram_io_properties_55555_t>
									sBtrArray32_55555_256 (sRAMproperties55555, 256);
	CBTreeArray<uint32_t, btree_ram_io_properties_55555_t>
									sBtrArray32_55555_1024 (sRAMproperties55555, 1024);
	
	CBTreeArray<uint32_t, btree_ram_io_properties_55455_t>
									sBtrArray32_55455_16 (sRAMproperties55455, 16);
	CBTreeArray<uint32_t, btree_ram_io_properties_55455_t>
									sBtrArray32_55455_256 (sRAMproperties55455, 256);
	CBTreeArray<uint32_t, btree_ram_io_properties_55455_t>
									sBtrArray32_55455_1024 (sRAMproperties55455, 1024);
	
	InitTestType (rType, nProblemSizeBias);

	// type: uint32_t, uint64_t, uint64_t[2], etc...
	// insertion: front, back, random
	// problem size: 100, 10000, 1000000, ...
	// node size: 16, 256, 1024, ...
	// size type: 32, 64
	// node size type: 32, 64
	// sub-node size type: 16, 32
	
	sResultList.clear ();

	TestArrayPerfInsertSingleRun ("::std::list<uint32_t>", &sList32, rType, nOperation, nProblemSize, nProblemSizeBias, &sResultList);
	TestArrayPerfInsertSingleRun ("::std::vector<uint32_t>", &sVector32, rType, nOperation, nProblemSize, nProblemSizeBias, &sResultList);
	TestArrayPerfInsertSingleRun ("CBTreeArray<uint32_t, 64, 64, 32, 64, 32> (16)", &sBtrArray32_66565_16, rType, nOperation, nProblemSize, nProblemSizeBias, &sResultList);
	TestArrayPerfInsertSingleRun ("CBTreeArray<uint32_t, 64, 64, 32, 64, 32> (256)", &sBtrArray32_66565_256, rType, nOperation, nProblemSize, nProblemSizeBias, &sResultList);
	TestArrayPerfInsertSingleRun ("CBTreeArray<uint32_t, 64, 64, 32, 64, 32> (1024)", &sBtrArray32_66565_1024, rType, nOperation, nProblemSize, nProblemSizeBias, &sResultList);
	TestArrayPerfInsertSingleRun ("CBTreeArray<uint32_t, 64, 64, 32, 32, 32> (16)", &sBtrArray32_66555_16, rType, nOperation, nProblemSize, nProblemSizeBias, &sResultList);
	TestArrayPerfInsertSingleRun ("CBTreeArray<uint32_t, 64, 64, 32, 32, 32> (256)", &sBtrArray32_66555_256, rType, nOperation, nProblemSize, nProblemSizeBias, &sResultList);
	TestArrayPerfInsertSingleRun ("CBTreeArray<uint32_t, 64, 64, 32, 32, 32> (1024)", &sBtrArray32_66555_1024, rType, nOperation, nProblemSize, nProblemSizeBias, &sResultList);
	TestArrayPerfInsertSingleRun ("CBTreeArray<uint32_t, 64, 32, 32, 32, 32> (16)", &sBtrArray32_65555_16, rType, nOperation, nProblemSize, nProblemSizeBias, &sResultList);
	TestArrayPerfInsertSingleRun ("CBTreeArray<uint32_t, 64, 32, 32, 32, 32> (256)", &sBtrArray32_65555_256, rType, nOperation, nProblemSize, nProblemSizeBias, &sResultList);
	TestArrayPerfInsertSingleRun ("CBTreeArray<uint32_t, 64, 32, 32, 32, 32> (1024)", &sBtrArray32_65555_1024, rType, nOperation, nProblemSize, nProblemSizeBias, &sResultList);
	TestArrayPerfInsertSingleRun ("CBTreeArray<uint32_t, 32, 32, 32, 32, 32> (16)", &sBtrArray32_55555_16, rType, nOperation, nProblemSize, nProblemSizeBias, &sResultList);
	TestArrayPerfInsertSingleRun ("CBTreeArray<uint32_t, 32, 32, 32, 32, 32> (256)", &sBtrArray32_55555_256, rType, nOperation, nProblemSize, nProblemSizeBias, &sResultList);
	TestArrayPerfInsertSingleRun ("CBTreeArray<uint32_t, 32, 32, 32, 32, 32> (1024)", &sBtrArray32_55555_1024, rType, nOperation, nProblemSize, nProblemSizeBias, &sResultList);
	TestArrayPerfInsertSingleRun ("CBTreeArray<uint32_t, 32, 32, 16, 32, 32> (16)", &sBtrArray32_55455_16, rType, nOperation, nProblemSize, nProblemSizeBias, &sResultList);
	TestArrayPerfInsertSingleRun ("CBTreeArray<uint32_t, 32, 32, 16, 32, 32> (256)", &sBtrArray32_55455_256, rType, nOperation, nProblemSize, nProblemSizeBias, &sResultList);
	TestArrayPerfInsertSingleRun ("CBTreeArray<uint32_t, 32, 32, 16, 32, 32> (1024)", &sBtrArray32_55455_1024, rType, nOperation, nProblemSize, nProblemSizeBias, &sResultList);

	switch (nOperation)
	{
	case	0	:	::std::cout << "front insert operation";	break;
	case	1	:	::std::cout << "back insert operation";		break;
	case	2	:	::std::cout << "random insert operation";	break;
	}

	::std::cout << ::std::endl;

	output_perf_results (sResultList, nProblemSize, nProblemSizeBias);
}

void TestArrayPerfInsertSingle (uint64_t nProblemSize, uint32_t nProblemBias)
{
	uint32_t	sSelectedTypeui32;

	TestArrayPerfInsertSingleSelectOperation (2, nProblemSize, nProblemBias, sSelectedTypeui32);
	TestArrayPerfInsertSingleSelectOperation (0, nProblemSize, nProblemBias, sSelectedTypeui32);
	TestArrayPerfInsertSingleSelectOperation (1, nProblemSize, nProblemBias, sSelectedTypeui32);
}

void TestArrayPerfInsertArrayCopy (uint64_t nProblemSize, uint32_t nProblemBias)
{
	uint32_t	sSelectedTypeui32;

	TestArrayPerfInsertSingleSelectOperation (2, nProblemSize, nProblemBias, sSelectedTypeui32);
	TestArrayPerfInsertSingleSelectOperation (0, nProblemSize, nProblemBias, sSelectedTypeui32);
	TestArrayPerfInsertSingleSelectOperation (1, nProblemSize, nProblemBias, sSelectedTypeui32);
}

void TestArrayPerfInsertIterator (uint64_t nProblemSize, uint32_t nProblemBias)
{
	::std::vector<uint32_t>		sSelectedTypeVector_ui32;

	TestArrayPerfInsertSingleSelectOperation (2, nProblemSize, nProblemBias, sSelectedTypeVector_ui32);
	TestArrayPerfInsertSingleSelectOperation (0, nProblemSize, nProblemBias, sSelectedTypeVector_ui32);
	TestArrayPerfInsertSingleSelectOperation (1, nProblemSize, nProblemBias, sSelectedTypeVector_ui32);
}

void TestArrayPerf (uint32_t nTestNum, uint64_t nProblemSize, uint32_t nProblemBias)
{
	::std::cout << "array performance test bench" << ::std::endl;
	::std::cout << ::std::fixed << ::std::setprecision (2);

	switch (nTestNum)
	{
	case BTREETEST_ARRAY_PERF_INSERT_SINGLE		:

		TestArrayPerfInsertSingle (nProblemSize, nProblemBias);

		break;

	case BTREETEST_ARRAY_PERF_INSERT_ARRAY_COPY	:

		TestArrayPerfInsertArrayCopy (nProblemSize, nProblemBias);

		break;

	case BTREETEST_ARRAY_PERF_INSERT_ITERATOR	:

		TestArrayPerfInsertIterator (nProblemSize, nProblemBias);

		break;

	case BTREETEST_ARRAY_PERF_ERASE_SINGLE		:

		break;

	case BTREETEST_ARRAY_PERF_ERASE_ITERATOR	:

		break;

	case BTREETEST_ARRAY_PERF_ASSIGN_SET		:

		break;

	case BTREETEST_ARRAY_PERF_ASSIGN_ITERATOR	:

		break;

	case BTREETEST_ARRAY_PERF_POP_BACK			:

		break;

	case BTREETEST_ARRAY_PERF_PUSH_BACK			:

		break;

	default										:

		::std::cerr << "ERROR: TestArrayPerf: Unknown array performance test selected!" << ::std::endl;

		exit (-1);

		break;
	}
}

// #endif


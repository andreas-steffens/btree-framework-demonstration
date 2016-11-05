#include "testbench/tests/performance/btreemultimapperftestbench.h"

template<class _t_container>
void TestMultiMapPerfInsertSingleRun (const char *pszTitle, _t_container *pContainer, uint64_t nProblemSize, CResultList_t *pClResultList)
{
	typedef typename _t_container::value_type	value_type;

	uint64_t		i;
	uint64_t		nCnt = 0;
	double			dblTimeSpan;
	auto			sClkStart = ::std::chrono::high_resolution_clock::now ();

	do
	{
		pContainer->clear ();

		for (i = 0; i < nProblemSize; i++)
		{
			value_type		sValue (generate_rand32 (), generate_rand32 ());

			pContainer->insert (sValue);

			nCnt++;
		}

		auto		sClkEnd = ::std::chrono::high_resolution_clock::now ();

		dblTimeSpan = convert_chrono_duration_to_seconds (sClkStart, sClkEnd);
	} while (dblTimeSpan < 1.0);

	add_perf_result (*pClResultList, dblTimeSpan, nCnt, pszTitle);

	pContainer->clear ();
}

void TestMultiMapPerfInsertSingle (uint64_t nProblemSize, uint64_t nProblemBias)
{
	nProblemBias;

	btree_ram_io_properties_66565_t	sRAMproperties66565;
	btree_ram_io_properties_66555_t	sRAMproperties66555;
	btree_ram_io_properties_65555_t	sRAMproperties65555;
	btree_ram_io_properties_55555_t	sRAMproperties55555;
	btree_ram_io_properties_55455_t	sRAMproperties55455;
	CResultList_t					sResultList (sRAMproperties55555, 16);

	::std::multimap<uint32_t, uint32_t>
									sMultiMap;

	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_16 (sRAMproperties66565, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_128 (sRAMproperties66565, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_256 (sRAMproperties66565, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_512 (sRAMproperties66565, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_1024 (sRAMproperties66565, 1024);
	
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_16 (sRAMproperties66555, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_128 (sRAMproperties66555, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_256 (sRAMproperties66555, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_512 (sRAMproperties66555, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_1024 (sRAMproperties66555, 1024);
	
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_16 (sRAMproperties65555, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_128 (sRAMproperties65555, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_256 (sRAMproperties65555, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_512 (sRAMproperties65555, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_1024 (sRAMproperties65555, 1024);
	
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_16 (sRAMproperties55555, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_128 (sRAMproperties55555, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_256 (sRAMproperties55555, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_512 (sRAMproperties55555, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_1024 (sRAMproperties55555, 1024);
	
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_16 (sRAMproperties55455, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_128 (sRAMproperties55455, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_256 (sRAMproperties55455, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_512 (sRAMproperties55455, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_1024 (sRAMproperties55455, 1024);

	TestMultiMapPerfInsertSingleRun ("::std::multimap<uint32_t, uint32_t>", &sMultiMap, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (16)", &sBtrMMap3232_66565_16, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (128)", &sBtrMMap3232_66565_128, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (256)", &sBtrMMap3232_66565_256, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (512)", &sBtrMMap3232_66565_512, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (1024)", &sBtrMMap3232_66565_1024, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (16)", &sBtrMMap3232_66555_16, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (128)", &sBtrMMap3232_66555_128, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (256)", &sBtrMMap3232_66555_256, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (512)", &sBtrMMap3232_66555_512, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (1024)", &sBtrMMap3232_66555_1024, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (16)", &sBtrMMap3232_65555_16, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (128)", &sBtrMMap3232_65555_128, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (256)", &sBtrMMap3232_65555_256, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (512)", &sBtrMMap3232_65555_512, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (1024)", &sBtrMMap3232_65555_1024, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (16)", &sBtrMMap3232_55555_16, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (128)", &sBtrMMap3232_55555_128, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (256)", &sBtrMMap3232_55555_256, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (512)", &sBtrMMap3232_55555_512, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (1024)", &sBtrMMap3232_55555_1024, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (16)", &sBtrMMap3232_55455_16, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (128)", &sBtrMMap3232_55455_128, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (256)", &sBtrMMap3232_55455_256, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (512)", &sBtrMMap3232_55455_512, nProblemSize, &sResultList);
	TestMultiMapPerfInsertSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (1024)", &sBtrMMap3232_55455_1024, nProblemSize, &sResultList);

	output_perf_results (sResultList, nProblemSize, 1);
}

template<class _t_container, class _t_feeder_container>
void TestMultiMapPerfInsertIteratorRun (const char *pszTitle, _t_container *pContainer, _t_feeder_container *pFeeder, uint64_t nProblemSize, CResultList_t *pClResultList)
{
	typedef typename _t_container::value_type	value_type;

	uint64_t		nCnt = 0;
	double			dblTimeSpan;
	auto			sClkStart = ::std::chrono::high_resolution_clock::now ();

	do
	{
		pContainer->clear ();

		auto		sCIterFeederBegin = pFeeder->cbegin ();
		auto		sCIterFeederEnd = pFeeder->cend ();

		pContainer->insert (sCIterFeederBegin, sCIterFeederEnd);

		nCnt += nProblemSize;

		auto		sClkEnd = ::std::chrono::high_resolution_clock::now ();

		dblTimeSpan = convert_chrono_duration_to_seconds (sClkStart, sClkEnd);
	} while (dblTimeSpan < 1.0);

	add_perf_result (*pClResultList, dblTimeSpan, nCnt, pszTitle);

	pContainer->clear ();
}

void TestMultiMapPerfInsertIterator (uint64_t nProblemSize, uint64_t nProblemBias)
{
	nProblemBias;

	btree_ram_io_properties_66565_t	sRAMproperties66565;
	btree_ram_io_properties_66555_t	sRAMproperties66555;
	btree_ram_io_properties_65555_t	sRAMproperties65555;
	btree_ram_io_properties_55555_t	sRAMproperties55555;
	btree_ram_io_properties_55455_t	sRAMproperties55455;
	CResultList_t					sResultList (sRAMproperties55555, 16);

	::std::multimap<uint32_t, uint32_t>
									sMultiMap;

	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_16 (sRAMproperties66565, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_128 (sRAMproperties66565, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_256 (sRAMproperties66565, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_512 (sRAMproperties66565, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_1024 (sRAMproperties66565, 1024);
	
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_16 (sRAMproperties66555, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_128 (sRAMproperties66555, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_256 (sRAMproperties66555, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_512 (sRAMproperties66555, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_1024 (sRAMproperties66555, 1024);
	
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_16 (sRAMproperties65555, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_128 (sRAMproperties65555, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_256 (sRAMproperties65555, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_512 (sRAMproperties65555, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_1024 (sRAMproperties65555, 1024);
	
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_16 (sRAMproperties55555, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_128 (sRAMproperties55555, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_256 (sRAMproperties55555, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_512 (sRAMproperties55555, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_1024 (sRAMproperties55555, 1024);
	
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_16 (sRAMproperties55455, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_128 (sRAMproperties55455, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_256 (sRAMproperties55455, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_512 (sRAMproperties55455, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_1024 (sRAMproperties55455, 1024);

	::std::vector<typename ::std::multimap<uint32_t, uint32_t>::value_type>		sFeederVector;

	uint64_t			i;

	for (i = 0; i < nProblemSize; i++)
	{
		::std::multimap<uint32_t, uint32_t>::value_type		sValue (generate_rand32 (), generate_rand32 ());

		sFeederVector.push_back (sValue);
	}

	TestMultiMapPerfInsertIteratorRun ("::std::multimap<uint32_t, uint32_t>", &sMultiMap, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (16)", &sBtrMMap3232_66565_16, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (128)", &sBtrMMap3232_66565_128, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (256)", &sBtrMMap3232_66565_256, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (512)", &sBtrMMap3232_66565_512, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (1024)", &sBtrMMap3232_66565_1024, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (16)", &sBtrMMap3232_66555_16, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (128)", &sBtrMMap3232_66555_128, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (256)", &sBtrMMap3232_66555_256, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (512)", &sBtrMMap3232_66555_512, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (1024)", &sBtrMMap3232_66555_1024, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (16)", &sBtrMMap3232_65555_16, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (128)", &sBtrMMap3232_65555_128, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (256)", &sBtrMMap3232_65555_256, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (512)", &sBtrMMap3232_65555_512, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (1024)", &sBtrMMap3232_65555_1024, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (16)", &sBtrMMap3232_55555_16, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (128)", &sBtrMMap3232_55555_128, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (256)", &sBtrMMap3232_55555_256, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (512)", &sBtrMMap3232_55555_512, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (1024)", &sBtrMMap3232_55555_1024, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (16)", &sBtrMMap3232_55455_16, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (128)", &sBtrMMap3232_55455_128, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (256)", &sBtrMMap3232_55455_256, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (512)", &sBtrMMap3232_55455_512, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfInsertIteratorRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (1024)", &sBtrMMap3232_55455_1024, &sFeederVector, nProblemSize, &sResultList);

	output_perf_results (sResultList, nProblemSize, 1);
}

template<class _t_container, class _t_feeder_container>
void TestMultiMapPerfEraseIteratorSingleRun (const char *pszTitle, _t_container *pContainer, _t_feeder_container *pFeeder, uint64_t nProblemSize, CResultList_t *pClResultList)
{
	typedef typename _t_container::value_type	value_type;

	uint64_t		nCnt = 0;
	double			dblTimeSpan = 0.0;

	do
	{
		pContainer->clear ();

		auto		sCIterFeederBegin = pFeeder->cbegin ();
		auto		sCIterFeederEnd = pFeeder->cend ();

		pContainer->insert (sCIterFeederBegin, sCIterFeederEnd);

		nCnt += nProblemSize;

		auto		sClkStart = ::std::chrono::high_resolution_clock::now ();

		while (pContainer->size () > 0)
		{
			typename _t_container::size_type	nPos = generate_rand32 ();
			auto								sCIter = pContainer->cbegin ();

			nPos = nPos % pContainer->size ();

			::std::advance (sCIter, nPos);

			pContainer->erase (sCIter);
		}

		auto		sClkEnd = ::std::chrono::high_resolution_clock::now ();

		dblTimeSpan += convert_chrono_duration_to_seconds (sClkStart, sClkEnd);
	} while (dblTimeSpan < 1.0);

	add_perf_result (*pClResultList, dblTimeSpan, nCnt, pszTitle);

	pContainer->clear ();
}

void TestMultiMapPerfEraseIteratorSingle (uint64_t nProblemSize, uint64_t nProblemBias)
{
	nProblemBias;

	btree_ram_io_properties_66565_t	sRAMproperties66565;
	btree_ram_io_properties_66555_t	sRAMproperties66555;
	btree_ram_io_properties_65555_t	sRAMproperties65555;
	btree_ram_io_properties_55555_t	sRAMproperties55555;
	btree_ram_io_properties_55455_t	sRAMproperties55455;
	CResultList_t					sResultList (sRAMproperties55555, 16);

	::std::multimap<uint32_t, uint32_t>
									sMultiMap;

	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_16 (sRAMproperties66565, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_128 (sRAMproperties66565, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_256 (sRAMproperties66565, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_512 (sRAMproperties66565, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_1024 (sRAMproperties66565, 1024);
	
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_16 (sRAMproperties66555, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_128 (sRAMproperties66555, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_256 (sRAMproperties66555, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_512 (sRAMproperties66555, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_1024 (sRAMproperties66555, 1024);
	
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_16 (sRAMproperties65555, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_128 (sRAMproperties65555, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_256 (sRAMproperties65555, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_512 (sRAMproperties65555, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_1024 (sRAMproperties65555, 1024);
	
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_16 (sRAMproperties55555, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_128 (sRAMproperties55555, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_256 (sRAMproperties55555, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_512 (sRAMproperties55555, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_1024 (sRAMproperties55555, 1024);
	
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_16 (sRAMproperties55455, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_128 (sRAMproperties55455, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_256 (sRAMproperties55455, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_512 (sRAMproperties55455, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_1024 (sRAMproperties55455, 1024);

	::std::vector<typename ::std::multimap<uint32_t, uint32_t>::value_type>		sFeederVector;

	uint64_t			i;

	for (i = 0; i < nProblemSize; i++)
	{
		::std::multimap<uint32_t, uint32_t>::value_type	sValue (generate_rand32 (), generate_rand32 ());

		sFeederVector.push_back (sValue);
	}

	TestMultiMapPerfEraseIteratorSingleRun ("::std::multimap<uint32_t, uint32_t>", &sMultiMap, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (16)", &sBtrMMap3232_66565_16, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (128)", &sBtrMMap3232_66565_128, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (256)", &sBtrMMap3232_66565_256, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (512)", &sBtrMMap3232_66565_512, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (1024)", &sBtrMMap3232_66565_1024, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (16)", &sBtrMMap3232_66555_16, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (128)", &sBtrMMap3232_66555_128, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (256)", &sBtrMMap3232_66555_256, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (512)", &sBtrMMap3232_66555_512, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (1024)", &sBtrMMap3232_66555_1024, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (16)", &sBtrMMap3232_65555_16, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (128)", &sBtrMMap3232_65555_128, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (256)", &sBtrMMap3232_65555_256, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (512)", &sBtrMMap3232_65555_512, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (1024)", &sBtrMMap3232_65555_1024, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (16)", &sBtrMMap3232_55555_16, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (128)", &sBtrMMap3232_55555_128, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (256)", &sBtrMMap3232_55555_256, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (512)", &sBtrMMap3232_55555_512, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (1024)", &sBtrMMap3232_55555_1024, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (16)", &sBtrMMap3232_55455_16, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (128)", &sBtrMMap3232_55455_128, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (256)", &sBtrMMap3232_55455_256, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (512)", &sBtrMMap3232_55455_512, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorSingleRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (1024)", &sBtrMMap3232_55455_1024, &sFeederVector, nProblemSize, &sResultList);

	output_perf_results (sResultList, nProblemSize, 1);
}

template<class _t_container, class _t_feeder_container>
void TestMultiMapPerfEraseKeyRun (const char *pszTitle, _t_container *pContainer, _t_feeder_container *pFeeder, uint64_t nProblemSize, CResultList_t *pClResultList)
{
	typedef typename _t_container::value_type	value_type;

	uint64_t		nCnt = 0;
	double			dblTimeSpan = 0.0;

	do
	{
		pContainer->clear ();

		auto		sCIterFeederBegin = pFeeder->cbegin ();
		auto		sCIterFeederEnd = pFeeder->cend ();

		pContainer->insert (sCIterFeederBegin, sCIterFeederEnd);

		nCnt += nProblemSize;

		auto		sClkStart = ::std::chrono::high_resolution_clock::now ();

		while (sCIterFeederBegin != sCIterFeederEnd)
		{
			uint32_t		nKey = (*sCIterFeederBegin).first;

			pContainer->erase (nKey);

			::std::advance (sCIterFeederBegin, 1);
		}

		auto		sClkEnd = ::std::chrono::high_resolution_clock::now ();

		dblTimeSpan += convert_chrono_duration_to_seconds (sClkStart, sClkEnd);
	} while (dblTimeSpan < 1.0);

	add_perf_result (*pClResultList, dblTimeSpan, nCnt, pszTitle);

	pContainer->clear ();
}

void TestMultiMapPerfEraseKey (uint64_t nProblemSize, uint64_t nProblemBias)
{
	nProblemBias;

	btree_ram_io_properties_66565_t	sRAMproperties66565;
	btree_ram_io_properties_66555_t	sRAMproperties66555;
	btree_ram_io_properties_65555_t	sRAMproperties65555;
	btree_ram_io_properties_55555_t	sRAMproperties55555;
	btree_ram_io_properties_55455_t	sRAMproperties55455;
	CResultList_t					sResultList (sRAMproperties55555, 16);

	::std::multimap<uint32_t, uint32_t>
									sMultiMap;

	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_16 (sRAMproperties66565, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_128 (sRAMproperties66565, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_256 (sRAMproperties66565, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_512 (sRAMproperties66565, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_1024 (sRAMproperties66565, 1024);
	
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_16 (sRAMproperties66555, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_128 (sRAMproperties66555, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_256 (sRAMproperties66555, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_512 (sRAMproperties66555, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_1024 (sRAMproperties66555, 1024);
	
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_16 (sRAMproperties65555, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_128 (sRAMproperties65555, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_256 (sRAMproperties65555, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_512 (sRAMproperties65555, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_1024 (sRAMproperties65555, 1024);
	
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_16 (sRAMproperties55555, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_128 (sRAMproperties55555, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_256 (sRAMproperties55555, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_512 (sRAMproperties55555, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_1024 (sRAMproperties55555, 1024);
	
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_16 (sRAMproperties55455, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_128 (sRAMproperties55455, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_256 (sRAMproperties55455, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_512 (sRAMproperties55455, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_1024 (sRAMproperties55455, 1024);

	::std::vector<typename ::std::multimap<uint32_t, uint32_t>::value_type>		sFeederVector;

	uint64_t			i;

	for (i = 0; i < nProblemSize; i++)
	{
		::std::multimap<uint32_t, uint32_t>::value_type	sValue (generate_rand32 (), generate_rand32 ());

		sFeederVector.push_back (sValue);
	}

	TestMultiMapPerfEraseKeyRun ("::std::multimap<uint32_t, uint32_t>", &sMultiMap, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (16)", &sBtrMMap3232_66565_16, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (128)", &sBtrMMap3232_66565_128, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (256)", &sBtrMMap3232_66565_256, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (512)", &sBtrMMap3232_66565_512, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (1024)", &sBtrMMap3232_66565_1024, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (16)", &sBtrMMap3232_66555_16, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (128)", &sBtrMMap3232_66555_128, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (256)", &sBtrMMap3232_66555_256, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (512)", &sBtrMMap3232_66555_512, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (1024)", &sBtrMMap3232_66555_1024, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (16)", &sBtrMMap3232_65555_16, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (128)", &sBtrMMap3232_65555_128, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (256)", &sBtrMMap3232_65555_256, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (512)", &sBtrMMap3232_65555_512, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (1024)", &sBtrMMap3232_65555_1024, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (16)", &sBtrMMap3232_55555_16, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (128)", &sBtrMMap3232_55555_128, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (256)", &sBtrMMap3232_55555_256, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (512)", &sBtrMMap3232_55555_512, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (1024)", &sBtrMMap3232_55555_1024, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (16)", &sBtrMMap3232_55455_16, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (128)", &sBtrMMap3232_55455_128, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (256)", &sBtrMMap3232_55455_256, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (512)", &sBtrMMap3232_55455_512, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseKeyRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (1024)", &sBtrMMap3232_55455_1024, &sFeederVector, nProblemSize, &sResultList);

	output_perf_results (sResultList, nProblemSize, 1);
}

template<class _t_container, class _t_feeder_container>
void TestMultiMapPerfEraseIteratorRangeRun (const char *pszTitle, _t_container *pContainer, _t_feeder_container *pFeeder, uint64_t nProblemSize, CResultList_t *pClResultList)
{
	typedef typename _t_container::value_type	value_type;

	uint64_t		nCnt = 0;
	double			dblTimeSpan = 0.0;

	do
	{
		pContainer->clear ();

		auto		sCIterFeederBegin = pFeeder->cbegin ();
		auto		sCIterFeederEnd = pFeeder->cend ();

		pContainer->insert (sCIterFeederBegin, sCIterFeederEnd);

		nCnt += nProblemSize;

		auto		sCIterBegin = pContainer->cbegin ();
		auto		sCIterEnd = pContainer->cend ();

		auto		sClkStart = ::std::chrono::high_resolution_clock::now ();

		pContainer->erase (sCIterBegin, sCIterEnd);

		auto		sClkEnd = ::std::chrono::high_resolution_clock::now ();

		dblTimeSpan += convert_chrono_duration_to_seconds (sClkStart, sClkEnd);
	} while (dblTimeSpan < 1.0);

	add_perf_result (*pClResultList, dblTimeSpan, nCnt, pszTitle);

	pContainer->clear ();
}

void TestMultiMapPerfEraseIteratorRange (uint64_t nProblemSize, uint64_t nProblemBias)
{
	nProblemBias;

	btree_ram_io_properties_66565_t	sRAMproperties66565;
	btree_ram_io_properties_66555_t	sRAMproperties66555;
	btree_ram_io_properties_65555_t	sRAMproperties65555;
	btree_ram_io_properties_55555_t	sRAMproperties55555;
	btree_ram_io_properties_55455_t	sRAMproperties55455;
	CResultList_t					sResultList (sRAMproperties55555, 16);

	::std::multimap<uint32_t, uint32_t>
									sMultiMap;

	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_16 (sRAMproperties66565, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_128 (sRAMproperties66565, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_256 (sRAMproperties66565, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_512 (sRAMproperties66565, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66565_t>
									sBtrMMap3232_66565_1024 (sRAMproperties66565, 1024);
	
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_16 (sRAMproperties66555, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_128 (sRAMproperties66555, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_256 (sRAMproperties66555, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_512 (sRAMproperties66555, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_66555_t>
									sBtrMMap3232_66555_1024 (sRAMproperties66555, 1024);
	
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_16 (sRAMproperties65555, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_128 (sRAMproperties65555, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_256 (sRAMproperties65555, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_512 (sRAMproperties65555, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_65555_t>
									sBtrMMap3232_65555_1024 (sRAMproperties65555, 1024);
	
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_16 (sRAMproperties55555, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_128 (sRAMproperties55555, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_256 (sRAMproperties55555, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_512 (sRAMproperties55555, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55555_t>
									sBtrMMap3232_55555_1024 (sRAMproperties55555, 1024);
	
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_16 (sRAMproperties55455, 16);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_128 (sRAMproperties55455, 128);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_256 (sRAMproperties55455, 256);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_512 (sRAMproperties55455, 512);
	CBTreeMultiMap<uint32_t, uint32_t, btree_ram_io_properties_55455_t>
									sBtrMMap3232_55455_1024 (sRAMproperties55455, 1024);

	::std::vector<typename ::std::multimap<uint32_t, uint32_t>::value_type>		sFeederVector;

	uint64_t			i;

	for (i = 0; i < nProblemSize; i++)
	{
		::std::multimap<uint32_t, uint32_t>::value_type	sValue (generate_rand32 (), generate_rand32 ());

		sFeederVector.push_back (sValue);
	}

	TestMultiMapPerfEraseIteratorRangeRun ("::std::multimap<uint32_t, uint32_t>", &sMultiMap, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (16)", &sBtrMMap3232_66565_16, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (128)", &sBtrMMap3232_66565_128, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (256)", &sBtrMMap3232_66565_256, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (512)", &sBtrMMap3232_66565_512, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 64, 32> (1024)", &sBtrMMap3232_66565_1024, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (16)", &sBtrMMap3232_66555_16, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (128)", &sBtrMMap3232_66555_128, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (256)", &sBtrMMap3232_66555_256, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (512)", &sBtrMMap3232_66555_512, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 64, 32, 32, 32> (1024)", &sBtrMMap3232_66555_1024, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (16)", &sBtrMMap3232_65555_16, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (128)", &sBtrMMap3232_65555_128, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (256)", &sBtrMMap3232_65555_256, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (512)", &sBtrMMap3232_65555_512, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 64, 32, 32, 32, 32> (1024)", &sBtrMMap3232_65555_1024, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (16)", &sBtrMMap3232_55555_16, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (128)", &sBtrMMap3232_55555_128, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (256)", &sBtrMMap3232_55555_256, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (512)", &sBtrMMap3232_55555_512, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 32, 32, 32> (1024)", &sBtrMMap3232_55555_1024, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (16)", &sBtrMMap3232_55455_16, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (128)", &sBtrMMap3232_55455_128, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (256)", &sBtrMMap3232_55455_256, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (512)", &sBtrMMap3232_55455_512, &sFeederVector, nProblemSize, &sResultList);
	TestMultiMapPerfEraseIteratorRangeRun ("CBTreeMultiMap<uint32_t, uint32_t, 32, 32, 16, 32, 32> (1024)", &sBtrMMap3232_55455_1024, &sFeederVector, nProblemSize, &sResultList);

	output_perf_results (sResultList, nProblemSize, 1);
}

void TestMultiMapPerf (uint32_t nTestNum, uint64_t nProblemSize, uint64_t nProblemBias)
{
	::std::cout << "multimap performance test bench" << ::std::endl;
	::std::cout << "problem size: " << nProblemSize << ::std::endl;
	::std::cout << ::std::fixed << ::std::setprecision (2);
	
	switch (nTestNum)
	{
	case BTREETEST_MULTIMAP_PERF_INSERT_SINGLE	:
		{
			TestMultiMapPerfInsertSingle (nProblemSize, nProblemBias);

			break;
		}

	case BTREETEST_MULTIMAP_PERF_INSERT_SINGLE_ACCURATE_HINT	:
		{

			break;
		}

	case BTREETEST_MULTIMAP_PERF_INSERT_SINGLE_INACCURATE_HINT	:
		{

			break;
		}

	case BTREETEST_MULTIMAP_PERF_INSERT_ITERATOR	:	
		{
			TestMultiMapPerfInsertIterator (nProblemSize, nProblemBias);

			break;
		}

	case BTREETEST_MULTIMAP_PERF_ERASE_ITERATOR_SINGLE	:
		{
			TestMultiMapPerfEraseIteratorSingle (nProblemSize, nProblemBias);

			break;
		}

	case BTREETEST_MULTIMAP_PERF_ERASE_KEY	:
		{
			TestMultiMapPerfEraseKey (nProblemSize, nProblemBias);

			break;
		}

	case BTREETEST_MULTIMAP_PERF_ERASE_ITERATOR_RANGE	:
		{
			TestMultiMapPerfEraseIteratorRange (nProblemSize, nProblemBias);

			break;
		}

	default		:
		{
			::std::cerr << "TestMultiMapPerf: ERROR: Unknown multimap performance test selected!" << ::std::endl;

			break;
		}
	}
}


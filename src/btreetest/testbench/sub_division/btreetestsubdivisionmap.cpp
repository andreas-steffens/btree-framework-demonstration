#include "btreetestsubdivisionmap.h"

void TestBTreeMapSubDivision (uint32_t nTestNum, uint32_t nNodeSize, uint32_t nPageSize, size_type_e eSizeType)
{
	CBTreeMapTestWrapper<mapPair_t, ::std::pair<uint32_t, mapMap_t>, uint32_t, map_reference_t>	*pMapWrapper32 = NULL;
	CBTreeMapTestWrapper<mapPair_t, ::std::pair<uint32_t, mapMap_t>, uint64_t, map_reference_t>	*pMapWrapper64 = NULL;

	switch (eSizeType)
	{
	case SIZE_TYPE_32	:	TestBTreeSTLmap (nTestNum, nNodeSize, nPageSize, pMapWrapper32);

							break;

	case SIZE_TYPE_64	:	TestBTreeSTLmap (nTestNum, nNodeSize, nPageSize, pMapWrapper64);

							break;

	default				:	::std::cerr << "ERROR: size type not specified or not supported!" << ::std::endl;

							exit (-1);

							break;
	}
}


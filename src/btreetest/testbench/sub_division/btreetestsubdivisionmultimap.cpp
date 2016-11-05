#include "btreetestsubdivisionmultimap.h"

void TestBTreeMultiMapSubDivision (uint32_t nTestNum, uint32_t nNodeSize, uint32_t nPageSize, size_type_e eSizeType)
{
	CBTreeMultiMapTestWrapper<multiMapPair_t, ::std::pair<uint32_t, multiMapMap_t>, uint32_t, multimap_reference_t>	*pMultiMapWrapper32 = NULL;
	CBTreeMultiMapTestWrapper<multiMapPair_t, ::std::pair<uint32_t, multiMapMap_t>, uint64_t, multimap_reference_t>	*pMultiMapWrapper64 = NULL;

	switch (eSizeType)
	{
	case SIZE_TYPE_32	:	TestBTreeSTLmultiMap (nTestNum, nNodeSize, nPageSize, pMultiMapWrapper32);

							break;

	case SIZE_TYPE_64	:	TestBTreeSTLmultiMap (nTestNum, nNodeSize, nPageSize, pMultiMapWrapper64);

							break;

	default				:	::std::cerr << "ERROR: size type not specified or not supported!" << ::std::endl;

							exit (-1);

							break;
	}
}


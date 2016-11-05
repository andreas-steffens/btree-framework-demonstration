#include "btreetestsubdivisionmultiset.h"

void TestBTreeMultiSetSubDivision (uint32_t nTestNum, uint32_t nNodeSize, uint32_t nPageSize, size_type_e eSizeType)
{
	CBTreeMultiSetTestWrapper<uint32_t, uint32_t, uint32_t, multiset_reference_t>	*pMultiSetWrapper32 = NULL;
	CBTreeMultiSetTestWrapper<uint32_t, uint32_t, uint64_t, multiset_reference_t>	*pMultiSetWrapper64 = NULL;

	switch (eSizeType)
	{
	case SIZE_TYPE_32	:	TestBTreeSTLmultiSet (nTestNum, nNodeSize, nPageSize, pMultiSetWrapper32);

							break;

	case SIZE_TYPE_64	:	TestBTreeSTLmultiSet (nTestNum, nNodeSize, nPageSize, pMultiSetWrapper64);

							break;

	default				:	::std::cerr << "ERROR: size type not specified or not supported!" << ::std::endl;

							exit (-1);

							break;
	}
}


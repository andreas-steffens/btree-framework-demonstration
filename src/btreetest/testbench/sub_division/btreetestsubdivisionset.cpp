#include "btreetestsubdivisionset.h"

void TestBTreeSetSubDivision (uint32_t nTestNum, uint32_t nNodeSize, uint32_t nPageSize, size_type_e eSizeType)
{
	CBTreeSetTestWrapper<uint32_t, uint32_t, uint32_t, set_reference_t>				*pSetWrapper32 = NULL;
	CBTreeSetTestWrapper<uint32_t, uint32_t, uint64_t, set_reference_t>				*pSetWrapper64 = NULL;

	switch (eSizeType)
	{
	case SIZE_TYPE_32	:	TestBTreeSTLset (nTestNum, nNodeSize, nPageSize, pSetWrapper32);

							break;

	case SIZE_TYPE_64	:	TestBTreeSTLset (nTestNum, nNodeSize, nPageSize, pSetWrapper64);

							break;

	default				:	::std::cerr << "ERROR: size type not specified or not supported!" << ::std::endl;

							exit (-1);

							break;
	}
}


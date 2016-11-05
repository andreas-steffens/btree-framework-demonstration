#include "btreetestsubdivisionarray.h"

void TestBTreeArraySubDivision (uint32_t nTestNum, uint32_t nNodeSize, uint32_t nPageSize, size_type_e eSizeType)
{
	CBTreeArrayTestWrapper<arrayEntry_t, uint32_t, ::std::list<arrayEntry_t> >		*pArrayWrapper32 = NULL;
	CBTreeArrayTestWrapper<arrayEntry_t, uint64_t, ::std::list<arrayEntry_t> >		*pArrayWrapper64 = NULL;

	switch (eSizeType)
	{
	case SIZE_TYPE_32	:	TestBTreeArray (nTestNum, nNodeSize, nPageSize, pArrayWrapper32);

							break;

	case SIZE_TYPE_64	:	TestBTreeArray (nTestNum, nNodeSize, nPageSize, pArrayWrapper64);

							break;

	default				:	::std::cerr << "ERROR: size type not specified or not supported!" << ::std::endl;

							exit (-1);

							break;
	}
}


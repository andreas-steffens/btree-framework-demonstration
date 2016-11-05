#include "btreetestsubdivisionkeysortiter.h"

void TestBTreeKeySortIterSubDivision (uint32_t nTestNum, uint32_t nNodeSize, uint32_t nPageSize, size_type_e eSizeType)
{
	switch (eSizeType)
	{
	case SIZE_TYPE_32	:	TestBTreeKeySortIter<uint32_t> (nTestNum, nNodeSize, nPageSize);

							break;

	case SIZE_TYPE_64	:	TestBTreeKeySortIter<uint64_t> (nTestNum, nNodeSize, nPageSize);

							break;

	default				:	::std::cerr << "ERROR: size type not specified or not supported!" << ::std::endl;

							exit (-1);

							break;
	}
}


#include "btreetestsubdivisionkeysort.h"

void TestBTreeKeySortSubDivision (uint32_t nTestNum, uint32_t nNodeSize, uint32_t nPageSize, size_type_e eSizeType)
{
	CBTreeKeySortTestWrapper<keySortEntry_t, keySortEntry_t, uint32_t, keysort_reference_t>	*pKeySortWrapper32 = NULL;
	CBTreeKeySortTestWrapper<keySortEntry_t, keySortEntry_t, uint64_t, keysort_reference_t>	*pKeySortWrapper64 = NULL;

	CBTreeKeySortTestWrapper<keySortPair_t, keySortPair_t, uint32_t, keysort_reference_t>	*pKeySortPairWrapper32 = NULL;
	CBTreeKeySortTestWrapper<keySortPair_t, keySortPair_t, uint64_t, keysort_reference_t>	*pKeySortPairWrapper64 = NULL;

	switch (eSizeType)
	{
	case SIZE_TYPE_32	:	TestBTreeKeySort (nTestNum, nNodeSize, nPageSize, pKeySortWrapper32, pKeySortPairWrapper32);

							break;

	case SIZE_TYPE_64	:	TestBTreeKeySort (nTestNum, nNodeSize, nPageSize, pKeySortWrapper64, pKeySortPairWrapper64);

							break;

	default				:	::std::cerr << "ERROR: size type not specified or not supported!" << ::std::endl;

							exit (-1);

							break;
	}
}


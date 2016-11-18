/************************************************************
**
** file:	btreemultimaptestbench.cpp
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
** This file contains code for the b-tree framework's test bench
** exercising functional, code coverage and regression tests
** for the multi map application class.
**
************************************************************/

#include "btreemultimaptestbench.h"

template<class _t_multimap>
void TestBTreeMultiMapSTLifAssignmentOperator (_t_multimap *pClMM, typename _t_multimap::size_type nNumEntries)
{
	typedef typename _t_multimap::const_iterator						citer_t;
	typedef typename _t_multimap::key_type								key_type;

	_t_multimap					sClMM (*pClMM);
	key_type					nLastKey = 0;
	citer_t						sIter;
	citer_t						sIterRslt;
	
	::std::cout << "exercises assignment operator compatible to STL interface CBTreeMultiMap<>:: operator= (CBTreeMultiMap<> &)" << ::std::endl;

	associative_container_add_primitive (pClMM, nNumEntries, 0, nLastKey, BTREETEST_KEY_GENERATION_RANDOM);

	sClMM = *pClMM;

	if (sClMM != (*pClMM))
	{
		::std::cerr << ::std::endl;
		::std::cerr << "TestBTreeMultiMapSTLifAssignmentOperator<>: ERROR: mismatch after assignment operation" << ::std::endl;

		exit (-1);
	}
}

template<class _t_multimap>
void TestBTreeMultiMapSTLifInsert (_t_multimap *pClMM, typename _t_multimap::size_type nNumEntries)
{
	typename _t_multimap::key_type	nLastSeed = 0;

	::std::cout << "CBTreeMultiMap::insert (const valuetype &) is exercised" << ::std::endl;

	associative_container_add_primitive (pClMM, nNumEntries, 0, nLastSeed, BTREETEST_KEY_GENERATION_RANDOM);
}

template<class _t_multimap>
void TestBTreeMultiMapSTLifEraseViaIterator (_t_multimap *pClMM, typename _t_multimap::size_type nNumEntries)
{
	typedef typename _t_multimap::const_iterator	citer_t;
	typedef typename _t_multimap::size_type			size_type;
	typedef typename _t_multimap::key_type			key_type;

	key_type									nLastKey = 0;
	citer_t										sIter;
	citer_t										sIterRslt;
	size_type									nOffset;
	size_type									nRslt;
	
	::std::cout << "exercises method compatible to STL interface CBTreeMultiMap<>:: erase (const_iterator)" << ::std::endl;

	associative_container_add_primitive (pClMM, nNumEntries, 0, nLastKey, BTREETEST_KEY_GENERATION_RANDOM);

	while (pClMM->size () > 0)
	{
		nOffset = generate_rand32 () % pClMM->size ();

		sIter = pClMM->cbegin ();

		::std::advance (sIter, nOffset);

		sIterRslt = pClMM->erase (sIter);

		nRslt = ::std::distance (pClMM->cbegin (), sIterRslt);

		if (nOffset != nRslt)
		{
			::std::cerr << ::std::endl;
			::std::cerr << "TestBTreeMultiMapSTLifEraseViaIterator: returned iterator mismatches!" << ::std::endl;

			exit (-1);
		}
	}
}

template<class _t_multimap>
void TestBTreeMultiMapSTLifEraseViaKey (_t_multimap *pClMM, typename _t_multimap::size_type nNumEntries, uint32_t nInstances)
{
	typedef typename _t_multimap::const_iterator	citer_t;
	typedef typename _t_multimap::size_type			size_type;
	typedef typename _t_multimap::key_type			key_type;

	key_type						nLastKey;
	key_type						nKey;
	citer_t							sIter;
	uint32_t						i;
	size_type						nRslt;
	size_type						nOffset;
	
	::std::cout << "exercises method compatible to STL interface CBTreeMultiMap<>:: erase (const keytype &)" << ::std::endl;

	for (i = 0; i < nInstances; i++)
	{
		nLastKey = 0;

		associative_container_add_primitive (pClMM, nNumEntries, 0, nLastKey, BTREETEST_KEY_GENERATION_RANDOM);
	}

	while (pClMM->size () > 0)
	{
		nOffset = generate_rand32 () % pClMM->size ();

		sIter = pClMM->cbegin ();

		::std::advance (sIter, nOffset);

		nKey = (*sIter).first;

		nRslt = pClMM->erase (nKey);

		if (nRslt != nInstances)
		{
			::std::cerr << ::std::endl;
			::std::cerr << "TestBTreeMultiMapSTLifEraseViaKey: unexpected number of items deleted!" << ::std::endl;

			exit (-1);
		}
	}
}

template<class _t_multimap>
void TestBTreeMultiMapSTLifEraseViaIteratorMultiple (_t_multimap *pClMM, typename _t_multimap::size_type nNumEntries, uint32_t nInstances)
{
	typedef typename _t_multimap::const_iterator	citer_t;
	typedef typename _t_multimap::size_type			size_type;
	typedef typename _t_multimap::key_type			key_type;

	key_type									nLastKey;
	citer_t										sIterBegin;
	citer_t										sIterEnd;
	citer_t										sIterRslt;
	uint32_t									i;
	size_type									nBegin;
	size_type									nRslt;
	
#if defined (_DEBUG)

	uint32_t									nDebug = 0;

#endif
	
	::std::cout << "exercises method compatible to STL interface CBTreeMultiMap<>:: erase (const_iterator, const_iterator)" << ::std::endl;

	for (i = 0; i < nInstances; i++)
	{
		nLastKey = 0;

		associative_container_add_primitive (pClMM, nNumEntries, 0, nLastKey, BTREETEST_KEY_GENERATION_RANDOM);
	}

	while (pClMM->size () > 0)
	{
		sIterBegin = pClMM->cbegin ();
		sIterEnd = pClMM->cend ();

		nBegin = 0;

		if (pClMM->size () > 1)
		{
			nBegin = generate_rand32 () % (pClMM->size () / 2);

			::std::advance (sIterBegin, nBegin);
			::std::advance (sIterEnd, (int) (0 - (generate_rand32 () % (pClMM->size () / 2))));
		}

		sIterRslt = pClMM->erase (sIterBegin, sIterEnd);

		nRslt = ::std::distance (pClMM->cbegin (), sIterRslt);

		if (nRslt != nBegin)
		{
			::std::cerr << ::std::endl;
			::std::cerr << "TestBTreeMultiMapSTLifEraseViaIteratorMultiple: returned iterator mismatches!" << ::std::endl;
			::std::cerr << "expected value: " << nBegin << ::std::endl;
			::std::cerr << "returned value: " << nRslt << ::std::endl;

#if defined (_DEBUG)

			::std::cerr << "iteration: " << nDebug << ::std::endl;

#endif

			exit (-1);
		}

#if defined (_DEBUG)

		nDebug++;

#endif
	}
}

template<class _t_multimap>
void TestBTreeMultiMapSTLifKeyComp (_t_multimap *pClMM, typename _t_multimap::size_type nNumEntries)
{
	typedef typename _t_multimap::iterator		iter_t;
	typedef typename _t_multimap::key_type		key_type;
	typedef typename _t_multimap::value_type	value_type;

	key_type									nLastKey = 0;
	iter_t										sIterBegin;
	iter_t										sIterEnd;
	iter_t										sIter;
	iter_t										sIterUpper;
	key_type									nKey;
	uint32_t									nNextKey;
	typename _t_multimap::key_compare			sMMComp = pClMM->key_comp ();
	
	::std::cout << "exercises method compatible to STL interface CBTreeMultiMap<>:: key_comp ()" << ::std::endl;

	associative_container_add_primitive (pClMM, nNumEntries, 0, nLastKey, BTREETEST_KEY_GENERATION_RANDOM);

	sIterBegin = pClMM->begin ();
	sIterEnd = pClMM->end ();

	for (sIter = sIterBegin; sIter != sIterEnd; sIter++)
	{
		nKey = ((value_type)(*sIter)).first;

		sIterUpper = pClMM->upper_bound (nKey);

		if (sIterUpper != sIterEnd)
		{
			nNextKey = ((value_type)(*sIterUpper)).first;

			if (!sMMComp (nKey, nNextKey))
			{
				::std::cerr << ::std::endl;
				::std::cerr << "TestBTreeMultiMapSTLifKeyComp: ERROR: CBTreeMultiMap::key_compare (const keytype &, const keytype &) delivered unexpected result!" << ::std::endl;

				exit (-1);
			}
		}
	}
}

template<class _t_multimap>
void TestBTreeMultiMapSTLifValueComp (_t_multimap *pClMM, typename _t_multimap::size_type nNumEntries)
{
	typedef typename _t_multimap::iterator		iter_t;
	typedef typename _t_multimap::key_type		key_type;
	typedef typename _t_multimap::value_type	value_type;

	key_type									nLastKey = 0;
	iter_t										sIterBegin;
	iter_t										sIterEnd;
	iter_t										sIter;
	iter_t										sIterUpper;
	key_type									nKey;
	typename _t_multimap::value_compare			sMMComp = pClMM->value_comp ();
	
	::std::cout << "exercises method compatible to STL interface CBTreeMultiMap<>:: value_comp ()" << ::std::endl;

	associative_container_add_primitive (pClMM, nNumEntries, 0, nLastKey, BTREETEST_KEY_GENERATION_RANDOM);

	sIterBegin = pClMM->begin ();
	sIterEnd = pClMM->end ();

	for (sIter = sIterBegin; sIter != sIterEnd; sIter++)
	{
		nKey = ((value_type)(*sIter)).first;

		sIterUpper = pClMM->upper_bound (nKey);

		if (sIterUpper != sIterEnd)
		{
			if (!sMMComp (((value_type)(*sIter)), ((value_type)(*sIterUpper))))
			{
				::std::cerr << ::std::endl;
				::std::cerr << "TestBTreeMultiMapSTLifValueComp: ERROR: CBTreeMultiMap::value_compare (const valuetype &, const valuetype &) delivered unexpected result!" << ::std::endl;

				exit (-1);
			}
		}
	}
}

template<class _t_multimap>
void TestBTreeMultiMapSTLifSwap (_t_multimap *pClMM, typename _t_multimap::size_type nNumEntries)
{
	typedef typename _t_multimap::const_iterator			citer_t;
	typedef typename _t_multimap::key_type					key_type;
	
	key_type						nLastKey = 0;
	_t_multimap						sClMultiMapTarget ((const _t_multimap &) *pClMM);
	_t_multimap						sClMultiMapRef ((const _t_multimap &) *pClMM);
	_t_multimap						sClMultiMapTargetRef ((const _t_multimap &) *pClMM);

	::std::cout << "exercises method compatible to STL interface CBTreeMultiMap<>:: swap (CBTreeMultiMap &)" << ::std::endl;

	associative_container_add_primitive (pClMM, nNumEntries, 0, nLastKey, BTREETEST_KEY_GENERATION_RANDOM);

	sClMultiMapRef.insert (pClMM->cbegin (), pClMM->cend ());

	if ((*pClMM) != sClMultiMapRef)
	{
		::std::cerr << "ERROR: Unexpected multimap mismatch!" << ::std::endl;

		exit (-1);
	}

	associative_container_add_primitive (&sClMultiMapTarget, nNumEntries, 0, nLastKey, BTREETEST_KEY_GENERATION_RANDOM);

	sClMultiMapTargetRef.insert (sClMultiMapTarget.cbegin (), sClMultiMapTarget.cend ());

	if (sClMultiMapTarget != sClMultiMapTargetRef)
	{
		::std::cerr << "ERROR: Unexpected target mismatch!" << ::std::endl;

		exit (-1);
	}

	pClMM->swap (sClMultiMapTarget);

	if ((*pClMM) != sClMultiMapTargetRef)
	{
		::std::cerr << "ERROR: swapped multimap mismatches target reference!" << ::std::endl;

		exit (-1);
	}

	if (sClMultiMapTarget != sClMultiMapRef)
	{
		::std::cerr << "ERROR: target mismatches multimap reference!" << ::std::endl;

		exit (-1);
	}

	sClMultiMapTarget.swap (*pClMM);

	if ((*pClMM) != sClMultiMapRef)
	{
		::std::cerr << "ERROR: multimap mismatches multimap reference!" << ::std::endl;

		exit (-1);
	}

	if (sClMultiMapTarget != sClMultiMapTargetRef)
	{
		::std::cerr << "ERROR: target mismatches target reference!" << ::std::endl;

		exit (-1);
	}
}

template<class _t_multimap>
void TestBTreeMultiMapSTLifFind (_t_multimap *pClMM, typename _t_multimap::size_type nNumEntries)
{
	typedef typename _t_multimap::const_iterator			citer_t;
	typedef typename _t_multimap::key_type					key_type;

	key_type			nLastKey = 1;
	key_type			nKey;
	citer_t				sCIter;
	citer_t				sCIterRslt;
	
	::std::cout << "exercises method compatible to STL interface CBTreeMultiMap<>:: find (const _t_keytype &)" << ::std::endl;

	associative_container_add_primitive (pClMM, nNumEntries, 0, nLastKey, BTREETEST_KEY_GENERATION_ASCEND);

	for (sCIter = pClMM->cbegin (); sCIter != pClMM->cend (); sCIter++)
	{
		nKey = (*sCIter).first;

		sCIterRslt = pClMM->find (nKey);

		if (sCIter != sCIterRslt)
		{
			::std::cerr << ::std::endl;
			::std::cerr << "TestBTreeMultiMapSTLifFind: ERROR: iterator mismatch!" << ::std::endl;

			exit (-1);
		}
	}

	nKey = 0;

	sCIterRslt = pClMM->find (nKey);

	if (sCIterRslt != pClMM->cend ())
	{
		::std::cerr << ::std::endl;
		::std::cerr << "TestBTreeMultiMapSTLifFind: ERROR: find () didn't return cend () on lower bound check!" << ::std::endl;

		exit (-1);
	}

	nKey = (key_type) (nNumEntries + 1);

	sCIterRslt = pClMM->find (nKey);

	if (sCIterRslt != pClMM->cend ())
	{
		::std::cerr << ::std::endl;
		::std::cerr << "TestBTreeMultiMapSTLifFind: ERROR: find () didn't return cend () on upper bound check!" << ::std::endl;

		exit (-1);
	}
}

template<class _t_multimap>
void TestBTreeMultiMapSTLifLowerBoundUpperBound (_t_multimap *pClMM, typename _t_multimap::size_type nNumEntries, uint32_t nInstance)
{
	typedef typename _t_multimap::const_iterator			citer_t;
	typedef typename _t_multimap::key_type					key_type;

	key_type			nLastKey;
	key_type			nKey;
	uint32_t			i;
	citer_t				sCIterLower;
	citer_t				sCIterUpper;
	
	::std::cout << "exercises method compatible to STL interface CBTreeMultiMap<>:: lower_bound () upper_bound () count ()" << ::std::endl;
	
	for (i = 0; i < nInstance; i++)
	{
		nLastKey = 1;

		associative_container_add_primitive (pClMM, nNumEntries, 0, nLastKey, BTREETEST_KEY_GENERATION_ASCEND);
	}

	for (i = 0; i < nNumEntries; i++)
	{
		nKey = i + 1;

		sCIterLower = pClMM->lower_bound (nKey);
		sCIterUpper = pClMM->upper_bound (nKey);

		::std::advance (sCIterLower, (int) nInstance);

		if (sCIterLower != sCIterUpper)
		{
			::std::cerr << ::std::endl;
			::std::cerr << "TestBTreeMultiMapSTLifLowerBoundUpperBound: ERROR: boundary mismatch!" << ::std::endl;

			exit (-1);
		}

		if (pClMM->count (nKey) != nInstance)
		{
			::std::cerr << ::std::endl;
			::std::cerr << "TestBTreeMultiMapSTLifLowerBoundUpperBound: ERROR: count () returned with unexpected value!" << ::std::endl;

			exit (-1);
		}
	}

	nKey = 0;

	sCIterLower = pClMM->lower_bound (nKey);

	if (sCIterLower != pClMM->cbegin ())
	{
		::std::cerr << ::std::endl;
		::std::cerr << "TestBTreeMultiMapSTLifLowerBoundUpperBound: ERROR: lower_bound () didn't return cbegin () when testing for lowest key!" << ::std::endl;

		exit (-1);
	}

	nKey = (key_type) (nNumEntries + 1);

	sCIterUpper = pClMM->upper_bound (nKey);

	if (sCIterUpper != pClMM->cend ())
	{
		::std::cerr << ::std::endl;
		::std::cerr << "TestBTreeMultiMapSTLifLowerBoundUpperBound: ERROR: upper_bound () didn't return cend () when testing for lowest key!" << ::std::endl;

		exit (-1);
	}
}

template<class _t_multimap>
void TestBTreeMultiMapSTLifEmplace (_t_multimap *pClMM, typename _t_multimap::size_type nNumEntries)
{
	uint32_t		nLastKey = 1;

	::std::cout << "exercises method compatible to STL interface CBTreeMultiMap<>:: emplace ()" << ::std::endl;

	associative_container_add_primitive (pClMM, nNumEntries, 0, nLastKey, BTREETEST_KEY_GENERATION_RANDOM, ASSOCIATIVE_ADD_METHOD_EMPLACE);

	nLastKey = 1;

	associative_container_add_primitive (pClMM, nNumEntries, 0, nLastKey, BTREETEST_KEY_GENERATION_RANDOM, ASSOCIATIVE_ADD_METHOD_EMPLACE);
}

template<class _t_multimap>
void TestBTreeMultiMapSTLifEmplaceHint (_t_multimap *pClMM, typename _t_multimap::size_type nNumEntries, typename _t_multimap::size_type nHintVariation)
{
	uint32_t		nLastKey = 1;

	::std::cout << "exercises method compatible to STL interface CBTreeMultiMap<>:: emplace_hint () with hint variation set to " << nHintVariation << ::std::endl;

	associative_container_add_primitive (pClMM, nNumEntries, nHintVariation, nLastKey, BTREETEST_KEY_GENERATION_RANDOM, ASSOCIATIVE_ADD_METHOD_EMPLACE_HINT);

	nLastKey = 1;

	associative_container_add_primitive (pClMM, nNumEntries, nHintVariation, nLastKey, BTREETEST_KEY_GENERATION_RANDOM, ASSOCIATIVE_ADD_METHOD_EMPLACE_HINT);
}

template<class _t_multimap>
void TestBTreeMultiMapSTLifInsertHint (_t_multimap *pClMM, typename _t_multimap::size_type nNumEntries, typename _t_multimap::size_type nHintVariation)
{
	uint32_t		nLastKey = 1;

	::std::cout << "exercises method compatible to STL interface CBTreeMultiMap<>:: insert (hint) with hint variation set to " << nHintVariation << ::std::endl;

	associative_container_add_primitive (pClMM, nNumEntries, nHintVariation, nLastKey, BTREETEST_KEY_GENERATION_RANDOM, ASSOCIATIVE_ADD_METHOD_INSERT_HINT);

	nLastKey = 1;

	associative_container_add_primitive (pClMM, nNumEntries, nHintVariation, nLastKey, BTREETEST_KEY_GENERATION_RANDOM, ASSOCIATIVE_ADD_METHOD_INSERT_HINT);
}

template<class _t_multimap>
void TestBTreeMultiMapSTLifEmplaceViaCtor (_t_multimap *pClMM, typename _t_multimap::size_type nNumEntries, typename _t_multimap::size_type nHintVariation)
{
	uint32_t		nLastKey = 1;

	::std::cout << "exercises method compatible to STL interface CBTreeMultiMap<>:: emplace (ctor)" << ::std::endl;

	associative_container_add_primitive (pClMM, nNumEntries, nHintVariation, nLastKey, BTREETEST_KEY_GENERATION_RANDOM, ASSOCIATIVE_ADD_METHOD_ABSTRACT_EMPLACE);

	nLastKey = 1;

	associative_container_add_primitive (pClMM, nNumEntries, nHintVariation, nLastKey, BTREETEST_KEY_GENERATION_RANDOM, ASSOCIATIVE_ADD_METHOD_ABSTRACT_EMPLACE);
}

template<class _t_multimap>
void TestBTreeMultiMapSTLifEmplaceHintViaCtor (_t_multimap *pClMM, typename _t_multimap::size_type nNumEntries, typename _t_multimap::size_type nHintVariation)
{
	uint32_t		nLastKey = 1;

	::std::cout << "exercises method compatible to STL interface CBTreeMultiMap<>:: emplace_hint (ctor)" << ::std::endl;

	associative_container_add_primitive (pClMM, nNumEntries, nHintVariation, nLastKey, BTREETEST_KEY_GENERATION_RANDOM, ASSOCIATIVE_ADD_METHOD_ABSTRACT_EMPLACE_HINT);

	nLastKey = 1;

	associative_container_add_primitive (pClMM, nNumEntries, nHintVariation, nLastKey, BTREETEST_KEY_GENERATION_RANDOM, ASSOCIATIVE_ADD_METHOD_ABSTRACT_EMPLACE_HINT);
}

template<class _t_multimap>
void TestBTreeMultiMapSTLifEqualRange (_t_multimap *pClMM, typename _t_multimap::size_type nNumEntries, uint32_t nInstance)
{
	typedef typename _t_multimap::const_iterator			citer_t;

	typedef typename _t_multimap::key_type					key_type;
	typedef typename _t_multimap::size_type					size_type;

	typedef typename _t_multimap::equal_range_type			equal_range_type;
	typedef typename _t_multimap::equal_range_const_type	equal_range_const_type;

	key_type								nLastKey;
	key_type								nKey;
	uint32_t								i;
	size_type								j;
	equal_range_type						sEqRange;
	equal_range_const_type					sCEqRange;

	::std::cout << "exercises methods compatible to STL interface CBTreeMultiMap<>:: equal_range ()" << ::std::endl;

	for (i = 0; i < nInstance; i++)
	{
		nLastKey = 1;

		associative_container_add_primitive (pClMM, nNumEntries, 0, nLastKey, BTREETEST_KEY_GENERATION_ASCEND);

		for (j = 0; j < nNumEntries; j++)
		{
			nKey = key_type (j + 1);

			sEqRange = pClMM->equal_range (nKey);
			sCEqRange = ((const _t_multimap *) pClMM)->equal_range (nKey);

			if (::std::distance (sEqRange.first, sEqRange.second) != size_type (i + 1))
			{
				::std::cerr << ::std::endl;
				::std::cerr << "TestBTreeMultiMapSTLifEqualRange: ERROR: rw distance mismatch!" << ::std::endl;

				exit (-1);
			}

			if (::std::distance (sCEqRange.first, sCEqRange.second) != size_type (i + 1))
			{
				::std::cerr << ::std::endl;
				::std::cerr << "TestBTreeMultiMapSTLifEqualRange: ERROR: ro distance mismatch!" << ::std::endl;

				exit (-1);
			}
		}

		nKey = 0;

		sEqRange = pClMM->equal_range (nKey);
		sCEqRange = ((const _t_multimap *) pClMM)->equal_range (nKey);

		if (sEqRange.first != pClMM->begin ())
		{
			::std::cerr << ::std::endl;
			::std::cerr << "TestBTreeMultiMapSTLifEqualRange: ERROR: equal_range ().first didn't return begin () when testing for lowest key!" << ::std::endl;

			exit (-1);
		}

		if (sEqRange.second != pClMM->begin ())
		{
			::std::cerr << ::std::endl;
			::std::cerr << "TestBTreeMultiMapSTLifEqualRange: ERROR: equal_range ().second didn't return begin () when testing for lowest key!" << ::std::endl;

			exit (-1);
		}

		if (sCEqRange.first != pClMM->cbegin ())
		{
			::std::cerr << ::std::endl;
			::std::cerr << "TestBTreeMultiMapSTLifEqualRange: ERROR: equal_range () const.first didn't return cbegin () when testing for lowest key!" << ::std::endl;

			exit (-1);
		}

		if (sCEqRange.second != pClMM->cbegin ())
		{
			::std::cerr << ::std::endl;
			::std::cerr << "TestBTreeMultiMapSTLifEqualRange: ERROR: equal_range () const.second didn't return cbegin () when testing for lowest key!" << ::std::endl;

			exit (-1);
		}

		nKey = (key_type) (nNumEntries + 1);

		sEqRange = pClMM->equal_range (nKey);
		sCEqRange = ((const _t_multimap *) pClMM)->equal_range (nKey);

		if (sEqRange.first != pClMM->end ())
		{
			::std::cerr << ::std::endl;
			::std::cerr << "TestBTreeMultiMapSTLifEqualRange: ERROR: equal_range ().first didn't return end () when testing for highest key!" << ::std::endl;

			exit (-1);
		}

		if (sEqRange.second != pClMM->end ())
		{
			::std::cerr << ::std::endl;
			::std::cerr << "TestBTreeMultiMapSTLifEqualRange: ERROR: equal_range ().second didn't return end () when testing for highest key!" << ::std::endl;

			exit (-1);
		}

		if (sCEqRange.first != pClMM->cend ())
		{
			::std::cerr << ::std::endl;
			::std::cerr << "TestBTreeMultiMapSTLifEqualRange: ERROR: equal_range () const.first didn't return cend () when testing for highest key!" << ::std::endl;

			exit (-1);
		}

		if (sCEqRange.second != pClMM->cend ())
		{
			::std::cerr << ::std::endl;
			::std::cerr << "TestBTreeMultiMapSTLifEqualRange: ERROR: equal_range () const.second didn't return cend () when testing for highest key!" << ::std::endl;

			exit (-1);
		}
	}
}

template<class _t_container>
void TestBTreeSTLmultiMap (uint32_t nTestNum, uint32_t nNodeSize, uint32_t nPageSize, _t_container *pMMapWrapper)
{
	typename _t_container::size_test_type		sTypeSelect;
	::std::string								sTypeStr;

	get_typename (sTypeSelect, sTypeStr);

	::std::cout << "b-tree multi-map test bench selected using type " << sTypeStr << ::std::endl;

	pMMapWrapper = new _t_container (nNodeSize, nPageSize);

	if (pMMapWrapper == NULL)
	{
		::std::cerr << "insufficient memory!" << ::std::endl;

		exit (-1);
	}

	switch (nTestNum)
	{
	case BTREETEST_MULTIMAP_ASSIGNMENT_OPERATOR	:
		{
			TestBTreeMultiMapSTLifAssignmentOperator (pMMapWrapper, 64);

			break;
		}
	
	case BTREETEST_MULTIMAP_STL_IF_INSERT	:
		{
			TestBTreeMultiMapSTLifInsert (pMMapWrapper, 64);

			break;
		}
	
	case BTREETEST_MULTIMAP_STL_IF_INSERT_VIA_ITERATOR	:
		{
			TestBTreeMapSTLifInsertViaIterator (pMMapWrapper, 64);
			
			break;
		}
	
	case BTREETEST_MULTIMAP_STL_IF_ERASE_VIA_ITERATOR	:
		{
			TestBTreeMultiMapSTLifEraseViaIterator (pMMapWrapper, 64);

			break;
		}
	
	case BTREETEST_MULTIMAP_STL_IF_ERASE_VIA_KEY	:
		{
			TestBTreeMultiMapSTLifEraseViaKey (pMMapWrapper, 64, 5);

			break;
		}
	
	case BTREETEST_MULTIMAP_STL_IF_ERASE_VIA_ITERATOR_MULTIPLE	:
		{
			TestBTreeMultiMapSTLifEraseViaIteratorMultiple (pMMapWrapper, 64, 5);

			break;
		}
	
	case BTREETEST_MULTIMAP_STL_IF_KEY_COMP	:
		{
			TestBTreeMultiMapSTLifKeyComp (pMMapWrapper, 64);

			break;
		}
	
	case BTREETEST_MULTIMAP_STL_IF_VALUE_COMP	:
		{
			TestBTreeMultiMapSTLifValueComp (pMMapWrapper, 64);

			break;
		}
	
	case BTREETEST_MULTIMAP_STL_IF_SWAP	:
		{
			TestBTreeMultiMapSTLifSwap (pMMapWrapper, 128);

			break;
		}
	
	case BTREETEST_MULTIMAP_STL_IF_FIND	:
		{
			TestBTreeMultiMapSTLifFind (pMMapWrapper, 64);

			break;
		}
	
	case BTREETEST_MULTIMAP_STL_IF_LOWER_BOUND_UPPER_BOUND	:
		{
			TestBTreeMultiMapSTLifLowerBoundUpperBound (pMMapWrapper, 64, 5);

			break;
		}
	
	case BTREETEST_MULTIMAP_STL_IF_EMPLACE	:
		{
			TestBTreeMultiMapSTLifEmplace (pMMapWrapper, 64);

			break;
		}
	
	case BTREETEST_MULTIMAP_STL_IF_EMPLACE_HINT	:
		{
			TestBTreeMultiMapSTLifEmplaceHint (pMMapWrapper, 64, 0);

			break;
		}
	
	case BTREETEST_MULTIMAP_STL_IF_EMPLACE_HINT_MINOR	:
		{
			TestBTreeMultiMapSTLifEmplaceHint (pMMapWrapper, 64, 1);

			break;
		}
	
	case BTREETEST_MULTIMAP_STL_IF_EMPLACE_HINT_SIGNIFICANT	:
		{
			TestBTreeMultiMapSTLifEmplaceHint (pMMapWrapper, 64, 6);

			break;
		}
	
	case BTREETEST_MULTIMAP_STL_IF_EMPLACE_HINT_LARGE	:
		{
			TestBTreeMultiMapSTLifEmplaceHint (pMMapWrapper, 64, 64);

			break;
		}
	
	case BTREETEST_MULTIMAP_STL_IF_INSERT_HINT	:
		{
			TestBTreeMultiMapSTLifInsertHint (pMMapWrapper, 64, 0);

			break;
		}
	
	case BTREETEST_MULTIMAP_STL_IF_INSERT_HINT_MINOR	:
		{
			TestBTreeMultiMapSTLifInsertHint (pMMapWrapper, 64, 1);

			break;
		}
	
	case BTREETEST_MULTIMAP_STL_IF_INSERT_HINT_SIGNIFICANT	:
		{
			TestBTreeMultiMapSTLifInsertHint (pMMapWrapper, 64, 6);

			break;
		}
	
	case BTREETEST_MULTIMAP_STL_IF_INSERT_HINT_LARGE	:
		{
			TestBTreeMultiMapSTLifInsertHint (pMMapWrapper, 64, 64);

			break;
		}
	
	case BTREETEST_MULTIMAP_STL_IF_EMPLACE_VIA_CTOR	:
		{
			TestBTreeMultiMapSTLifEmplaceViaCtor (pMMapWrapper, 64, 0);
	
			break;
		}
	
	case BTREETEST_MULTIMAP_STL_IF_EMPLACE_HINT_VIA_CTOR	:
		{
			TestBTreeMultiMapSTLifEmplaceHintViaCtor (pMMapWrapper, 64, 0);

			break;
		}
	
	case BTREETEST_MULTIMAP_STL_IF_EQUAL_RANGE	:
		{
			TestBTreeMultiMapSTLifEqualRange (pMMapWrapper, 64, 5);

			break;
		}
	
	default:
		{
			::std::cerr << "ERROR: TestBTreeSTLmultiMap: Unknown test or test not specified!" << ::std::endl;

			exit (-1);

			break;
		}
	}

	delete pMMapWrapper;
}

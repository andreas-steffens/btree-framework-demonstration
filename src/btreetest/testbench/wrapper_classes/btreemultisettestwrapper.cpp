/************************************************************
**
** file:	btreemultisettestwrapper.cpp
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
** This file contains the definition of a multi set test class 
** wrapping accesses to a multi map application class instance and
** a reference container instance, while making sure the
** multi map instance acts the same way as the reference.
**
************************************************************/

#ifndef	BTREEMULTISETTESTWRAPPER_CPP
#define	BTREEMULTISETTESTWRAPPER_CPP

#include "btreemultisettestwrapper.h"

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeMultiSetTestWrapper (const uint32_t nNodeSize, const uint32_t nPageSize)
	:	CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container> (nNodeSize, nPageSize)
{
	this->m_nNumContainers = CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::m_nNumContainersMS;

	this->instantiate_container_array ();

	this->init_containers (this->m_nNodeSize, this->m_nPageSize);

	this->transfer_containers ();
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeMultiSetTestWrapper (const CBTreeMultiSetTestWrapper &rContainer)
	:	CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container> (rContainer)
{
	this->m_nNumContainers = CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::m_nNumContainersMS;

	this->instantiate_container_array ();

	this->init_containers (rContainer);

	this->transfer_containers ();

	this->test ();
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::~CBTreeMultiSetTestWrapper ()
{
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
template<class _t_iterator>
void CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::insert (_t_iterator sIterFirst, _t_iterator sIterLast)
{
	uint32_t		i = 0;

	this->m_pReference->insert (sIterFirst, sIterLast);

	m_pContainerRAM6565_n->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerRAM6555_n->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerRAM5555_n->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerRAM5554_n->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerRAM5454_n->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerRAM5444_n->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerRAM4444_n->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerRAM6565_2n->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerRAM6555_2n->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerRAM5555_2n->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerRAM5554_2n->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerRAM5454_2n->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerRAM5444_2n->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerRAM4444_2n->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerRAM6565_4n->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerRAM6555_4n->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerRAM5555_4n->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerRAM5554_4n->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerRAM5454_4n->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerRAM5444_4n->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerRAM4444_4n->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerFile6565min->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerFile6555min->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerFile5555min->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerFile5554min->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerFile5454min->template insert<_t_iterator> (sIterFirst, sIterLast); i++;

	m_pContainerFile6565default->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerFile6555default->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerFile5555default->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerFile5554default->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerFile5454default->template insert<_t_iterator> (sIterFirst, sIterLast); i++;

	m_pContainerFile6565large->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerFile6555large->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerFile5555large->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerFile5554large->template insert<_t_iterator> (sIterFirst, sIterLast); i++;
	m_pContainerFile5454large->template insert<_t_iterator> (sIterFirst, sIterLast); i++;

	BTREE_ASSERT (i == this->get_num_containers (), "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::insert<_t_iterator>: ERROR: Unexpected number of test containers!");

	this->test ();
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
template<class _t_iterator, class _t_dummy_iterator>
void CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::insert (_t_dummy_iterator &rIterDummy, _t_iterator sIterFirst, _t_iterator sIterLast)
{
	rIterDummy;

	this->insert (sIterFirst, sIterLast);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::iterator CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::insert (const typename CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::value_type &rData, const bool bInsertNotEmplace)
{
	return (CBTreeAssociativeTestWrapper_t::insert (rData, bInsertNotEmplace));
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
void CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::insert_hint
	(
		const typename CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::value_type &rData, 
		const bool bInsertNotEmplace
	)
{
	CBTreeAssociativeTestWrapper_t::insert_hint (rData, bInsertNotEmplace);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
template<class _t_iterator, class _t_test_iterator>
void CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::insert_self_reference (_t_iterator sIterFirst, _t_iterator sIterLast, _t_test_iterator &rIterTest)
{
	uint32_t			i = 0;
	_t_iterator			sIterBegin;
	size_test_type		nFirst;
	size_test_type		nLast;
	reference_t			sTempContainer;
	_t_test_iterator	sIterTestFirst;
	_t_test_iterator	sIterTestLast;
	const_iterator		sCIterRefBegin;
	const_iterator		sCIterRefEnd;

	get_begin (this->m_pReference, sIterBegin);
	nFirst = (size_test_type) ::std::distance (sIterBegin, sIterFirst);
	nLast = (size_test_type) ::std::distance (sIterBegin, sIterLast);
	
	sTempContainer.insert (sIterFirst, sIterLast);

	sCIterRefBegin = sTempContainer.cbegin ();
	sCIterRefEnd = sTempContainer.cend ();

	this->m_pReference->insert (sCIterRefBegin, sCIterRefEnd);

	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerRAM6565_n->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerRAM6555_n->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerRAM5555_n->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerRAM5554_n->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerRAM5454_n->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerRAM5444_n->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerRAM4444_n->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerRAM6565_2n->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerRAM6555_2n->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerRAM5555_2n->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerRAM5554_2n->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerRAM5454_2n->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerRAM5444_2n->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerRAM4444_2n->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerRAM6565_4n->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerRAM6555_4n->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerRAM5555_4n->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerRAM5554_4n->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerRAM5454_4n->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerRAM5444_4n->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerRAM4444_4n->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerFile6565min->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerFile6555min->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerFile5555min->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerFile5554min->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerFile5454min->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;

	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerFile6565default->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerFile6555default->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerFile5555default->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerFile5554default->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerFile5454default->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;

	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerFile6565large->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerFile6555large->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerFile5555large->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerFile5554large->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;
	get_begin (this->m_ppContainers[i], sIterTestFirst); sIterTestLast = sIterTestFirst; ::std::advance (sIterTestFirst, nFirst); ::std::advance (sIterTestLast, nLast); m_pContainerFile5454large->template insert<_t_test_iterator> (sIterTestFirst, sIterTestLast); i++;

	BTREE_ASSERT (i == this->get_num_containers (), "CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::insert_self_reference<_t_iterator>: ERROR: Unexpected number of test containers!");

	this->test ();
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
template<class _t_ext_container, class _t_ext_iterator, class _t_ref_iterator>
void CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::test_all_containers_insert (_t_ext_container *pExtContainer, _t_ext_iterator &rExtPos, _t_ref_iterator &rIterBegin, _t_ref_iterator &rIterFirst, _t_ref_iterator &rIterLast) const
{
	_t_ext_container		sExtOriginal (*pExtContainer);
	uint32_t				i = 0;
	size_test_type			nFirst = (size_test_type) ::std::distance (rIterBegin, rIterFirst);
	size_test_type			nLast = (size_test_type) ::std::distance (rIterBegin, rIterLast);
	_t_ext_iterator			sExtIterBegin;
	bool					bRefIterConst = is_const_iterator (this->m_pReference, rIterFirst);
	bool					bRefIterReverse = is_reverse_iterator (this->m_pReference, rIterFirst);

	get_begin (pExtContainer, sExtIterBegin);

	typename _t_ext_container::size_type		nDist = ::std::distance (sExtIterBegin, rExtPos);
	
	container_insert (pExtContainer, sExtIterBegin, rIterFirst, rIterLast);
	
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerRAM6565_n); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerRAM6555_n); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerRAM5555_n); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerRAM5554_n); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerRAM5454_n); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerRAM5444_n); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerRAM4444_n); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerRAM6565_2n); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerRAM6555_2n); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerRAM5555_2n); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerRAM5554_2n); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerRAM5454_2n); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerRAM5444_2n); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerRAM4444_2n); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerRAM6565_4n); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerRAM6555_4n); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerRAM5555_4n); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerRAM5554_4n); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerRAM5454_4n); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerRAM5444_4n); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerRAM4444_4n); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerFile6565min); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerFile6555min); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerFile5555min); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerFile5554min); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerFile5454min); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerFile6565default); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerFile6555default); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerFile5555default); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerFile5554default); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerFile5454default); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerFile6565large); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerFile6555large); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerFile5555large); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerFile5554large); i++;
	test_one_container_insert (&sExtOriginal, pExtContainer, nDist, nFirst, nLast, rExtPos, bRefIterConst, bRefIterReverse, m_pContainerFile5454large); i++;

	BTREE_ASSERT (i == this->get_num_containers (), "CBTreeMapTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::test_all_containers_insert: ERROR: Unexpected number of containers has been exercised!");
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
template<class ..._t_va_args>
void CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::emplace (_t_va_args && ... rrArgs)
{
	uint32_t								i = 0;
	_t_data									sInputData;
	typename _t_ref_container::value_type	sRefData;

	new (&sInputData) _t_data (::std::forward<_t_va_args> (rrArgs) ...);

	entry_conversion (sRefData, sInputData);

	this->m_pReference->emplace (sRefData);

	m_pContainerRAM6565_n->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerRAM6555_n->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerRAM5555_n->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerRAM5554_n->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerRAM5454_n->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerRAM5444_n->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerRAM4444_n->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerRAM6565_2n->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerRAM6555_2n->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerRAM5555_2n->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerRAM5554_2n->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerRAM5454_2n->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerRAM5444_2n->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerRAM4444_2n->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerRAM6565_4n->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerRAM6555_4n->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerRAM5555_4n->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerRAM5554_4n->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerRAM5454_4n->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerRAM5444_4n->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerRAM4444_4n->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerFile6565min->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerFile6555min->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerFile5555min->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerFile5554min->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerFile5454min->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;

	m_pContainerFile6565default->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerFile6555default->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerFile5555default->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerFile5554default->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerFile5454default->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;

	m_pContainerFile6565large->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerFile6555large->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerFile5555large->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerFile5554large->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;
	m_pContainerFile5454large->emplace (::std::forward<_t_va_args> (rrArgs) ...); i++;

	BTREE_ASSERT (i == this->get_num_containers (), "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::emplace<>: ERROR: Unexpected number of test containers!");

	this->test ();	
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
template<class ..._t_va_args>
void CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::emplace_hint
	(
		_t_va_args && ... rrArgs
	)
{
	uint32_t								i = 0;
	_t_data									sInputData;
	value_type								sRefData;
	iterator								sIterHint;
	iterator								sIterBegin;
	size_type								nDist;
	test_const_iterator						sCIterTestHint;
	signed_size_type						nVariation = 0;
	size_type								nHintVariation;
	
	new (&sInputData) _t_data (::std::forward<_t_va_args> (rrArgs) ...);

	entry_conversion (sRefData, sInputData);

	sIterHint = this->m_pReference->emplace (sRefData);

	sIterBegin = this->m_pReference->begin ();

	nDist = ::std::distance (sIterBegin, sIterHint);

	if (generate_rand32 () & 0x1)
	{
		nHintVariation = ::std::min<size_type> (nDist, this->m_nHintVariation);

		nVariation = 0 - (generate_rand32 () % (nHintVariation + 1));
	}
	else
	{
		nHintVariation = ::std::min<size_type> ((this->m_pReference->size () - 1) - nDist, this->m_nHintVariation);

		nVariation = generate_rand32 () % (nHintVariation + 1);
	}

	nDist += nVariation;
	
	sCIterTestHint = m_pContainerRAM6565_n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM6565_n->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerRAM6555_n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM6555_n->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerRAM5555_n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5555_n->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerRAM5554_n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5554_n->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerRAM5454_n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5454_n->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerRAM5444_n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5444_n->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerRAM4444_n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM4444_n->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;

	sCIterTestHint = m_pContainerRAM6565_2n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM6565_2n->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerRAM6555_2n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM6555_2n->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerRAM5555_2n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5555_2n->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerRAM5554_2n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5554_2n->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerRAM5454_2n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5454_2n->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerRAM5444_2n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5444_2n->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerRAM4444_2n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM4444_2n->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerRAM6565_4n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM6565_4n->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerRAM6555_4n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM6555_4n->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerRAM5555_4n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5555_4n->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerRAM5554_4n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5554_4n->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerRAM5454_4n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5454_4n->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerRAM5444_4n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5444_4n->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerRAM4444_4n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM4444_4n->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;

	sCIterTestHint = m_pContainerFile6565min->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile6565min->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerFile6555min->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile6555min->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerFile5555min->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile5555min->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerFile5554min->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile5554min->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerFile5454min->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile5454min->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;

	sCIterTestHint = m_pContainerFile6565default->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile6565default->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerFile6555default->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile6555default->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerFile5555default->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile5555default->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerFile5554default->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile5554default->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerFile5454default->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile5454default->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;

	sCIterTestHint = m_pContainerFile6565large->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile6565large->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerFile6555large->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile6555large->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerFile5555large->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile5555large->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerFile5554large->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile5554large->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;
	sCIterTestHint = m_pContainerFile5454large->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile5454large->emplace_hint (sCIterTestHint, ::std::forward<_t_va_args> (rrArgs) ...); i++;

	BTREE_ASSERT (i == this->get_num_containers (), "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::emplace_hint<>: ERROR: Unexpected number of test containers!");

	this->test ();
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::key_compare CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::key_comp () const
{
	key_compare		sRetval;

	sRetval.m_pThis = (CBTreeMultiSetTestWrapper_t *) this;

	return (sRetval);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::value_compare CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::value_comp () const
{
	value_compare	sRetval;

	sRetval.m_pThis = (CBTreeMultiSetTestWrapper_t *) this;

	return (sRetval);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
bool CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::run_key_compare (const typename CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::key_type &rKey0, const typename CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::key_type &rKey1) const
{
	typename reference_t::key_compare	sRefComp = this->m_pReference->key_comp ();
	bool								bRefValue = sRefComp (rKey0, rKey1);
	uint32_t							i;

	for (i = 0; i < this->get_num_containers (); i++)
	{
		typename CBTreeAssociativeIf_t::key_compare		sTestComp = this->m_ppContainers[i]->key_comp ();
		bool											bTestValue = sTestComp (rKey0, rKey1);

		if (bRefValue != bTestValue)
		{
			::std::cerr << "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::run_key_compare: ERROR: comparison result mismatch!" << ::std::endl;

			exit (-1);
		}
	}

	return (bRefValue);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
bool CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::run_value_compare (const typename CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::value_type &rVal0, const typename CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::value_type &rVal1) const
{
	typename reference_t::value_compare	sRefComp = this->m_pReference->value_comp ();
	bool								bRefValue = sRefComp (rVal0, rVal1);
	uint32_t							i;

	for (i = 0; i < this->get_num_containers (); i++)
	{
		typename CBTreeAssociativeIf_t::value_compare	sTestComp = this->m_ppContainers[i]->value_comp ();
		bool											bTestValue = sTestComp (rVal0, rVal1);

		if (bRefValue != bTestValue)
		{
			::std::cerr << "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::run_value_compare: ERROR: comparison result mismatch!" << ::std::endl;

			exit (-1);
		}
	}

	return (bRefValue);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
void CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers (const uint32_t nNodeSize, const uint32_t nPageSize)
{
	CBTreeIOpropertiesRAM<size_test_type, uint64_t, uint32_t, uint64_t, uint32_t>		sRAMprop6565;
	CBTreeIOpropertiesRAM<size_test_type, uint64_t, uint32_t, uint32_t, uint32_t>		sRAMprop6555;
	CBTreeIOpropertiesRAM<size_test_type, uint32_t, uint32_t, uint32_t, uint32_t>		sRAMprop5555;
	CBTreeIOpropertiesRAM<size_test_type, uint32_t, uint32_t, uint32_t, uint16_t>		sRAMprop5554;
	CBTreeIOpropertiesRAM<size_test_type, uint32_t, uint16_t, uint32_t, uint16_t>		sRAMprop5454;
	CBTreeIOpropertiesRAM<size_test_type, uint32_t, uint16_t, uint16_t, uint16_t>		sRAMprop5444;
	CBTreeIOpropertiesRAM<size_test_type, uint16_t, uint16_t, uint16_t, uint16_t>		sRAMprop4444;
	CBTreeIOpropertiesFile<_t_sizetype, uint64_t, uint32_t, uint64_t, uint32_t>			sFilePropertiesMin6565 ("./", 1, nPageSize);
	CBTreeIOpropertiesFile<_t_sizetype, uint64_t, uint32_t, uint32_t, uint32_t>			sFilePropertiesMin6555 ("./", 1, nPageSize);
	CBTreeIOpropertiesFile<_t_sizetype, uint32_t, uint32_t, uint32_t, uint32_t>			sFilePropertiesMin5555 ("./", 1, 1);
	CBTreeIOpropertiesFile<_t_sizetype, uint32_t, uint32_t, uint32_t, uint16_t>			sFilePropertiesMin5554 ("./", 1, nPageSize * 2 / 3);
	CBTreeIOpropertiesFile<_t_sizetype, uint32_t, uint16_t, uint32_t, uint16_t>			sFilePropertiesMin5454 ("./", 1, nPageSize * 16);
	CBTreeIOpropertiesFile<_t_sizetype, uint64_t, uint32_t, uint64_t, uint32_t>			sFilePropertiesDefault6565 ("./", 1048576, nPageSize * 2 / 3);
	CBTreeIOpropertiesFile<_t_sizetype, uint64_t, uint32_t, uint32_t, uint32_t>			sFilePropertiesDefault6555 ("./", 1048576, nPageSize * 2 / 3);
	CBTreeIOpropertiesFile<_t_sizetype, uint32_t, uint32_t, uint32_t, uint32_t>			sFilePropertiesDefault5555 ("./", 1048576, nPageSize * 16);
	CBTreeIOpropertiesFile<_t_sizetype, uint32_t, uint32_t, uint32_t, uint16_t>			sFilePropertiesDefault5554 ("./", 1048576, nPageSize);
	CBTreeIOpropertiesFile<_t_sizetype, uint32_t, uint16_t, uint32_t, uint16_t>			sFilePropertiesDefault5454 ("./", 1048576, 1);
	CBTreeIOpropertiesFile<_t_sizetype, uint64_t, uint32_t, uint64_t, uint32_t>			sFilePropertiesLarge6565 ("./", 16777216, nPageSize);
	CBTreeIOpropertiesFile<_t_sizetype, uint64_t, uint32_t, uint32_t, uint32_t>			sFilePropertiesLarge6555 ("./", 16777216, nPageSize);
	CBTreeIOpropertiesFile<_t_sizetype, uint32_t, uint32_t, uint32_t, uint32_t>			sFilePropertiesLarge5555 ("./", 1048576, 1);
	CBTreeIOpropertiesFile<_t_sizetype, uint32_t, uint32_t, uint32_t, uint16_t>			sFilePropertiesLarge5554 ("./", 1048576, nPageSize * 2 / 3);
	CBTreeIOpropertiesFile<_t_sizetype, uint32_t, uint16_t, uint32_t, uint16_t>			sFilePropertiesLarge5454 ("./", 1048576, nPageSize * 16);
	uint32_t																			i = 0;

	m_pContainerRAM6565_n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (sRAMprop6565, nNodeSize, this->m_pReference);
	m_pContainerRAM6555_n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (sRAMprop6555, nNodeSize, this->m_pReference);
	m_pContainerRAM5555_n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (sRAMprop5555, nNodeSize, this->m_pReference);
	m_pContainerRAM5554_n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (sRAMprop5554, nNodeSize, this->m_pReference);
	m_pContainerRAM5454_n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (sRAMprop5454, nNodeSize, this->m_pReference);
	m_pContainerRAM5444_n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint16_t, uint16_t> > (sRAMprop5444, nNodeSize, this->m_pReference);
	m_pContainerRAM4444_n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint16_t, uint16_t, uint16_t, uint16_t> > (sRAMprop4444, nNodeSize, this->m_pReference);
	m_pContainerRAM6565_2n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (sRAMprop6565, nNodeSize * 2, this->m_pReference);
	m_pContainerRAM6555_2n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (sRAMprop6555, nNodeSize * 2, this->m_pReference);
	m_pContainerRAM5555_2n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (sRAMprop5555, nNodeSize * 2, this->m_pReference);
	m_pContainerRAM5554_2n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (sRAMprop5554, nNodeSize * 2, this->m_pReference);
	m_pContainerRAM5454_2n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (sRAMprop5454, nNodeSize * 2, this->m_pReference);
	m_pContainerRAM5444_2n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint16_t, uint16_t> > (sRAMprop5444, nNodeSize * 2, this->m_pReference);
	m_pContainerRAM4444_2n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint16_t, uint16_t, uint16_t, uint16_t> > (sRAMprop4444, nNodeSize * 2, this->m_pReference);
	m_pContainerRAM6565_4n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (sRAMprop6565, nNodeSize * 4, this->m_pReference);
	m_pContainerRAM6555_4n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (sRAMprop6555, nNodeSize * 4, this->m_pReference);
	m_pContainerRAM5555_4n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (sRAMprop5555, nNodeSize * 4, this->m_pReference);
	m_pContainerRAM5554_4n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (sRAMprop5554, nNodeSize * 4, this->m_pReference);
	m_pContainerRAM5454_4n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (sRAMprop5454, nNodeSize * 4, this->m_pReference);
	m_pContainerRAM5444_4n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint16_t, uint16_t> > (sRAMprop5444, nNodeSize * 4, this->m_pReference);
	m_pContainerRAM4444_4n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint16_t, uint16_t, uint16_t, uint16_t> > (sRAMprop4444, nNodeSize * 4, this->m_pReference);
	m_pContainerFile6565min = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (sFilePropertiesMin6565, nNodeSize * 4, this->m_pReference);
	m_pContainerFile6555min = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (sFilePropertiesMin6555, nNodeSize * 8, this->m_pReference);
	m_pContainerFile5555min = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (sFilePropertiesMin5555, nNodeSize * 7, this->m_pReference);
	m_pContainerFile5554min = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (sFilePropertiesMin5554, nNodeSize * 6, this->m_pReference);
	m_pContainerFile5454min = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (sFilePropertiesMin5454, nNodeSize * 5, this->m_pReference);

	m_pContainerFile6565default = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (sFilePropertiesDefault6565, nNodeSize * 3, this->m_pReference);
	m_pContainerFile6555default = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (sFilePropertiesDefault6555, nNodeSize * 2, this->m_pReference);
	m_pContainerFile5555default = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (sFilePropertiesDefault5555, nNodeSize, this->m_pReference);
	m_pContainerFile5554default = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (sFilePropertiesDefault5554, nNodeSize * 8, this->m_pReference);
	m_pContainerFile5454default = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (sFilePropertiesDefault5454, nNodeSize * 7, this->m_pReference);

	m_pContainerFile6565large = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (sFilePropertiesLarge6565, nNodeSize * 5, this->m_pReference);
	m_pContainerFile6555large = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (sFilePropertiesLarge6555, nNodeSize * 4, this->m_pReference);
	m_pContainerFile5555large = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (sFilePropertiesLarge5555, nNodeSize * 3, this->m_pReference);
	m_pContainerFile5554large = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (sFilePropertiesLarge5554, nNodeSize * 2, this->m_pReference);
	m_pContainerFile5454large = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (sFilePropertiesLarge5454, nNodeSize, this->m_pReference);

	BTREE_ASSERT (NULL != m_pContainerRAM6565_n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM6565_n)");
	BTREE_ASSERT (NULL != m_pContainerRAM6555_n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM6555_n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5555_n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5555_n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5554_n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5554_n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5454_n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5454_n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5444_n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5444_n)");
	BTREE_ASSERT (NULL != m_pContainerRAM4444_n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM4444_n)");
	BTREE_ASSERT (NULL != m_pContainerRAM6565_2n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM6565_2n)");
	BTREE_ASSERT (NULL != m_pContainerRAM6555_2n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM6555_2n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5555_2n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5555_2n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5554_2n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5554_2n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5454_2n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5454_2n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5444_2n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5444_2n)");
	BTREE_ASSERT (NULL != m_pContainerRAM4444_2n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM4444_2n)");
	BTREE_ASSERT (NULL != m_pContainerRAM6565_4n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM6565_4n)");
	BTREE_ASSERT (NULL != m_pContainerRAM6555_4n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM6555_4n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5555_4n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5555_4n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5554_4n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5554_4n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5454_4n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5454_4n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5444_4n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5444_4n)");
	BTREE_ASSERT (NULL != m_pContainerRAM4444_4n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM4444_4n)");
	BTREE_ASSERT (NULL != m_pContainerFile6565min, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile6565min)");
	BTREE_ASSERT (NULL != m_pContainerFile6555min, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile6555min)");
	BTREE_ASSERT (NULL != m_pContainerFile5555min, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile5555min)");
	BTREE_ASSERT (NULL != m_pContainerFile5554min, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile5554min)");
	BTREE_ASSERT (NULL != m_pContainerFile5454min, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile5454min)");

	BTREE_ASSERT (NULL != m_pContainerFile6565default, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile6565default)");
	BTREE_ASSERT (NULL != m_pContainerFile6555default, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile6555default)");
	BTREE_ASSERT (NULL != m_pContainerFile5555default, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile5555default)");
	BTREE_ASSERT (NULL != m_pContainerFile5554default, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile5554default)");
	BTREE_ASSERT (NULL != m_pContainerFile5454default, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile5454default)");

	BTREE_ASSERT (NULL != m_pContainerFile6565large, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile6565large)");
	BTREE_ASSERT (NULL != m_pContainerFile6555large, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile6555large)");
	BTREE_ASSERT (NULL != m_pContainerFile5555large, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile5555large)");
	BTREE_ASSERT (NULL != m_pContainerFile5554large, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile5554large)");
	BTREE_ASSERT (NULL != m_pContainerFile5454large, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile5454large)");
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
void CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers (const CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container> &rWrapper)
{
	uint32_t	i = 0;

	const CBTreeMultiSetTestWrapper_t		&rThisWrapper = dynamic_cast<const CBTreeMultiSetTestWrapper_t &> (rWrapper);

	m_pContainerRAM6565_n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (*rThisWrapper.m_pContainerRAM6565_n); i++;
	m_pContainerRAM6555_n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerRAM6555_n); i++;
	m_pContainerRAM5555_n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerRAM5555_n); i++;
	m_pContainerRAM5554_n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerRAM5554_n); i++;
	m_pContainerRAM5454_n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerRAM5454_n); i++;
	m_pContainerRAM5444_n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint16_t, uint16_t> > (*rThisWrapper.m_pContainerRAM5444_n); i++;
	m_pContainerRAM4444_n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint16_t, uint16_t, uint16_t, uint16_t> > (*rThisWrapper.m_pContainerRAM4444_n); i++;
	m_pContainerRAM6565_2n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (*rThisWrapper.m_pContainerRAM6565_2n); i++;
	m_pContainerRAM6555_2n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerRAM6555_2n); i++;
	m_pContainerRAM5555_2n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerRAM5555_2n); i++;
	m_pContainerRAM5554_2n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerRAM5554_2n); i++;
	m_pContainerRAM5454_2n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerRAM5454_2n); i++;
	m_pContainerRAM5444_2n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint16_t, uint16_t> > (*rThisWrapper.m_pContainerRAM5444_2n); i++;
	m_pContainerRAM4444_2n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint16_t, uint16_t, uint16_t, uint16_t> > (*rThisWrapper.m_pContainerRAM4444_2n); i++;
	m_pContainerRAM6565_4n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (*rThisWrapper.m_pContainerRAM6565_4n); i++;
	m_pContainerRAM6555_4n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerRAM6555_4n); i++;
	m_pContainerRAM5555_4n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerRAM5555_4n); i++;
	m_pContainerRAM5554_4n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerRAM5554_4n); i++;
	m_pContainerRAM5454_4n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerRAM5454_4n); i++;
	m_pContainerRAM5444_4n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint16_t, uint16_t> > (*rThisWrapper.m_pContainerRAM5444_4n); i++;
	m_pContainerRAM4444_4n = new CBTreeTestMultiSet<CBTreeIOpropertiesRAM <size_test_type, uint16_t, uint16_t, uint16_t, uint16_t> > (*rThisWrapper.m_pContainerRAM4444_4n); i++;
	m_pContainerFile6565min = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (*rThisWrapper.m_pContainerFile6565min); i++;
	m_pContainerFile6555min = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerFile6555min); i++;
	m_pContainerFile5555min = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerFile5555min); i++;
	m_pContainerFile5554min = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerFile5554min); i++;
	m_pContainerFile5454min = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerFile5454min); i++;

	m_pContainerFile6565default = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (*rThisWrapper.m_pContainerFile6565default); i++;
	m_pContainerFile6555default = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerFile6555default); i++;
	m_pContainerFile5555default = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerFile5555default); i++;
	m_pContainerFile5554default = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerFile5554default); i++;
	m_pContainerFile5454default = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerFile5454default); i++;

	m_pContainerFile6565large = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (*rThisWrapper.m_pContainerFile6565large); i++;
	m_pContainerFile6555large = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerFile6555large); i++;
	m_pContainerFile5555large = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerFile5555large); i++;
	m_pContainerFile5554large = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerFile5554large); i++;
	m_pContainerFile5454large = new CBTreeTestMultiSet<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerFile5454large); i++;

	BTREE_ASSERT (i == this->get_num_containers (), "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers (const CBTreeAssociativeTestWrapper &): ERROR: Unexpected number of test containers instantiated!");

	i = 0;

	BTREE_ASSERT (NULL != m_pContainerRAM6565_n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM6565_n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM6555_n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM6555_n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5555_n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5555_n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5554_n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5554_n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5454_n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5454_n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5444_n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5444_n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM4444_n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM4444_n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM6565_2n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM6565_2n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM6555_2n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM6555_2n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5555_2n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5555_2n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5554_2n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5554_2n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5454_2n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5454_2n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5444_2n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5444_2n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM4444_2n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM4444_2n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM6565_4n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM6565_4n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM6555_4n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM6555_4n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5555_4n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5555_4n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5554_4n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5554_4n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5454_4n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5454_4n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5444_4n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM5444_4n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM4444_4n, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerRAM4444_4n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile6565min, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile6565min)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile6555min, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile6555min)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile5555min, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile5555min)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile5554min, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile5554min)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile5454min, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile5454min)"); i++;

	BTREE_ASSERT (NULL != m_pContainerFile6565default, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile6565default)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile6555default, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile6555default)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile5555default, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile5555default)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile5554default, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile5554default)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile5454default, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile5454default)"); i++;

	BTREE_ASSERT (NULL != m_pContainerFile6565large, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile6565large)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile6555large, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile6555large)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile5555large, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile5555large)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile5554large, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile5554large)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile5454large, "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers: ERROR: insufficient memory! (m_pContainerFile5454large)"); i++;

	BTREE_ASSERT (i == this->get_num_containers (), "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers (const CBTreeAssociativeTestWrapper &): ERROR: Unexpected number of test containers checked to be instantiated successfully!");

	i = 0;

	m_pContainerRAM6565_n->set_reference (this->m_pReference); i++;
	m_pContainerRAM6555_n->set_reference (this->m_pReference); i++;
	m_pContainerRAM5555_n->set_reference (this->m_pReference); i++;
	m_pContainerRAM5554_n->set_reference (this->m_pReference); i++;
	m_pContainerRAM5454_n->set_reference (this->m_pReference); i++;
	m_pContainerRAM5444_n->set_reference (this->m_pReference); i++;
	m_pContainerRAM4444_n->set_reference (this->m_pReference); i++;
	m_pContainerRAM6565_2n->set_reference (this->m_pReference); i++;
	m_pContainerRAM6555_2n->set_reference (this->m_pReference); i++;
	m_pContainerRAM5555_2n->set_reference (this->m_pReference); i++;
	m_pContainerRAM5554_2n->set_reference (this->m_pReference); i++;
	m_pContainerRAM5454_2n->set_reference (this->m_pReference); i++;
	m_pContainerRAM5444_2n->set_reference (this->m_pReference); i++;
	m_pContainerRAM4444_2n->set_reference (this->m_pReference); i++;
	m_pContainerRAM6565_4n->set_reference (this->m_pReference); i++;
	m_pContainerRAM6555_4n->set_reference (this->m_pReference); i++;
	m_pContainerRAM5555_4n->set_reference (this->m_pReference); i++;
	m_pContainerRAM5554_4n->set_reference (this->m_pReference); i++;
	m_pContainerRAM5454_4n->set_reference (this->m_pReference); i++;
	m_pContainerRAM5444_4n->set_reference (this->m_pReference); i++;
	m_pContainerRAM4444_4n->set_reference (this->m_pReference); i++;
	m_pContainerFile6565min->set_reference (this->m_pReference); i++;
	m_pContainerFile6555min->set_reference (this->m_pReference); i++;
	m_pContainerFile5555min->set_reference (this->m_pReference); i++;
	m_pContainerFile5554min->set_reference (this->m_pReference); i++;
	m_pContainerFile5454min->set_reference (this->m_pReference); i++;

	m_pContainerFile6565default->set_reference (this->m_pReference); i++;
	m_pContainerFile6555default->set_reference (this->m_pReference); i++;
	m_pContainerFile5555default->set_reference (this->m_pReference); i++;
	m_pContainerFile5554default->set_reference (this->m_pReference); i++;
	m_pContainerFile5454default->set_reference (this->m_pReference); i++;

	m_pContainerFile6565large->set_reference (this->m_pReference); i++;
	m_pContainerFile6555large->set_reference (this->m_pReference); i++;
	m_pContainerFile5555large->set_reference (this->m_pReference); i++;
	m_pContainerFile5554large->set_reference (this->m_pReference); i++;
	m_pContainerFile5454large->set_reference (this->m_pReference); i++;

	BTREE_ASSERT (i == this->get_num_containers (), "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers (const CBTreeAssociativeTestWrapper &): ERROR: Unexpected number of test containers after setting reference container!");
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
void CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::transfer_containers ()
{
	uint32_t		i = 0;

	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerRAM6565_n); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerRAM6555_n); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerRAM5555_n); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerRAM5554_n); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerRAM5454_n); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerRAM5444_n); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerRAM4444_n); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerRAM6565_2n); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerRAM6555_2n); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerRAM5555_2n); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerRAM5554_2n); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerRAM5454_2n); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerRAM5444_2n); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerRAM4444_2n); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerRAM6565_4n); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerRAM6555_4n); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerRAM5555_4n); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerRAM5554_4n); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerRAM5454_4n); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerRAM5444_4n); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerRAM4444_4n); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerFile6565min); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerFile6555min); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerFile5555min); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerFile5554min); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerFile5454min); i++;

	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerFile6565default); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerFile6555default); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerFile5555default); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerFile5554default); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerFile5454default); i++;

	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerFile6565large); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerFile6555large); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerFile5555large); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerFile5554large); i++;
	this->m_ppContainers[i] = dynamic_cast<CBTreeAssociativeIf_t *> (m_pContainerFile5454large); i++;

	BTREE_ASSERT (i == this->get_num_containers (), "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::transfer_containers: ERROR: Unexpected number of test containers!");
}
	
template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
template<class _t_ext_container, class _t_source_container, class _t_ext_sizetype, class _t_ext_iterator>
void CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::test_one_container_insert (_t_ext_container *pExtOriginal, _t_ext_container *pExtReference, _t_ext_sizetype nPos, typename CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::size_test_type nFirst, typename CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::size_test_type nLast, _t_ext_iterator &rExtIter, bool bRefIterConst, bool bRefIterReverse, _t_source_container *pSrc) const
{
//#if defined (_MSC_VER)

	bRefIterConst;

//#else

//	if (bRefIterConst)
//	{
//#endif
		if (bRefIterReverse)
		{
			typename _t_source_container::const_reverse_iterator	sCRIter;

			test_one_container_insert (pExtOriginal, pExtReference, nPos, nFirst, nLast, rExtIter, sCRIter, pSrc);
		}
		else
		{
			typename _t_source_container::const_iterator			sCIter;

			test_one_container_insert (pExtOriginal, pExtReference, nPos, nFirst, nLast, rExtIter, sCIter, pSrc);
		}
/*
#if !defined (_MSC_VER)
	}
	else
	{
		if (bRefIterReverse)
		{
			typename _t_source_container::reverse_iterator			sRIter;

			test_one_container_insert (pExtOriginal, pExtReference, nPos, nFirst, nLast, rExtIter, sRIter, pSrc);
		}
		else
		{
			typename _t_source_container::iterator					sIter;

			test_one_container_insert (pExtOriginal, pExtReference, nPos, nFirst, nLast, rExtIter, sIter, pSrc);
		}
	}
#endif
*/
}
	
template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
template<class _t_ext_container, class _t_source_container, class _t_ext_sizetype, class _t_ext_iterator, class _t_iterator>
void CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::test_one_container_insert	(_t_ext_container *pExtOriginal, _t_ext_container *pExtReference, _t_ext_sizetype nPos, typename CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::size_test_type nFirst, typename CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::size_test_type nLast, _t_ext_iterator &rExtIter, _t_iterator &rIter, _t_source_container *pSrc) const
{
	_t_ext_container	sExtTest (*pExtOriginal);
	_t_iterator			sIterBegin;
	_t_iterator			sIterFirst;
	_t_iterator			sIterLast;
	_t_ext_iterator		sExtIter;
	_t_ext_iterator		sExtIterBegin;
	_t_ext_iterator		sExtIterRefBegin;
	_t_ext_iterator		sExtIterRefEnd;

	get_begin (pSrc, sIterBegin);
	get_begin (pSrc, sIterFirst);
	get_begin (pSrc, sIterLast);
	get_begin (&sExtTest, sExtIter);
	
	::std::advance (sIterFirst, nFirst);
	::std::advance (sIterLast, nLast);

	::std::advance (sExtIter, nPos);

	container_insert (&sExtTest, sExtIter, sIterFirst, sIterLast);

	if (sExtTest.size () != pExtReference->size ())
	{
		::std::cerr << "CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::test_one_container_insert: ERROR: size mismatch!" << ::std::endl << ::std::flush;

		exit (-1);
	}

	get_begin (&sExtTest, sExtIterBegin);
	get_begin (pExtReference, sExtIterRefBegin);
	get_end (pExtReference, sExtIterRefEnd);

	while (sExtIterRefBegin != sExtIterRefEnd)
	{
		value_type		sDataTest;
		value_type		sDataRef;

		entry_conversion (sDataTest, *sExtIterBegin);
		entry_conversion (sDataRef, *sExtIterRefBegin);

		if (is_entry_not_equal_to_entry (sDataTest, sDataRef))
		{
			::std::cerr << "CBTreeMapTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::test_one_container_insert: ERROR: data mismatch!" << ::std::endl << ::std::flush;

			exit (-1);
		}

		::std::advance (sExtIterBegin, 1);
		::std::advance (sExtIterRefBegin, 1);
	}

	pSrc->test ();
}
	
template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
const uint32_t CBTreeMultiSetTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::m_nNumContainersMS = 36;

#endif // BTREEMULTISETTESTWRAPPER_CPP

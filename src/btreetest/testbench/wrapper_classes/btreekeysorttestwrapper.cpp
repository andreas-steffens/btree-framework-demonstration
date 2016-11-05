/************************************************************
**
** file:	btreekeysorttestwrapper.cpp
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
** This file contains the definition of a key sort test class 
** wrapping accesses to a key sort application class instance and
** a reference container instance, while making sure the
** key sort instance acts the same way as the reference.
**
************************************************************/

#ifndef	BTREEKEYSORTTESTWRAPPER_CPP
#define	BTREEKEYSORTTESTWRAPPER_CPP

#include "testbench/wrapper_classes/btreekeysorttestwrapper.h"

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper (const uint32_t nNodeSize, const uint32_t nPageSize)
	:	CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container> (nNodeSize, nPageSize)
{
	this->m_nNumContainers = CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::m_nNumContainersKS;

	this->instantiate_container_array ();

	this->init_containers (this->m_nNodeSize, this->m_nPageSize);

	this->transfer_containers ();
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper (const CBTreeKeySortTestWrapper &rContainer)
	:	CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container> (rContainer)
{
	this->m_nNumContainers = CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::m_nNumContainersKS;

	this->instantiate_container_array ();

	this->init_containers (rContainer);

	this->transfer_containers ();

	this->test ();
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::~CBTreeKeySortTestWrapper ()
{
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
template<class _t_iterator>
void CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::insert (_t_iterator sIterFirst, _t_iterator sIterLast)
{
	uint32_t		i = 0;

	this->m_pReference->insert (sIterFirst, sIterLast);

	m_pContainerRAM6565_n->insert (sIterFirst, sIterLast); i++;
	m_pContainerRAM6555_n->insert (sIterFirst, sIterLast); i++;
	m_pContainerRAM5555_n->insert (sIterFirst, sIterLast); i++;
	m_pContainerRAM5554_n->insert (sIterFirst, sIterLast); i++;
	m_pContainerRAM5454_n->insert (sIterFirst, sIterLast); i++;
	m_pContainerRAM5444_n->insert (sIterFirst, sIterLast); i++;
	m_pContainerRAM4444_n->insert (sIterFirst, sIterLast); i++;
	m_pContainerRAM6565_2n->insert (sIterFirst, sIterLast); i++;
	m_pContainerRAM6555_2n->insert (sIterFirst, sIterLast); i++;
	m_pContainerRAM5555_2n->insert (sIterFirst, sIterLast); i++;
	m_pContainerRAM5554_2n->insert (sIterFirst, sIterLast); i++;
	m_pContainerRAM5454_2n->insert (sIterFirst, sIterLast); i++;
	m_pContainerRAM5444_2n->insert (sIterFirst, sIterLast); i++;
	m_pContainerRAM4444_2n->insert (sIterFirst, sIterLast); i++;
	m_pContainerRAM6565_4n->insert (sIterFirst, sIterLast); i++;
	m_pContainerRAM6555_4n->insert (sIterFirst, sIterLast); i++;
	m_pContainerRAM5555_4n->insert (sIterFirst, sIterLast); i++;
	m_pContainerRAM5554_4n->insert (sIterFirst, sIterLast); i++;
	m_pContainerRAM5454_4n->insert (sIterFirst, sIterLast); i++;
	m_pContainerRAM5444_4n->insert (sIterFirst, sIterLast); i++;
	m_pContainerRAM4444_4n->insert (sIterFirst, sIterLast); i++;
	m_pContainerFile6565min->insert (sIterFirst, sIterLast); i++;
	m_pContainerFile6555min->insert (sIterFirst, sIterLast); i++;
	m_pContainerFile5555min->insert (sIterFirst, sIterLast); i++;
	m_pContainerFile5554min->insert (sIterFirst, sIterLast); i++;
	m_pContainerFile5454min->insert (sIterFirst, sIterLast); i++;

	m_pContainerFile6565default->insert (sIterFirst, sIterLast); i++;
	m_pContainerFile6555default->insert (sIterFirst, sIterLast); i++;
	m_pContainerFile5555default->insert (sIterFirst, sIterLast); i++;
	m_pContainerFile5554default->insert (sIterFirst, sIterLast); i++;
	m_pContainerFile5454default->insert (sIterFirst, sIterLast); i++;

	m_pContainerFile6565large->insert (sIterFirst, sIterLast); i++;
	m_pContainerFile6555large->insert (sIterFirst, sIterLast); i++;
	m_pContainerFile5555large->insert (sIterFirst, sIterLast); i++;
	m_pContainerFile5554large->insert (sIterFirst, sIterLast); i++;
	m_pContainerFile5454large->insert (sIterFirst, sIterLast); i++;

	BTREE_ASSERT (i == this->get_num_containers (), "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::insert<_t_iterator>: ERROR: Unexpected number of test containers!");

	this->test ();
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::iterator CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::insert (const typename CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::value_type &rData)
{
	return (CBTreeAssociativeTestWrapper_t::insert (rData));
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
void CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::insert_hint
	(
		const typename CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::value_type &rData
	)
{
	CBTreeAssociativeTestWrapper_t::insert_hint (rData);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
template<class _t_iterator, class _t_test_iterator>
void CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::insert_self_reference (_t_iterator sIterFirst, _t_iterator sIterLast, _t_test_iterator &rIterTest)
{
	uint32_t			i = 0;
	_t_iterator			sIterBegin;
	size_test_type		nFirst;
	size_test_type		nLast;
	reference_t			sTempContainer;
	_t_test_iterator	sIterTestFirst;
	_t_test_iterator	sIterTestLast;

	get_begin (this->m_pReference, sIterBegin);
	nFirst = (size_test_type) ::std::distance (sIterBegin, sIterFirst);
	nLast = (size_test_type) ::std::distance (sIterBegin, sIterLast);

	sTempContainer.insert (sIterFirst, sIterLast);

	this->m_pReference->insert (sTempContainer.cbegin (), sTempContainer.cend ());

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

	BTREE_ASSERT (i == this->get_num_containers (), "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::insert<_t_iterator>: ERROR: Unexpected number of test containers!");

	this->test ();
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
void CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers (const uint32_t nNodeSize, const uint32_t nPageSize)
{
	CBTreeIOpropertiesRAM<size_test_type, uint64_t, uint32_t, uint64_t, uint32_t>		sRAMprop6565;
	CBTreeIOpropertiesRAM<size_test_type, uint64_t, uint32_t, uint32_t, uint32_t>		sRAMprop6555;
	CBTreeIOpropertiesRAM<size_test_type, uint32_t, uint32_t, uint32_t, uint32_t>		sRAMprop5555;
	CBTreeIOpropertiesRAM<size_test_type, uint32_t, uint32_t, uint32_t, uint16_t>		sRAMprop5554;
	CBTreeIOpropertiesRAM<size_test_type, uint32_t, uint16_t, uint32_t, uint16_t>		sRAMprop5454;
	CBTreeIOpropertiesRAM<size_test_type, uint32_t, uint16_t, uint16_t, uint16_t>		sRAMprop5444;
	CBTreeIOpropertiesRAM<size_test_type, uint16_t, uint16_t, uint16_t, uint16_t>		sRAMprop4444;
	CBTreeIOpropertiesFile<_t_sizetype, uint64_t, uint32_t, uint64_t, uint32_t>		sFilePropertiesMin6565 ("./", 1, nPageSize);
	CBTreeIOpropertiesFile<_t_sizetype, uint64_t, uint32_t, uint32_t, uint32_t>		sFilePropertiesMin6555 ("./", 1, nPageSize);
	CBTreeIOpropertiesFile<_t_sizetype, uint32_t, uint32_t, uint32_t, uint32_t>		sFilePropertiesMin5555 ("./", 1, 1);
	CBTreeIOpropertiesFile<_t_sizetype, uint32_t, uint32_t, uint32_t, uint16_t>		sFilePropertiesMin5554 ("./", 1, nPageSize * 2 / 3);
	CBTreeIOpropertiesFile<_t_sizetype, uint32_t, uint16_t, uint32_t, uint16_t>		sFilePropertiesMin5454 ("./", 1, nPageSize * 16);
	CBTreeIOpropertiesFile<_t_sizetype, uint64_t, uint32_t, uint64_t, uint32_t>		sFilePropertiesDefault6565 ("./", 1048576, nPageSize * 2 / 3);
	CBTreeIOpropertiesFile<_t_sizetype, uint64_t, uint32_t, uint32_t, uint32_t>		sFilePropertiesDefault6555 ("./", 1048576, nPageSize * 2 / 3);
	CBTreeIOpropertiesFile<_t_sizetype, uint32_t, uint32_t, uint32_t, uint32_t>		sFilePropertiesDefault5555 ("./", 1048576, nPageSize * 16);
	CBTreeIOpropertiesFile<_t_sizetype, uint32_t, uint32_t, uint32_t, uint16_t>		sFilePropertiesDefault5554 ("./", 1048576, nPageSize);
	CBTreeIOpropertiesFile<_t_sizetype, uint32_t, uint16_t, uint32_t, uint16_t>		sFilePropertiesDefault5454 ("./", 1048576, 1);
	CBTreeIOpropertiesFile<_t_sizetype, uint64_t, uint32_t, uint64_t, uint32_t>		sFilePropertiesLarge6565 ("./", 16777216, nPageSize);
	CBTreeIOpropertiesFile<_t_sizetype, uint64_t, uint32_t, uint32_t, uint32_t>		sFilePropertiesLarge6555 ("./", 16777216, nPageSize);
	CBTreeIOpropertiesFile<_t_sizetype, uint32_t, uint32_t, uint32_t, uint32_t>		sFilePropertiesLarge5555 ("./", 1048576, 1);
	CBTreeIOpropertiesFile<_t_sizetype, uint32_t, uint32_t, uint32_t, uint16_t>		sFilePropertiesLarge5554 ("./", 1048576, nPageSize * 2 / 3);
	CBTreeIOpropertiesFile<_t_sizetype, uint32_t, uint16_t, uint32_t, uint16_t>		sFilePropertiesLarge5454 ("./", 1048576, nPageSize * 16);
//	btree_cache_description_t															sCacheDescPageSize = {nPageSize};
//	btree_cache_description_t															sCacheDescMin = {1};
//	btree_cache_description_t															sCacheDescNearestBigger = {nPageSize * 2 / 3};
//	btree_cache_description_t															sCacheDescLarge = {nPageSize * 16};
	uint32_t																			i = 0;

	m_pContainerRAM6565_n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (sRAMprop6565, nNodeSize, this->m_pReference);
	m_pContainerRAM6555_n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (sRAMprop6555, nNodeSize, this->m_pReference);
	m_pContainerRAM5555_n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (sRAMprop5555, nNodeSize, this->m_pReference);
	m_pContainerRAM5554_n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (sRAMprop5554, nNodeSize, this->m_pReference);
	m_pContainerRAM5454_n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (sRAMprop5454, nNodeSize, this->m_pReference);
	m_pContainerRAM5444_n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint16_t, uint16_t> > (sRAMprop5444, nNodeSize, this->m_pReference);
	m_pContainerRAM4444_n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint16_t, uint16_t, uint16_t, uint16_t> > (sRAMprop4444, nNodeSize, this->m_pReference);
	m_pContainerRAM6565_2n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (sRAMprop6565, nNodeSize * 2, this->m_pReference);
	m_pContainerRAM6555_2n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (sRAMprop6555, nNodeSize * 2, this->m_pReference);
	m_pContainerRAM5555_2n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (sRAMprop5555, nNodeSize * 2, this->m_pReference);
	m_pContainerRAM5554_2n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (sRAMprop5554, nNodeSize * 2, this->m_pReference);
	m_pContainerRAM5454_2n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (sRAMprop5454, nNodeSize * 2, this->m_pReference);
	m_pContainerRAM5444_2n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint16_t, uint16_t> > (sRAMprop5444, nNodeSize * 2, this->m_pReference);
	m_pContainerRAM4444_2n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint16_t, uint16_t, uint16_t, uint16_t> > (sRAMprop4444, nNodeSize * 2, this->m_pReference);
	m_pContainerRAM6565_4n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (sRAMprop6565, nNodeSize * 4, this->m_pReference);
	m_pContainerRAM6555_4n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (sRAMprop6555, nNodeSize * 4, this->m_pReference);
	m_pContainerRAM5555_4n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (sRAMprop5555, nNodeSize * 4, this->m_pReference);
	m_pContainerRAM5554_4n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (sRAMprop5554, nNodeSize * 4, this->m_pReference);
	m_pContainerRAM5454_4n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (sRAMprop5454, nNodeSize * 4, this->m_pReference);
	m_pContainerRAM5444_4n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint16_t, uint16_t> > (sRAMprop5444, nNodeSize * 4, this->m_pReference);
	m_pContainerRAM4444_4n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint16_t, uint16_t, uint16_t, uint16_t> > (sRAMprop4444, nNodeSize * 4, this->m_pReference);
	m_pContainerFile6565min = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (sFilePropertiesMin6565, nNodeSize * 4, this->m_pReference);
	m_pContainerFile6555min = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (sFilePropertiesMin6555, nNodeSize * 8, this->m_pReference);
	m_pContainerFile5555min = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (sFilePropertiesMin5555, nNodeSize * 7, this->m_pReference);
	m_pContainerFile5554min = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (sFilePropertiesMin5554, nNodeSize * 6, this->m_pReference);
	m_pContainerFile5454min = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (sFilePropertiesMin5454, nNodeSize * 5, this->m_pReference);

	m_pContainerFile6565default = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (sFilePropertiesDefault6565, nNodeSize * 3, this->m_pReference);
	m_pContainerFile6555default = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (sFilePropertiesDefault6555, nNodeSize * 2, this->m_pReference);
	m_pContainerFile5555default = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (sFilePropertiesDefault5555, nNodeSize, this->m_pReference);
	m_pContainerFile5554default = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (sFilePropertiesDefault5554, nNodeSize * 8, this->m_pReference);
	m_pContainerFile5454default = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (sFilePropertiesDefault5454, nNodeSize * 7, this->m_pReference);

	m_pContainerFile6565large = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (sFilePropertiesLarge6565, nNodeSize * 5, this->m_pReference);
	m_pContainerFile6555large = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (sFilePropertiesLarge6555, nNodeSize * 4, this->m_pReference);
	m_pContainerFile5555large = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (sFilePropertiesLarge5555, nNodeSize * 3, this->m_pReference);
	m_pContainerFile5554large = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (sFilePropertiesLarge5554, nNodeSize * 2, this->m_pReference);
	m_pContainerFile5454large = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (sFilePropertiesLarge5454, nNodeSize, this->m_pReference);

	BTREE_ASSERT (NULL != m_pContainerRAM6565_n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM6565_n)");
	BTREE_ASSERT (NULL != m_pContainerRAM6555_n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM6555_n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5555_n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5555_n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5554_n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5554_n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5454_n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5454_n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5444_n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5444_n)");
	BTREE_ASSERT (NULL != m_pContainerRAM4444_n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM4444_n)");
	BTREE_ASSERT (NULL != m_pContainerRAM6565_2n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM6565_2n)");
	BTREE_ASSERT (NULL != m_pContainerRAM6555_2n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM6555_2n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5555_2n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5555_2n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5554_2n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5554_2n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5454_2n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5454_2n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5444_2n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5444_2n)");
	BTREE_ASSERT (NULL != m_pContainerRAM4444_2n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM4444_2n)");
	BTREE_ASSERT (NULL != m_pContainerRAM6565_4n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM6565_4n)");
	BTREE_ASSERT (NULL != m_pContainerRAM6555_4n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM6555_4n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5555_4n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5555_4n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5554_4n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5554_4n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5454_4n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5454_4n)");
	BTREE_ASSERT (NULL != m_pContainerRAM5444_4n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5444_4n)");
	BTREE_ASSERT (NULL != m_pContainerRAM4444_4n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM4444_4n)");
	BTREE_ASSERT (NULL != m_pContainerFile6565min, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile6565min)");
	BTREE_ASSERT (NULL != m_pContainerFile6555min, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile6555min)");
	BTREE_ASSERT (NULL != m_pContainerFile5555min, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile5555min)");
	BTREE_ASSERT (NULL != m_pContainerFile5554min, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile5554min)");
	BTREE_ASSERT (NULL != m_pContainerFile5454min, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile5454min)");

	BTREE_ASSERT (NULL != m_pContainerFile6565default, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile6565default)");
	BTREE_ASSERT (NULL != m_pContainerFile6555default, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile6555default)");
	BTREE_ASSERT (NULL != m_pContainerFile5555default, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile5555default)");
	BTREE_ASSERT (NULL != m_pContainerFile5554default, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile5554default)");
	BTREE_ASSERT (NULL != m_pContainerFile5454default, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile5454default)");

	BTREE_ASSERT (NULL != m_pContainerFile6565large, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile6565large)");
	BTREE_ASSERT (NULL != m_pContainerFile6555large, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile6555large)");
	BTREE_ASSERT (NULL != m_pContainerFile5555large, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile5555large)");
	BTREE_ASSERT (NULL != m_pContainerFile5554large, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile5554large)");
	BTREE_ASSERT (NULL != m_pContainerFile5454large, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile5454large)");
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
void CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_containers (const CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container> &rWrapper)
{
	uint32_t	i = 0;

	const CBTreeKeySortTestWrapper_t		&rThisWrapper = dynamic_cast<const CBTreeKeySortTestWrapper_t &> (rWrapper);

	m_pContainerRAM6565_n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (*rThisWrapper.m_pContainerRAM6565_n); i++;
	m_pContainerRAM6555_n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerRAM6555_n); i++;
	m_pContainerRAM5555_n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerRAM5555_n); i++;
	m_pContainerRAM5554_n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerRAM5554_n); i++;
	m_pContainerRAM5454_n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerRAM5454_n); i++;
	m_pContainerRAM5444_n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint16_t, uint16_t> > (*rThisWrapper.m_pContainerRAM5444_n); i++;
	m_pContainerRAM4444_n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint16_t, uint16_t, uint16_t, uint16_t> > (*rThisWrapper.m_pContainerRAM4444_n); i++;
	m_pContainerRAM6565_2n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (*rThisWrapper.m_pContainerRAM6565_2n); i++;
	m_pContainerRAM6555_2n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerRAM6555_2n); i++;
	m_pContainerRAM5555_2n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerRAM5555_2n); i++;
	m_pContainerRAM5554_2n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerRAM5554_2n); i++;
	m_pContainerRAM5454_2n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerRAM5454_2n); i++;
	m_pContainerRAM5444_2n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint16_t, uint16_t> > (*rThisWrapper.m_pContainerRAM5444_2n); i++;
	m_pContainerRAM4444_2n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint16_t, uint16_t, uint16_t, uint16_t> > (*rThisWrapper.m_pContainerRAM4444_2n); i++;
	m_pContainerRAM6565_4n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (*rThisWrapper.m_pContainerRAM6565_4n); i++;
	m_pContainerRAM6555_4n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerRAM6555_4n); i++;
	m_pContainerRAM5555_4n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerRAM5555_4n); i++;
	m_pContainerRAM5554_4n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerRAM5554_4n); i++;
	m_pContainerRAM5454_4n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerRAM5454_4n); i++;
	m_pContainerRAM5444_4n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint16_t, uint16_t> > (*rThisWrapper.m_pContainerRAM5444_4n); i++;
	m_pContainerRAM4444_4n = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesRAM <size_test_type, uint16_t, uint16_t, uint16_t, uint16_t> > (*rThisWrapper.m_pContainerRAM4444_4n); i++;
	m_pContainerFile6565min = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (*rThisWrapper.m_pContainerFile6565min); i++;
	m_pContainerFile6555min = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerFile6555min); i++;
	m_pContainerFile5555min = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerFile5555min); i++;
	m_pContainerFile5554min = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerFile5554min); i++;
	m_pContainerFile5454min = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerFile5454min); i++;

	m_pContainerFile6565default = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (*rThisWrapper.m_pContainerFile6565default); i++;
	m_pContainerFile6555default = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerFile6555default); i++;
	m_pContainerFile5555default = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerFile5555default); i++;
	m_pContainerFile5554default = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerFile5554default); i++;
	m_pContainerFile5454default = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerFile5454default); i++;

	m_pContainerFile6565large = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> > (*rThisWrapper.m_pContainerFile6565large); i++;
	m_pContainerFile6555large = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerFile6555large); i++;
	m_pContainerFile5555large = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> > (*rThisWrapper.m_pContainerFile5555large); i++;
	m_pContainerFile5554large = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerFile5554large); i++;
	m_pContainerFile5454large = new CBTreeKeySortTest<value_test_type, uint32_t, CBTreeIOpropertiesFile <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> > (*rThisWrapper.m_pContainerFile5454large); i++;

	BTREE_ASSERT (i == this->get_num_containers (), "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_container (const CBTreeAssociativeTestWrapper &): ERROR: Unexpected number of test containers instantiated!");

	i = 0;

	BTREE_ASSERT (NULL != m_pContainerRAM6565_n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM6565_n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM6555_n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM6555_n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5555_n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5555_n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5554_n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5554_n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5454_n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5454_n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5444_n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5444_n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM4444_n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM4444_n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM6565_2n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM6565_2n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM6555_2n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM6555_2n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5555_2n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5555_2n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5554_2n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5554_2n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5454_2n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5454_2n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5444_2n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5444_2n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM4444_2n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM4444_2n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM6565_4n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM6565_4n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM6555_4n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM6555_4n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5555_4n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5555_4n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5554_4n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5554_4n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5454_4n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5454_4n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM5444_4n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM5444_4n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerRAM4444_4n, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerRAM4444_4n)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile6565min, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile6565min)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile6555min, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile6555min)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile5555min, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile5555min)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile5554min, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile5554min)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile5454min, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile5454min)"); i++;

	BTREE_ASSERT (NULL != m_pContainerFile6565default, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile6565default)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile6555default, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile6555default)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile5555default, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile5555default)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile5554default, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile5554default)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile5454default, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile5454default)"); i++;

	BTREE_ASSERT (NULL != m_pContainerFile6565large, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile6565large)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile6555large, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile6555large)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile5555large, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile5555large)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile5554large, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile5554large)"); i++;
	BTREE_ASSERT (NULL != m_pContainerFile5454large, "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeKeySortTestWrapper: ERROR: insufficient memory! (m_pContainerFile5454large)"); i++;

	BTREE_ASSERT (i == this->get_num_containers (), "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_container (const CBTreeAssociativeTestWrapper &): ERROR: Unexpected number of test containers checked to be instantiated successfully!");

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

	BTREE_ASSERT (i == this->get_num_containers (), "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::init_container (const CBTreeAssociativeTestWrapper &): ERROR: Unexpected number of test containers after setting reference container!");
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
void CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::transfer_containers ()
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

	BTREE_ASSERT (i == this->get_num_containers (), "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeMapTestWrapper: ERROR: Unexpected number of test containers!");
}
	
template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
void CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::emplace (const typename CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::value_type &rData)
{
	uint32_t								i = 0;
	typename _t_ref_container::value_type	sRefData;
	uint32_t								nKey;
	uint32_t								nData;
	uint32_t								nDebug;

	entry_conversion (sRefData, rData);

	this->m_pReference->emplace (sRefData);

	nKey = get_entry_key (rData);
	nData = get_entry_data (rData);
	nDebug = get_entry_debug (rData);

	m_pContainerRAM6565_n->emplace (nKey, nData, nDebug); i++;
	m_pContainerRAM6555_n->emplace (nKey, nData, nDebug); i++;
	m_pContainerRAM5555_n->emplace (nKey, nData, nDebug); i++;
	m_pContainerRAM5554_n->emplace (nKey, nData, nDebug); i++;
	m_pContainerRAM5454_n->emplace (nKey, nData, nDebug); i++;
	m_pContainerRAM5444_n->emplace (nKey, nData, nDebug); i++;
	m_pContainerRAM4444_n->emplace (nKey, nData, nDebug); i++;
	m_pContainerRAM6565_2n->emplace (nKey, nData, nDebug); i++;
	m_pContainerRAM6555_2n->emplace (nKey, nData, nDebug); i++;
	m_pContainerRAM5555_2n->emplace (nKey, nData, nDebug); i++;
	m_pContainerRAM5554_2n->emplace (nKey, nData, nDebug); i++;
	m_pContainerRAM5454_2n->emplace (nKey, nData, nDebug); i++;
	m_pContainerRAM5444_2n->emplace (nKey, nData, nDebug); i++;
	m_pContainerRAM4444_2n->emplace (nKey, nData, nDebug); i++;
	m_pContainerRAM6565_4n->emplace (nKey, nData, nDebug); i++;
	m_pContainerRAM6555_4n->emplace (nKey, nData, nDebug); i++;
	m_pContainerRAM5555_4n->emplace (nKey, nData, nDebug); i++;
	m_pContainerRAM5554_4n->emplace (nKey, nData, nDebug); i++;
	m_pContainerRAM5454_4n->emplace (nKey, nData, nDebug); i++;
	m_pContainerRAM5444_4n->emplace (nKey, nData, nDebug); i++;
	m_pContainerRAM4444_4n->emplace (nKey, nData, nDebug); i++;
	m_pContainerFile6565min->emplace (nKey, nData, nDebug); i++;
	m_pContainerFile6555min->emplace (nKey, nData, nDebug); i++;
	m_pContainerFile5555min->emplace (nKey, nData, nDebug); i++;
	m_pContainerFile5554min->emplace (nKey, nData, nDebug); i++;
	m_pContainerFile5454min->emplace (nKey, nData, nDebug); i++;

	m_pContainerFile6565default->emplace (nKey, nData, nDebug); i++;
	m_pContainerFile6555default->emplace (nKey, nData, nDebug); i++;
	m_pContainerFile5555default->emplace (nKey, nData, nDebug); i++;
	m_pContainerFile5554default->emplace (nKey, nData, nDebug); i++;
	m_pContainerFile5454default->emplace (nKey, nData, nDebug); i++;

	m_pContainerFile6565large->emplace (nKey, nData, nDebug); i++;
	m_pContainerFile6555large->emplace (nKey, nData, nDebug); i++;
	m_pContainerFile5555large->emplace (nKey, nData, nDebug); i++;
	m_pContainerFile5554large->emplace (nKey, nData, nDebug); i++;
	m_pContainerFile5454large->emplace (nKey, nData, nDebug); i++;

	BTREE_ASSERT (i == this->get_num_containers (), "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::emplace<>: ERROR: Unexpected number of test containers!");

	this->test ();	
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
void CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::emplace_hint (const typename CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::value_type &rData)
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
	uint32_t								nKey;
	uint32_t								nData;
	uint32_t								nDebug;

	entry_conversion (sRefData, rData);

	sIterHint = this->m_pReference->emplace (sRefData);

	nKey = get_entry_key (rData);
	nData = get_entry_data (rData);
	nDebug = get_entry_debug (rData);

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
	
	sCIterTestHint = m_pContainerRAM6565_n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM6565_n->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerRAM6555_n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM6555_n->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerRAM5555_n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5555_n->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerRAM5554_n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5554_n->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerRAM5454_n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5454_n->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerRAM5444_n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5444_n->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerRAM4444_n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM4444_n->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;

	sCIterTestHint = m_pContainerRAM6565_2n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM6565_2n->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerRAM6555_2n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM6555_2n->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerRAM5555_2n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5555_2n->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerRAM5554_2n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5554_2n->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerRAM5454_2n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5454_2n->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerRAM5444_2n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5444_2n->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerRAM4444_2n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM4444_2n->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerRAM6565_4n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM6565_4n->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerRAM6555_4n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM6555_4n->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerRAM5555_4n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5555_4n->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerRAM5554_4n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5554_4n->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerRAM5454_4n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5454_4n->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerRAM5444_4n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM5444_4n->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerRAM4444_4n->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerRAM4444_4n->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;

	sCIterTestHint = m_pContainerFile6565min->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile6565min->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerFile6555min->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile6555min->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerFile5555min->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile5555min->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerFile5554min->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile5554min->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerFile5454min->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile5454min->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;

	sCIterTestHint = m_pContainerFile6565default->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile6565default->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerFile6555default->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile6555default->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerFile5555default->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile5555default->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerFile5554default->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile5554default->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerFile5454default->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile5454default->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;

	sCIterTestHint = m_pContainerFile6565large->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile6565large->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerFile6555large->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile6555large->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerFile5555large->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile5555large->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerFile5554large->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile5554large->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;
	sCIterTestHint = m_pContainerFile5454large->cbegin (); ::std::advance (sCIterTestHint, nDist); sCIterTestHint.sync (); m_pContainerFile5454large->emplace_hint (sCIterTestHint, nKey, nData, nDebug); i++;

	BTREE_ASSERT (i == this->get_num_containers (), "CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::emplace_hint<>: ERROR: Unexpected number of test containers!");

	this->test ();
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
const uint32_t CBTreeKeySortTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::m_nNumContainersKS = 36;

#endif // BTREEKEYSORTTESTWRAPPER_CPP

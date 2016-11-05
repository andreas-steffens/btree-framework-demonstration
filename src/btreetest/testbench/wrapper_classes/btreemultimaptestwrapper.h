/************************************************************
**
** file:	btreemultimaptestwrapper.h
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
** This file contains the declaration of a multi map test class 
** wrapping accesses to a multi map application class instance and
** a reference container instance, while making sure the
** multi map instance acts the same way as the reference.
**
************************************************************/

#ifndef BTREEMULTIMAPTESTWRAPPER_H
#define BTREEMULTIMAPTESTWRAPPER_H

#include <stdint.h>

#include "btreeiofile.h"
#include "btreeioram.h"

#include "btreearray.h"
#include "testbench/application_classes/regression/btreetestmultimap.h"

#include "testbench/wrapper_classes/base/btreeassociativetestwrapper.h"

#include "testbench/primitives/btreemultimapprimitives.h"

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
class CBTreeMultiMapTestWrapper	:	public CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>
{
public:

	typedef CBTreeMultiMapTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>
																CBTreeMultiMapTestWrapper_t;

	typedef CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>
																CBTreeAssociativeTestWrapper_t;

	typedef _t_ref_container									reference_t;

	typedef typename reference_t::iterator						iterator;
	typedef typename reference_t::const_iterator				const_iterator;
	typedef typename reference_t::reverse_iterator				reverse_iterator;
	typedef typename reference_t::const_reverse_iterator		const_reverse_iterator;

	typedef typename reference_t::value_type					value_type;
	typedef typename reference_t::key_type						key_type;
	typedef typename reference_t::size_type						size_type;

	typedef typename ::std::make_signed<size_type>::type		signed_size_type;

	typedef _t_data												value_test_type;
	typedef uint32_t											key_test_type;
	typedef _t_sizetype											size_test_type;

	typedef CBTreeAssociativeIf<_t_value, key_test_type, size_test_type>
																CBTreeAssociativeIf_t;

	typedef typename CBTreeAssociativeIf_t::iterator			test_iterator;

	typedef typename CBTreeAssociativeIf_t::const_iterator		test_const_iterator;

	typedef typename CBTreeAssociativeIf_t::reverse_iterator	test_reverse_iterator;

	typedef typename CBTreeAssociativeIf_t::const_reverse_iterator
																test_const_reverse_iterator;

	template<class _ti_keytype>
	struct key_compare_s
	{
		bool operator()(const _ti_keytype& rKey0, const _ti_keytype& rKey1) const
		{	
			return (m_pThis->run_key_compare (rKey0, rKey1));
		}

		CBTreeMultiMapTestWrapper_t		*m_pThis;
	};

	template<class _t_valuetype>
	struct value_compare_s
	{
		bool operator()(const _t_valuetype& rVal0, const _t_valuetype& rVal1) const
		{	
			const value_test_type	sValTestPair0 (rVal0);
			const value_test_type	sValTestPair1 (rVal1);

			return (m_pThis->run_value_compare (sValTestPair0, sValTestPair1));
		}

		CBTreeMultiMapTestWrapper_t		*m_pThis;
	};

	typedef	struct key_compare_s<key_type>				key_compare;
	typedef struct value_compare_s<value_type>			value_compare;

							CBTreeMultiMapTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>
																(const uint32_t nNodeSize, const uint32_t nPageSize);

							CBTreeMultiMapTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>
																(const CBTreeMultiMapTestWrapper &rContainer);

							~CBTreeMultiMapTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>
																();

	template<class _t_iterator>
	void					insert								(_t_iterator sIterFirst, _t_iterator sIterLast);

	template<class _t_iterator, class _t_dummy_iterator>
	void					insert								(_t_dummy_iterator &rIterDummy, _t_iterator sIterFirst, _t_iterator sIterLast);
	
	iterator				insert								(const value_type &rData);

	void					insert_hint							(const value_type &rData);
	
	template<class _t_iterator, class _t_test_iterator>
	void					insert_self_reference				(_t_iterator sIterFirst, _t_iterator sIterLast, _t_test_iterator &rIterTest);

	template<class _t_ext_container, class _t_ext_iterator, class _t_ref_iterator>
	void					test_all_containers_insert			(_t_ext_container *pExtContainer, _t_ext_iterator &rExtPos, _t_ref_iterator &rIterBegin, _t_ref_iterator &rIterFirst, _t_ref_iterator &rIterLast) const;

	template<class ..._t_va_args>
	void					emplace								(_t_va_args && ... rrArgs);
	
	template<class ..._t_va_args>
	void					emplace_hint						(_t_va_args && ... rrArgs);

	key_compare				key_comp							() const;
	value_compare			value_comp							() const;

	bool					run_key_compare						(const key_type &rKey0, const key_type &rKey1) const;
	bool					run_value_compare					(const value_type &rKey0, const value_type &rKey1) const;

protected:

	void					init_containers						(const uint32_t nNodeSize, const uint32_t nPageSize);

	void					init_containers						(const CBTreeAssociativeTestWrapper_t &rWrapper);

	void					transfer_containers					();

	template<class _t_ext_container, class _t_source_container, class _t_ext_sizetype, class _t_ext_iterator>
	void					test_one_container_insert			(_t_ext_container *pExtOriginal, _t_ext_container *pExtReference, _t_ext_sizetype nPos, size_test_type nFirst, size_test_type nLast, _t_ext_iterator &rExtIter, bool bRefIterConst, bool bRefIterReverse, _t_source_container *pSrc) const;

	template<class _t_ext_container, class _t_source_container, class _t_ext_sizetype, class _t_ext_iterator, class _t_iterator>
	void					test_one_container_insert			(_t_ext_container *pExtOriginal, _t_ext_container *pExtReference, _t_ext_sizetype nPos, size_test_type nFirst, size_test_type nLast, _t_ext_iterator &rExtIter, _t_iterator &rIter, _t_source_container *pSrc) const;

	CBTreeTestMultiMap<CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> >		*m_pContainerFile6565min;
	CBTreeTestMultiMap<CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> >		*m_pContainerFile6555min;
	CBTreeTestMultiMap<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> >		*m_pContainerFile5555min;
	CBTreeTestMultiMap<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> >		*m_pContainerFile5554min;
	CBTreeTestMultiMap<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> >		*m_pContainerFile5454min;

	CBTreeTestMultiMap<CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> >		*m_pContainerFile6565default;
	CBTreeTestMultiMap<CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> >		*m_pContainerFile6555default;
	CBTreeTestMultiMap<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> >		*m_pContainerFile5555default;
	CBTreeTestMultiMap<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> >		*m_pContainerFile5554default;
	CBTreeTestMultiMap<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> >		*m_pContainerFile5454default;

	CBTreeTestMultiMap<CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> >		*m_pContainerFile6565large;
	CBTreeTestMultiMap<CBTreeIOpropertiesFile <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> >		*m_pContainerFile6555large;
	CBTreeTestMultiMap<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> >		*m_pContainerFile5555large;
	CBTreeTestMultiMap<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> >		*m_pContainerFile5554large;
	CBTreeTestMultiMap<CBTreeIOpropertiesFile <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> >		*m_pContainerFile5454large;

	CBTreeTestMultiMap<CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> >			*m_pContainerRAM6565_n;
	CBTreeTestMultiMap<CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> >			*m_pContainerRAM6555_n;
	CBTreeTestMultiMap<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> >			*m_pContainerRAM5555_n;
	CBTreeTestMultiMap<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> >			*m_pContainerRAM5554_n;
	CBTreeTestMultiMap<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> >			*m_pContainerRAM5454_n;
	CBTreeTestMultiMap<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint16_t, uint16_t> >			*m_pContainerRAM5444_n;
	CBTreeTestMultiMap<CBTreeIOpropertiesRAM <size_test_type, uint16_t, uint16_t, uint16_t, uint16_t> >			*m_pContainerRAM4444_n;

	CBTreeTestMultiMap<CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> >			*m_pContainerRAM6565_2n;
	CBTreeTestMultiMap<CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> >			*m_pContainerRAM6555_2n;
	CBTreeTestMultiMap<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> >			*m_pContainerRAM5555_2n;
	CBTreeTestMultiMap<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> >			*m_pContainerRAM5554_2n;
	CBTreeTestMultiMap<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> >			*m_pContainerRAM5454_2n;
	CBTreeTestMultiMap<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint16_t, uint16_t> >			*m_pContainerRAM5444_2n;
	CBTreeTestMultiMap<CBTreeIOpropertiesRAM <size_test_type, uint16_t, uint16_t, uint16_t, uint16_t> >			*m_pContainerRAM4444_2n;

	CBTreeTestMultiMap<CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint64_t, uint32_t> >			*m_pContainerRAM6565_4n;
	CBTreeTestMultiMap<CBTreeIOpropertiesRAM <size_test_type, uint64_t, uint32_t, uint32_t, uint32_t> >			*m_pContainerRAM6555_4n;
	CBTreeTestMultiMap<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint32_t> >			*m_pContainerRAM5555_4n;
	CBTreeTestMultiMap<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint32_t, uint32_t, uint16_t> >			*m_pContainerRAM5554_4n;
	CBTreeTestMultiMap<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint32_t, uint16_t> >			*m_pContainerRAM5454_4n;
	CBTreeTestMultiMap<CBTreeIOpropertiesRAM <size_test_type, uint32_t, uint16_t, uint16_t, uint16_t> >			*m_pContainerRAM5444_4n;
	CBTreeTestMultiMap<CBTreeIOpropertiesRAM <size_test_type, uint16_t, uint16_t, uint16_t, uint16_t> >			*m_pContainerRAM4444_4n;

	static const uint32_t											m_nNumContainersMM;
};

#include "btreemultimaptestwrapper.cpp"

#endif // BTREEMAPTESTWRAPPER_H
/************************************************************
**
** file:	btreetestset.h
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
** This file contains set application class code derived
** from the b-tree framework's set class to allow
** for the set class being tested by having
** the set application class act as a wrapper.
**
************************************************************/

#ifndef BTREETESTSET_H
#define	BTREETESTSET_H

#include <stdint.h>

#include <set>
#include <utility>
#include <sstream>

#include "testbench/common/btreetestcommon.h"
#include "testbench/application_classes/regression/base/btreetestbaseset.h"

#include "specific_data_classes/btreeset.h"

template<class _t_datalayerproperties>
class CBTreeTestSet
	:	public CBTreeTestBaseSet
				<
					CBTreeSet<uint32_t, _t_datalayerproperties>, 
					::std::set<uint32_t>, 
					uint32_t, 
					_t_datalayerproperties
				>
{
public:

	typedef CBTreeTestSet												CBTreeTestSet_t;

	typedef CBTreeTestBaseSet
		<
			CBTreeSet<uint32_t, _t_datalayerproperties>, 
			::std::set<uint32_t>, 
			uint32_t, 
			_t_datalayerproperties
		>																CBTreeTestBaseSet_t;

	typedef uint32_t													value_type;
	typedef uint32_t													key_type;
	typedef typename _t_datalayerproperties::size_type					size_type;
	typedef typename _t_datalayerproperties::node_iter_type				node_iter_type;
	typedef typename _t_datalayerproperties::sub_node_iter_type			sub_node_iter_type;
	typedef _t_datalayerproperties										data_layer_properties_type;
	typedef typename _t_datalayerproperties::data_layer_type			data_layer_type;

	typedef value_type&													reference;
	typedef const value_type&											const_reference;
	typedef value_type*													pointer;
	typedef const value_type*											const_pointer;
	typedef	typename ::std::make_signed<size_type>::type				difference_type;

	typedef CBTreeSet<key_type, _t_datalayerproperties>					CBTreeSet_t;

	typedef typename CBTreeSet_t::CBTreeAssociativeIf_t					CBTreeAssociativeIf_t;

	typedef typename CBTreeSet_t::CBTreeIf_t							CBTreeIf_t;

	typedef typename CBTreeSet_t::CBTreeDefaults_t						CBTreeDefaults_t;

	typedef typename CBTreeSet_t::CBTreeBaseIf_t						CBTreeBaseIf_t;

	typedef typename CBTreeSet_t::CBTreeBaseDefaults_t					CBTreeBaseDefaults_t;

	typedef typename CBTreeSet_t::iterator								iterator;
	typedef typename CBTreeSet_t::const_iterator						const_iterator;
	typedef typename CBTreeSet_t::reverse_iterator						reverse_iterator;
	typedef typename CBTreeSet_t::const_reverse_iterator				const_reverse_iterator;

	typedef	typename CBTreeSet_t::key_compare							key_compare;
	typedef typename CBTreeSet_t::value_compare							value_compare;

	struct data_s
	{
		key_type			nKey;
	};

	typedef ::std::set<key_type>										reference_t;

							CBTreeTestSet<_t_datalayerproperties>
								(_t_datalayerproperties &rDataLayerProperties, sub_node_iter_type nNodeSize, reference_t *pClRefData);

							CBTreeTestSet<_t_datalayerproperties>
								(const CBTreeTestSet<_t_datalayerproperties> &rContainer, const bool bAssign = true);

							CBTreeTestSet<_t_datalayerproperties>
								(CBTreeTestSet<_t_datalayerproperties> &&rRhsContainer);

							~CBTreeTestSet<_t_datalayerproperties>
								();

	CBTreeTestSet_t &		operator=				(const CBTreeTestSet_t &rContainer);
	CBTreeTestSet_t &		operator=				(CBTreeTestSet_t &&rRhsContainer);

	template<class _t_iterator>
	void					insert					(_t_iterator sItFirst, _t_iterator sItLast);

	template<class _t_iterator, class _t_ref_iterator>
	void					insert					(_t_iterator sItFirst, _t_iterator sItLast);

	iterator				insert					(const value_type &rData);

	template<class ..._t_va_args>
	iterator				insert					(const_iterator sCIterHint, _t_va_args && ... rrArgs);

	iterator				erase					(const_iterator sCIterPos);
	size_type				erase					(const key_type &rKey);
	iterator				erase					(const_iterator sCIterFirst, const_iterator sCIterLast);

	void					swap					(CBTreeTestSet &rContainer);

	void					clear					();

	bool					operator==				(const CBTreeTestSet &rTMM) const;
	bool					operator!=				(const CBTreeTestSet &rTMM) const;

protected:

	void					_swap					(CBTreeTestSet_t &rContainer);

	bool					show_data				(std::ofstream &ofs, std::stringstream &rstrData, std::stringstream &rszMsg, const node_iter_type nNode, const sub_node_iter_type nSubPos) const;

public:

	friend class CBTreeIterator<CBTreeIf_t>;
	friend class CBTreeConstIterator<CBTreeIf_t>;
	friend class CBTreeReverseIterator<iterator>;
	friend class CBTreeConstReverseIterator<const_iterator>;
};

#endif // !BTREETESTSET_H

#include "btreetestset.cpp"

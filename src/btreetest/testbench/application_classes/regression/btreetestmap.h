/************************************************************
**
** file:	btreetestmap.h
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
** This file contains map application class code derived
** from the b-tree framework's map class to allow
** for the map class being tested by having
** the map application class act as a wrapper.
**
************************************************************/

#ifndef BTREETESTMAP_H
#define	BTREETESTMAP_H

#include <stdint.h>

#include <map>
#include <utility>
#include <sstream>

#include "testbench/common/btreetestcommon.h"
#include "testbench/application_classes/regression/base/btreetestbaseassociative.h"

#include "specific_data_classes/btreemap.h"

typedef struct mapMap_s
{
	uint32_t	nData;
	uint32_t	nDebug;

	bool	operator== (const struct mapMap_s &rOpr) const
	{
		return ((nData == rOpr.nData) && (nDebug == rOpr.nDebug));
	};
} mapMap_t;

template<class _t_datalayerproperties>
class CBTreeTestMap
	:	public CBTreeTestBaseAssociative
				<
					CBTreeMap<uint32_t, mapMap_t, _t_datalayerproperties>, 
					::std::map<uint32_t, mapMap_t>, 
					::std::pair<uint32_t, mapMap_t>, 
					uint32_t, 
					_t_datalayerproperties
				>
{
public:

	typedef CBTreeTestMap											CBTreeTestMap_t;

	typedef CBTreeTestBaseAssociative
		<
			CBTreeMap<uint32_t, mapMap_t, _t_datalayerproperties>, 
			::std::map<uint32_t, mapMap_t>, 
			::std::pair<uint32_t, mapMap_t>, 
			uint32_t, 
			_t_datalayerproperties
		>															CBTreeTestBaseAssociative_t;

	typedef mapMap_t												map_type;
	typedef uint32_t												key_type;
	typedef typename ::std::pair<key_type, map_type>				value_type;
	typedef typename _t_datalayerproperties::size_type				size_type;
	typedef typename _t_datalayerproperties::node_iter_type			node_iter_type;
	typedef typename _t_datalayerproperties::sub_node_iter_type		sub_node_iter_type;
	typedef _t_datalayerproperties									data_layer_properties_type;
	typedef typename _t_datalayerproperties::data_layer_type		data_layer_type;

	typedef value_type&												reference;
	typedef const value_type&										const_reference;
	typedef value_type*												pointer;
	typedef const value_type*										const_pointer;
	typedef	typename ::std::make_signed<size_type>::type			difference_type;

	typedef CBTreeMap<key_type, map_type, _t_datalayerproperties>	CBTreeMap_t;

	typedef typename CBTreeMap_t::CBTreeAssociativeIf_t				CBTreeAssociativeIf_t;

	typedef typename CBTreeMap_t::CBTreeIf_t						CBTreeIf_t;

	typedef typename CBTreeMap_t::CBTreeDefaults_t					CBTreeDefaults_t;

	typedef typename CBTreeMap_t::CBTreeBaseIf_t					CBTreeBaseIf_t;

	typedef typename CBTreeMap_t::CBTreeBaseDefaults_t				CBTreeBaseDefaults_t;

	typedef typename CBTreeMap_t::iterator							iterator;
	typedef typename CBTreeMap_t::const_iterator					const_iterator;
	typedef typename CBTreeMap_t::reverse_iterator					reverse_iterator;
	typedef typename CBTreeMap_t::const_reverse_iterator			const_reverse_iterator;

	typedef	typename CBTreeMap_t::key_compare						key_compare;
	typedef typename CBTreeMap_t::value_compare						value_compare;

	typedef ::std::map<key_type, map_type>							reference_t;

							CBTreeTestMap<_t_datalayerproperties>
								(_t_datalayerproperties &rDataLayerProperties, sub_node_iter_type nNodeSize, reference_t *pClRefData);

							CBTreeTestMap<_t_datalayerproperties>
								(const CBTreeTestMap<_t_datalayerproperties> &rContainer, const bool bAssign = true);

							CBTreeTestMap<_t_datalayerproperties>
								(CBTreeTestMap<_t_datalayerproperties> &&rRhsContainer);

							~CBTreeTestMap<_t_datalayerproperties>
								();

	CBTreeTestMap_t &		operator=				(const CBTreeTestMap_t &rContainer);
	CBTreeTestMap_t &		operator=				(CBTreeTestMap_t &&rRhsContainer);

	template<class _t_iterator>
	void					insert					(_t_iterator sItFirst, _t_iterator sItLast);

	iterator				insert					(const value_type &rData);

	iterator				insert					(const_iterator sCIterHint, const value_type &rData);

	iterator				erase					(const_iterator sCIterPos);
	size_type				erase					(const key_type &rKey);
	iterator				erase					(const_iterator sCIterFirst, const_iterator sCIterLast);

	void					swap					(CBTreeTestMap &rContainer);

	void					clear					();
	
	bool					operator==				(const CBTreeTestMap &rTMM) const;
	bool					operator!=				(const CBTreeTestMap &rTMM) const;

protected:

	void					_swap					(CBTreeTestMap_t &rContainer);

	bool					show_data				(std::ofstream &ofs, std::stringstream &rstrData, std::stringstream &rszMsg, const node_iter_type nNode, const sub_node_iter_type nSubPos) const;

public:

	friend class CBTreeIterator<CBTreeIf_t>;
	friend class CBTreeConstIterator<CBTreeIf_t>;
	friend class CBTreeReverseIterator<iterator>;
	friend class CBTreeConstReverseIterator<const_iterator>;
};

#endif // !BTREETESTMAP_H

#include "btreetestmap.cpp"

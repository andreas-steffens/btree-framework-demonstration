/************************************************************
**
** file:	btreetestbaseset.h
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
**
************************************************************/

#ifndef	BTREETESTBASESET_H
#define	BTREETESTBASESET_H

#include <stdint.h>

#include <string.h>

#include <iostream>
#include <iomanip>


#include "testbench/application_classes/regression/base/btreetestbase.h"

template<class _t_set, class _t_reference, class _t_key, class _t_datalayerproperties>
class CBTreeTestBaseSet :
	public _t_set, 
	public CBTreeTestBase<_t_reference>
{
public:

	typedef CBTreeTestBaseSet									CBTreeTestBaseSet_t;

	typedef CBTreeTestBase<_t_reference>						CBTreeTestBase_t;

	typedef _t_set												CBTreeSet_t;

	typedef typename CBTreeSet_t::CBTreeBaseDefaults_t			CBTreeBaseDefaults_t;


	typedef _t_key												key_type;
	typedef _t_key												value_type;

	typedef _t_datalayerproperties								datalayerproperties_t;

	typedef typename datalayerproperties_t::size_type			size_type;
	typedef typename datalayerproperties_t::sub_node_iter_type	sub_node_iter_type;

	typedef typename CBTreeBaseDefaults_t::const_iterator		const_iterator;

	typedef	_t_reference										reference_t;

							CBTreeTestBaseSet<_t_set, _t_reference, _t_key, _t_datalayerproperties>
								(const _t_datalayerproperties &rDataLayerProperties, const sub_node_iter_type nNodeSize, const reference_t *pReference, const bool bAtomicTesting);

							CBTreeTestBaseSet<_t_set, _t_reference, _t_key, _t_datalayerproperties>
								(const CBTreeTestBaseSet &rContainer, const bool bAssign = true);

							CBTreeTestBaseSet<_t_set, _t_reference, _t_key, _t_datalayerproperties>
								(CBTreeTestBaseSet &&rRhsContainer);

	virtual					~CBTreeTestBaseSet<_t_set, _t_reference, _t_key, _t_datalayerproperties>
								();

	virtual void			set_atomic_testing		(const bool bEnable);

	virtual void			test					() const;

	CBTreeTestBaseSet_t &	operator=				(const CBTreeTestBaseSet_t &rContainer);

	CBTreeTestBaseSet_t &	operator=				(CBTreeTestBaseSet_t &&rRhsContainer);

protected:

	void					_swap					(CBTreeTestBaseSet_t &rContainer);
};

#endif // BTREETESTBASESET_H

#include "testbench/application_classes/regression/base/btreetestbaseset.cpp"

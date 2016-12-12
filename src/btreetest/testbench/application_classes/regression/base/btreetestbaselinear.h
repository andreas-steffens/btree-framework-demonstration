/************************************************************
**
** file:	btreetestbaselinear.h
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
**
************************************************************/

#ifndef	BTREETESTBASELINEAR_H
#define	BTREETESTBASELINEAR_H

#include <stdint.h>

#include <string.h>

#include <iostream>
#include <iomanip>

#include "testbench/application_classes/regression/base/btreetestbase.h"

template<class _t_linear, class _t_reference, class _t_data, class _t_datalayerproperties>
class CBTreeTestBaseLinear :
	public _t_linear, 
	public CBTreeTestBase<_t_reference>
{
public:

	typedef CBTreeTestBaseLinear								CBTreeTestBaseLinear_t;

	typedef CBTreeTestBase<_t_reference>						CBTreeTestBase_t;

	typedef _t_linear											linear_type;

	typedef typename linear_type::CBTreeBaseDefaults_t			CBTreeBaseDefaults_t;

	typedef _t_data												value_type;

	typedef _t_datalayerproperties								datalayerproperties_t;

	typedef typename datalayerproperties_t::size_type			size_type;
	typedef typename datalayerproperties_t::sub_node_iter_type	sub_node_iter_type;

	typedef typename CBTreeBaseDefaults_t::const_iterator		const_iterator;

	typedef	_t_reference										reference_t;

							CBTreeTestBaseLinear<_t_linear, _t_reference, _t_data, _t_datalayerproperties>
								(
									const _t_datalayerproperties &rDataLayerProperties, 
									const sub_node_iter_type nNodeSize, 
									const reference_t *pReference, 
									const bool bAtomicTesting
								);

							CBTreeTestBaseLinear<_t_linear, _t_reference, _t_data, _t_datalayerproperties>
								(const CBTreeTestBaseLinear &rContainer, const bool bAssign);

							CBTreeTestBaseLinear<_t_linear, _t_reference, _t_data, _t_datalayerproperties>
								(CBTreeTestBaseLinear &&rRhsContainer);

	virtual					~CBTreeTestBaseLinear<_t_linear, _t_reference, _t_data, _t_datalayerproperties>
								();

	virtual void			set_atomic_testing		(const bool bEnable);

	virtual void			test					() const;

	CBTreeTestBaseLinear<_t_linear, _t_reference, _t_data, _t_datalayerproperties> &
							operator= (const CBTreeTestBaseLinear_t &rContainer);

	CBTreeTestBaseLinear<_t_linear, _t_reference, _t_data, _t_datalayerproperties> &
							operator= (CBTreeTestBaseLinear_t &&rRhsContainer);

protected:

	void					_swap					(CBTreeTestBaseLinear_t &rContainer);
};

#endif // BTREETESTBASELINEAR_H

#include "testbench/application_classes/regression/base/btreetestbaselinear.cpp"

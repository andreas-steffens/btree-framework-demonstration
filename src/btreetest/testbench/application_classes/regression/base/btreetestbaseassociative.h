/************************************************************
**
** file:	btreetestbaseassociative.h
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
**
************************************************************/

#ifndef	BTREETESTBASEASSOCIATIVE_H
#define	BTREETESTBASEASSOCIATIVE_H

#include <stdint.h>

#include <string.h>

#include <iostream>
#include <iomanip>


#include "testbench/application_classes/regression/base/btreetestbase.h"

template<class _t_associative, class _t_reference, class _t_data, class _t_key, class _t_datalayerproperties>
class CBTreeTestBaseAssociative :
	public _t_associative, 
	public CBTreeTestBase<_t_reference>
{
public:

	typedef CBTreeTestBaseAssociative							CBTreeTestBaseAssociative_t;

	typedef CBTreeTestBase<_t_reference>						CBTreeTestBase_t;

	typedef _t_associative										CBTreeAssociative_t;

	typedef typename CBTreeAssociative_t::CBTreeBaseDefaults_t	CBTreeBaseDefaults_t;


	typedef _t_key												key_type;
	typedef _t_data												value_type;

	typedef _t_datalayerproperties								datalayerproperties_t;

	typedef typename datalayerproperties_t::size_type			size_type;
	typedef typename datalayerproperties_t::sub_node_iter_type	sub_node_iter_type;

	typedef typename CBTreeBaseDefaults_t::const_iterator		const_iterator;

	typedef	_t_reference										reference_t;

							CBTreeTestBaseAssociative<_t_associative, _t_reference, _t_data, _t_key, _t_datalayerproperties>
								(const _t_datalayerproperties &rDataLayerProperties, const sub_node_iter_type nNodeSize, const reference_t *pReference, const bool bAtomicTesting);

							CBTreeTestBaseAssociative<_t_associative, _t_reference, _t_data, _t_key, _t_datalayerproperties>
								(const CBTreeTestBaseAssociative &rContainer, const bool bAssign = true);

							CBTreeTestBaseAssociative<_t_associative, _t_reference, _t_data, _t_key, _t_datalayerproperties>
								(CBTreeTestBaseAssociative &&rRhsContainer);

	virtual					~CBTreeTestBaseAssociative<_t_associative, _t_reference, _t_data, _t_key, _t_datalayerproperties>
								();

	virtual void			set_atomic_testing		(const bool bEnable);

	virtual void			test					() const;

	CBTreeTestBaseAssociative_t &
							operator=				(const CBTreeTestBaseAssociative_t &rContainer);

	CBTreeTestBaseAssociative_t &
							operator=				(CBTreeTestBaseAssociative_t &&rRhsContainer);

protected:

	void					_swap					(CBTreeTestBaseAssociative_t &rContainer);
};

#endif // BTREETESTBASEASSOCIATIVE_H

#include "testbench/application_classes/regression/base/btreetestbaseassociative.cpp"

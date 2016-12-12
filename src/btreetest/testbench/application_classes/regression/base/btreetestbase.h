/************************************************************
**
** file:	btreetestbase.h
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
**
************************************************************/

#ifndef	BTREETESTBASE_H
#define	BTREETESTBASE_H

#include <stdint.h>

#include "btree_framework/common/btreecommon.h"

template<class _t_reference>
class CBTreeTestBase
{
public:

	typedef CBTreeTestBase									CBTreeTestBase_t;

	typedef	_t_reference									reference_t;

							CBTreeTestBase<_t_reference>
								(const reference_t *pReference, const bool bAtomicTesting);

							CBTreeTestBase<_t_reference>
								(const CBTreeTestBase &rContainer);

							CBTreeTestBase<_t_reference>
								(CBTreeTestBase &&rRhsContainer);

							~CBTreeTestBase<_t_reference>
								();

	void					set_reference			(reference_t *pReference);

	void					destroy_reference		();

	CBTreeTestBase_t &		operator=				(const CBTreeTestBase_t &rContainer);
	CBTreeTestBase_t &		operator=				(CBTreeTestBase_t &&rRhsContainer);

protected:

	void					_local_swap				(CBTreeTestBase &rContainer);

	reference_t				*m_pClRef;

	bool					m_bAtomicTesting;
	btree_time_stamp_t		*m_psTestTimeStamp;
};

#endif // BTREETESTBASE_H

#include "testbench/application_classes/regression/base/btreetestbase.cpp"

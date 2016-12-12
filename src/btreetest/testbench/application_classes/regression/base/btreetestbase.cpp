/************************************************************
**
** file:	btreetestbase.cpp
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
**
************************************************************/

#ifndef BTREETESTBASE_CPP
#define	BTREETESTBASE_CPP

#include "testbench/application_classes/regression/base/btreetestbase.h"

template<class _t_reference>
CBTreeTestBase<_t_reference>::CBTreeTestBase (const _t_reference *pReference, const bool bAtomicTesting)
	:	m_pClRef ((_t_reference *) pReference)
	,	m_bAtomicTesting (bAtomicTesting)
	,	m_psTestTimeStamp (NULL)
{
}

template<class _t_reference>
CBTreeTestBase<_t_reference>::CBTreeTestBase
	(const CBTreeTestBase<_t_reference> &rContainer)
	:	m_pClRef (NULL)
	,	m_bAtomicTesting (false)
	,	m_psTestTimeStamp (NULL)
{
}

template<class _t_reference>
CBTreeTestBase<_t_reference>::CBTreeTestBase
	(CBTreeTestBase<_t_reference> &&rRhsContainer)
	:	m_pClRef (NULL)
	,	m_bAtomicTesting (true)
	,	m_psTestTimeStamp (NULL)
{
	_local_swap (rRhsContainer);
}

template<class _t_reference>
CBTreeTestBase<_t_reference>::~CBTreeTestBase ()
{
	if (m_psTestTimeStamp != NULL)
	{
		delete m_psTestTimeStamp;

		m_psTestTimeStamp = NULL;
	}
}

template<class _t_reference>
void CBTreeTestBase<_t_reference>::set_reference (reference_t *pReference)
{
	m_pClRef = pReference;
}

template<class _t_reference>
void CBTreeTestBase<_t_reference>::destroy_reference ()
{
	if (m_pClRef != NULL)
	{
		delete m_pClRef;
	}

	m_pClRef = NULL;
}

template<class _t_reference>
CBTreeTestBase<_t_reference> &
CBTreeTestBase<_t_reference>::operator= (const CBTreeTestBase_t &rContainer)
{
	bool		bSameAccCounter;

	if (this != &rContainer)
	{
		*m_pClRef = *rContainer.m_pClRef;

		m_bAtomicTesting = rContainer.m_bAtomicTesting;

		bSameAccCounter = m_psTestTimeStamp->nAccCtr == rContainer.m_psTestTimeStamp->nAccCtr;
	
		*m_psTestTimeStamp = *rContainer.m_psTestTimeStamp;

		if (bSameAccCounter)
		{
			// modify access counter to make sure the result of this operation is tested
			m_psTestTimeStamp->nAccCtr++;
		}
	}

	return (*this);
}

template<class _t_reference>
CBTreeTestBase<_t_reference> &
CBTreeTestBase<_t_reference>::operator= (CBTreeTestBase_t &&rRhsContainer)
{
	bool		bSameAccCounter;

	_local_swap (rRhsContainer);

	bSameAccCounter = m_psTestTimeStamp->nAccCtr == rRhsContainer.m_psTestTimeStamp->nAccCtr;
	
	if (bSameAccCounter)
	{
		// modify access counter to make sure the result of this operation is tested
		m_psTestTimeStamp->nAccCtr++;

		rRhsContainer.m_psTestTimeStamp->nAccCtr++;
	}

	return (*this);
}

template<class _t_reference>
void CBTreeTestBase<_t_reference>::_local_swap (CBTreeTestBase &rContainer)
{
	fast_swap (this->m_pClRef, rContainer.m_pClRef);
	fast_swap (this->m_bAtomicTesting, rContainer.m_bAtomicTesting);
	fast_swap (this->m_psTestTimeStamp, rContainer.m_psTestTimeStamp);
}

#endif // BTREETESTBASE_CPP

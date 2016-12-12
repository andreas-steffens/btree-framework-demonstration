/************************************************************
**
** file:	btreetestbaselinear.cpp
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
**
************************************************************/

#ifndef BTREETESTBASELINEAR_CPP
#define	BTREETESTBASELINEAR_CPP

#include "testbench/application_classes/regression/base/btreetestbaselinear.h"

template<class _t_linear, class _t_reference, class _t_data, class _t_datalayerproperties>
CBTreeTestBaseLinear<_t_linear, _t_reference, _t_data, _t_datalayerproperties>::CBTreeTestBaseLinear
	(
		const _t_datalayerproperties &rDataLayerProperties, 
		const typename _t_datalayerproperties::sub_node_iter_type nNodeSize, 
		const _t_reference *pReference, 
		const bool bAtomicTesting
	)
	:	_t_linear (rDataLayerProperties, nNodeSize)
	,	CBTreeTestBase<_t_reference> (pReference, bAtomicTesting)
{
	this->m_psTestTimeStamp = new btree_time_stamp_t (this->get_time_stamp ());
}

template<class _t_linear, class _t_reference, class _t_data, class _t_datalayerproperties>
CBTreeTestBaseLinear<_t_linear, _t_reference, _t_data, _t_datalayerproperties>::CBTreeTestBaseLinear
	(
		const CBTreeTestBaseLinear<_t_linear, _t_reference, _t_data, _t_datalayerproperties> &rContainer, 
		const bool bAssign
	)
	:	
	_t_linear
	(
		dynamic_cast<const _t_linear &> (rContainer), 
		bAssign
	), 
	CBTreeTestBase<_t_reference>
	(
		dynamic_cast<const CBTreeTestBase<_t_reference> &> (rContainer)
	)
{
	this->m_psTestTimeStamp = new btree_time_stamp_t (this->get_time_stamp ());
}

template<class _t_linear, class _t_reference, class _t_data, class _t_datalayerproperties>
CBTreeTestBaseLinear<_t_linear, _t_reference, _t_data, _t_datalayerproperties>::CBTreeTestBaseLinear
	(CBTreeTestBaseLinear<_t_linear, _t_reference, _t_data, _t_datalayerproperties> &&rRhsContainer)
	:
	_t_linear
	(
		dynamic_cast<_t_linear &&> (rRhsContainer)
	),
	CBTreeTestBase<_t_reference>
	(
		dynamic_cast<CBTreeTestBase<_t_reference> &&> (rRhsContainer)
	)
{
}

template<class _t_linear, class _t_reference, class _t_data, class _t_datalayerproperties>
CBTreeTestBaseLinear<_t_linear, _t_reference, _t_data, _t_datalayerproperties>::~CBTreeTestBaseLinear ()
{
}

template<class _t_linear, class _t_reference, class _t_data, class _t_datalayerproperties>
void CBTreeTestBaseLinear<_t_linear, _t_reference, _t_data, _t_datalayerproperties>::set_atomic_testing (const bool bEnable)
{
	this->m_bAtomicTesting = bEnable;
}

template<class _t_linear, class _t_reference, class _t_data, class _t_datalayerproperties>
void CBTreeTestBaseLinear<_t_linear, _t_reference, _t_data, _t_datalayerproperties>::test () const
{
	if (!this->m_bAtomicTesting)
	{
		return;
	}

	if (*this->m_psTestTimeStamp == this->get_time_stamp ())
	{
		return;
	}

	*this->m_psTestTimeStamp = this->get_time_stamp ();

	if (!this->test_integrity ())
	{
		::std::cerr << ::std::endl;
		::std::cerr << "integrity test failed" << ::std::endl;

		::std::cerr << "creating integrity.html..." << ::std::endl;

		this->show_integrity ("integrity.html");

		::std::cerr << "finished!" << ::std::endl;

		exit (-1);
	}

	if (this->size () != (size_type) this->m_pClRef->size ())
	{
		::std::cerr << ::std::endl;
		::std::cerr << "size mismatches" << ::std::endl;
		::std::cerr << "size: " << this->size () << ::std::endl;
		::std::cerr << "reference: " << this->m_pClRef->size () << ::std::endl;

		::std::cerr << "creating size.html..." << ::std::endl;

		this->show_integrity ("size.html");

		::std::cerr << "finished!" << ::std::endl;

		exit (-1);
	}

	typename reference_t::iterator		itRef = this->m_pClRef->begin ();
	size_type							it;
	value_type							sData;
	value_type							sRef;
	const_iterator						sCIter;

	sCIter = this->cbegin ();

	for (it = 0; it < this->size (); it++, itRef++, sCIter++)
	{
		sData = *sCIter;

		sRef = *itRef;

		if (memcmp ((void *) &sData, (void *) &sRef, sizeof (sData)) != 0)
		{
			::std::cerr << ::std::endl;
			::std::cerr << "data mismatch at " << it << ::std::endl;
			
			::std::cerr << "creating error.html..." << ::std::endl;

			this->show_integrity ("error.html");

			::std::cerr << "finished!" << ::std::endl;

			exit (-1);
		}
	}
}

template<class _t_linear, class _t_reference, class _t_data, class _t_datalayerproperties>
CBTreeTestBaseLinear<_t_linear, _t_reference, _t_data, _t_datalayerproperties> &
CBTreeTestBaseLinear<_t_linear, _t_reference, _t_data, _t_datalayerproperties>::operator= (const CBTreeTestBaseLinear<_t_linear, _t_reference, _t_data, _t_datalayerproperties> &rContainer)
{
	if (this != &rContainer)
	{
		CBTreeTestBase_t			&rTestBaseThis = dynamic_cast<CBTreeTestBase_t &> (*this);
		const CBTreeTestBase_t		&rTestBaseContainer = dynamic_cast<const CBTreeTestBase_t &> (rContainer);

		rTestBaseThis = rTestBaseContainer;

		_t_linear					&rLinearThis = dynamic_cast<_t_linear &> (*this);
		const _t_linear				&rLinearContainer = dynamic_cast<const _t_linear &> (rContainer);

		rLinearThis = rLinearContainer;
	}

	return (*this);
}

template<class _t_linear, class _t_reference, class _t_data, class _t_datalayerproperties>
CBTreeTestBaseLinear<_t_linear, _t_reference, _t_data, _t_datalayerproperties> &
CBTreeTestBaseLinear<_t_linear, _t_reference, _t_data, _t_datalayerproperties>::operator= (CBTreeTestBaseLinear<_t_linear, _t_reference, _t_data, _t_datalayerproperties> &&rRhsContainer)
{
	CBTreeTestBase_t		&rTestBaseThis = dynamic_cast<CBTreeTestBase_t &> (*this);
	CBTreeTestBase_t		&rTestBaseContainer = dynamic_cast<CBTreeTestBase_t &> (rRhsContainer);

	rTestBaseThis = ::std::move (rTestBaseContainer);

	_t_linear				&rLinearThis = dynamic_cast<_t_linear &> (*this);
	_t_linear				&rLinearContainer = dynamic_cast<_t_linear &> (rRhsContainer);

	rLinearThis = ::std::move (rLinearContainer);

	return (*this);
}

template<class _t_linear, class _t_reference, class _t_data, class _t_datalayerproperties>
void CBTreeTestBaseLinear<_t_linear, _t_reference, _t_data, _t_datalayerproperties>::_swap (CBTreeTestBaseLinear<_t_linear, _t_reference, _t_data, _t_datalayerproperties> &rContainer)
{
	_t_linear			&rLinearContainer = dynamic_cast<_t_linear &> (rContainer);

	_t_linear::_swap (rLinearContainer);

	CBTreeTestBase_t	&rTestBaseContainer = dynamic_cast<CBTreeTestBase_t &> (rContainer);

	CBTreeTestBase_t::_swap (rTestBaseContainer);
}

#endif // BTREETESTBASELINEAR_CPP

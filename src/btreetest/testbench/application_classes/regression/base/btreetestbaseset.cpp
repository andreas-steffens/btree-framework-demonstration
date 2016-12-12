/************************************************************
**
** file:	btreetestbaseset.cpp
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
**
************************************************************/

#ifndef BTREETESTBASESET_CPP
#define	BTREETESTBASESET_CPP

#include "testbench/application_classes/regression/base/btreetestbaseset.h"

template<class _t_set, class _t_reference, class _t_key, class _t_datalayerproperties>
CBTreeTestBaseSet<_t_set, _t_reference, _t_key, _t_datalayerproperties>::CBTreeTestBaseSet
	(
		const _t_datalayerproperties &rDataLayerProperties, 
		const typename _t_datalayerproperties::sub_node_iter_type nNodeSize, 
		const _t_reference *pReference, 
		const bool bAtomicTesting
	)
	:	_t_set (rDataLayerProperties, nNodeSize)
	,	CBTreeTestBase<_t_reference> (pReference, bAtomicTesting)
{
	this->m_psTestTimeStamp = new btree_time_stamp_t (this->get_time_stamp ());
}

template<class _t_set, class _t_reference, class _t_key, class _t_datalayerproperties>
CBTreeTestBaseSet<_t_set, _t_reference, _t_key, _t_datalayerproperties>::CBTreeTestBaseSet
	(
		const CBTreeTestBaseSet<_t_set, _t_reference, _t_key, _t_datalayerproperties> &rContainer, 
		const bool bAssign
	)
	:	
	_t_set
	(
		dynamic_cast<const _t_set &> (rContainer), 
		bAssign
	), 
	CBTreeTestBase<_t_reference>
	(
		dynamic_cast<const CBTreeTestBase<_t_reference> &> (rContainer)
	)
{
	this->m_psTestTimeStamp = new btree_time_stamp_t (this->get_time_stamp ());
}

template<class _t_set, class _t_reference, class _t_key, class _t_datalayerproperties>
CBTreeTestBaseSet<_t_set, _t_reference, _t_key, _t_datalayerproperties>::CBTreeTestBaseSet
	(CBTreeTestBaseSet<_t_set, _t_reference, _t_key, _t_datalayerproperties> &&rRhsContainer)
	:	
	_t_set
	(
		dynamic_cast<_t_set &&> (rRhsContainer)
	), 
	CBTreeTestBase<_t_reference>
	(
		dynamic_cast<CBTreeTestBase<_t_reference> &&> (rRhsContainer)
	)
{
}

template<class _t_set, class _t_reference, class _t_key, class _t_datalayerproperties>
CBTreeTestBaseSet<_t_set, _t_reference, _t_key, _t_datalayerproperties>::~CBTreeTestBaseSet ()
{
}

template<class _t_set, class _t_reference, class _t_key, class _t_datalayerproperties>
void CBTreeTestBaseSet<_t_set, _t_reference, _t_key, _t_datalayerproperties>::set_atomic_testing (const bool bEnable)
{
	this->m_bAtomicTesting = bEnable;
}

template<class _t_set, class _t_reference, class _t_key, class _t_datalayerproperties>
void CBTreeTestBaseSet<_t_set, _t_reference, _t_key, _t_datalayerproperties>::test () const
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

	typedef typename reference_t::const_iterator	ref_citer_t;
	typedef typename reference_t::value_type		ref_value_type;

	reference_t										sSet;
	key_type										nKey;
	key_type										*pnKey;
	bool											bBounce;
	size_type										nTotalCount = 0;
	ref_value_type									sEntry;
	ref_value_type									sValue;
	ref_citer_t										sItSetLower;
	ref_citer_t										sItSetUpper;
	ref_citer_t										sItSet;
	const_iterator									sCIterBegin;
	const_iterator									sCIterEnd;
	const_iterator									sCIterLower;
	const_iterator									sCIterUpper;
	const_iterator									sCIter;
	bool											bDeleted;
	
	if (!this->test_integrity ())
	{
		::std::cerr << ::std::endl;
		::std::cerr << "integrity test failed" << ::std::endl;

		::std::cerr << "creating integrity.html..." << ::std::endl;

		this->show_integrity ("integrity.html");

		::std::cerr << "finished!" << ::std::endl;

		exit (-1);
	}

	sCIterBegin = this->cbegin ();
	sCIterEnd = this->cend ();

	sCIter = sCIterBegin;

	if (this->size () > 0)
	{
		pnKey = this->extract_key (&nKey, ((value_type) (*sCIter)));
	}

	while (sCIter != sCIterEnd)
	{
		if (this->m_pClRef->count (*pnKey) != this->count (*pnKey))
		{
			::std::cerr << ::std::endl;
			::std::cerr << "number of instances mismatches" << ::std::endl;
			::std::cerr << "key: " << std::setfill ('0') << std::hex << std::setw (8) << *pnKey << ::std::endl;
			::std::cerr << std::setfill (' ') << std::dec << std::setw (0);

			::std::cerr << "count: " << this->count (*pnKey) << ::std::endl;
			::std::cerr << "reference: " << this->m_pClRef->count (*pnKey) << ::std::endl;
			
			::std::cerr << "creating count.html..." << ::std::endl;

			this->show_integrity ("count.html");

			::std::cerr << "finished!" << ::std::endl;

			exit (-1);
		}

		if (this->count (*pnKey) == 1)
		{
			sItSetLower = this->m_pClRef->lower_bound (*pnKey);

			sCIterLower = this->lower_bound (*pnKey);

			sValue = *sItSetLower;

			sEntry = ((value_type) (*sCIterLower));

			if (sEntry != sValue)
			{
				::std::cerr << ::std::endl;
				::std::cerr << "data mismatches" << ::std::endl;
				::std::cerr << "key: " << std::setfill ('0') << std::hex << std::setw (8) << sEntry << ::std::endl;
				
				::std::cerr << std::setfill (' ') << std::dec << std::setw (0);

				::std::cerr << "reference" << ::std::endl;

				::std::cerr << "data: " << std::setfill ('0') << std::hex << std::setw (8) << sValue << ::std::endl;

				::std::cerr << std::setfill (' ') << std::dec << std::setw (0);

				::std::cerr << "creating data.html..." << ::std::endl;

				this->show_integrity ("data.html");

				::std::cerr << "finished!" << ::std::endl;

				exit (-1);
			}
		}
		else
		{
			sItSetLower = this->m_pClRef->lower_bound (*pnKey);
			sItSetUpper = this->m_pClRef->upper_bound (*pnKey);

			sSet.insert (sItSetLower, sItSetUpper);

			sCIterLower = this->lower_bound (*pnKey);
			sCIterUpper = this->upper_bound (*pnKey);

			for (sCIter = sCIterLower; sCIter != sCIterUpper; sCIter++)
			{
				sEntry = ((value_type) (*sCIter));

				bDeleted = false;

				for (sItSet = sSet.cbegin (); sItSet != sSet.cend (); sItSet++)
				{
					sValue = *sItSet;

					if (sEntry == sValue)
					{
						sSet.erase (sItSet);

						bDeleted = true;

						break;
					}
				}

				if (!bDeleted)
				{
					::std::cerr << ::std::endl;
					::std::cerr << "number of instances mismatches" << ::std::endl;
					::std::cerr << "key: " << std::setfill ('0') << std::hex << std::setw (8) << sEntry << ::std::endl;
					
					::std::cerr << std::setfill (' ') << std::dec << std::setw (0);

					::std::cerr << "Instance not found in reference!" << ::std::endl;

					::std::cerr << "creating error.html..." << ::std::endl;

					this->show_integrity ("error.html");

					::std::cerr << "finished!" << ::std::endl;

					exit (-1);
				}
			}

			if (sSet.size () != 0)
			{
				::std::cerr << ::std::endl;
				::std::cerr << "number of instances mismatches" << ::std::endl;
				::std::cerr << "the following entries are still present in reference:" << ::std::endl;

				for (sItSet = sSet.cbegin (); sItSet != sSet.cend (); sItSet++)
				{
					sValue = *sItSet;

					::std::cerr << "key: ";

					::std::cerr << std::setfill ('0') << std::hex << std::setw (8);
					{
						::std::cerr << sValue << " ";
					}
					::std::cerr << std::setfill (' ') << std::dec << std::setw (0);
				}

				::std::cerr << "creating error.html..." << ::std::endl;

				this->show_integrity ("error.html");

				::std::cerr << "finished!" << ::std::endl;

				exit (-1);
			}
		}

		this->get_next_key (*pnKey, *pnKey, bBounce);

		if (bBounce)
		{
			break;
		}
	}
	
	if ((this->m_pClRef == NULL) && (!this->empty ()))
	{
		::std::cerr << ::std::endl;
		::std::cerr << "reference not set while data container not empty" << ::std::endl;
		::std::cerr << "size: " << this->size () << ::std::endl;

		exit (-1);
	}
	
	if ((this->m_pClRef != NULL) && (this->m_pClRef->size () != this->size ()))
	{
		::std::cerr << ::std::endl;
		::std::cerr << "size mismatches" << ::std::endl;
		::std::cerr << "size: " << this->size () << ::std::endl;
		::std::cerr << "reference size: " << this->m_pClRef->size () << ::std::endl;

		::std::cerr << "creating size.html..." << ::std::endl;

		this->show_integrity ("size.html");

		::std::cerr << "finished!" << ::std::endl;

		exit (-1);
	}
}

template<class _t_set, class _t_reference, class _t_key, class _t_datalayerproperties>
CBTreeTestBaseSet<_t_set, _t_reference, _t_key, _t_datalayerproperties> &
CBTreeTestBaseSet<_t_set, _t_reference, _t_key, _t_datalayerproperties>::operator= (const CBTreeTestBaseSet<_t_set, _t_reference, _t_key, _t_datalayerproperties> &rContainer)
{
	if (this != &rContainer)
	{
		CBTreeTestBase_t			&rTestBaseThis = dynamic_cast<CBTreeTestBase_t &> (*this);
		const CBTreeTestBase_t		&rTestBaseContainer = dynamic_cast<const CBTreeTestBase_t &> (rContainer);

		rTestBaseThis = rTestBaseContainer;

		_t_set				&rAssociativeThis = dynamic_cast<_t_set &> (*this);
		const _t_set		&rAssociativeContainer = dynamic_cast<const _t_set &> (rContainer);

		rAssociativeThis = rAssociativeContainer;
	}

	return (*this);
}

template<class _t_set, class _t_reference, class _t_key, class _t_datalayerproperties>
CBTreeTestBaseSet<_t_set, _t_reference, _t_key, _t_datalayerproperties> &
CBTreeTestBaseSet<_t_set, _t_reference, _t_key, _t_datalayerproperties>::operator= (CBTreeTestBaseSet<_t_set, _t_reference, _t_key, _t_datalayerproperties> &&rRhsContainer)
{
	CBTreeTestBase_t		&rTestBaseThis = dynamic_cast<CBTreeTestBase_t &> (*this);
	CBTreeTestBase_t		&rTestBaseContainer = dynamic_cast<CBTreeTestBase_t &> (rRhsContainer);

	rTestBaseThis = ::std::move (rTestBaseContainer);

	_t_set			&rAssociativeThis = dynamic_cast<_t_set &> (*this);
	_t_set			&rAssociativeContainer = dynamic_cast<_t_set &> (rRhsContainer);

	rAssociativeThis = ::std::move (rAssociativeContainer);

	return (*this);
}

template<class _t_set, class _t_reference, class _t_key, class _t_datalayerproperties>
void CBTreeTestBaseSet<_t_set, _t_reference, _t_key, _t_datalayerproperties>::_swap (CBTreeTestBaseSet_t &rContainer)
{
	_t_set		&rLinearContainer = dynamic_cast<_t_set &> (rContainer);

	_t_set::_swap (rLinearContainer);

	CBTreeTestBase_t	&rTestBaseContainer = dynamic_cast<CBTreeTestBase_t &> (rContainer);

	CBTreeTestBase_t::_swap (rTestBaseContainer);
}

#endif // BTREETESTBASEASSOCIATIVE_CPP

/************************************************************
**
** file:	btreetestbaseassociative.cpp
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
**
************************************************************/

#ifndef BTREETESTBASEASSOCIATIVE_CPP
#define	BTREETESTBASEASSOCIATIVE_CPP

#include "testbench/application_classes/regression/base/btreetestbaseassociative.h"

template<class _t_associative, class _t_reference, class _t_data, class _t_key, class _t_datalayerproperties>
CBTreeTestBaseAssociative<_t_associative, _t_reference, _t_data, _t_key, _t_datalayerproperties>::CBTreeTestBaseAssociative
	(
		const _t_datalayerproperties &rDataLayerProperties, 
		const typename _t_datalayerproperties::sub_node_iter_type nNodeSize, 
		const _t_reference *pReference, 
		const bool bAtomicTesting
	)
	:	_t_associative (rDataLayerProperties, nNodeSize)
	,	CBTreeTestBase<_t_reference> (pReference, bAtomicTesting)
{
	this->m_psTestTimeStamp = new btree_time_stamp_t (this->get_time_stamp ());
}

template<class _t_associative, class _t_reference, class _t_data, class _t_key, class _t_datalayerproperties>
CBTreeTestBaseAssociative<_t_associative, _t_reference, _t_data, _t_key, _t_datalayerproperties>::CBTreeTestBaseAssociative
	(
		const CBTreeTestBaseAssociative<_t_associative, _t_reference, _t_data, _t_key, _t_datalayerproperties> &rContainer, 
		const bool bAssign
	)
	:	
	_t_associative
	(
		dynamic_cast<const _t_associative &> (rContainer), 
		bAssign
	), 
	CBTreeTestBase<_t_reference>
	(
		dynamic_cast<const CBTreeTestBase<_t_reference> &> (rContainer)
	)
{
	this->m_psTestTimeStamp = new btree_time_stamp_t (this->get_time_stamp ());
}

template<class _t_associative, class _t_reference, class _t_data, class _t_key, class _t_datalayerproperties>
CBTreeTestBaseAssociative<_t_associative, _t_reference, _t_data, _t_key, _t_datalayerproperties>::CBTreeTestBaseAssociative
	(CBTreeTestBaseAssociative<_t_associative, _t_reference, _t_data, _t_key, _t_datalayerproperties> &&rRhsContainer)
	:	
	_t_associative
	(
		dynamic_cast<_t_associative &&> (rRhsContainer)
	), 
	CBTreeTestBase<_t_reference>
	(
		dynamic_cast<CBTreeTestBase<_t_reference> &&> (rRhsContainer)
	)
{
}

template<class _t_associative, class _t_reference, class _t_data, class _t_key, class _t_datalayerproperties>
CBTreeTestBaseAssociative<_t_associative, _t_reference, _t_data, _t_key, _t_datalayerproperties>::~CBTreeTestBaseAssociative ()
{
}

template<class _t_associative, class _t_reference, class _t_data, class _t_key, class _t_datalayerproperties>
void CBTreeTestBaseAssociative<_t_associative, _t_reference, _t_data, _t_key, _t_datalayerproperties>::set_atomic_testing (const bool bEnable)
{
	this->m_bAtomicTesting = bEnable;
}

template<class _t_associative, class _t_reference, class _t_data, class _t_key, class _t_datalayerproperties>
void CBTreeTestBaseAssociative<_t_associative, _t_reference, _t_data, _t_key, _t_datalayerproperties>::test () const
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

	typedef typename reference_t::const_iterator			ref_citer_t;
	typedef typename reference_t::value_type				ref_value_type;

	reference_t									sMMap;
	key_type									nKey;
	key_type									*pnKey;
	bool										bBounce;
	size_type									nTotalCount = 0;
	value_type									sEntry;
	ref_citer_t									sItMMapLower;
	ref_citer_t									sItMMapUpper;
	ref_citer_t									sItMMap;
	const_iterator								sCIterBegin;
	const_iterator								sCIterEnd;
	const_iterator								sCIterLower;
	const_iterator								sCIterUpper;
	const_iterator								sCIter;
	bool										bDeleted;
	
	if (!this->test_integrity ())
	{
		::std::cerr << ::std::endl;
		::std::cerr << "integrity test failed" << ::std::endl;

		::std::cerr << "creating integrity.html..." << ::std::endl;

		this->show_integrity ("integrity.html");

		::std::cerr << "finished!" << ::std::endl;

		exit (-1);
	}

	sCIterBegin = _t_associative::cbegin ();
	sCIterEnd = _t_associative::cend ();

	sCIter = sCIterBegin;

	if (this->size () > 0)
	{
		nKey = get_entry_key ((value_type) *sCIter);

		pnKey = &nKey;
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
			sItMMapLower = this->m_pClRef->lower_bound (*pnKey);

			sCIterLower = _t_associative::lower_bound (*pnKey);

			ref_value_type						sValue ((ref_value_type) *sItMMapLower);

			sEntry = ((value_type) (*sCIterLower));

			if (is_entry_not_equal_to_entry (sEntry, sValue))
			{
				::std::cerr << ::std::endl;
				::std::cerr << "data mismatches" << ::std::endl;
				::std::cerr << "key: " << std::setfill ('0') << std::hex << std::setw (8) << get_entry_key (sEntry) << ::std::endl;
				::std::cerr << "data: " << get_entry_data (sEntry) << ::std::endl;

				::std::cerr << std::setfill (' ') << std::dec << std::setw (0);

				::std::cerr << "debug: " << get_entry_debug (sEntry) << ::std::endl;
				::std::cerr << "reference" << ::std::endl;

				::std::cerr << "data: " << std::setfill ('0') << std::hex << std::setw (8) << get_entry_data (sValue) << ::std::endl;

				::std::cerr << std::setfill (' ') << std::dec << std::setw (0);

				::std::cerr << "debug: " << get_entry_debug (sValue) << ::std::endl;
				
				::std::cerr << "creating data.html..." << ::std::endl;

				this->show_integrity ("data.html");

				::std::cerr << "finished!" << ::std::endl;

				exit (-1);
			}
		}
		else
		{
			sItMMapLower = this->m_pClRef->lower_bound (*pnKey);
			sItMMapUpper = this->m_pClRef->upper_bound (*pnKey);

			sMMap.insert (sItMMapLower, sItMMapUpper);

			sCIterLower = _t_associative::lower_bound (*pnKey);
			sCIterUpper = _t_associative::upper_bound (*pnKey);

			for (sCIter = sCIterLower; sCIter != sCIterUpper; sCIter++)
			{
				sEntry = ((value_type) (*sCIter));

				bDeleted = false;

				for (sItMMap = sMMap.cbegin (); sItMMap != sMMap.cend (); sItMMap++)
				{
					ref_value_type				sValue ((ref_value_type) *sItMMap);

					if (get_entry_data (sEntry) == get_entry_data (sValue))
					{
						if (get_entry_debug (sEntry) == get_entry_debug (sValue))
						{
							sMMap.erase (sItMMap);

							bDeleted = true;

							break;
						}
					}
				}

				if (!bDeleted)
				{
					::std::cerr << ::std::endl;
					::std::cerr << "number of instances mismatches" << ::std::endl;
					::std::cerr << "key: " << std::setfill ('0') << std::hex << std::setw (8) << get_entry_key (sEntry) << ::std::endl;
					::std::cerr << "data: " << get_entry_data (sEntry) << ::std::endl;

					::std::cerr << std::setfill (' ') << std::dec << std::setw (0);

					::std::cerr << "debug: " << get_entry_debug (sEntry) << ::std::endl;
					::std::cerr << "Instance not found in reference!" << ::std::endl;

					::std::cerr << "creating error.html..." << ::std::endl;

					this->show_integrity ("error.html");

					::std::cerr << "finished!" << ::std::endl;

					exit (-1);
				}
			}

			if (sMMap.size () != 0)
			{
				::std::cerr << ::std::endl;
				::std::cerr << "number of instances mismatches" << ::std::endl;
				::std::cerr << "the following entries are still present in reference:" << ::std::endl;

				for (sItMMap = sMMap.cbegin (); sItMMap != sMMap.cend (); sItMMap++)
				{
					ref_value_type						sValue ((ref_value_type) *sItMMap);

					::std::cerr << "key: ";

					::std::cerr << std::setfill ('0') << std::hex << std::setw (8);
					{
						::std::cerr << get_entry_key (sValue) << " ";
						::std::cerr << "data: " << ::std::flush;
						::std::cerr << get_entry_data (sValue) << " ";
					}
					::std::cerr << std::setfill (' ') << std::dec << std::setw (0);

					::std::cerr << "debug: " << get_entry_debug (sValue) << ::std::endl;
				}

				::std::cerr << "creating error.html..." << ::std::endl;

				this->show_integrity ("error.html");

				::std::cerr << "finished!" << ::std::endl;

				exit (-1);
			}
		}

		_t_associative::get_next_key (*pnKey, *pnKey, bBounce);

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

template<class _t_associative, class _t_reference, class _t_data, class _t_key, class _t_datalayerproperties>
CBTreeTestBaseAssociative<_t_associative, _t_reference, _t_data, _t_key, _t_datalayerproperties> &
CBTreeTestBaseAssociative<_t_associative, _t_reference, _t_data, _t_key, _t_datalayerproperties>::operator= (const CBTreeTestBaseAssociative<_t_associative, _t_reference, _t_data, _t_key, _t_datalayerproperties> &rContainer)
{
	if (this != &rContainer)
	{
		CBTreeTestBase_t			&rTestBaseThis = dynamic_cast<CBTreeTestBase_t &> (*this);
		const CBTreeTestBase_t		&rTestBaseContainer = dynamic_cast<const CBTreeTestBase_t &> (rContainer);

		rTestBaseThis = rTestBaseContainer;

		_t_associative				&rAssociativeThis = dynamic_cast<_t_associative &> (*this);
		const _t_associative		&rAssociativeContainer = dynamic_cast<const _t_associative &> (rContainer);

		rAssociativeThis = rAssociativeContainer;
	}

	return (*this);
}

template<class _t_associative, class _t_reference, class _t_data, class _t_key, class _t_datalayerproperties>
CBTreeTestBaseAssociative<_t_associative, _t_reference, _t_data, _t_key, _t_datalayerproperties> &
CBTreeTestBaseAssociative<_t_associative, _t_reference, _t_data, _t_key, _t_datalayerproperties>::operator= (CBTreeTestBaseAssociative<_t_associative, _t_reference, _t_data, _t_key, _t_datalayerproperties> &&rRhsContainer)
{
	CBTreeTestBase_t		&rTestBaseThis = dynamic_cast<CBTreeTestBase_t &> (*this);
	CBTreeTestBase_t		&rTestBaseContainer = dynamic_cast<CBTreeTestBase_t &> (rRhsContainer);

	rTestBaseThis = ::std::move (rTestBaseContainer);

	_t_associative			&rAssociativeThis = dynamic_cast<_t_associative &> (*this);
	_t_associative			&rAssociativeContainer = dynamic_cast<_t_associative &> (rRhsContainer);

	rAssociativeThis = ::std::move (rAssociativeContainer);

	return (*this);
}

template<class _t_associative, class _t_reference, class _t_data, class _t_key, class _t_datalayerproperties>
void CBTreeTestBaseAssociative<_t_associative, _t_reference, _t_data, _t_key, _t_datalayerproperties>::_swap (CBTreeTestBaseAssociative_t &rContainer)
{
	_t_associative		&rLinearContainer = dynamic_cast<_t_associative &> (rContainer);

	_t_associative::_swap (rLinearContainer);

	CBTreeTestBase_t	&rTestBaseContainer = dynamic_cast<CBTreeTestBase_t &> (rContainer);

	CBTreeTestBase_t::_swap (rTestBaseContainer);
}

#endif // BTREETESTBASEASSOCIATIVE_CPP

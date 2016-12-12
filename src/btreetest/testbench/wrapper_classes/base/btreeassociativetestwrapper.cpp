/************************************************************
**
** file:	btreeassociativetestwrapper.cpp
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
** This file contains the definition of the associative container
** test class wrapping abstract accesses to associative container test class
** and a templatebased reference container instance, while making sure the
** associative container instance acts the same way as the abstract reference.
**
************************************************************/

#include "testbench/wrapper_classes/base/btreeassociativetestwrapper.h"

#ifndef BTREEASSOCIATIVETESTWRAPPER_CPP
#define BTREEASSOCIATIVETESTWRAPPER_CPP

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeAssociativeTestWrapper (const uint32_t nNodeSize, const uint32_t nPageSize)
	:	m_pReference (NULL)
	,	m_nNodeSize (nNodeSize)
	,	m_nPageSize (nPageSize)
	,	m_nHintVariation (0)
{
	m_pReference = new reference_t;

	BTREE_ASSERT (m_pReference != NULL, "CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeAssociativeTestWrapper: ERROR: insufficient memory! (m_pReference)");
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeAssociativeTestWrapper (const CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container> &rContainer)
	:	m_pReference (NULL)
	,	m_nNodeSize (rContainer.m_nNodeSize)
	,	m_nPageSize (rContainer.m_nPageSize)
	,	m_nHintVariation (0)
{
	m_pReference = new reference_t (*rContainer.m_pReference);

	BTREE_ASSERT (m_pReference != NULL, "CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeAssociativeTestWrapper (const CBTreeAssociativeTestWrapper &): ERROR: insufficient memory! (m_pReference)");
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeAssociativeTestWrapper (CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container> &&rRhsContainer)
	:	m_pReference (NULL)
	,	m_nNodeSize (rRhsContainer.m_nNodeSize)
	,	m_nPageSize (rRhsContainer.m_nPageSize)
	,	m_nHintVariation (0)
{
	m_pReference = new reference_t;

	BTREE_ASSERT (m_pReference != NULL, "CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::CBTreeAssociativeTestWrapper (const CBTreeAssociativeTestWrapper &): ERROR: insufficient memory! (m_pReference)");

	fast_swap (m_pReference, rRhsContainer.m_pReference);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::~CBTreeAssociativeTestWrapper ()
{
	uint32_t		i;

	if (m_ppContainers != NULL)
	{
		for (i = 0; i < this->get_num_containers (); i++)
		{
			if (m_ppContainers[i] != NULL)
			{
				delete m_ppContainers[i];
			}
		}

		delete [] m_ppContainers;
	}

	if (m_pReference != NULL)
	{
		delete m_pReference;
	}
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::size_type CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::size () const
{
	size_type		nSize = m_pReference->size ();
	uint32_t			i;

	for (i = 0; i < this->get_num_containers (); i++)
	{
		if (nSize != m_ppContainers[i]->size ())
		{
			::std::cerr << "Container returned different size than the reference container" << ::std::endl;
			::std::cerr << "reference size:" << nSize << ::std::endl;
			::std::cerr << "container size (" << i << "):" << m_ppContainers[i]->size () << ::std::endl;
			::std::cerr << "writing output to size.html" << ::std::endl << ::std::flush;

			m_ppContainers[i]->show_integrity ("size.html");

			::std::cerr << "completed" << ::std::endl << ::std::flush;

			exit (-1);
		}
	}

	return (nSize);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
void CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::clear ()
{
	uint32_t		i;

	m_pReference->clear ();

	for (i = 0; i < this->get_num_containers (); i++)
	{
		m_ppContainers[i]->clear ();
	}

	this->test ();
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename _t_ref_container::iterator CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::begin ()
{
	iterator		sIter = this->m_pReference->begin ();

	return (sIter);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename _t_ref_container::iterator CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::end ()
{
	iterator		sIter = this->m_pReference->end ();

	return (sIter);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename _t_ref_container::reverse_iterator CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::rbegin ()
{
	reverse_iterator		sRIter = this->m_pReference->rbegin ();

	return (sRIter);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename _t_ref_container::reverse_iterator CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::rend ()
{
	reverse_iterator		sRIter = this->m_pReference->rend ();

	return (sRIter);
}

	

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename _t_ref_container::const_iterator CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::cbegin () const
{
	const_iterator		sCIter = this->m_pReference->cbegin ();

	return (sCIter);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename _t_ref_container::const_iterator CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::cend () const
{
	const_iterator		sCIter = this->m_pReference->cend ();

	return (sCIter);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename _t_ref_container::const_reverse_iterator CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::crbegin () const
{
	const_reverse_iterator	sCRIter = this->m_pReference->crbegin ();

	return (sCRIter);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename _t_ref_container::const_reverse_iterator CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::crend () const
{
	const_reverse_iterator	sCRIter = this->m_pReference->crend ();

	return (sCRIter);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
void CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::swap (CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container> &rContainer)
{
	m_pReference->swap ((reference_t &) (*(rContainer.m_pReference)));

	uint32_t	i;

	for (i = 0; i < this->get_num_containers (); i++)
	{
		m_ppContainers[i]->swap ((CBTreeAssociativeIf_t &) (*(rContainer.m_ppContainers[i])));
	}

	test ();
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::iterator CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::insert (const typename CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::value_type &rData, const bool bInsertNotEmplace)
{
	iterator			sRefIter;
	size_type			nRefDiff;
	size_type			nRefKeyDist;
	uint32_t			i;
	test_iterator		sTestIter;
	size_test_type		nTestDiff;
	size_test_type		nTestKeyDist;
	value_test_type		sData;

	sRefIter = m_pReference->insert (rData);

	nRefDiff = ::std::distance (m_pReference->begin (), sRefIter);

	sRefIter = m_pReference->lower_bound (get_entry_key (rData));

	nRefKeyDist = ::std::distance (m_pReference->begin (), sRefIter);

	for (i = 0; i < this->get_num_containers (); i++)
	{
		entry_conversion (sData, rData);

		if (bInsertNotEmplace)
		{
			sTestIter = m_ppContainers[i]->insert (sData);
		}
		else
		{
			sTestIter = m_ppContainers[i]->emplace (::std::forward<value_test_type> (value_test_type (sData)));
		}

		nTestDiff = ::std::distance (m_ppContainers[i]->begin (), sTestIter);

		sTestIter = m_ppContainers[i]->lower_bound (get_entry_key (sData));

		nTestKeyDist = ::std::distance (m_ppContainers[i]->begin (), sTestIter);

		if ((nTestDiff != nRefDiff) || (nTestKeyDist != nRefKeyDist))
		{
			::std::cerr << "Container returned different iterator offset than reference container" << ::std::endl;
			::std::cerr << "reference offset:" << nRefDiff << ::std::endl;
			::std::cerr << "container offset (" << i << "):" << nTestDiff << ::std::endl;
			::std::cerr << "reference distance:" << nRefKeyDist << ::std::endl;
			::std::cerr << "container distance (" << i << "):" << nTestKeyDist << ::std::endl;
			::std::cerr << "writing output to mismatch.html" << ::std::endl << ::std::flush;

			m_ppContainers[i]->show_integrity ("mismatch.html");

			::std::cerr << "completed" << ::std::endl << ::std::flush;

			exit (-1);
		}
	}

	this->test ();

	return (sRefIter);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
void CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::insert_hint (const typename CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::value_type &rData, const bool bInsertNotEmplace)
{
	iterator					sRefIter;
	iterator					sIterBegin;
	size_type					nRefDiff;
	size_type					nRefKeyDist;
	size_type					nDist;
	uint32_t					i;
	test_iterator				sTestIter;
	size_test_type				nTestDiff;
	size_test_type				nTestKeyDist;
	value_test_type				sData;
	test_const_iterator			sCIterTestHint;
	signed_size_type			nVariation = 0;
	size_type					nHintVariation;
	
	sRefIter = m_pReference->insert (rData);

	nRefDiff = ::std::distance (m_pReference->begin (), sRefIter);

	sRefIter = m_pReference->lower_bound (get_entry_key (rData));

	nRefKeyDist = ::std::distance (m_pReference->begin (), sRefIter);

	nDist = nRefDiff;

	if (generate_rand32 () & 0x1)
	{
		nHintVariation = ::std::min<size_type> (nDist, this->m_nHintVariation);

		nVariation = 0 - (generate_rand32 () % (nHintVariation + 1));
	}
	else
	{
		nHintVariation = ::std::min<size_type> ((this->m_pReference->size () - 1) - nDist, this->m_nHintVariation);

		nVariation = generate_rand32 () % (nHintVariation + 1);
	}

	nDist += nVariation;

	for (i = 0; i < this->get_num_containers (); i++)
	{
		entry_conversion (sData, rData);

		sCIterTestHint = m_ppContainers[i]->cbegin ();

		::std::advance (sCIterTestHint, nDist);

		sCIterTestHint.sync ();

		if (bInsertNotEmplace)
		{
			sTestIter = m_ppContainers[i]->insert (sCIterTestHint, sData);
		}
		else
		{
			sTestIter = m_ppContainers[i]->emplace_hint (sCIterTestHint, ::std::forward<value_test_type> (value_test_type (sData)));
		}

		nTestDiff = ::std::distance (m_ppContainers[i]->begin (), sTestIter);

		sTestIter = m_ppContainers[i]->lower_bound (get_entry_key (sData));

		nTestKeyDist = ::std::distance (m_ppContainers[i]->begin (), sTestIter);

		if ((nTestDiff != nRefDiff) || (nTestKeyDist != nRefKeyDist))
		{
			::std::cerr << "Container returned different iterator offset than reference container" << ::std::endl;
			::std::cerr << "reference offset:" << nRefDiff << ::std::endl;
			::std::cerr << "container offset (" << i << "):" << nTestDiff << ::std::endl;
			::std::cerr << "reference distance:" << nRefKeyDist << ::std::endl;
			::std::cerr << "container distance (" << i << "):" << nTestKeyDist << ::std::endl;
			::std::cerr << "writing output to mismatch.html" << ::std::endl << ::std::flush;

			m_ppContainers[i]->show_integrity ("mismatch.html");

			::std::cerr << "completed" << ::std::endl << ::std::flush;

			exit (-1);
		}
	}

	this->test ();
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename _t_ref_container::iterator CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::erase (typename _t_ref_container::const_iterator sCIterPos)
{
	size_type			nOffset = ::std::distance (m_pReference->cbegin (), sCIterPos);
	uint32_t			i;
	iterator			sRefIter;
	size_type			nRefDiff;
	size_test_type		nTestDiff;
	value_type			sValue = *sCIterPos;
	key_type			sKey = get_entry_key (sValue);
	size_type			nKeys = m_pReference->count (sKey);

	sRefIter = m_pReference->erase (sCIterPos);

	nRefDiff = ::std::distance (m_pReference->begin (), sRefIter);

	for (i = 0; i < this->get_num_containers (); i++)
	{
		if (nKeys < 2)
		{
			test_const_iterator		sCIter = m_ppContainers[i]->cbegin ();
			test_iterator			sIter;

			::std::advance (sCIter, (size_test_type) nOffset);

			sIter = m_ppContainers[i]->erase (sCIter);

			nTestDiff = ::std::distance (m_ppContainers[i]->begin (), sIter);

			if (nTestDiff != nRefDiff)
			{
				::std::cerr << "Container returned different iterator offset than reference container" << ::std::endl;
				::std::cerr << "reference offset:" << nRefDiff << ::std::endl;
				::std::cerr << "container offset (" << i << "):" << nTestDiff << ::std::endl;
				::std::cerr << "writing output to mismatch.html" << ::std::endl << ::std::flush;

				m_ppContainers[i]->show_integrity ("mismatch.html");

				::std::cerr << "completed" << ::std::endl << ::std::flush;

				exit (-1);
			}
		}
		else
		{
			test_const_iterator		sCIterLower = m_ppContainers[i]->lower_bound (sKey);
			test_const_iterator		sCIterUpper = m_ppContainers[i]->upper_bound (sKey);

			while (sCIterLower < sCIterUpper)
			{
				value_test_type			sValueTest;

				entry_conversion (sValueTest, *sCIterLower);

				if (!is_entry_not_equal_to_entry (sValue, sValueTest))
				{
					if (get_entry_debug (sValue) == get_entry_debug (sValueTest))
					{
						m_ppContainers[i]->erase (sCIterLower);

						break;
					}
				}

				::std::advance (sCIterLower, 1);
			}
		}
	}

	this->test ();

	return (sRefIter);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename _t_ref_container::size_type CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::erase (typename _t_ref_container::key_type &rKey)
{
	size_type		nRefRslt;
	size_test_type		nTestRslt;
	uint32_t			i;
	
	nRefRslt = m_pReference->erase (rKey);

	for (i = 0; i < this->get_num_containers (); i++)
	{
		nTestRslt = m_ppContainers[i]->erase (rKey);

		if (nTestRslt != nRefRslt)
		{
			::std::cerr << "Container returned different number of entries removed than reference container" << ::std::endl;
			::std::cerr << "reference offset:" << nRefRslt << ::std::endl;
			::std::cerr << "container offset (" << i << "):" << nTestRslt << ::std::endl;
			::std::cerr << "writing output to mismatch.html" << ::std::endl << ::std::flush;

			m_ppContainers[i]->show_integrity ("mismatch.html");

			::std::cerr << "completed" << ::std::endl << ::std::flush;

			exit (-1);
		}
	}

	this->test ();

	return (nRefRslt);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename _t_ref_container::iterator CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::erase (typename _t_ref_container::const_iterator sCIterFirst, typename _t_ref_container::const_iterator sCIterLast)
{
	size_type			nFirst = ::std::distance (m_pReference->cbegin (), sCIterFirst);
	size_type			nLast = ::std::distance (m_pReference->cbegin (), sCIterLast);
	uint32_t			i;
	iterator			sRefIter;
	size_test_type		nRefDiff;
	size_test_type		nTestDiff;

	sRefIter = m_pReference->erase (sCIterFirst, sCIterLast);

	nRefDiff = (size_test_type) ::std::distance (m_pReference->begin (), sRefIter);

	for (i = 0; i < this->get_num_containers (); i++)
	{
		test_const_iterator		sCIterTestFirst = m_ppContainers[i]->cbegin ();
		test_const_iterator		sCIterTestLast = m_ppContainers[i]->cbegin ();
		test_iterator			sIter;

		::std::advance (sCIterTestFirst, (size_test_type) nFirst);
		::std::advance (sCIterTestLast, (size_test_type) nLast);

		sIter = m_ppContainers[i]->erase (sCIterTestFirst, sCIterTestLast);

		nTestDiff = ::std::distance (m_ppContainers[i]->begin (), sIter);

		if (nTestDiff != nRefDiff)
		{
			::std::cerr << "Container returned different iterator offset than reference container" << ::std::endl;
			::std::cerr << "reference offset:" << nRefDiff << ::std::endl;
			::std::cerr << "container offset (" << i << "):" << nTestDiff << ::std::endl;
			::std::cerr << "writing output to mismatch.html" << ::std::endl << ::std::flush;

			m_ppContainers[i]->show_integrity ("mismatch.html");

			::std::cerr << "completed" << ::std::endl << ::std::flush;

			exit (-1);
		}
	}

	this->test ();

	return (sRefIter);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename _t_ref_container::iterator CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::find (typename _t_ref_container::key_type &rKey)
{
	iterator		sIter = this->m_pReference->find (rKey);
	size_type		nRefOffset = ::std::distance (m_pReference->begin (), sIter);
	uint32_t		i;

	for (i = 0; i < this->get_num_containers (); i++)
	{
		test_iterator	sTestIter = m_ppContainers[i]->find (rKey);
		size_test_type	nTestOffset = ::std::distance (m_ppContainers[i]->begin (), sTestIter);

		if (((sIter == m_pReference->end ()) != (sTestIter == m_ppContainers[i]->end ())) || 
			((sIter != m_pReference->end ()) && (get_entry_key (*sIter) != get_entry_key ((const _t_value &) *sTestIter))))
		{
			::std::cerr << "Container returned iterator pointing at an entry displaying a different key than reference container" << ::std::endl;

			if (sIter == m_pReference->end ())
			{
				::std::cerr << "reference key value: ? at " << nRefOffset << ::std::endl;
			}
			else
			{
				::std::cerr << "reference key value: " << get_entry_key (*sIter) << " at " << nRefOffset << ::std::endl;
			}

			if (sTestIter == m_ppContainers[i]->end ())
			{
				::std::cerr << "container key value (" << i << "): ? at " << nTestOffset << ::std::endl;
			}
			else
			{
				::std::cerr << "container key value (" << i << "): " << get_entry_key ((const _t_value &) *sTestIter) << " at " << nTestOffset << ::std::endl;
			}

			::std::cerr << "writing output to mismatch.html" << ::std::endl << ::std::flush;

			m_ppContainers[i]->show_integrity ("mismatch.html");

			::std::cerr << "completed" << ::std::endl << ::std::flush;

			exit (-1);
		}
	}

	return (sIter);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename _t_ref_container::const_iterator CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::find (typename _t_ref_container::key_type &rKey) const
{
	const_iterator		sCIter = this->m_pReference->find (rKey);
	size_type			nRefOffset = ::std::distance (m_pReference->cbegin (), sCIter);
	uint32_t			i;

	for (i = 0; i < this->get_num_containers (); i++)
	{
		test_const_iterator		sTestCIter = ((const CBTreeAssociativeIf_t *) m_ppContainers[i])->find (rKey);
		size_test_type			nTestOffset = ::std::distance (m_ppContainers[i]->cbegin (), sTestCIter);

		if (((sCIter == m_pReference->end ()) != (sTestCIter == m_ppContainers[i]->end ())) || 
			((sCIter != m_pReference->end ()) && (get_entry_key (*sCIter) != get_entry_key ((const value_test_type &) *sTestCIter))))
		{
			::std::cerr << "Container returned iterator pointing at an entry displaying a different key than reference container" << ::std::endl;

			if (sCIter == m_pReference->cend ())
			{
				::std::cerr << "reference key value: ? at " << nRefOffset << ::std::endl;
			}
			else
			{
				::std::cerr << "reference key value: " << get_entry_key (*sCIter) << " at " << nRefOffset << ::std::endl;
			}

			if (sTestCIter == m_ppContainers[i]->cend ())
			{
				::std::cerr << "container key value (" << i << "): ? at " << nTestOffset << ::std::endl;
			}
			else
			{
				::std::cerr << "container key value (" << i << "): " << get_entry_key ((const value_test_type &) *sTestCIter) << " at " << nTestOffset << ::std::endl;
			}

			::std::cerr << "writing output to mismatch.html" << ::std::endl << ::std::flush;

			m_ppContainers[i]->show_integrity ("mismatch.html");

			::std::cerr << "completed" << ::std::endl << ::std::flush;

			exit (-1);
		}
	}

	return (sCIter);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename _t_ref_container::iterator CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::lower_bound (typename _t_ref_container::key_type &rKey)
{
	const_iterator		sCIter = this->template _bound <test_iterator, CBTreeAssociativeIf_t> (rKey, true);
	size_type			nDiff = ::std::distance (this->m_pReference->cbegin (), sCIter);
	iterator			sIter = this->m_pReference->begin ();

	::std::advance (sIter, nDiff);

	return (sIter);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename _t_ref_container::const_iterator CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::lower_bound (typename _t_ref_container::key_type &rKey) const
{
	return (this->template _bound <test_const_iterator, const CBTreeAssociativeIf_t> (rKey, true));
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename _t_ref_container::iterator CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::upper_bound (typename _t_ref_container::key_type &rKey)
{
	const_iterator	sCIter = this->template _bound <test_iterator, CBTreeAssociativeIf_t> (rKey, false);
	iterator		sIter = this->m_pReference->begin ();
	size_type		nDiff = ::std::distance (this->m_pReference->cbegin (), sCIter);

	::std::advance (sIter, nDiff);

	return (sIter);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename _t_ref_container::const_iterator CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::upper_bound (typename _t_ref_container::key_type &rKey) const
{
	return (this->template _bound <test_const_iterator, const CBTreeAssociativeIf_t> (rKey, false));
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::equal_range_type
	CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::equal_range (key_type &rKey)
{
	equal_range_const_type		sCEqRange = this->template _equal_range <test_iterator, CBTreeAssociativeIf_t> (rKey);

	iterator					sIterLower = this->m_pReference->begin ();
	size_type					nDiff = ::std::distance (this->m_pReference->cbegin (), sCEqRange.first);

	::std::advance (sIterLower, nDiff);

	iterator					sIterUpper = this->m_pReference->begin ();

	nDiff = ::std::distance (this->m_pReference->cbegin (), sCEqRange.second);

	::std::advance (sIterUpper, nDiff);

	return (equal_range_type (sIterLower, sIterUpper));
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::equal_range_const_type
	CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::equal_range (key_type &rKey) const
{
	return (this->template _equal_range <test_const_iterator, const CBTreeAssociativeIf_t> (rKey));
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename _t_ref_container::size_type CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::count (typename _t_ref_container::key_type &rKey) const
{
	size_type		nRefRslt = m_pReference->count (rKey);
	uint32_t			i;

	for (i = 0; i < this->get_num_containers (); i++)
	{
		size_test_type			nTestRslt = m_ppContainers[i]->count (rKey);

		if (nRefRslt != nTestRslt)
		{
			::std::cerr << "Container returned different offset than reference container" << ::std::endl;
			::std::cerr << "input key value: " << rKey << :: std::endl;
			::std::cerr << "reference count result:" << nRefRslt << ::std::endl;
			::std::cerr << "container key value (" << i << "):" << nTestRslt << ::std::endl;
			::std::cerr << "writing output to mismatch.html" << ::std::endl << ::std::flush;

			m_ppContainers[i]->show_integrity ("mismatch.html");

			::std::cerr << "completed" << ::std::endl << ::std::flush;

			exit (-1);
		}
	}

	return (nRefRslt);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
typename CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::size_type CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::serialize (const size_type nStart, const size_type nLen, typename CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::value_type *pData) const
{
	size_type				i;
	size_type				j;
	const_iterator			sCIter;
	size_type				nRslt;
	size_type				nRetval;
	value_test_type			*pContainerData = new value_test_type [(size_t) nLen];

	if (pContainerData == NULL)
	{
		::std::cerr << "CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::serialize: insufficient memory!" << ::std::endl;

		exit (-1);
	}

	for (i = 0; i < this->get_num_containers (); i++)
	{
		nRetval = 
			(size_type) m_ppContainers[i]->serialize ((size_test_type) nStart, (size_test_type) nLen, pContainerData);
		
		for (j = 0; j < nRetval; j++)
		{
			entry_conversion (pData[j], pContainerData[j]);
		}

		if (i == 0)
		{
			nRslt = nRetval;
		}
		else
		{
			if (nRslt != nRetval)
			{
				::std::cerr << "ERROR: CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::serialize: unexpected size!" << ::std::endl;
				::std::cerr << "container return value (" << i << "): " << nRetval << ::std::endl;
				::std::cerr << "container return value (" << (i - 1) << "): " << nRslt << ::std::endl;
				::std::cerr << "outputting serialize.html" << ::std::endl << ::std::flush;

				m_ppContainers[i]->show_integrity ("serialize.html");

				::std::cerr << "completed" << ::std::endl << ::std::flush;

				exit (-1);
			}
		}

		sCIter = m_pReference->cbegin ();

		::std::advance (sCIter, nStart);

		for (j = 0; j < nRslt; j++, sCIter++)
		{
			value_type				sEntry (*sCIter);
			
			if (memcmp ((void *) &(pData[j]), (void *) &sEntry, sizeof (sEntry)) != 0)
			{
				::std::cerr << "ERROR: CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::serialize: data mismatch!" << ::std::endl;
				::std::cerr << "container: " << i << ::std::endl;
				::std::cerr << "position: " << j << ::std::endl;
				::std::cerr << "key: " << get_entry_key (pData[j]) << " " << get_entry_key (sEntry) << ::std::endl;
				::std::cerr << "data: " << get_entry_data (pData[j]) << " " << get_entry_data (sEntry) << ::std::endl;
				::std::cerr << "debug: " << get_entry_debug (pData[j]) << " " << get_entry_debug (sEntry) << ::std::endl;
				::std::cerr << "outputting serialize.html" << ::std::endl << ::std::flush;

				m_ppContainers[i]->show_integrity ("serialize.html");

				::std::cerr << "completed" << ::std::endl << ::std::flush;

				exit (-1);
			}
		}
	}

	delete [] pContainerData;

	return (nRslt);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
void CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::set_iter_data (typename CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::const_iterator sCIter, const typename CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::value_type &rData)
{
	const_iterator			sCIterBegin;
	size_type				nDist;
	value_test_type			sTestData;
	uint32_t				i;

	entry_conversion (sTestData, rData);

	get_begin (m_pReference, sCIterBegin);
	
	nDist = ::std::distance (sCIterBegin, sCIter);

	m_pReference->erase (sCIter);

	m_pReference->insert (rData);

	for (i = 0; i < this->get_num_containers (); i++)
	{
		test_iterator		sTestIter;

		get_begin (m_ppContainers[i], sTestIter);

		::std::advance (sTestIter, (size_test_type) nDist);

		*sTestIter = sTestData;
	}

	test ();
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
void CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::unload ()
{
	uint32_t	i;

	for (i = 0; i < this->get_num_containers (); i++)
	{
		m_ppContainers[i]->unload ();
	}
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
bool CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::compare_individual_containers (const CBTreeAssociativeTestWrapper &rContainer) const
{
	bool		bRslt;
	uint32_t	ui32;

	bRslt = *(this->m_pReference) == *(rContainer.m_pReference);

	for (ui32 = 0; ui32 < this->get_num_containers (); ui32++)
	{
		bool	bCntRslt = *(this->m_ppContainers[ui32]) == *(rContainer.m_ppContainers[ui32]);

		BTREE_ASSERT (bRslt == bCntRslt, "CBTreeAssociativeTestWrapper<>::compare_individual_containers: ERROR: Unexpected container mismatch!");
	}

	return (bRslt);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
void CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::set_hint_variation (const typename _t_ref_container::size_type nHintVariation)
{
	m_nHintVariation = nHintVariation;
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>& CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::operator= (const CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container> &rContainer)
{
	uint32_t		i;

	*(this->m_pReference) = *(rContainer.m_pReference);

	disable_atomic_testing ();
	{
		for (i = 0; i < this->get_num_containers (); i++)
		{
			*(this->m_ppContainers[i]) = *(rContainer.m_ppContainers[i]);
		}
	}
	enable_atomic_testing ();

	this->test ();

	return (*this);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>& CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::operator= (CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container> &&rRhsContainer)
{
	uint32_t		i;

	this->m_pReference->swap (*(rRhsContainer.m_pReference));

	disable_atomic_testing ();
	{
		for (i = 0; i < this->get_num_containers (); i++)
		{
			*(this->m_ppContainers[i]) = ::std::move (*(rRhsContainer.m_ppContainers[i]));
		}
	}
	enable_atomic_testing ();

	this->test ();

	return (*this);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
bool CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::operator== (const CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container> &rContainer) const
{
	if (this == &rContainer)
	{
		return (true);
	}

	this->test ();

	if (this->size () != rContainer.size ())
	{
		return (false);
	}

	const_iterator		sCIter, sExtCIter;

	sCIter = m_pReference->cbegin ();
	sExtCIter = rContainer.m_pReference->cbegin ();

	while (sCIter != m_pReference->cend ())
	{
		typename reference_t::value_type		sEntry (*sCIter);
		typename reference_t::value_type		sExtEntry (*sExtCIter);

		if (is_entry_not_equal_to_entry (sEntry, sExtEntry))
		{
			return (false);
		}

		::std::advance (sCIter, 1);
		::std::advance (sExtCIter, 1);
	}

	uint32_t		i;

	for (i = 0; i < this->get_num_containers (); i++)
	{
		if (*(m_ppContainers[i]) != *(rContainer.m_ppContainers[i]))
		{
			return (false);
		}
	}

	return (true);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
bool CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::operator!= (const CBTreeAssociativeTestWrapper &rContainer) const
{
	return (!(*(this) == rContainer));
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
void CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::show_integrity (const char *pszPrefix)
{
	uint32_t				i;
	
	for (i = 0; i < this->get_num_containers (); i++)
	{
		::std::stringstream		sStr;

		sStr << pszPrefix << ::std::setw (4) << ::std::setfill ('0') << i << ".html";

		m_ppContainers[i]->show_integrity (sStr.str ().c_str ());
	}
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
void CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::test () const
{
	uint32_t			i;

	for (i = 0; i < this->get_num_containers (); i++)
	{
		m_ppContainers[i]->test ();
	}
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
void CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::disable_atomic_testing () const
{
	uint32_t			i;

	for (i = 0; i < this->get_num_containers (); i++)
	{
		m_ppContainers[i]->set_atomic_testing (false);
	}
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
void CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::enable_atomic_testing () const
{
	uint32_t			i;

	for (i = 0; i < this->get_num_containers (); i++)
	{
		m_ppContainers[i]->set_atomic_testing (true);
	}
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
void CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::instantiate_container_array ()
{
	m_ppContainers = new CBTreeAssociativeIf<_t_value, uint32_t, size_test_type> * [this->get_num_containers ()];

	BTREE_ASSERT (NULL != m_ppContainers, "CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::instantiate_container_array: ERROR: insufficient memory! (m_ppContainers)");
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
uint32_t CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::get_num_containers () const
{
	return (m_nNumContainers);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
template<class _t_test_iterator, class _t_test_call_type>
typename CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::const_iterator
	CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::_bound (key_type &rKey, const bool bLowerNotUpper) const
{
	const_iterator		sCIter;
	size_type			nRefOffset;
	uint32_t			i;

	if (bLowerNotUpper)
	{
		sCIter = m_pReference->lower_bound (rKey);
	}
	else
	{
		sCIter = m_pReference->upper_bound (rKey);
	}

	nRefOffset = ::std::distance (m_pReference->cbegin (), sCIter);

	for (i = 0; i < this->get_num_containers (); i++)
	{
		_t_test_iterator	sTestIter;
		size_test_type		nTestOffset;

		if (bLowerNotUpper)
		{
			sTestIter = ((_t_test_call_type *) m_ppContainers[i])->lower_bound (rKey);
		}
		else
		{
			sTestIter = ((_t_test_call_type *) m_ppContainers[i])->upper_bound (rKey);
		}

		nTestOffset = ::std::distance (((_t_test_call_type *) m_ppContainers[i])->begin (), sTestIter);

		if (sCIter == this->m_pReference->cend ())
		{
			if (sTestIter != ((_t_test_call_type *) m_ppContainers[i])->end ())
			{
				::std::cerr << "Container didn't return end (iterator) while the reference container did" << ::std::endl;
				::std::cerr << "reference offset:" << nRefOffset << ::std::endl;
				::std::cerr << "container key value (" << i << "):" << nTestOffset << ::std::endl;
				::std::cerr << "writing output to mismatch.html" << ::std::endl << ::std::flush;

				m_ppContainers[i]->show_integrity ("mismatch.html");

				::std::cerr << "completed" << ::std::endl << ::std::flush;

				exit (-1);
			}

			continue;
		}

		if (get_entry_key (*sCIter) != get_entry_key ((const _t_value &) *sTestIter))
		{
			::std::cerr << "Container returned iterator pointing at an entry displaying a different key than reference container" << ::std::endl;
			::std::cerr << "reference key value:" << get_entry_key (*sCIter) << " at " << nRefOffset << ::std::endl;
			::std::cerr << "container key value (" << i << "):" << get_entry_key ((const _t_value &) *sTestIter) << " at " << nTestOffset << ::std::endl;
			::std::cerr << "writing output to mismatch.html" << ::std::endl << ::std::flush;

			m_ppContainers[i]->show_integrity ("mismatch.html");

			::std::cerr << "completed" << ::std::endl << ::std::flush;

			exit (-1);
		}

		if (nRefOffset != nTestOffset)
		{
			::std::cerr << "Container returned different offset than reference container" << ::std::endl;
			::std::cerr << "reference key value:" << get_entry_key (*sCIter) << " at " << nRefOffset << ::std::endl;
			::std::cerr << "container key value (" << i << "):" << get_entry_key ((const _t_value &) *sTestIter) << " at " << nTestOffset << ::std::endl;
			::std::cerr << "writing output to mismatch.html" << ::std::endl << ::std::flush;

			m_ppContainers[i]->show_integrity ("mismatch.html");

			::std::cerr << "completed" << ::std::endl << ::std::flush;

			exit (-1);
		}
	}

	return (sCIter);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
template<class _t_test_iterator, class _t_test_call_type>
typename CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::equal_range_const_type
	CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::_equal_range (key_type &rKey) const
{
	typedef typename ::std::pair<_t_test_iterator, _t_test_iterator>		test_equal_range_type;

	equal_range_const_type		sCEqRange;
	size_type					anRefOffset[2];
	uint32_t					i;

	sCEqRange = m_pReference->equal_range (rKey);

	anRefOffset[0] = ::std::distance (m_pReference->cbegin (), sCEqRange.first);
	anRefOffset[1] = ::std::distance (m_pReference->cbegin (), sCEqRange.second);

	for (i = 0; i < this->get_num_containers (); i++)
	{
		test_equal_range_type	sTestEqRange;
		size_test_type			anTestOffset[2];

		sTestEqRange = ((_t_test_call_type *) m_ppContainers[i])->equal_range (rKey);

		anTestOffset[0] = ::std::distance (((_t_test_call_type *) m_ppContainers[i])->begin (), sTestEqRange.first);
		anTestOffset[1] = ::std::distance (((_t_test_call_type *) m_ppContainers[i])->begin (), sTestEqRange.second);

		if (((sCEqRange.first == this->m_pReference->cend ()) && (sTestEqRange.first != ((_t_test_call_type *) m_ppContainers[i])->end ())) ||
			((sCEqRange.second == this->m_pReference->cend ()) && (sTestEqRange.second != ((_t_test_call_type *) m_ppContainers[i])->end ())))
		{
			::std::cerr << "Container (" << i << ") didn't return end (iterator) while the reference container did" << ::std::endl;
			::std::cerr << "reference offset lower" << anRefOffset[0] << ::std::endl;
			::std::cerr << "container offset lower" << anTestOffset[0] << ::std::endl;
			::std::cerr << "reference offset upper" << anRefOffset[1] << ::std::endl;
			::std::cerr << "container offset upper" << anTestOffset[1] << ::std::endl;
			::std::cerr << "writing output to mismatch.html" << ::std::endl << ::std::flush;

			m_ppContainers[i]->show_integrity ("mismatch.html");

			::std::cerr << "completed" << ::std::endl << ::std::flush;

			exit (-1);
		}

		if (sCEqRange.first == this->m_pReference->cend ())
		{
			continue;
		}

		_t_test_iterator	sIterTestLower = ((_t_test_call_type *) m_ppContainers[i])->lower_bound (rKey);

		if (sTestEqRange.first != sIterTestLower)
		{
			_t_test_iterator	sIterTestBegin = ((_t_test_call_type *) m_ppContainers[i])->begin ();

			::std::cerr << "equal_range.first and lower_bound () mismatch --> container(" << i << ")" << ::std::endl;
			::std::cerr << "equal_range.first:" << ::std::distance (sIterTestBegin, sTestEqRange.first) << ::std::endl;
			::std::cerr << "lower_bound ()   :" << ::std::distance (sIterTestBegin, sIterTestLower) << ::std::endl;
			::std::cerr << "writing output to mismatch.html" << ::std::endl << ::std::flush;

			m_ppContainers[i]->show_integrity ("mismatch.html");

			::std::cerr << "completed" << ::std::endl << ::std::flush;

			exit (-1);
		}

		if (get_entry_key ((const _t_value &) *sTestEqRange.first) != get_entry_key (*sCEqRange.first))
		{
			::std::cerr << "Container (" << i << ") returned iterator (first) pointing at an entry displaying a different key than reference container" << ::std::endl;
			::std::cerr << "reference key value:" << get_entry_key (*sCEqRange.first) << " at " << anRefOffset[0] << ::std::endl;
			::std::cerr << "container key value:" << get_entry_key ((const _t_value &) *sTestEqRange.first) << " at " << anTestOffset[0] << ::std::endl;
			::std::cerr << "writing output to mismatch.html" << ::std::endl << ::std::flush;

			m_ppContainers[i]->show_integrity ("mismatch.html");

			::std::cerr << "completed" << ::std::endl << ::std::flush;

			exit (-1);
		}

		if (sCEqRange.second == this->m_pReference->cend ())
		{
			continue;
		}

		_t_test_iterator	sIterTestUpper = ((_t_test_call_type *) m_ppContainers[i])->upper_bound (rKey);

		if (sTestEqRange.second != sIterTestUpper)
		{
			_t_test_iterator	sIterTestBegin = ((_t_test_call_type *) m_ppContainers[i])->begin ();

			::std::cerr << "equal_range.first and upper_bound () mismatch --> container(" << i << ")" << ::std::endl;
			::std::cerr << "equal_range.first:" << ::std::distance (sIterTestBegin, sTestEqRange.second) << ::std::endl;
			::std::cerr << "upper_bound ()   :" << ::std::distance (sIterTestBegin, sIterTestUpper) << ::std::endl;
			::std::cerr << "writing output to mismatch.html" << ::std::endl << ::std::flush;

			m_ppContainers[i]->show_integrity ("mismatch.html");

			::std::cerr << "completed" << ::std::endl << ::std::flush;

			exit (-1);
		}

		if (get_entry_key ((const _t_value &) *sTestEqRange.second) != get_entry_key (*sCEqRange.second))
		{
			::std::cerr << "Container (" << i << ") returned iterator (second) pointing at an entry displaying a different key than reference container" << ::std::endl;
			::std::cerr << "reference key value:" << get_entry_key (*sCEqRange.second) << " at " << anRefOffset[1] << ::std::endl;
			::std::cerr << "container key value:" << get_entry_key ((const _t_value &) *sTestEqRange.second) << " at " << anTestOffset[1] << ::std::endl;
			::std::cerr << "writing output to mismatch.html" << ::std::endl << ::std::flush;

			m_ppContainers[i]->show_integrity ("mismatch.html");

			::std::cerr << "completed" << ::std::endl << ::std::flush;

			exit (-1);
		}

		if ((anRefOffset[0] != anTestOffset[0]) || (anRefOffset[1] != anTestOffset[1]))
		{
			::std::cerr << "Container returned different offset than reference container (" << i << ")" << ::std::endl;
			::std::cerr << "reference offset lower" << anRefOffset[0] << ::std::endl;
			::std::cerr << "container offset lower" << anTestOffset[0] << ::std::endl;
			::std::cerr << "reference offset upper" << anRefOffset[1] << ::std::endl;
			::std::cerr << "container offset upper" << anTestOffset[1] << ::std::endl;
			::std::cerr << "writing output to mismatch.html" << ::std::endl << ::std::flush;

			m_ppContainers[i]->show_integrity ("mismatch.html");

			::std::cerr << "completed" << ::std::endl << ::std::flush;

			exit (-1);
		}
	}

	return (sCEqRange);
}

template<class _t_data, class _t_value, class _t_sizetype, class _t_ref_container>
template<class _t_container>
_t_container CBTreeAssociativeTestWrapper<_t_data, _t_value, _t_sizetype, _t_ref_container>::generate_move_construction (_t_container *pContainer, _t_ref_container *pReference) const
{
	_t_container	sContainer (*pContainer);

	sContainer.set_reference (pReference);

	return (sContainer);
}

#endif // BTREEASSOCIATIVETESTWRAPPER_CPP

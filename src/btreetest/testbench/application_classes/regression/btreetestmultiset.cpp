/************************************************************
**
** file:	btreetestmultiset.cpp
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
** This file contains multi set application class code derived
** from the b-tree framework's multi set class to allow
** for the multi set class being tested by having
** the multi set application class act as a wrapper.
**
************************************************************/

#ifndef BTREETESTMULTISET_CPP
#define	BTREETESTMULTISET_CPP

#include "testbench/application_classes/regression/btreetestmultiset.h"

template<class _t_datalayerproperties>
CBTreeTestMultiSet<_t_datalayerproperties>::CBTreeTestMultiSet
	(
		_t_datalayerproperties &rDataLayerProperties, 
		typename _t_datalayerproperties::sub_node_iter_type nNodeSize, 
		typename CBTreeTestMultiSet<_t_datalayerproperties>::reference_t *pClRefData
	)
	:	CBTreeTestBaseSet
			<
				CBTreeMultiSet<uint32_t, _t_datalayerproperties>, 
				::std::multiset<uint32_t>, 
				uint32_t, 
				_t_datalayerproperties
			>
		(
			rDataLayerProperties, 
			nNodeSize, 
			pClRefData, 
			true
		)
{
}

template<class _t_datalayerproperties>
CBTreeTestMultiSet<_t_datalayerproperties>::CBTreeTestMultiSet
	(const CBTreeTestMultiSet<_t_datalayerproperties> &rContainer, const bool bAssign)
	:	CBTreeTestBaseSet
			<
				CBTreeMultiSet<uint32_t, _t_datalayerproperties>, 
				::std::multiset<uint32_t>, 
				uint32_t, 
				_t_datalayerproperties
			>
		(
			dynamic_cast<const CBTreeTestBaseSet
							<
								CBTreeMultiSet<uint32_t, _t_datalayerproperties>, 
								::std::multiset<uint32_t>, 
								uint32_t, 
								_t_datalayerproperties
							> &> (rContainer), 
							false
		)
{
	if (bAssign)
	{
		this->_assign (rContainer);
	}

	this->set_atomic_testing (true);
}

template<class _t_datalayerproperties>
CBTreeTestMultiSet<_t_datalayerproperties>::CBTreeTestMultiSet
	(CBTreeTestMultiSet<_t_datalayerproperties> &&rRhsContainer)
	:	CBTreeTestBaseSet
			<
				CBTreeMultiSet<uint32_t, _t_datalayerproperties>, 
				::std::multiset<uint32_t>, 
				uint32_t, 
				_t_datalayerproperties
			>
		(
			dynamic_cast<CBTreeTestBaseSet
							<
								CBTreeMultiSet<uint32_t, _t_datalayerproperties>, 
								::std::multiset<uint32_t>, 
								uint32_t, 
								_t_datalayerproperties
							> &&> (rRhsContainer)
		)
{
	this->test ();
}

template<class _t_datalayerproperties>
CBTreeTestMultiSet<_t_datalayerproperties>::~CBTreeTestMultiSet ()
{
}

template<class _t_datalayerproperties>
CBTreeTestMultiSet<_t_datalayerproperties>&
	CBTreeTestMultiSet<_t_datalayerproperties>::operator=
	(
		const CBTreeTestMultiSet<_t_datalayerproperties> &rContainer
	)
{
	if (this != &rContainer)
	{
		CBTreeTestBaseSet_t			&rAssociativeThis = dynamic_cast<CBTreeTestBaseSet_t &> (*this);
		const CBTreeTestBaseSet_t	&rAssociativeContainer = dynamic_cast<const CBTreeTestBaseSet_t &> (rContainer);

		rAssociativeThis = rAssociativeContainer;

		this->test ();
	}

	return (*this);
}

template<class _t_datalayerproperties>
CBTreeTestMultiSet<_t_datalayerproperties>&
	CBTreeTestMultiSet<_t_datalayerproperties>::operator=
	(
		CBTreeTestMultiSet<_t_datalayerproperties> &&rRhsContainer
	)
{
	CBTreeTestBaseSet_t		&rAssociativeThis = dynamic_cast<CBTreeTestBaseSet_t &> (*this);
	CBTreeTestBaseSet_t		&rAssociativeContainer = dynamic_cast<CBTreeTestBaseSet_t &> (rRhsContainer);

	rAssociativeThis = ::std::move (rAssociativeContainer);

	this->test ();

	return (*this);
}

template<class _t_datalayerproperties>
template<class _t_iterator>
void CBTreeTestMultiSet<_t_datalayerproperties>::insert (_t_iterator sItFirst, _t_iterator sItLast)
{
	CBTreeMultiSet_t::insert (sItFirst, sItLast);

	this->test ();
}

template<class _t_datalayerproperties>
template<class _t_iterator, class _t_ref_iterator>
void CBTreeTestMultiSet<_t_datalayerproperties>::insert (_t_iterator sItFirst, _t_iterator sItLast)
{
	_t_ref_iterator		sCItFirst (sItFirst);
	_t_ref_iterator		sCItLast (sItLast);

	CBTreeMultiSet_t::insert (sItFirst, sItLast);

	this->test ();
}

template<class _t_datalayerproperties>
typename CBTreeTestMultiSet<_t_datalayerproperties>::iterator
	CBTreeTestMultiSet<_t_datalayerproperties>::insert
	(
		const typename CBTreeTestMultiSet<_t_datalayerproperties>::value_type &rData
	)
{
	iterator		sIter;
	value_type		sData = rData;

	sIter = CBTreeMultiSet_t::insert (sData);

	if (this->m_pClRef != NULL)
	{
		if (CBTreeMultiSet_t::count (sData) != this->m_pClRef->count (sData))
		{
			::std::cerr << ::std::endl;
			::std::cerr << "CBTreeTestMultiSet<>::insert: ERROR: multi key size mismatch!" << ::std::endl;
			::std::cerr << "key: ";
			::std::cerr << std::setfill ('0') << std::hex << std::setw (8);
			{
				::std::cerr << sData;
			}
			::std::cerr << std::setfill (' ') << std::dec << std::setw (0);
			::std::cerr << "reference: " << this->m_pClRef->count (sData) << ::std::endl;
			::std::cerr << "container: " << CBTreeMultiSet_t::count (sData) << ::std::endl;
			
			::std::cerr << "creating count.html... ";

			this->show_integrity ("count.html");

			::std::cerr << "finished" << ::std::endl;

			exit (-1);
		}
	}
	
	this->test ();

	return (sIter);
}

template<class _t_datalayerproperties>
template<class ..._t_va_args>
typename CBTreeTestMultiSet<_t_datalayerproperties>::iterator
	CBTreeTestMultiSet<_t_datalayerproperties>::insert
	(
		typename CBTreeTestMultiSet<_t_datalayerproperties>::const_iterator sCIterHint, 
		_t_va_args && ... rrArgs
	)
{
	iterator					sIter;

	sIter = CBTreeMultiSet_t::insert (sCIterHint, ::std::forward<_t_va_args> (rrArgs) ...);

	this->test ();

	return (sIter);
}

template<class _t_datalayerproperties>
typename CBTreeTestMultiSet<_t_datalayerproperties>::iterator
	CBTreeTestMultiSet<_t_datalayerproperties>::erase
	(
		typename CBTreeTestMultiSet<_t_datalayerproperties>::const_iterator sCIterPos
	)
{
	iterator		sRslt;

	sRslt = CBTreeMultiSet_t::erase (sCIterPos);

	this->test ();

	return (sRslt);
}

template<class _t_datalayerproperties>
typename _t_datalayerproperties::size_type CBTreeTestMultiSet<_t_datalayerproperties>::erase (const typename CBTreeTestMultiSet<_t_datalayerproperties>::key_type &rKey)
{
	size_type		nRslt;

	nRslt = CBTreeMultiSet_t::erase (rKey);

	this->test ();

	return (nRslt);
}

template<class _t_datalayerproperties>
typename CBTreeTestMultiSet<_t_datalayerproperties>::iterator
	CBTreeTestMultiSet<_t_datalayerproperties>::erase
	(
		typename CBTreeTestMultiSet<_t_datalayerproperties>::const_iterator sCIterFirst, 
		typename CBTreeTestMultiSet<_t_datalayerproperties>::const_iterator sCIterLast
	)
{
	iterator	nRslt = CBTreeMultiSet_t::erase (sCIterFirst, sCIterLast);

	this->test ();

	return (nRslt);
}

template<class _t_datalayerproperties>
void CBTreeTestMultiSet<_t_datalayerproperties>::swap (CBTreeTestMultiSet_t &rContainer)
{
	if (this != &rContainer)
	{
		CBTreeTestMultiSet_t::_swap (rContainer);

		this->test ();
	}
}

template<class _t_datalayerproperties>
void CBTreeTestMultiSet<_t_datalayerproperties>::clear ()
{
	CBTreeMultiSet_t::clear ();

	this->test ();
}

template<class _t_datalayerproperties>
bool CBTreeTestMultiSet<_t_datalayerproperties>::operator== (const CBTreeTestMultiSet_t &rTMM) const
{
	if (this == &rTMM)
	{
		return (true);
	}

	if (this->size () != rTMM.size ())
	{
		return (false);
	}

	const_iterator		sCIterThis;
	const_iterator		sCIterThisBegin;
	const_iterator		sCIterThisEnd;
	const_iterator		sCIterRTMM;
	const_iterator		sCIterRTMMbegin;
	value_type			sThisVal;
	value_type			sTMMval;

	sCIterThisBegin = this->cbegin ();
	sCIterThisEnd = this->cend ();

	sCIterRTMMbegin = rTMM.cbegin ();

	for (sCIterThis = sCIterThisBegin, sCIterRTMM = sCIterRTMMbegin; sCIterThis != sCIterThisEnd; sCIterThis++, sCIterRTMM++)
	{
		sThisVal = *sCIterThis;
		sTMMval = *sCIterRTMM;

		if (sThisVal != sTMMval)
		{
			return (false);
		}
	}

	return (true);
}

template<class _t_datalayerproperties>
bool CBTreeTestMultiSet<_t_datalayerproperties>::operator!= (const CBTreeTestMultiSet_t &rTMM) const
{
	return (! ((*this) == rTMM));
}

template<class _t_datalayerproperties>
void CBTreeTestMultiSet<_t_datalayerproperties>::_swap (CBTreeTestMultiSet_t &rContainer)
{
	CBTreeTestBaseSet_t		&rAssociative = dynamic_cast<CBTreeTestBaseSet_t &> (*this);

	CBTreeTestBaseSet_t::_swap (rAssociative);
}

template<class _t_datalayerproperties>
bool CBTreeTestMultiSet<_t_datalayerproperties>::show_data (std::ofstream &ofs, std::stringstream &rstrData, std::stringstream &rszMsg, const typename _t_datalayerproperties::node_iter_type nNode, const typename _t_datalayerproperties::sub_node_iter_type nSubPos) const
{
	value_type				*psData;
	key_type				rData;

	try
	{
		psData = this->get_data (nNode, nSubPos);

		rData = *psData;
		rData = (rData >> 16) | (rData << 16);
		rData = ((rData >> 8) & 0xFF00FF) | ((rData << 8) & 0xFF00FF00);
		
		rstrData.clear ();
		rstrData << "<table border=\"0\" cellspacing=\"1\" width=\"220\"><tr><td>";
		rstrData << "key: " << ::std::hex << ::std::setfill ('0') << ::std::setw (8) << rData << "<br>";
		rstrData << "instance: " << this->get_instancePos (nNode, nSubPos);
		rstrData << "</td>";

		size_type		nDiff = this->lower_bound (*psData) - this->begin ();
		size_type		nOffset = nDiff + this->get_instancePos (nNode, nSubPos);

		rstrData << "<td align=\"top\">";

		if (nOffset < this->m_pClRef->size ())
		{
			reference_t::const_iterator		sItSet;

			sItSet = this->m_pClRef->cbegin ();

			::std::advance (sItSet, nDiff);

			rData = *sItSet;
			rData = (rData >> 16) | (rData << 16);
			rData = ((rData >> 8) & 0xFF00FF)| ((rData << 8) & 0xFF00FF00);

			if (*psData != *sItSet)
			{
				rstrData << "<font color=\"#FF0000\">";
			}
			else
			{
				rstrData << "<font color=\"#00BB00\">";
			}
			
			rstrData << "key: " << ::std::hex << ::std::setfill ('0') << ::std::setw (8) << rData << "<br>";
			rstrData << "</font>";
			rstrData << "instance: " << nDiff;
		}
		else
		{
			rstrData << "<font color=\"#FF0000\">";
			rstrData << "reference<br>";
			rstrData << "out of<br>";
			rstrData << "range";
			rstrData << "</font>";
		}

		rstrData << "</td></tr>";
		rstrData << "</table>" << ::std::endl;
	}
	catch (::std::exception *pE)
	{
		if (!ofs.is_open ())
		{
			return (false);
		}

		rszMsg.clear ();
		rszMsg << "<br>data: corruption (" << pE->what () << ")";

		rData = *psData;
		rData = (rData >> 16) | (rData << 16);
		rData = ((rData >> 8) & 0xFF00FF)| ((rData << 8) & 0xFF00FF00);
		
		rstrData.clear ();
		rstrData << "key: " << ::std::hex << ::std::setfill ('0') << ::std::setw (8) << rData << "<br>instance: ---";
	}

	return (true);
}

#endif // !BTREETESTMULTISET_CPP


/************************************************************
**
** file:	btreetestset.cpp
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
** This file contains set application class code derived
** from the b-tree framework's set class to allow
** for the set class being tested by having
** the set application class act as a wrapper.
**
************************************************************/

#ifndef BTREETESTSET_CPP
#define	BTREETESTSET_CPP

#include "testbench/application_classes/regression/btreetestset.h"

template<class _t_datalayerproperties>
CBTreeTestSet<_t_datalayerproperties>::CBTreeTestSet
	(
		_t_datalayerproperties &rDataLayerProperties, 
		typename _t_datalayerproperties::sub_node_iter_type nNodeSize, 
		typename CBTreeTestSet<_t_datalayerproperties>::reference_t *pClRefData
	)
	:	CBTreeTestBaseSet
			<
				CBTreeSet<uint32_t, _t_datalayerproperties>, 
				::std::set<uint32_t>, 
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
CBTreeTestSet<_t_datalayerproperties>::CBTreeTestSet
	(const CBTreeTestSet<_t_datalayerproperties> &rContainer, const bool bAssign)
	:	CBTreeTestBaseSet
			<
				CBTreeSet<uint32_t, _t_datalayerproperties>, 
				::std::set<uint32_t>, 
				uint32_t, 
				_t_datalayerproperties
			>
	(
		dynamic_cast<const CBTreeTestBaseSet
						<
							CBTreeSet<uint32_t, _t_datalayerproperties>, 
							::std::set<uint32_t>, 
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
CBTreeTestSet<_t_datalayerproperties>::CBTreeTestSet
	(CBTreeTestSet<_t_datalayerproperties> &&rRhsContainer)
	:	CBTreeTestBaseSet
			<
				CBTreeSet<uint32_t, _t_datalayerproperties>, 
				::std::set<uint32_t>, 
				uint32_t, 
				_t_datalayerproperties
			>
	(
		dynamic_cast<CBTreeTestBaseSet
						<
							CBTreeSet<uint32_t, _t_datalayerproperties>, 
							::std::set<uint32_t>, 
							uint32_t, 
							_t_datalayerproperties
						> &&> (rRhsContainer)
	)
{
	this->test ();
}

template<class _t_datalayerproperties>
CBTreeTestSet<_t_datalayerproperties>::~CBTreeTestSet ()
{
}

template<class _t_datalayerproperties>
CBTreeTestSet<_t_datalayerproperties>&
	CBTreeTestSet<_t_datalayerproperties>::operator=
	(
		const CBTreeTestSet<_t_datalayerproperties> &rContainer
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
CBTreeTestSet<_t_datalayerproperties>&
	CBTreeTestSet<_t_datalayerproperties>::operator=
	(
		CBTreeTestSet<_t_datalayerproperties> &&rRhsContainer
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
void CBTreeTestSet<_t_datalayerproperties>::insert (_t_iterator sItFirst, _t_iterator sItLast)
{
	CBTreeSet_t::insert (sItFirst, sItLast);

	this->test ();
}

template<class _t_datalayerproperties>
typename CBTreeTestSet<_t_datalayerproperties>::iterator
	CBTreeTestSet<_t_datalayerproperties>::insert
	(
		const typename CBTreeTestSet<_t_datalayerproperties>::value_type &rData
	)
{
	iterator		sIter;
	value_type		sData = rData;
	
	sIter = CBTreeSet_t::insert (sData);

	if (this->m_pClRef != NULL)
	{
		if (CBTreeSet_t::count (sData) != this->m_pClRef->count (sData))
		{
			::std::cerr << ::std::endl;
			::std::cerr << "CBTreeTestSet<>::insert: ERROR: multi key size mismatch!" << ::std::endl;
			::std::cerr << "key: ";
			::std::cerr << std::setfill ('0') << std::hex << std::setw (8);
			{
				::std::cerr << sData;
			}
			::std::cerr << std::setfill (' ') << std::dec << std::setw (0);
			::std::cerr << "reference: " << this->m_pClRef->count (sData) << ::std::endl;
			::std::cerr << "container: " << CBTreeSet_t::count (sData) << ::std::endl;
			
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
typename CBTreeTestSet<_t_datalayerproperties>::iterator
	CBTreeTestSet<_t_datalayerproperties>::insert
	(
		typename CBTreeTestSet<_t_datalayerproperties>::const_iterator sCIterHint, 
		_t_va_args && ... rrArgs
	)
{
	iterator					sIter;

	sIter = CBTreeSet_t::insert (sCIterHint, ::std::forward<_t_va_args> (rrArgs) ...);

	this->test ();

	return (sIter);
}

template<class _t_datalayerproperties>
typename CBTreeTestSet<_t_datalayerproperties>::iterator
	CBTreeTestSet<_t_datalayerproperties>::erase
	(
		typename CBTreeTestSet<_t_datalayerproperties>::const_iterator sCIterPos
	)
{
	iterator		sRslt;

	sRslt = CBTreeSet_t::erase (sCIterPos);

	this->test ();

	return (sRslt);
}

template<class _t_datalayerproperties>
typename _t_datalayerproperties::size_type CBTreeTestSet<_t_datalayerproperties>::erase (const uint32_t &rKey)
{
	size_type		nRslt;

	nRslt = CBTreeSet_t::erase (rKey);

	this->test ();

	return (nRslt);
}

template<class _t_datalayerproperties>
typename CBTreeTestSet<_t_datalayerproperties>::iterator
	CBTreeTestSet<_t_datalayerproperties>::erase
	(
		typename CBTreeTestSet<_t_datalayerproperties>::const_iterator sCIterFirst, 
		typename CBTreeTestSet<_t_datalayerproperties>::const_iterator sCIterLast
	)
{
	iterator	nRslt = CBTreeSet_t::erase (sCIterFirst, sCIterLast);

	this->test ();

	return (nRslt);
}

template<class _t_datalayerproperties>
void CBTreeTestSet<_t_datalayerproperties>::swap (CBTreeTestSet_t &rContainer)
{
	if (this != &rContainer)
	{
		CBTreeTestSet_t::_swap (rContainer);

		this->test ();
	}
}

template<class _t_datalayerproperties>
void CBTreeTestSet<_t_datalayerproperties>::clear ()
{
	CBTreeSet_t::clear ();

	this->test ();
}

template<class _t_datalayerproperties>
bool CBTreeTestSet<_t_datalayerproperties>::operator== (const CBTreeTestSet_t &rTSet) const
{
	if (this == &rTSet)
	{
		return (true);
	}

	if (this->size () != rTSet.size ())
	{
		return (false);
	}

	const_iterator		sCIterThis;
	const_iterator		sCIterThisBegin;
	const_iterator		sCIterThisEnd;
	const_iterator		sCIterRTSet;
	const_iterator		sCIterRTSetbegin;
	value_type			sThisVal;
	value_type			sTSetVal;

	sCIterThisBegin = this->cbegin ();
	sCIterThisEnd = this->cend ();

	sCIterRTSetbegin = rTSet.cbegin ();

	for (sCIterThis = sCIterThisBegin, sCIterRTSet = sCIterRTSetbegin; sCIterThis != sCIterThisEnd; sCIterThis++, sCIterRTSet++)
	{
		sThisVal = *sCIterThis;
		sTSetVal = *sCIterRTSet;

		if (sThisVal != sTSetVal)
		{
			return (false);
		}
	}

	return (true);
}

template<class _t_datalayerproperties>
bool CBTreeTestSet<_t_datalayerproperties>::operator!= (const CBTreeTestSet_t &rTSet) const
{
	return (! ((*this) == rTSet));
}

template<class _t_datalayerproperties>
void CBTreeTestSet<_t_datalayerproperties>::_swap (CBTreeTestSet_t &rContainer)
{
	CBTreeTestBaseSet_t		&rAssociative = dynamic_cast<CBTreeTestBaseSet_t &> (*this);

	CBTreeTestBaseSet_t::_swap (rAssociative);
}

template<class _t_datalayerproperties>
bool CBTreeTestSet<_t_datalayerproperties>::show_data (std::ofstream &ofs, std::stringstream &rstrData, std::stringstream &rszMsg, const typename _t_datalayerproperties::node_iter_type nNode, const typename _t_datalayerproperties::sub_node_iter_type nSubPos) const
{
	uint32_t				*psData;
	uint32_t				rData;

	try
	{
		psData = this->get_data (nNode, nSubPos);

		rData = *psData;
		rData = (rData >> 16) | (rData << 16);
		rData = ((rData >> 8) & 0xFF00FF) | ((rData << 8) & 0xFF00FF00);
		
		rstrData.clear ();
		rstrData << "<table border=\"0\" cellspacing=\"1\" width=\"220\"><tr><td>";
		rstrData << "key: " << ::std::hex << ::std::setfill ('0') << ::std::setw (8) << rData << "<br>";

		if (this->get_instancePos (nNode, nSubPos) > 0)
		{
			rstrData << "<font color=\"#FF0000\">";
		}
		else
		{
			rstrData << "<font color=\"#000000\">";
		}

		rstrData << "instance: " << this->get_instancePos (nNode, nSubPos);
		rstrData << "</font>";
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

			if (this->get_instancePos (nNode, nSubPos) > 0)
			{
				rstrData << "<font color=\"#FF0000\">";
			}
			else
			{
				rstrData << "<font color=\"#00BB00\">";
			}

			rstrData << "instance: 0";
			rstrData << "</font>";
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

#endif // !BTREETESTSET_CPP


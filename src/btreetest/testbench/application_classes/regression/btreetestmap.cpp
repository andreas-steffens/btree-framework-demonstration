/************************************************************
**
** file:	btreetestmap.cpp
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
** This file contains map application class code derived
** from the b-tree framework's map class to allow
** for the map class being tested by having
** the map application class act as a wrapper.
**
************************************************************/

#ifndef BTREETESTMAP_CPP
#define	BTREETESTMAP_CPP

#include "testbench/application_classes/regression/btreetestmap.h"

template<class _t_datalayerproperties>
CBTreeTestMap<_t_datalayerproperties>::CBTreeTestMap
	(
		_t_datalayerproperties &rDataLayerProperties, 
		typename _t_datalayerproperties::sub_node_iter_type nNodeSize, 
		typename CBTreeTestMap<_t_datalayerproperties>::reference_t *pClRefData
	)
	:	CBTreeTestBaseAssociative
			<
				CBTreeMap<uint32_t, mapMap_t, _t_datalayerproperties>, 
				::std::map<uint32_t, mapMap_t>, 
				::std::pair<uint32_t, mapMap_t>, 
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
CBTreeTestMap<_t_datalayerproperties>::CBTreeTestMap
	(const CBTreeTestMap<_t_datalayerproperties> &rContainer, const bool bAssign)
	:	CBTreeTestBaseAssociative
			<
				CBTreeMap<uint32_t, mapMap_t, _t_datalayerproperties>, 
				::std::map<uint32_t, mapMap_t>, 
				::std::pair<uint32_t, mapMap_t>, 
				uint32_t, 
				_t_datalayerproperties
			>
		(
			dynamic_cast<const CBTreeTestBaseAssociative
							<
								CBTreeMap<uint32_t, mapMap_t, _t_datalayerproperties>, 
								::std::map<uint32_t, mapMap_t>, 
								::std::pair<uint32_t, mapMap_t>, 
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
CBTreeTestMap<_t_datalayerproperties>::CBTreeTestMap
	(CBTreeTestMap<_t_datalayerproperties> &&rRhsContainer)
	:	CBTreeTestBaseAssociative
			<
				CBTreeMap<uint32_t, mapMap_t, _t_datalayerproperties>, 
				::std::map<uint32_t, mapMap_t>, 
				::std::pair<uint32_t, mapMap_t>, 
				uint32_t, 
				_t_datalayerproperties
			>
		(
			dynamic_cast<CBTreeTestBaseAssociative
							<
								CBTreeMap<uint32_t, mapMap_t, _t_datalayerproperties>, 
								::std::map<uint32_t, mapMap_t>, 
								::std::pair<uint32_t, mapMap_t>, 
								uint32_t, 
								_t_datalayerproperties
							> &&> (rRhsContainer)
		)
{
	this->test ();
}

template<class _t_datalayerproperties>
CBTreeTestMap<_t_datalayerproperties>::~CBTreeTestMap ()
{
}

template<class _t_datalayerproperties>
CBTreeTestMap<_t_datalayerproperties>&
	CBTreeTestMap<_t_datalayerproperties>::operator=
	(
		const CBTreeTestMap<_t_datalayerproperties> &rContainer
	)
{
	if (this != &rContainer)
	{
		CBTreeTestBaseAssociative_t			&rMapThis = dynamic_cast<CBTreeTestBaseAssociative_t &> (*this);
		const CBTreeTestBaseAssociative_t	&rMapContainer = dynamic_cast<const CBTreeTestBaseAssociative_t &> (rContainer);

		rMapThis = rMapContainer;

		this->test ();
	}

	return (*this);
}

template<class _t_datalayerproperties>
CBTreeTestMap<_t_datalayerproperties>&
	CBTreeTestMap<_t_datalayerproperties>::operator=
	(
		CBTreeTestMap<_t_datalayerproperties> &&rRhsContainer
	)
{
	CBTreeTestBaseAssociative_t			&rMapThis = dynamic_cast<CBTreeTestBaseAssociative_t &> (*this);
	CBTreeTestBaseAssociative_t			&rMapContainer = dynamic_cast<CBTreeTestBaseAssociative_t &> (rRhsContainer);

	rMapThis = ::std::move (rMapContainer);

	this->test ();

	return (*this);
}

template<class _t_datalayerproperties>
template<class _t_iterator>
void CBTreeTestMap<_t_datalayerproperties>::insert (_t_iterator sItFirst, _t_iterator sItLast)
{
	CBTreeMap_t::insert (sItFirst, sItLast);

	this->test ();
}

template<class _t_datalayerproperties>
typename CBTreeTestMap<_t_datalayerproperties>::iterator
	CBTreeTestMap<_t_datalayerproperties>::insert
	(
		const typename CBTreeTestMap<_t_datalayerproperties>::value_type &rData
	)
{
	bool				bRefRslt;
	iterator			sIter;
	value_type			sData = rData;
	bool				bSuccess;

	if (this->m_pClRef != NULL)
	{
		bRefRslt = this->m_pClRef->count (sData.first) != 0;
	}

	sIter = CBTreeMap_t::insert (sData);

	if (this->m_pClRef != NULL)
	{
		bSuccess = sIter < this->end ();

		if (CBTreeMap_t::count (sData.first) != this->m_pClRef->count (sData.first))
		{
			::std::cerr << ::std::endl;
			::std::cerr << "CBTreeTestMap<>::insert: ERROR: reference claims that key ";
			::std::cerr << std::setfill ('0') << std::hex << std::setw (8);
			{
				::std::cerr << sData.first;
			}
			::std::cerr << std::setfill (' ') << std::dec << std::setw (0);
			::std::cerr << " was ";

			if (bRefRslt)
			{
				::std::cerr << "not ";
			}

			::std::cerr << "present, whereas the instance claims that said key was ";

			if (bSuccess)
			{
				::std::cerr << "not ";
			}

			::std::cerr << "present!" << ::std::endl;
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
typename CBTreeTestMap<_t_datalayerproperties>::iterator
	CBTreeTestMap<_t_datalayerproperties>::insert
	(
		typename CBTreeTestMap<_t_datalayerproperties>::const_iterator sCIterHint, 
		const typename CBTreeTestMap<_t_datalayerproperties>::value_type &rData
	)
{
	iterator					sIter;

	sIter = CBTreeMap_t::insert (sCIterHint, rData);

	this->test ();

	return (sIter);
}

template<class _t_datalayerproperties>
typename CBTreeTestMap<_t_datalayerproperties>::iterator
	CBTreeTestMap<_t_datalayerproperties>::erase
	(
		typename CBTreeTestMap<_t_datalayerproperties>::const_iterator sCIterPos
	)
{
	iterator		sRslt;

	sRslt = CBTreeMap_t::erase (sCIterPos);

	this->test ();

	return (sRslt);
}

template<class _t_datalayerproperties>
typename _t_datalayerproperties::size_type CBTreeTestMap<_t_datalayerproperties>::erase (const uint32_t &rKey)
{
	size_type		nRslt;

	nRslt = CBTreeMap_t::erase (rKey);

	this->test ();

	return (nRslt);
}

template<class _t_datalayerproperties>
typename CBTreeTestMap<_t_datalayerproperties>::iterator
	CBTreeTestMap<_t_datalayerproperties>::erase
	(
		typename CBTreeTestMap<_t_datalayerproperties>::const_iterator sCIterFirst, 
		typename CBTreeTestMap<_t_datalayerproperties>::const_iterator sCIterLast
	)
{
	iterator	sRslt = CBTreeMap_t::erase (sCIterFirst, sCIterLast);

	this->test ();

	return (sRslt);
}

template<class _t_datalayerproperties>
void CBTreeTestMap<_t_datalayerproperties>::swap (CBTreeTestMap_t &rContainer)
{
	if (this != &rContainer)
	{
		CBTreeTestMap_t::_swap (rContainer);

		this->test ();
	}
}

template<class _t_datalayerproperties>
void CBTreeTestMap<_t_datalayerproperties>::clear ()
{
	CBTreeMap_t::clear ();

	this->test ();
}

template<class _t_datalayerproperties>
bool CBTreeTestMap<_t_datalayerproperties>::operator== (const CBTreeTestMap_t &rTMM) const
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

		if ((sThisVal.first != sTMMval.first) ||
			(sThisVal.second.nData != sThisVal.second.nData) ||
			(sThisVal.second.nDebug != sTMMval.second.nDebug))
		{
			return (false);
		}
	}

	return (true);
}

template<class _t_datalayerproperties>
bool CBTreeTestMap<_t_datalayerproperties>::operator!= (const CBTreeTestMap_t &rTMM) const
{
	return (! ((*this) == rTMM));
}

template<class _t_datalayerproperties>
void CBTreeTestMap<_t_datalayerproperties>::_swap (CBTreeTestMap_t &rContainer)
{
	CBTreeTestBaseAssociative_t		&rAssociative = dynamic_cast<CBTreeTestBaseAssociative_t &> (*this);

	CBTreeTestBaseAssociative_t::_swap (rAssociative);
}
	
template<class _t_datalayerproperties>
bool CBTreeTestMap<_t_datalayerproperties>::show_data (std::ofstream &ofs, std::stringstream &rstrData, std::stringstream &rszMsg, const typename _t_datalayerproperties::node_iter_type nNode, const typename _t_datalayerproperties::sub_node_iter_type nSubPos) const
{
	value_type		*psData;
	key_type		rData;

	try
	{
		psData = this->get_data (nNode, nSubPos);

		rData = psData->first;
		rData = (rData >> 16) | (rData << 16);
		rData = ((rData >> 8) & 0xFF00FF) | ((rData << 8) & 0xFF00FF00);
		
		rstrData.clear ();
		rstrData << "<table border=\"0\" cellspacing=\"1\" width=\"220\"><tr><td>";
		rstrData << "key: " << ::std::hex << ::std::setfill ('0') << ::std::setw (8) << rData << "<br>";
		rstrData << "data: " << psData->second.nData << ::std::dec << "<br>";
		rstrData << "debug: " << psData->second.nDebug << "<br>";
		rstrData << "instance: " << this->get_instancePos (nNode, nSubPos);
		rstrData << "</td>";

		size_type		nDiff = this->lower_bound (psData->first) - this->cbegin ();
		size_type		nOffset = nDiff + this->get_instancePos (nNode, nSubPos);

		rstrData << "<td align=\"top\">";

		if (nOffset < this->m_pClRef->size ())
		{
			reference_t::const_iterator		sItMMap;

			sItMMap = this->m_pClRef->cbegin ();

			::std::advance (sItMMap, nDiff);

			rData = (*sItMMap).first;
			rData = (rData >> 16) | (rData << 16);
			rData = ((rData >> 8) & 0xFF00FF)| ((rData << 8) & 0xFF00FF00);

			if (psData->first != (*sItMMap).first)
			{
				rstrData << "<font color=\"#FF0000\">";
			}
			else
			{
				rstrData << "<font color=\"#00BB00\">";
			}
			
			rstrData << "key: " << ::std::hex << ::std::setfill ('0') << ::std::setw (8) << rData << "<br>";
			rstrData << "</font>";

			if (psData->second.nData != (*sItMMap).second.nData)
			{
				rstrData << "<font color=\"#AAAA00\">";
			}
			else
			{
				rstrData << "<font color=\"#00BB00\">";
			}
			
			rstrData << "data: " << (*sItMMap).second.nData << ::std::dec << "<br>";
			rstrData << "</font>";

			if (psData->second.nDebug != (*sItMMap).second.nDebug)
			{
				rstrData << "<font color=\"#AAAA00\">";
			}
			else
			{
				rstrData << "<font color=\"#00BB00\">";
			}
			
			rstrData << "debug: " << (*sItMMap).second.nDebug << "<br>";
			rstrData << "</font>";
			rstrData << "-";
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

		rData = psData->first;
		rData = (rData >> 16) | (rData << 16);
		rData = ((rData >> 8) & 0xFF00FF)| ((rData << 8) & 0xFF00FF00);
		
		rstrData.clear ();
		rstrData << "key: " << ::std::hex << ::std::setfill ('0') << ::std::setw (8) << rData << ::std::dec << "<br>debug: " << psData->second.nDebug << "<br>instance: ---";
	}

	return (true);
}

#endif // !BTREETESTMAP_CPP


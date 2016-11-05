#include "testbench/common/btreeperftestcommon.h"

void output_perf_results (CResultList_t &rRstlList, uint64_t nProblemSize, uint32_t nProblemSizeBias)
{
	auto	sCRIter = rRstlList.crbegin ();
	auto	sCRIterEnd = rRstlList.crend ();

	::std::cout << "problem size: " << nProblemSize;

	if (nProblemSizeBias != 1)
	{
		::std::cout << " x " << nProblemSizeBias;
	}

	::std::cout << ::std::endl;

	for (; sCRIter != sCRIterEnd; sCRIter++)
	{
		::std::cout << ::std::setw (12) << (*sCRIter).first << " OP/s " << (*sCRIter).second << ::std::endl;
	}
}

void add_perf_result (CResultList_t &rRstlList, const double dblPeriodInSecs, const uint64_t nProblemSize, const char *pszTitle)
{
	double									dblIOPs = nProblemSize / dblPeriodInSecs;
	::std::pair<double, const char *>		sResult (dblIOPs, pszTitle);

	rRstlList.insert (sResult);
}


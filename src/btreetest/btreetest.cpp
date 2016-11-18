/************************************************************
**
** file:	btreetest.cpp
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
** This file contains code for the b-tree framework's test bench
** exercising functional, code coverage and regression tests
** for any part of said framework there is.
**
************************************************************/

#include <stdio.h>

#if defined (_MSC_VER)
 #if defined (_HAS_MFC)
  #include <afxtempl.h>
 #else
  #include <list>
 #endif

#include "conio.h"

#elif defined(__GNUC__) || defined(__GNUG__)
 #include <vector>
#endif

#include <string.h>
#include <time.h>
#include <stdlib.h>

#include <string>

#include <stdint.h>

#include "testbench/sub_division/btreetestsubdivisionkeysort.h"
#include "testbench/sub_division/btreetestsubdivisionarray.h"

#include "testbench/sub_division/btreetestsubdivisionkeysortiter.h"
#include "testbench/sub_division/btreetestsubdivisionarrayiter.h"

#include "testbench/sub_division/btreetestsubdivisionmap.h"
#include "testbench/sub_division/btreetestsubdivisionmultimap.h"
#include "testbench/sub_division/btreetestsubdivisionset.h"
#include "testbench/sub_division/btreetestsubdivisionmultiset.h"

#include "testbench/tests/performance/btreearrayperftestbench.h"
#include "testbench/tests/performance/btreemultimapperftestbench.h"

#include "avp_path_find_core.h"

#include "testbench/examples/example_1_polymorphic_calls.h"
#include "testbench/examples/example_2_simple_database.h"

using namespace std;

/*

btreetest	-type <name> -test <n> [-nodesize <n>]

-type <name>	- specifies btree type to be tested
					valid names are:
					+ array
					+ keysort

-test <n>		- specifies number of test to be executed

-nodesize <n>	- specifies parameter t of btree instance

*/

typedef enum
{
	BTREETYPE_NOT_SPECIFIED, 
	BTREETYPE_KEY_SORT, 
	BTREETYPE_ARRAY, 
	BTREETYPE_INDEX,
	BTREETYPE_REFERENCE, 
	BTREETYPE_EXAMPLES, 
	BTREETYPE_APPLICATION, 
	BTREETYPE_KEY_SORT_ITERATOR, 
	BTREETYPE_ARRAY_ITERATOR, 
	BTREETYPE_STL_MULTIMAP, 
	BTREETYPE_STL_MAP, 
	BTREETYPE_STL_MULTISET, 
	BTREETYPE_STL_SET
} btreeType_e;

typedef enum
{
	APPLICATION_TYPE_NOT_SPECIFIED, 
	APPLICATION_TYPE_AVP
} application_type_e;

void print_usage (const char *pszBinary)
{
	::std::cerr << "Synopsis" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << pszBinary << " -help | --help | -usage | --usage" << ::std::endl;
	::std::cerr << pszBinary << " -type <test type> [-app <app name>] -test <test number> [-sizetype <address space bit width>]" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "-type           selects the container type or application test mode" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "                stl-set         - selects STL interface equivalent set container types" << ::std::endl;
	::std::cerr << "                stl-multiset    - selects STL interface equivalent multiset container types" << ::std::endl;
	::std::cerr << "                stl-map         - selects STL interface equivalent map container types" << ::std::endl;
	::std::cerr << "                stl-multimap    - selects STL interface equivalent multimap container types" << ::std::endl;
	::std::cerr << "                array           - selects array container types" << ::std::endl;
	::std::cerr << "                keysort         - selects keysort container types" << ::std::endl;
	::std::cerr << "                array-iter      - selects array iterators" << ::std::endl;
	::std::cerr << "                keysort-iter    - selects keysort iterators" << ::std::endl;
	::std::cerr << "                app             - switches test bench to application testing mode" << ::std::endl;
	::std::cerr << "                example         - runs the code of an example as it is displayed in the \"quick overview\" documentation" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "-app            selects an application name for real world testing" << ::std::endl;
	::std::cerr << "                purposes, in case the application testing mode has" << ::std::endl;
	::std::cerr << "                been selected" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "                avp             - AVP path find application" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "-test           selects the test number of the test to be executed" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "                The test list can be found at the end of this document." << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "-sizetype       selects the bit width of size_type of the target containers" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "                32              - size_type is set to uint32_t (default)" << ::std::endl;
	::std::cerr << "                64              - size_type is set to uint64_t (default)" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "                This setting is ineffective in application testing mode." << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "stl-set, stl-multiset, stl-map and stl-multimap" << ::std::endl;
	::std::cerr << "0       - test exercises assignment operator of selected container type" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "1000    - test exercises interface method insert (const value_type &)" << ::std::endl;
	::std::cerr << "1001    - test exercises interface method insert<iterator> (iterator &, iterator &)" << ::std::endl;
	::std::cerr << "1002    - test exercises interface method erase (const_iterator &) " << ::std::endl;
	::std::cerr << "1003    - test exercises interface method erase (const key_value &)" << ::std::endl;
	::std::cerr << "1004    - test exercises interface method erase (const_iterator &, const_iterator &)" << ::std::endl;
	::std::cerr << "1005    - test exercises interface method key_comp ()" << ::std::endl;
	::std::cerr << "1006    - test exercises interface method value_comp ()" << ::std::endl;
	::std::cerr << "1007    - test exercises interface method swap (container &)" << ::std::endl;
	::std::cerr << "1008    - test exercises interface method find (const key_type &)" << ::std::endl;
	::std::cerr << "1009    - test exercises interface methods lower_bound (const key_type &) and upper_bound (const key_type &)" << ::std::endl;
	::std::cerr << "1010    - test exercises interface method emplace<_t_va_args> (_t_va_args && ...)" << ::std::endl;
	::std::cerr << "1011    - test exercises interface method emplace_hint<_t_va_args> (const_iterator &, _t_va_args && ...) with perfect hint" << ::std::endl;
	::std::cerr << "1012    - test exercises interface method emplace_hint<_t_va_args> (const_iterator &, _t_va_args && ...) with near perfect hint" << ::std::endl;
	::std::cerr << "1013    - test exercises interface method emplace_hint<_t_va_args> (const_iterator &, _t_va_args && ...) with potentially bad hint" << ::std::endl;
	::std::cerr << "1014    - test exercises interface method emplace_hint<_t_va_args> (const_iterator &, _t_va_args && ...) with terrible hint" << ::std::endl;
	::std::cerr << "1015    - test exercises interface method insert (const_iterator &, const value_type &) with perfect hint" << ::std::endl;
	::std::cerr << "1016    - test exercises interface method insert (const_iterator &, const value_type &) with near perfect hint" << ::std::endl;
	::std::cerr << "1017    - test exercises interface method insert (const_iterator &, const value_type &) with potentially bad hint" << ::std::endl;
	::std::cerr << "1018    - test exercises interface method insert (const_iterator &, const value_type &) with terrible hint" << ::std::endl;
	::std::cerr << "1019    - test exercises interface method emplace (const value_type &)" << ::std::endl;
	::std::cerr << "1020    - test exercises interface method emplace_hint (const_iterator &, const value_type &) with perfect hint" << ::std::endl;
	::std::cerr << "1021    - test exercises interface method equal_range ()" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "array" << ::std::endl;
	::std::cerr << "0       - test adds data at the beginning and removes data at the end" << ::std::endl;
	::std::cerr << "1       - test adds data at the beginning and removes data at the end on a smaller scale" << ::std::endl;
	::std::cerr << "2       - test adds data at the end and removes data at the beginning" << ::std::endl;
	::std::cerr << "3       - test adds data at the end and removes data at the beginning on a smaller scale" << ::std::endl;
	::std::cerr << "4       - test adds data at a random positions and removes data at random positions" << ::std::endl;
	::std::cerr << "5       - test adds data at a random positions and removes data at random positions on a smaller scale" << ::std::endl;
	::std::cerr << "6       - test exercises if container is still ready to operate once interface method clear () has been called" << ::std::endl;
	::std::cerr << "7       - test exercises scenario where data is rapidly inserted and removed again" << ::std::endl;
	::std::cerr << "8       - test exercises if container is still ready to operate once interface method unload () has been called" << ::std::endl;
	::std::cerr << "9       - test exercises if container is still ready to operate once interface debug method show_integrity () has been called" << ::std::endl;
	::std::cerr << "10      - test exercises copy constructor of container type" << ::std::endl;
	::std::cerr << "11      - test exercises overloaded assignment operator of container type" << ::std::endl;
	::std::cerr << "12      - test exercises overloaded subscript operator of container type" << ::std::endl;
	::std::cerr << "13      - test reads all data from container using method serialize ()" << ::std::endl;
	::std::cerr << "14      - test reads data from half of a random node using method serialize ()" << ::std::endl;
	::std::cerr << "15      - test reads data from part of a random node using method serialize ()" << ::std::endl;
	::std::cerr << "16      - test reads data from from container using method serialize (), while parameters exceeding container size" << ::std::endl;
	::std::cerr << "17      - test exercises situation where a container is self-referenced using iterators" << ::std::endl;
	::std::cerr << "18      - test reads no data from container using method serialize () with read length set to zero" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "1000    - test exercises interface method assign (const size_type, const value_type &)" << ::std::endl;
	::std::cerr << "1001    - test exercises interface method assign<iterator> (iterator &, iterator &)" << ::std::endl;
	::std::cerr << "1002    - test exercises interface method push_back () and pop_back ()" << ::std::endl;
	::std::cerr << "1003    - test exercises interface method insert (const_iterator, const size_type &, const value_type &)" << ::std::endl;
	::std::cerr << "1004    - test exercises interface method insert<iterator> (const_iterator, iterator &, iterator &)" << ::std::endl;
	::std::cerr << "1005    - test exercises interface method insert (const_iterator, iterator &, iterator &) on a large container via self-reference" << ::std::endl;
	::std::cerr << "1006    - test exercises interface method insert (const_iterator, const_iterator &, const_iterator &) on a large container via self-reference" << ::std::endl;
	::std::cerr << "1007    - test exercises interface method insert (const_iterator, reverse_iterator &, reverse_iterator &) on a large container via self-reference" << ::std::endl;
	::std::cerr << "1008    - test exercises interface method insert (const_iterator, const_reverse_iterator &, const_reverse_iterator &) on a large container via self-reference" << ::std::endl;
	::std::cerr << "1009    - test exercises interface method erase (const key_value &)" << ::std::endl;
	::std::cerr << "1010    - test exercises interface method erase (const_iterator &, const_iterator &)" << ::std::endl;
	::std::cerr << "1011    - test exercises interface method swap (container &)" << ::std::endl;
	::std::cerr << "1012    - test exercises interface method emplace<_t_va_args> (const_iterator &, _t_va_args && ...)" << ::std::endl;
	::std::cerr << "1013    - test exercises interface method emplace_back<_t_va_args> (_t_va_args && ...)" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "2000    - code coverage test where data is removed resulting in nodes being merged, while the right node has a lower id than the left node" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "keysort" << ::std::endl;
	::std::cerr << "0       - test adds data at the beginning and removes data at the end" << ::std::endl;
	::std::cerr << "1       - test adds data at the beginning and removes data at the end on a smaller scale" << ::std::endl;
	::std::cerr << "2       - test adds data at the end and removes data at the beginning" << ::std::endl;
	::std::cerr << "3       - test adds data at the end and removes data at the beginning on a smaller scale" << ::std::endl;
	::std::cerr << "4       - test adds data at a random positions and removes data at random positions" << ::std::endl;
	::std::cerr << "5       - test adds data at a random positions and removes data at random positions on a smaller scale" << ::std::endl;
	::std::cerr << "6       - test exercises if container is still ready to operate once interface method clear () has been called" << ::std::endl;
	::std::cerr << "7       - test exercises scenario where data is rapidly inserted and removed again" << ::std::endl;
	::std::cerr << "8       - test exercises if container is still ready to operate once interface method unload () has been called" << ::std::endl;
	::std::cerr << "9       - test exercises interface method erase (const_iterator &), while removing specific instance of a key set" << ::std::endl;
	::std::cerr << "10      - test exercises if container is still ready to operate once interface debug method show_integrity () has been called" << ::std::endl;
	::std::cerr << "11      - test exercises copy constructor of container type" << ::std::endl;
	::std::cerr << "12      - test exercises overloaded assignment operator of container type" << ::std::endl;
	::std::cerr << "13      - test exercises overloaded assignment operator of container type, while making sure key sets remain in order" << ::std::endl;
	::std::cerr << "14      - test reads all data from container using method serialize ()" << ::std::endl;
	::std::cerr << "15      - test reads data from half of a random node using method serialize ()" << ::std::endl;
	::std::cerr << "16      - test reads data from part of a random node using method serialize ()" << ::std::endl;
	::std::cerr << "17      - test reads data from from container using method serialize (), while parameters exceeding container size" << ::std::endl;
	::std::cerr << "18      - test reads all data from container using method serialize (), while making sure key sets remain in order" << ::std::endl;
	::std::cerr << "19      - test reads data from half of a random node using method serialize (), while making sure key sets remain in order" << ::std::endl;
	::std::cerr << "20      - test reads data from part of a random node using method serialize (), while making sure key sets remain in order" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "1000    - test exercises interface method insert (const value_type &)" << ::std::endl;
	::std::cerr << "1001    - test exercises interface method insert<iterator> (iterator &, iterator &)" << ::std::endl;
	::std::cerr << "1002    - test exercises interface method erase (const_iterator &) " << ::std::endl;
	::std::cerr << "1003    - test exercises interface method erase (const key_value &)" << ::std::endl;
	::std::cerr << "1004    - test exercises interface method erase (const_iterator &, const_iterator &)" << ::std::endl;
	::std::cerr << "1005    - test exercises interface method swap (container &)" << ::std::endl;
	::std::cerr << "1006    - test exercises interface method find (const key_type &)" << ::std::endl;
	::std::cerr << "1007    - test exercises interface methods lower_bound (const key_type &) and upper_bound (const key_type &)" << ::std::endl;
	::std::cerr << "1008    - test exercises interface method emplace<_t_va_args> (_t_va_args && ...)" << ::std::endl;
	::std::cerr << "1009    - test exercises interface method emplace_hint<_t_va_args> (const_iterator &, _t_va_args && ...) with perfect hint" << ::std::endl;
	::std::cerr << "1010    - test exercises interface method emplace_hint<_t_va_args> (const_iterator &, _t_va_args && ...) with near perfect hint" << ::std::endl;
	::std::cerr << "1011    - test exercises interface method emplace_hint<_t_va_args> (const_iterator &, _t_va_args && ...) with potentially bad hint" << ::std::endl;
	::std::cerr << "1012    - test exercises interface method emplace_hint<_t_va_args> (const_iterator &, _t_va_args && ...) with terrible hint" << ::std::endl;
	::std::cerr << "1013    - test exercises interface method insert (const_iterator &, const value_type &) with perfect hint" << ::std::endl;
	::std::cerr << "1014    - test exercises interface method insert (const_iterator &, const value_type &) with near perfect hint" << ::std::endl;
	::std::cerr << "1015    - test exercises interface method insert (const_iterator &, const value_type &) with potentially bad hint" << ::std::endl;
	::std::cerr << "1016    - test exercises interface method insert (const_iterator &, const value_type &) with terrible hint" << ::std::endl;
	::std::cerr << "1017    - test exercises interface method emplace (const value_type &)" << ::std::endl;
	::std::cerr << "1018    - test exercises interface method emplace_hint (const_iterator &, const value_type &) with perfect hint" << ::std::endl;
	::std::cerr << "1019    - test exercises interface method equal_range ()" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "2000    - code coverage test which exercises corner cases in method determine_position ()" << ::std::endl;
	::std::cerr << "2001    - code coverage test which exercises corner cases in method find_first_key ()" << ::std::endl;
	::std::cerr << "2002    - code coverage test which exercises corner cases in method get_init_pos_of_key () on leaf node" << ::std::endl;
	::std::cerr << "2003    - code coverage test which exercises corner cases in overloaded method set_iter_data ()" << ::std::endl;
	::std::cerr << "2004    - code coverage test which exercises corner cases in overloaded compare operator" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "array-iter" << ::std::endl;
	::std::cerr << "0       - test exercises increment operator" << ::std::endl;
	::std::cerr << "1       - test exercises increment operator on a small scale" << ::std::endl;
	::std::cerr << "2       - test exercises decrement operator" << ::std::endl;
	::std::cerr << "3       - test exercises decrement operator on a small scale" << ::std::endl;
	::std::cerr << "4       - test exercises arithmetic operator+ with one of the operands being the result instance (a = a + n)" << ::std::endl;
	::std::cerr << "5       - test exercises arithmetic operator+ with one of the operands being the result instance on a small scale" << ::std::endl;
	::std::cerr << "6       - test exercises arithmetic operator- with one of the operands being the result instance (a = a - n)" << ::std::endl;
	::std::cerr << "7       - test exercises arithmetic operator- with one of the operands being the result instance on a small scale" << ::std::endl;
	::std::cerr << "8       - test exercises arithmetic operator+ with different step sizes versus different node sizes" << ::std::endl;
	::std::cerr << "9       - test exercises arithmetic operator- with different step sizes versus different node sizes" << ::std::endl;
	::std::cerr << "10      - test exercises dereference operator*" << ::std::endl;
	::std::cerr << "11      - test exercises subscript operator[size_type]" << ::std::endl;
	::std::cerr << "12      - test exercises subscript operator[int]" << ::std::endl;
	::std::cerr << "13      - test exercises compound operator+= (size_type)" << ::std::endl;
	::std::cerr << "14      - test exercises compound operator+= (int)" << ::std::endl;
	::std::cerr << "15      - test exercises compound operator+= (iterator)" << ::std::endl;
	::std::cerr << "16      - test exercises arithmetic operator+ and operator- with none of the operands being the result instance (r = a + b) or (r = a - b)" << ::std::endl;
	::std::cerr << "17      - test exercises all compare operators (<, >, <=, >=, ==, !=)" << ::std::endl;
	::std::cerr << "18      - test exercises interface method swap (iterator &) with parameter from a different container" << ::std::endl;
	::std::cerr << "19      - test exercises interface method swap (iterator &) with parameter from the same different container" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "2000    - code coverage test exercises compare operator with same instance as an input" << ::std::endl;
	::std::cerr << "2001    - code coverage test exercises situation where the time stamp is up to date after a re-assignment" << ::std::endl;
	::std::cerr << "2002    - code coverage test exercises situation where the time stamp is up to date after a re-register" << ::std::endl;
	::std::cerr << "2003    - code coverage test exercises situation where an uninitialised iterator is assigned to another instance" << ::std::endl;
	::std::cerr << "2004    - code coverage test exercises all begin () and end () methods" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "keysort-iter" << ::std::endl;
	::std::cerr << "0       - test exercises increment operator" << ::std::endl;
	::std::cerr << "1       - test exercises increment operator on a small scale" << ::std::endl;
	::std::cerr << "2       - test exercises decrement operator" << ::std::endl;
	::std::cerr << "3       - test exercises decrement operator on a small scale" << ::std::endl;
	::std::cerr << "4       - test exercises arithmetic operator+ with one of the operands being the result instance (a = a + n)" << ::std::endl;
	::std::cerr << "5       - test exercises arithmetic operator+ with one of the operands being the result instance on a small scale" << ::std::endl;
	::std::cerr << "6       - test exercises arithmetic operator- with one of the operands being the result instance (a = a - n)" << ::std::endl;
	::std::cerr << "7       - test exercises arithmetic operator- with one of the operands being the result instance on a small scale" << ::std::endl;
	::std::cerr << "8       - test exercises arithmetic operator+ with different step sizes versus different node sizes" << ::std::endl;
	::std::cerr << "9       - test exercises arithmetic operator- with different step sizes versus different node sizes" << ::std::endl;
	::std::cerr << "10      - test exercises subscript operator[size_type]" << ::std::endl;
	::std::cerr << "11      - test exercises subscript operator[int]" << ::std::endl;
	::std::cerr << "12      - test exercises compound operator+= (size_type)" << ::std::endl;
	::std::cerr << "13      - test exercises compound operator+= (int)" << ::std::endl;
	::std::cerr << "14      - test exercises compound operator+= (iterator)" << ::std::endl;
	::std::cerr << "15      - test exercises arithmetic operator+ and operator- with none of the operands being the result instance (r = a + b) or (r = a - b)" << ::std::endl;
	::std::cerr << "16      - test exercises all compare operators (<, >, <=, >=, ==, !=)" << ::std::endl;
	::std::cerr << "17      - test exercises interface method swap (iterator &) with parameter from the same different container" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "example" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "0       - run polymorphic calls example" << ::std::endl;
	::std::cerr << "1       - run simple database example" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "app" << ::std::endl;
	::std::cerr << ::std::endl;
	::std::cerr << "avp-application" << ::std::endl;
	::std::cerr << "0       - full path resolution" << ::std::endl;
	::std::cerr << "1       - speed run full path resolution" << ::std::endl;
	::std::cerr << "2       - parallel / part path resolution" << ::std::endl;
}

int main (int argc, char **argv)
{
#if defined(__GNUC__) || defined(__GNUG__)
	// this variable is for gdb to test when errno gets modified, since errno as such doesn't exist anymore -> usage: watch *pErrno
	int 					*pErrno = __errno_location ();

#endif

	int						nRetval = 0;
	int						i;
	uint32_t				nTestNum = ~0x0;
	uint32_t				nNodeSize = 2;
	uint64_t				nProblemSize = 10000000;
	uint32_t				nProblemBias = 1;
	btreeType_e				eBtreeType = BTREETYPE_NOT_SPECIFIED;
	application_type_e		eApplicationType = APPLICATION_TYPE_NOT_SPECIFIED;
	bool					bPerformanceTest = false;
	size_type_e				eSizeType =	SIZE_TYPE_64;
	
#if defined (_MSC_VER)

	SYSTEM_INFO				systemInfo;

	GetSystemInfo (&systemInfo);

	uint32_t				nPageSize = systemInfo.dwAllocationGranularity;

#elif defined(__GNUC__) || defined(__GNUG__)

	uint32_t				nPageSize = (uint64_t) getpagesize ();

#endif

	srand (0);

	for (i = 1; i < argc; i++)
	{
		if (strcmp (argv[i], "-type") == 0)
		{
			i++;

			if (strcmp (argv[i], "array") == 0)
			{
				eBtreeType = BTREETYPE_ARRAY;
			}
			else if (strcmp (argv[i], "keysort") == 0)
			{
				eBtreeType = BTREETYPE_KEY_SORT;
			}
			else if (strcmp (argv[i], "index") == 0)
			{
				eBtreeType = BTREETYPE_INDEX;
			}
			else if (strcmp (argv[i], "reference") == 0)
			{
				eBtreeType = BTREETYPE_REFERENCE;
			}
			else if (strcmp (argv[i], "app") == 0)
			{
				eBtreeType = BTREETYPE_APPLICATION;
			}
			else if (strcmp (argv[i], "keysort-iter") == 0)
			{
				eBtreeType = BTREETYPE_KEY_SORT_ITERATOR;
			}
			else if (strcmp (argv[i], "array-iter") == 0)
			{
				eBtreeType = BTREETYPE_ARRAY_ITERATOR;
			}
			else if (strcmp (argv[i], "stl-multimap") == 0)
			{
				eBtreeType = BTREETYPE_STL_MULTIMAP;
			}
			else if (strcmp (argv[i], "stl-map") == 0)
			{
				eBtreeType = BTREETYPE_STL_MAP;
			}
			else if (strcmp (argv[i], "stl-multiset") == 0)
			{
				eBtreeType = BTREETYPE_STL_MULTISET;
			}
			else if (strcmp (argv[i], "stl-set") == 0)
			{
				eBtreeType = BTREETYPE_STL_SET;
			}
			else if (strcmp (argv[i], "example") == 0)
			{
				eBtreeType = BTREETYPE_EXAMPLES;
			}
			else
			{
				cerr << "ERROR: Unknown btree type specified!" << endl;

				return (-1);
			}
		}
		else if (strcmp (argv[i], "-app") == 0)
		{
			i++;

			if (strcmp (argv[i], "avp") == 0)
			{
				eApplicationType = APPLICATION_TYPE_AVP;
			}
		}
		else if (strcmp (argv[i], "-test") == 0)
		{
			i++;

			sscanf (argv[i], "%u", &nTestNum);
		}
		else if (strcmp (argv[i], "-nodesize") == 0)
		{
			i++;

			sscanf (argv[i], "%u", &nNodeSize);
		}
		else if (strcmp (argv[i], "-sizetype") == 0)
		{
			uint32_t	nSizeType;

			i++;

			sscanf (argv[i], "%u", &nSizeType);

			switch (nSizeType)
			{
			case	32	:	eSizeType =	SIZE_TYPE_32;

							break;

			case	64	:	eSizeType =	SIZE_TYPE_64;

							break;

			default		:	::std::cerr << "ERROR: Unknown size type specified!" << ::std::endl;

							return (-1);

							break;
			}
		}
		else if (strcmp (argv[i], "-problemsize") == 0)
		{
			i++;

			sscanf (argv[i], "%llu", &nProblemSize);
		}
		else if (strcmp (argv[i], "-problembias") == 0)
		{
			i++;

			sscanf (argv[i], "%lu", &nProblemBias);
		}
		else if (strcmp (argv[i], "-performance") == 0)
		{
			bPerformanceTest = true;
		}
		else if (
					(strcmp (argv[i], "-help") == 0) || 
					(strcmp (argv[i], "--help") == 0) || 
					(strcmp (argv[i], "-usage") == 0) || 
					(strcmp (argv[i], "--usage") == 0)
				)
		{
			print_usage (argv[0]);

			return (0);
		}
		else
		{
			::std::cerr << "Unknown argument: " << argv[i] << ::std::endl;
			::std::cerr << ::std::endl;

			print_usage (argv[0]);

			return (-1);
		}
	}

	try
	{
		if (bPerformanceTest)
		{
			switch (eBtreeType)
			{
			case BTREETYPE_KEY_SORT		:	

											break;

			case BTREETYPE_ARRAY		:	TestArrayPerf (nTestNum, nProblemSize, nProblemBias);

											break;

			case BTREETYPE_INDEX		:	

											break;

			case BTREETYPE_REFERENCE	:	

											break;

			case BTREETYPE_EXAMPLES		:	

											break;

			case BTREETYPE_APPLICATION	:	

											break;

			case BTREETYPE_KEY_SORT_ITERATOR	:
											

											break;

			case BTREETYPE_ARRAY_ITERATOR:	

											break;

			case BTREETYPE_STL_MULTIMAP	:	TestMultiMapPerf (nTestNum, nProblemSize, nProblemBias);

											break;

			case BTREETYPE_STL_MAP		:	

											break;

			case BTREETYPE_STL_MULTISET	:	

											break;

			case BTREETYPE_STL_SET		:	

											break;

			default						:	cerr << "ERROR: btree type not specified or not supported!" << endl;

											return (-1);

											break;
			}
		}
		else
		{
			switch (eBtreeType)
			{
			case BTREETYPE_KEY_SORT		:	
			{
				TestBTreeKeySortSubDivision (nTestNum, nNodeSize, nPageSize, eSizeType);
				
				break;
			}

			case BTREETYPE_ARRAY		:	
			{
				TestBTreeArraySubDivision (nTestNum, nNodeSize, nPageSize, eSizeType);
				
				break;
			}

			case BTREETYPE_INDEX		:	

											break;

			case BTREETYPE_REFERENCE	:	

											break;

			case BTREETYPE_EXAMPLES		:	
				switch (nTestNum)
				{
					case	0:

					example_1_polymorphic_calls ();

					break;

					case	1:

					example_2_simple_database ();

					break;
				}

				break;

			case BTREETYPE_APPLICATION	:	
				switch (eApplicationType)
				{
					case APPLICATION_TYPE_AVP	:
					{
						switch (nTestNum)
						{
						case	0	:	
						case	1	:	
						case	2	:	nRetval = avp_path_find_core (nTestNum, nNodeSize);

										break;

						default		:	cerr << "ERROR: unknown AVP application test specified! -test " << nTestNum << endl;

										break;
						}

						break;
					}

					default						:
					{
						::std::cerr << "ERROR: application type not specified or not supported!" << ::std::endl;

						return (-1);

						break;
					}
				}

				break;

			case BTREETYPE_KEY_SORT_ITERATOR	:
			{
				TestBTreeKeySortIterSubDivision (nTestNum, nNodeSize, nPageSize, eSizeType);
				
				break;
			}

			case BTREETYPE_ARRAY_ITERATOR:	
			{
				TestBTreeArrayIterSubDivision (nTestNum, nNodeSize, nPageSize, eSizeType);
				
				break;
			}

			case BTREETYPE_STL_MULTIMAP:	
			{
				TestBTreeMultiMapSubDivision (nTestNum, nNodeSize, nPageSize, eSizeType);
				
				break;
			}

			case BTREETYPE_STL_MAP		:	
			{
				TestBTreeMapSubDivision (nTestNum, nNodeSize, nPageSize, eSizeType);
				
				break;
			}

			case BTREETYPE_STL_MULTISET:
			{
				TestBTreeMultiSetSubDivision (nTestNum, nNodeSize, nPageSize, eSizeType);
				
				break;
			}

			case BTREETYPE_STL_SET:
			{
				TestBTreeSetSubDivision (nTestNum, nNodeSize, nPageSize, eSizeType);

				break;
			}

			default						:	::std::cerr << "ERROR: btree type not specified or not supported!" << ::std::endl;

											return (-1);

											break;
			}
		}
	}
	catch (std::runtime_error *pe)
	{
		::std::cerr << ::std::endl << "ERROR caught in test bench main: ";
		::std::cerr << pe->what () << ::std::endl;
		
		nRetval = -1;
	}

#if defined (_MSC_VER)

	if (GetLastError () != ERROR_SUCCESS)
	{
		::std::cerr << "main: test bench terminated with GetLastError () not ERROR_SUCCESS!" << ::std::endl;
		::std::cerr << "error code: " << GetLastError () << ::std::endl << ::std::flush;

		nRetval = -1;
	}

#elif defined(__GNUC__) || defined(__GNUG__)

	if (errno != 0)
	{
		::std::cerr << "main: test bench terminated with errno not zero!" << ::std::endl;
		::std::cerr << "error code: " << errno << ::std::endl << ::std::flush;

		nRetval = -1;
	}

#endif

	return (nRetval);
}

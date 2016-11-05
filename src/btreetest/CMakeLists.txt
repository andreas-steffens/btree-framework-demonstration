cmake_minimum_required (VERSION 3.1)

project (btreetest)

if (UNIX)
	option	(LINUX_BUILD_DEBUG				"set build to debug settings for regression and validation testing"	OFF)
	option	(LINUX_BUILD_RELEASE			"set build to release settings for performance testing"				OFF)
	option	(LINUX_BUILD_RELEASE_DBG_INFO	"set build to release settings for profiling"						OFF)
	option	(LINUX_BUILD_COVERAGE			"set build to coverage settings to create a coverage report"		OFF)
endif ()

list (APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/btree_framework)

find_package	(btree_framework	REQUIRED)

set		(	sources
			./applications/avp_path_find/avp_path_find_core.cpp
			./testbench/application_classes/performance/btreetestarrayperf.cpp
			./testbench/application_classes/regression/btreetestarray.cpp
			./testbench/application_classes/regression/btreetestkeysort.cpp
			./testbench/application_classes/regression/btreetestmap.cpp
			./testbench/application_classes/regression/btreetestmultimap.cpp
			./testbench/application_classes/regression/btreetestmultiset.cpp
			./testbench/application_classes/regression/btreetestset.cpp
			./testbench/common/btreetestcommon.cpp
			./testbench/common/btreeperftestcommon.cpp
			./testbench/primitives/btreearraytestprimitive.cpp
			./testbench/primitives/btreecommonprimitives.cpp
			./testbench/primitives/btreekeysorttestprimitive.cpp
			./testbench/primitives/btreemultimapprimitives.cpp
			./testbench/primitives/btreemultisetprimitives.cpp
			./testbench/tests/performance/btreearrayperftestbench.cpp
			./testbench/tests/performance/btreemultimapperftestbench.cpp
			./testbench/tests/regression/btreearrayitertestbench.cpp
			./testbench/tests/regression/btreearraytestbench.cpp
			./testbench/tests/regression/btreekeysortitertestbench.cpp
			./testbench/tests/regression/btreekeysorttestbench.cpp
			./testbench/tests/regression/btreemaptestbench.cpp
			./testbench/tests/regression/btreemultimaptestbench.cpp
			./testbench/tests/regression/btreemultisettestbench.cpp
			./testbench/tests/regression/btreesettestbench.cpp
			./testbench/wrapper_classes/base/btreeassociativetestwrapper.cpp
			./testbench/wrapper_classes/btreearraytestwrapper.cpp
			./testbench/wrapper_classes/btreekeysorttestwrapper.cpp
			./testbench/wrapper_classes/btreemaptestwrapper.cpp
			./testbench/wrapper_classes/btreemultimaptestwrapper.cpp
			./testbench/wrapper_classes/btreemultisettestwrapper.cpp
			./testbench/wrapper_classes/btreesettestwrapper.cpp
			./testbench/sub_division/btreetestsubdivisionkeysort.cpp
			./testbench/sub_division/btreetestsubdivisionarray.cpp
			./testbench/sub_division/btreetestsubdivisionkeysortiter.cpp
			./testbench/sub_division/btreetestsubdivisionarrayiter.cpp
			./testbench/sub_division/btreetestsubdivisionmap.cpp
			./testbench/sub_division/btreetestsubdivisionmultimap.cpp
			./testbench/sub_division/btreetestsubdivisionset.cpp
			./testbench/sub_division/btreetestsubdivisionmultiset.cpp
			./testbench/examples/example_1_polymorphic_calls.cpp
			./testbench/examples/example_2_simple_database.cpp
			./btreetest.cpp
		)

set		(	headers
			./applications/avp_path_find/airduct1B.h
			./applications/avp_path_find/airduct2B.h
			./applications/avp_path_find/airduct3B.h
			./applications/avp_path_find/airduct3C.h
			./applications/avp_path_find/airduct4B.h
			./applications/avp_path_find/airduct4C.h
			./applications/avp_path_find/airduct5B.h
			./applications/avp_path_find/airduct5C.h
			./applications/avp_path_find/alienvessel.h
			./applications/avp_path_find/avp_path_find_core.h
			./applications/avp_path_find/predatorship.h
			./applications/avp_path_find/sublevel1.h
			./applications/avp_path_find/sublevel2.h
			./applications/avp_path_find/sublevel3.h
			./applications/avp_path_find/sublevel4.h
			./applications/avp_path_find/sublevel5.h
			./testbench/application_classes/performance/btreetestarrayperf.h
			./testbench/application_classes/regression/btreetestarray.h
			./testbench/application_classes/regression/btreetestkeysort.h
			./testbench/application_classes/regression/btreetestmap.h
			./testbench/application_classes/regression/btreetestmultimap.h
			./testbench/application_classes/regression/btreetestmultiset.h
			./testbench/application_classes/regression/btreetestset.h
			./testbench/common/btreetestcommon.h
			./testbench/common/btreeperftestcommon.h
			./testbench/primitives/btreearraytestprimitive.h
			./testbench/primitives/btreecommonprimitives.h
			./testbench/primitives/btreekeysorttestprimitive.h
			./testbench/primitives/btreemultimapprimitives.h
			./testbench/primitives/btreemultisetprimitives.h
			./testbench/primitives/btreeprimitivedefinitions.h
			./testbench/tests/performance/btreearrayperftestbench.h
			./testbench/tests/performance/btreemultimapperftestbench.h
			./testbench/tests/regression/btreearrayitertestbench.h
			./testbench/tests/regression/btreearraytestbench.h
			./testbench/tests/regression/btreekeysortitertestbench.h
			./testbench/tests/regression/btreekeysorttestbench.h
			./testbench/tests/regression/btreemaptestbench.h
			./testbench/tests/regression/btreemultimaptestbench.h
			./testbench/tests/regression/btreemultisettestbench.h
			./testbench/tests/regression/btreesettestbench.h
			./testbench/wrapper_classes/base/btreeassociativetestwrapper.h
			./testbench/wrapper_classes/btreearraytestwrapper.h
			./testbench/wrapper_classes/btreekeysorttestwrapper.h
			./testbench/wrapper_classes/btreemaptestwrapper.h
			./testbench/wrapper_classes/btreemultimaptestwrapper.h
			./testbench/wrapper_classes/btreemultisettestwrapper.h
			./testbench/wrapper_classes/btreesettestwrapper.h
			./testbench/sub_division/btreetestsubdivisionkeysort.h
			./testbench/sub_division/btreetestsubdivisionarray.h
			./testbench/sub_division/btreetestsubdivisionkeysortiter.h
			./testbench/sub_division/btreetestsubdivisionarrayiter.h
			./testbench/sub_division/btreetestsubdivisionmap.h
			./testbench/sub_division/btreetestsubdivisionmultimap.h
			./testbench/sub_division/btreetestsubdivisionset.h
			./testbench/sub_division/btreetestsubdivisionmultiset.h
			./testbench/examples/example_1_polymorphic_calls.h
			./testbench/examples/example_2_simple_database.h
		)

set		(	srcs
			${sources}
			${headers}
		)

include_directories	(
			${BTREE_FRAMEWORK_INCLUDE_DIRS}
			${CMAKE_SOURCE_DIR}
			${CMAKE_SOURCE_DIR}/applications/avp_path_find
		)

# source groups as they displayed in IDEs
source_group ("sources\\applications\\avp_path_find" REGULAR_EXPRESSION \./applications/avp_path_find/.*\\.cpp)
source_group ("sources\\testbench\\application_classes\\performance" REGULAR_EXPRESSION \./testbench/application_classes/performance/.*\\.cpp)
source_group ("sources\\testbench\\application_classes\\regression" REGULAR_EXPRESSION \./testbench/application_classes/regression/.*\\.cpp)
source_group ("sources\\testbench\\common" REGULAR_EXPRESSION \./testbench/common/.*\\.cpp)
source_group ("sources\\testbench\\primitives" REGULAR_EXPRESSION \./testbench/primitives/.*\\.cpp)
source_group ("sources\\testbench\\tests\\performance" REGULAR_EXPRESSION \./testbench/tests/performance/.*\\.cpp)
source_group ("sources\\testbench\\tests\\regression" REGULAR_EXPRESSION \./testbench/tests/regression/.*\\.cpp)
source_group ("sources\\testbench\\wrapper_classes\\base" REGULAR_EXPRESSION \./testbench/wrapper_classes/base/.*\\.cpp)
source_group ("sources\\testbench\\wrapper_classes" REGULAR_EXPRESSION \./testbench/wrapper_classes/.*\\.cpp)
source_group ("sources\\testbench\\sub_division" REGULAR_EXPRESSION \./testbench/sub_division/.*\\.cpp)
source_group ("sources\\testbench\\examples" REGULAR_EXPRESSION \./testbench/examples/.*\\.cpp)
source_group ("sources\\testbench" REGULAR_EXPRESSION \./.*\.cpp)

source_group ("headers\\applications\\avp_path_find" REGULAR_EXPRESSION \./applications/avp_path_find/.*\\.h)
source_group ("headers\\testbench\\application_classes\\performance" REGULAR_EXPRESSION \./testbench/application_classes/performance/.*\\.h)
source_group ("headers\\testbench\\application_classes\\regression" REGULAR_EXPRESSION \./testbench/application_classes/regression/.*\\.h)
source_group ("headers\\testbench\\common" REGULAR_EXPRESSION \./testbench/common/.*\\.h)
source_group ("headers\\testbench\\primitives" REGULAR_EXPRESSION \./testbench/primitives/.*\\.h)
source_group ("headers\\testbench\\tests\\performance" REGULAR_EXPRESSION \./testbench/tests/performance/.*\\.h)
source_group ("headers\\testbench\\tests\\regression" REGULAR_EXPRESSION \./testbench/tests/regression/.*\\.h)
source_group ("headers\\testbench\\wrapper_classes\\base" REGULAR_EXPRESSION \./testbench/wrapper_classes/base/.*\\.h)
source_group ("headers\\testbench\\wrapper_classes" REGULAR_EXPRESSION \./testbench/wrapper_classes/.*\\.h)
source_group ("headers\\testbench\\sub_division" REGULAR_EXPRESSION \./testbench/sub_division/.*\\.h)
source_group ("headers\\testbench\\examples" REGULAR_EXPRESSION \./testbench/examples/.*\\.h)

if (MSVC)

	if (WIN32)
		string (COMPARE LESS "${CMAKE_SYSTEM_VERSION}" "6" IS_WINXP_OR_BEFORE)
	endif ()

	foreach (CONFIG_NAME IN LISTS CMAKE_CONFIGURATION_TYPES ITEMS ${CMAKE_BUILD_TYPE})
		string (TOUPPER "${CONFIG_NAME}" CONFIG_NAME)

		# /bigobj   - may be required by some compilers that run out of object file space
		#             this is a result of the very high number of template parameter variations in the project
		#             resulting in a large number of container types and even more methods
		# 
		# /wd"4250" - the compiler warns about virtual methods that have been set via dominance
		#             this can be ignored, since this is desired in this project
		# 
		# /wd"4996" - the compiler warns about a potential data loss when casting btree-framework types to
		#             STL types
		#             this can be safely ignore for as long as size_t is not smaller than 32 bits

		foreach (FLAGS_NAME CXX_FLAGS C_FLAGS)
			set ("CMAKE_${FLAGS_NAME}_${CONFIG_NAME}" ${CMAKE_${FLAGS_NAME}_${CONFIG_NAME}} " /bigobj /wd\"4996\" /wd\"4250\" ")
		endforeach ()

		# if this project is constructed on windows vista or later, then the multi processor compiler flag is enabled
		if (NOT ${IS_WINXP_OR_BEFORE})
			foreach (FLAGS_NAME CXX_FLAGS C_FLAGS)
				set ("CMAKE_${FLAGS_NAME}_${CONFIG_NAME}" ${CMAKE_${FLAGS_NAME}_${CONFIG_NAME}} " /MP ")
			endforeach ()
		endif ()

		foreach (FLAGS_NAME CXX_FLAGS C_FLAGS)
			string (REGEX REPLACE "%3B" " " "CMAKE_${FLAGS_NAME}_${CONFIG_NAME}" ${CMAKE_${FLAGS_NAME}_${CONFIG_NAME}})
		endforeach ()
	endforeach ()
	
	# definitions
	add_definitions ("/DBTREE_ITERATOR_REGISTRATION")
	add_definitions ("/DBTREEFRAMEWORK_TEST_BENCH_ENABLED")

elseif (UNIX)

	if ((NOT LINUX_BUILD_DEBUG) AND (NOT LINUX_BUILD_RELEASE) AND (NOT LINUX_BUILD_RELEASE_DBG_INFO) AND (NOT LINUX_BUILD_COVERAGE))
		message (STATUS "")
		message (STATUS "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
		message (STATUS "")
		message (STATUS "It looks like you tried to call cmake directly!")
		message (STATUS "This is problematic, since cmake just destroyed the original Makefile. To recover from that please run recover_makefile.sh or execute the following commands:")
		message (STATUS "rm -fv CMakeCache.txt")
		message (STATUS "rm -rfv CMakeFiles")
		message (STATUS "cp -fv Makefile.backup Makefile")
		message (STATUS "")
		message (STATUS "Please use one of the command lines below, instead of calling cmake.")
		message (STATUS "The make file rules will call cmake for you with the correct cmake settings being involved. Those will allow not only for different binaries to be build, but also to build those in parallel. However, during the compile process, each job may take up to ~1GB of memory, so use the make option -j with caution or not at all!")
		message (STATUS "")
		message (STATUS "make debug                             # builds regression test binary with debug flags")
		message (STATUS "make profile                           # builds regression test binary with profile flags (resulting binary is supposed to be used with a profiler)")
		message (STATUS "make release                           # builds regression test binary with release flags")
		message (STATUS "make regression                        # build debug binary and runs regression tests (this may take hours to complete)")
		message (STATUS "make clean_all                         # runs any clean commands")
		message (STATUS "make clean                             # removes any build file (may those be intermediate or final) plus destroys all auto generated test make files")
		message (STATUS "make clean_regression_tests            # cleans all regression tests regardless of their result")
		message (STATUS "make clean_failed_regression_tests     # cleans all regression tests that returned with an error code")
		message (STATUS "")
		message (STATUS "Depending on what binary has been build, use one of the following command lines to find out what quick test can be run, instead of running a full regression:")
		message (STATUS "btreetest_dbg --help")
		message (STATUS "btreetest_prf --help")
		message (STATUS "btreetest --help")
		message (STATUS "")
		message (STATUS "Please read the README file in the base directory to see all build rules.")
		message (STATUS "")
		message (STATUS "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
		message (STATUS "")

		message (SEND_ERROR "This is not an error despite what cmake is saying! Please read the message above!")
	endif ()

	# general gcc / g++ compiler settings
	set		(CMAKE_C_FLAGS		"${CMAKE_C_FLAGS} --std=c11 -fpermissive")
	set		(CMAKE_CXX_FLAGS	"${CMAKE_CXX_FLAGS} --std=c++11 -fpermissive")
	
	if (LINUX_BUILD_DEBUG)
		set		(CMAKE_CXX_FLAGS			"${CMAKE_CXX_FLAGS} -g -O0 -ftemplate-backtrace-limit=0" CACHE STRING "c++ compiler flags used during linux debug builds." FORCE)
		set		(CMAKE_C_FLAGS				"${CMAKE_C_FLAGS} -g -O0 -ftemplate-backtrace-limit=0" CACHE STRING "c compiler flags used during linux debug builds." FORCE)
		set		(CMAKE_EXE_LINKER_FLAGS		"${CMAKE_EXE_LINKER_FLAGS}" CACHE STRING "linker flags used during linux debug binary builds." FORCE)
		set		(CMAKE_SHARED_LINKER_FLAGS	"${CMAKE_SHARED_LINKER_FLAGS}" CACHE STRING "linker flags used during linux debug shared library builds." FORCE)

#		add_definitions ("-D_DEBUG")
	endif ()
	
	if (LINUX_BUILD_RELEASE)
		set		(CMAKE_CXX_FLAGS			"${CMAKE_CXX_FLAGS} -O3 -s -march=native" CACHE STRING "c++ compiler flags used during linux release builds." FORCE)
		set		(CMAKE_C_FLAGS				"${CMAKE_C_FLAGS} -O3 -s -march=native" CACHE STRING "c compiler flags used during linux release builds." FORCE)
		set		(CMAKE_EXE_LINKER_FLAGS		"${CMAKE_EXE_LINKER_FLAGS}" CACHE STRING "linker flags used during linux release binary builds." FORCE)
		set		(CMAKE_SHARED_LINKER_FLAGS	"${CMAKE_SHARED_LINKER_FLAGS}" CACHE STRING "linker flags used during linux release shared library builds." FORCE)
	endif ()
	
	if (LINUX_BUILD_RELEASE_DBG_INFO)
		set		(CMAKE_CXX_FLAGS			"${CMAKE_CXX_FLAGS} -g -O2 -march=native" CACHE STRING "c++ compiler flags used during linux release builds." FORCE)
		set		(CMAKE_C_FLAGS				"${CMAKE_C_FLAGS} -g -O2 -march=native" CACHE STRING "c compiler flags used during linux release builds." FORCE)
		set		(CMAKE_EXE_LINKER_FLAGS		"${CMAKE_EXE_LINKER_FLAGS}" CACHE STRING "linker flags used during linux release binary builds." FORCE)
		set		(CMAKE_SHARED_LINKER_FLAGS	"${CMAKE_SHARED_LINKER_FLAGS}" CACHE STRING "linker flags used during linux release shared library builds." FORCE)

#		add_definitions ("-D_DEBUG")
	endif ()
	
	if (LINUX_BUILD_COVERAGE)
		set		(CMAKE_CXX_FLAGS			"${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage -coverage -fno-inline -fno-inline-small-functions -fno-default-inline" CACHE STRING "c++ compiler flags used during linux coverage builds." FORCE)
		set		(CMAKE_C_FLAGS				"${CMAKE_C_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage -coverage -fno-inline -fno-inline-small-functions -fno-default-inline" CACHE STRING "c compiler flags used during linux coverage builds." FORCE)
		set		(CMAKE_EXE_LINKER_FLAGS		"${CMAKE_EXE_LINKER_FLAGS} -lgcov -coverage" CACHE STRING "linker flags used during linux coverage binary builds." FORCE)
		set		(CMAKE_SHARED_LINKER_FLAGS	"${CMAKE_SHARED_LINKER_FLAGS} -lgcov -coverage" CACHE STRING "linker flags used during linux coverage shared library builds." FORCE)
	endif ()

	# definitions
	add_definitions ("-DBTREE_ITERATOR_REGISTRATION")
	add_definitions ("-DBTREEFRAMEWORK_TEST_BENCH_ENABLED")
endif ()

# sub projects
add_subdirectory (btree_framework)

add_executable (${PROJECT_NAME} ${srcs})

add_dependencies (${PROJECT_NAME} btree_framework)

target_link_libraries (${PROJECT_NAME} btree_framework)


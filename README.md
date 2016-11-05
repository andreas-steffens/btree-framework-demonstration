[btree-framework](https://github.com/andreas-steffens/btree-framework-demonstration)
=================

The btree-framework provides a number of associative and linear containers, each being based on a btree structure. The intention is to deliver increased performance, since other implementations use linear arrays, link lists and red-black as well as binary trees. Any of the above methods develop poor performance when it comes to large data amounts, while btrees can scale quite well to that end. Furthermore, the provided containers come with an API interface compatible to existing STL containers, which enables a quick switch between container types within a project. Any btree container type can be abstracted, as oppose to their existing STL equivalents, allowing applications to create their own container type hierarchy. Also, the sorting criteria is a virtual method and not a template parameter, which makes it possible for iterators to support so called "scary assignments", as described by Bjarne Sproustrup’s paper [“Minimizing Dependencies within Generic Classes for Faster and Smaller Programs”](http://www.stroustrup.com/SCARY.pdf). For increased scalability, the size&#95;type is selected via a template parameter and unlike other implementations, is not bound to what size&#95;t is set to.

And finally, the project supports cmake, which is explained in the "How To Build" section below.
<br>
<br>
## Documentation

The documentation of this project comes in two flavours:
- [Open Document Text file (.ODT)](https://github.com/andreas-steffens/btree-framework-demonstration/blob/master/doc/btree%20programmer%20guide.odt?raw=true)
- [Portable Document Format file (.PDF)](https://github.com/andreas-steffens/btree-framework-demonstration/blob/master/doc/btree%20programmer%20guide.pdf?raw=true)

The documentation is pretty large and might be a bit overwhelming. To address that problem, please find the section "1. Where to start" of the [README](https://github.com/andreas-steffens/btree-framework-demonstration/blob/master/README) file. This section tells what sections need to be initially read in order to understand how this framework is working and supposed to be used.
Also available is a quick overview presentation giving a short introduction to the project (see the links below):
- [Open Document Impress file (.ODP)](https://github.com/andreas-steffens/btree-framework-demonstration/blob/master/doc/quick%20overview.odp?raw=true)
- [Portable Document Format file (.PDF)](https://github.com/andreas-steffens/btree-framework-demonstration/blob/master/doc/quick%20overview.pdf?raw=true)

<br>
<br>
## How to build the test bench under windows for x86 and x86&#95;64 platforms?
--
Please read section "2.2. Windows - How to build the test bench using cygwin and cmake" of the [README](https://github.com/andreas-steffens/btree-framework-demonstration/blob/master/README) file.
<br>
<br>
## How to build the test bench under linux?
--
Please read section "2.1. Linux - How to build the test bench using cmake" of the [README](https://github.com/andreas-steffens/btree-framework-demonstration/blob/master/README) file.
<br>
<br>
## Version

The current version of the project is: 0.06 (alpha)

Please don't be discouraged by the fact that the version contains the word "alpha". What this means is that the feature set is incomplete, but what has been implemented is stable and thoroughly tested. See below to find out what is missing:

- initializer&#95;list<> support
- move constructors and move assignment operators
- equal&#95;range ()
 
<br>
<br>
## Agenda

For the project to leave its alpha state, all the above features and methods will be implemented. Once, the project is entering the beta phase the following points will be addressed:

- more application based testing, combined with the existing artificial testing approach
- performance tests
- c++11 language feature tests
- performance improvements

<br>
<br>
## Btree-Framework Project on Facebook

If you want to see updates or release on the btree-framework project, then follow this link: [https://www.facebook.com/btreeframework](https://www.facebook.com/btreeframework)<br>
Every release post also contains a brief change log statement, allowing to tell what major changes have been made.
<br>
<br>
## Contact

Please see [README](https://github.com/andreas-steffens/btree-framework-demonstration/blob/master/README) section "3. Feedback".
<br>
<br>
## Test Bench

The btree-framework-testbench is capable to exercise tests on the [btree-framework](https://github.com/andreas-steffens/btree-framework) in terms of regression, code_coverage and validation. Each of those test categories involves tests that cover basic functionality, API coverage and corner case coverage.
The project is cmake based and is therefore very easy to set up. The two "How to build ..." sections below show how.
<br>
<br>
## Synopsis
```
./btreetest -help | --help | -usage | --usage
./btreetest -type <test type> [-app <app name>] -test <test number> [-sizetype <address space bit width>]

-help, --help, 	prints this help page and exits
-usage, --usage

-type			selects the container type or application test mode

				stl-set			- selects STL interface equivalent set container types
				stl-multiset	- selects STL interface equivalent multiset container types
				stl-map			- selects STL interface equivalent map container types
				stl-multimap	- selects STL interface equivalent multimap container types
				array			- selects array container types
				keysort			- selects keysort container types
				array-iter		- selects array iterators
				keysort-iter	- selects keysort iterators
				app				- switches test bench to application testing mode

-app			selects an application name for real world testing
				purposes, in case the application testing mode has
				been selected

				avp				- AVP path find application

-test			selects the test number of the test to be executed

				The test list can be found at the end of this document.

-sizetype		selects the bit width of size_type of the target containers

				32				- size_type is set to uint32_t (default)
				64				- size_type is set to uint64_t (default)

				This setting is ineffective in application testing mode.
```

<br>
<br>
## Test Lists

stl-set, stl-multiset, stl-map and stl-multimap

	0		- test exercises assignment operator of selected container type

	1000	- test exercises interface method insert (const value_type &)
	1001	- test exercises interface method insert<iterator> (iterator &, iterator &)
	1002	- test exercises interface method erase (const_iterator &) 
	1003	- test exercises interface method erase (const key_value &)
	1004	- test exercises interface method erase (const_iterator &, const_iterator &)
	1005	- test exercises interface method key_comp ()
	1006	- test exercises interface method value_comp ()
	1007	- test exercises interface method swap (container &)
	1008	- test exercises interface method find (const key_type &)
	1009	- test exercises interface methods lower_bound (const key_type &) and upper_bound (const key_type &)
	1010	- test exercises interface method emplace<_t_va_args> (_t_va_args && ...)
	1011	- test exercises interface method emplace_hint<_t_va_args> (const_iterator &, _t_va_args && ...) with perfect hint
	1012	- test exercises interface method emplace_hint<_t_va_args> (const_iterator &, _t_va_args && ...) with near perfect hint
	1013	- test exercises interface method emplace_hint<_t_va_args> (const_iterator &, _t_va_args && ...) with potentially bad hint
	1014	- test exercises interface method emplace_hint<_t_va_args> (const_iterator &, _t_va_args && ...) with terrible hint
	1015	- test exercises interface method insert (const_iterator &, const value_type &) with perfect hint
	1016	- test exercises interface method insert (const_iterator &, const value_type &) with near perfect hint
	1017	- test exercises interface method insert (const_iterator &, const value_type &) with potentially bad hint
	1018	- test exercises interface method insert (const_iterator &, const value_type &) with terrible hint

array

	0		- test adds data at the beginning and removes data at the end
	1		- test adds data at the beginning and removes data at the end on a smaller scale
	2		- test adds data at the end and removes data at the beginning
	3		- test adds data at the end and removes data at the beginning on a smaller scale
	4		- test adds data at a random positions and removes data at random positions
	5		- test adds data at a random positions and removes data at random positions on a smaller scale
	6		- test exercises if container is still ready to operate once interface method clear () has been called
	7		- test exercises scenario where data is rapidly inserted and removed again
	8		- test exercises if container is still ready to operate once interface method unload () has been called
	9		- test exercises if container is still ready to operate once interface debug method show_integrity () has been called
	10		- test exercises copy constructor of container type
	11		- test exercises overloaded assignment operator of container type
	12		- test exercises overloaded subscript operator of container type
	13		- test reads all data from container using method serialize ()
	14		- test reads data from half of a random node using method serialize ()
	15		- test reads data from part of a random node using method serialize ()
	16		- test reads data from from container using method serialize (), while parameters exceeding container size
	17		- test exercises situation where a container is self-referenced using iterators
	18		- test reads no data from container using method serialize () with read length set to zero

	1000	- test exercises interface method assign (const size_type, const value_type &)
	1001	- test exercises interface method assign<iterator> (iterator &, iterator &)
	1002	- test exercises interface method push_back () and pop_back ()
	1003	- test exercises interface method insert (const_iterator, const size_type &, const value_type &)
	1004	- test exercises interface method insert<iterator> (const_iterator, iterator &, iterator &)
	1005	- test exercises interface method insert (const_iterator, iterator &, iterator &) on a large container via self-reference
	1006	- test exercises interface method insert (const_iterator, const_iterator &, const_iterator &) on a large container via self-reference
	1007	- test exercises interface method insert (const_iterator, reverse_iterator &, reverse_iterator &) on a large container via self-reference
	1008	- test exercises interface method insert (const_iterator, const_reverse_iterator &, const_reverse_iterator &) on a large container via self-reference
	1009	- test exercises interface method erase (const key_value &)
	1010	- test exercises interface method erase (const_iterator &, const_iterator &)
	1011	- test exercises interface method swap (container &)
	1012	- test exercises interface method emplace<_t_va_args> (const_iterator &, _t_va_args && ...)
	1013	- test exercises interface method emplace_back<_t_va_args> (_t_va_args && ...)

	2000	- code coverage test where data is removed resulting in nodes being merged, while the right node has a lower id than the left node

keysort

	0		- test adds data at the beginning and removes data at the end
	1		- test adds data at the beginning and removes data at the end on a smaller scale
	2		- test adds data at the end and removes data at the beginning
	3		- test adds data at the end and removes data at the beginning on a smaller scale
	4		- test adds data at a random positions and removes data at random positions
	5		- test adds data at a random positions and removes data at random positions on a smaller scale
	6		- test exercises if container is still ready to operate once interface method clear () has been called
	7		- test exercises scenario where data is rapidly inserted and removed again
	8		- test exercises if container is still ready to operate once interface method unload () has been called
	9		- test exercises interface method erase (const_iterator &), while removing specific instance of a key set
	10		- test exercises if container is still ready to operate once interface debug method show_integrity () has been called
	11		- test exercises copy constructor of container type
	12		- test exercises overloaded assignment operator of container type
	13		- test exercises overloaded assignment operator of container type, while making sure key sets remain in order
	14		- test reads all data from container using method serialize ()
	15		- test reads data from half of a random node using method serialize ()
	16		- test reads data from part of a random node using method serialize ()
	17		- test reads data from from container using method serialize (), while parameters exceeding container size
	18		- test reads all data from container using method serialize (), while making sure key sets remain in order
	19		- test reads data from half of a random node using method serialize (), while making sure key sets remain in order
	20		- test reads data from part of a random node using method serialize (), while making sure key sets remain in order

	1000	- test exercises interface method insert (const value_type &)
	1001	- test exercises interface method insert<iterator> (iterator &, iterator &)
	1002	- test exercises interface method erase (const_iterator &) 
	1003	- test exercises interface method erase (const key_value &)
	1004	- test exercises interface method erase (const_iterator &, const_iterator &)
	1005	- test exercises interface method swap (container &)
	1006	- test exercises interface method find (const key_type &)
	1007	- test exercises interface methods lower_bound (const key_type &) and upper_bound (const key_type &)
	1008	- test exercises interface method emplace<_t_va_args> (_t_va_args && ...)
	1009	- test exercises interface method emplace_hint<_t_va_args> (const_iterator &, _t_va_args && ...) with perfect hint
	1010	- test exercises interface method emplace_hint<_t_va_args> (const_iterator &, _t_va_args && ...) with near perfect hint
	1011	- test exercises interface method emplace_hint<_t_va_args> (const_iterator &, _t_va_args && ...) with potentially bad hint
	1012	- test exercises interface method emplace_hint<_t_va_args> (const_iterator &, _t_va_args && ...) with terrible hint
	1013	- test exercises interface method insert (const_iterator &, const value_type &) with perfect hint
	1014	- test exercises interface method insert (const_iterator &, const value_type &) with near perfect hint
	1015	- test exercises interface method insert (const_iterator &, const value_type &) with potentially bad hint
	1016	- test exercises interface method insert (const_iterator &, const value_type &) with terrible hint

	2000	- code coverage test which exercises corner cases in method determine_position ()
	2001	- code coverage test which exercises corner cases in method find_first_key ()
	2002	- code coverage test which exercises corner cases in method get_init_pos_of_key () on leaf node
	2003	- code coverage test which exercises corner cases in overloaded method set_iter_data ()
	2004	- code coverage test which exercises corner cases in overloaded compare operator

array-iter

	0		- test exercises increment operator
	1		- test exercises increment operator on a small scale
	2		- test exercises decrement operator
	3		- test exercises decrement operator on a small scale
	4		- test exercises arithmetic operator+ with one of the operands being the result instance (a = a + n)
	5		- test exercises arithmetic operator+ with one of the operands being the result instance on a small scale
	6		- test exercises arithmetic operator- with one of the operands being the result instance (a = a - n)
	7		- test exercises arithmetic operator- with one of the operands being the result instance on a small scale
	8		- test exercises arithmetic operator+ with different step sizes versus different node sizes
	9		- test exercises arithmetic operator- with different step sizes versus different node sizes
	10		- test exercises dereference operator*
	11		- test exercises subscript operator[size_type]
	12		- test exercises subscript operator[int]
	13		- test exercises compound operator+= (size_type)
	14		- test exercises compound operator+= (int)
	15		- test exercises compound operator+= (iterator)
	16		- test exercises arithmetic operator+ and operator- with none of the operands being the result instance (r = a + b) or (r = a - b)
	17		- test exercises all compare operators (<, >, <=, >=, ==, !=)
	18		- test exercises interface method swap (iterator &) with parameter from a different container
	19		- test exercises interface method swap (iterator &) with parameter from the same different container

	2000	- code coverage test exercises compare operator with same instance as an input
	2001	- code coverage test exercises situation where the time stamp is up to date after a re-assignment
	2002	- code coverage test exercises situation where the time stamp is up to date after a re-register
	2003	- code coverage test exercises situation where an uninitialised iterator is assigned to another instance
	2004	- code coverage test exercises all begin () and end () methods

keysort-iter

	0		- test exercises increment operator
	1		- test exercises increment operator on a small scale
	2		- test exercises decrement operator
	3		- test exercises decrement operator on a small scale
	4		- test exercises arithmetic operator+ with one of the operands being the result instance (a = a + n)
	5		- test exercises arithmetic operator+ with one of the operands being the result instance on a small scale
	6		- test exercises arithmetic operator- with one of the operands being the result instance (a = a - n)
	7		- test exercises arithmetic operator- with one of the operands being the result instance on a small scale
	8		- test exercises arithmetic operator+ with different step sizes versus different node sizes
	9		- test exercises arithmetic operator- with different step sizes versus different node sizes
	10		- test exercises subscript operator[size_type]
	11		- test exercises subscript operator[int]
	12		- test exercises compound operator+= (size_type)
	13		- test exercises compound operator+= (int)
	14		- test exercises compound operator+= (iterator)
	15		- test exercises arithmetic operator+ and operator- with none of the operands being the result instance (r = a + b) or (r = a - b)
	16		- test exercises all compare operators (<, >, <=, >=, ==, !=)
	17		- test exercises interface method swap (iterator &) with parameter from the same different container

app

avp-application

	0		- full path resolution
	1		- speed run full path resolution
	2		- parallel / part path resolution
<br>
<br>
## License

Licensed under the Lesser GNU Public License, Version 3.0: [http://www.gnu.org/licenses/lgpl-3.0.txt](http://www.gnu.org/licenses/lgpl-3.0.txt)


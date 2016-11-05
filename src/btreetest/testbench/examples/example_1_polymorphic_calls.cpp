/************************************************************
**
** file:	example_1_polymorphic_calls.cpp
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
** This file contains code displaying the btree-framework
** providing containers, which can be uniformly called.
**
************************************************************/

#include "example_1_polymorphic_calls.h"

void example_1_polymorphic_calls ()
{
	typedef CBTreeIOpropertiesRAM<>		ram_data_layer_property_type;

	typedef CBTreeMap<uint32_t, uint32_t, ram_data_layer_property_type>
										btree_map_type;

	typedef CBTreeMultiMap<uint32_t, uint32_t, ram_data_layer_property_type>
										btree_multimap_type;

	typedef btree_map_type::CBTreeAssociativeIf_t
										btree_polymorphic_type;

	typedef btree_map_type::value_type	value_type;

	uint32_t							i;

	// data will stored in RAM
	ram_data_layer_property_type		sRAMproperties;

	// we will use a unique and a multi key container
	btree_map_type						*psBTreeMap = new btree_map_type (sRAMproperties, 16);
	btree_multimap_type					*psBTreeMultiMap  = new btree_multimap_type (sRAMproperties, 16);

	btree_polymorphic_type				*apPolymorphicMaps[2];

	// this would not be possible with STL containers
	apPolymorphicMaps[0] = dynamic_cast<btree_polymorphic_type *> (psBTreeMap);
	apPolymorphicMaps[1] = dynamic_cast<btree_polymorphic_type *> (psBTreeMultiMap);

	for (i = 0; i < 16; i++)
	{
		uint32_t	j;

		// this will create data items with equal keys
		// the multi map container will accept any data
		// while the map container will only allow for data to stored that has a unique key value
		for (j = 0; j < (sizeof (apPolymorphicMaps) / sizeof (*apPolymorphicMaps)); j++)
		{
			value_type		sValue (i / 2, i);

			apPolymorphicMaps[j]->insert (sValue);
		}
	}

	// display content
	for (i = 0; i < (sizeof (apPolymorphicMaps) / sizeof (*apPolymorphicMaps)); i++)
	{
		auto	sCIter = apPolymorphicMaps[i]->cbegin ();
		auto	sCIterEnd = apPolymorphicMaps[i]->cend ();

		::std::cout << "Container " << i + 1 << " holds the following:" << ::std::endl;

		for (; sCIter < sCIterEnd; ::std::advance (sCIter, 1))
		{
			value_type		sValue = *sCIter;

			::std::cout << sValue.first << " : " << sValue.second << ::std::endl;
		}

		::std::cout << ::std::endl;
	}

	// also abstract deletions are possible
	for (i = 0; i < (sizeof (apPolymorphicMaps) / sizeof (*apPolymorphicMaps)); i++)
	{
		delete apPolymorphicMaps[i];
	}
}

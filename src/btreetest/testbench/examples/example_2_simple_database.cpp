/************************************************************
**
** file:	example_2_simple_database.cpp
** author:	Andreas Steffens
** license:	LGPL v3
**
** description:
**
** This file contains code displaying the btree-framework
** providing containers, which can be uniformly called.
**
************************************************************/

#include "example_2_simple_database.h"

typedef struct car_holders_s
{
	car_holders_s ()
	{};

	// we need a constructor for emplace_back () to work
	car_holders_s (const ::std::string & _strLastName, const ::std::string & _strLicensePlate, const ::std::string & _strPhoneNumber)
	{
		strLastName = _strLastName;
		strLicensePlate = _strLicensePlate;
		strPhoneNumber = _strPhoneNumber;
	};

	::std::string		strLastName;
	::std::string		strLicensePlate;
	::std::string		strPhoneNumber;
} car_holders_t;

template<class _t_keytype, int _t_nSelectKey, class _t_datalayerproperties>
class car_holders : public CBTreeMultiSet<_t_keytype, _t_datalayerproperties>
{
public:

	typedef CBTreeMultiSet<_t_keytype, _t_datalayerproperties>	CBTreeMultiSet_t;

	typedef	typename CBTreeMultiSet_t::value_type				value_type;
	typedef	typename CBTreeMultiSet_t::key_type					key_type;

	typedef	typename CBTreeMultiSet_t::sub_node_iter_type		sub_node_iter_type;

	typedef typename CBTreeMultiSet_t::CBTreeAssociativeIf_t	CBTreeAssociativeIf_t;

					car_holders<_t_keytype, _t_nSelectKey, _t_datalayerproperties>
						(_t_datalayerproperties &rDataLayerProperties, sub_node_iter_type nNodeSize)
						:	CBTreeMultiSet<_t_keytype, _t_datalayerproperties> (rDataLayerProperties, nNodeSize)
					{};

					~car_holders<_t_keytype, _t_nSelectKey, _t_datalayerproperties>
						()
					{};

	// application specific classes need to provide their own sort criteria method
	virtual int		comp (const key_type &rKey0, const key_type &rKey1) const
	{
		::std::string		*pstr0;
		::std::string		*pstr1;

		// select key to sort by
		switch (_t_nSelectKey)
		{
		case	0	:	pstr0 = (::std::string *) &rKey0.strLastName;
						pstr1 = (::std::string *) &rKey1.strLastName;

						break;

		case	1	:	pstr0 = (::std::string *) &rKey0.strLicensePlate;
						pstr1 = (::std::string *) &rKey1.strLicensePlate;

						break;

		case	2	:	pstr0 = (::std::string *) &rKey0.strPhoneNumber;
						pstr1 = (::std::string *) &rKey1.strPhoneNumber;

						break;
		}

		if (*pstr0 < *pstr1)
		{
			return (-1);
		}
		else if (*pstr0 == *pstr1)
		{
			return (0);
		}
		else
		{
			return (1);
		}
	};
};

template<class _t_polymorphic_container>
void add_entry (_t_polymorphic_container **ppContainers, uint32_t nNumContainers, ::std::string &rStrName, ::std::string &rStrLicensePlate, ::std::string &rStrPhoneNumber)
{
	uint32_t			i;
	car_holders_t		sEntry = {rStrName, rStrLicensePlate, rStrPhoneNumber};

	for (i = 0; i < nNumContainers; i++)
	{
		ppContainers[i]->insert (sEntry);
	}
}

void example_2_simple_database ()
{
	typedef CBTreeIOpropertiesRAM<>		ram_data_layer_property_type;

	typedef car_holders<car_holders_t, 0, ram_data_layer_property_type>
										car_holders_sort_by_name;

	typedef car_holders<car_holders_t, 1, ram_data_layer_property_type>
										car_holders_sort_by_license_plate;

	typedef car_holders<car_holders_t, 2, ram_data_layer_property_type>
										car_holders_sort_by_phone_number;

	typedef car_holders_sort_by_name::CBTreeAssociativeIf_t
										polymorphic_sort_type;

	typedef car_holders_sort_by_name::value_type	value_type;

	typedef CBTreeArray<value_type>		array_type;

	typedef CBTreeIf<value_type>		generic_type;

	uint32_t							i;

	// data will stored in RAM
	ram_data_layer_property_type		sRAMproperties;

	// we will use the three different sort criterias by type definition
	car_holders_sort_by_name			*psCarHoldersSortByName = new car_holders_sort_by_name (sRAMproperties, 16);
	car_holders_sort_by_license_plate	*psCarHoldersSortByLicensePlate = new car_holders_sort_by_license_plate (sRAMproperties, 16);
	car_holders_sort_by_phone_number	*psCarHoldersSortByPhoneNumer = new car_holders_sort_by_phone_number (sRAMproperties, 16);

	polymorphic_sort_type				*apSortCarHolders[3];

	array_type							*psCarHolders = new array_type (sRAMproperties, 16);

	const char							*apszSortCatecory[] = {"name", "license plate", "phone number"};

	apSortCarHolders[0] = dynamic_cast<polymorphic_sort_type *> (psCarHoldersSortByName);
	apSortCarHolders[1] = dynamic_cast<polymorphic_sort_type *> (psCarHoldersSortByLicensePlate);
	apSortCarHolders[2] = dynamic_cast<polymorphic_sort_type *> (psCarHoldersSortByPhoneNumer);

	psCarHolders->emplace_back (::std::string ("Miller"), ::std::string ("XYZ111"), ::std::string ("1234567"));
	psCarHolders->emplace_back (::std::string ("Thronton"), ::std::string ("MAY123"), ::std::string ("7654321"));
	psCarHolders->emplace_back (::std::string ("Claydon"), ::std::string ("EEE12X"), ::std::string ("9000001"));

	// display content
	for (i = 0; i < (sizeof (apSortCarHolders) / sizeof (*apSortCarHolders)); i++)
	{
		auto	sCIter = psCarHolders->cbegin ();
		auto	sCIterEnd = psCarHolders->cend ();

		// feed data entries to have those sorted
		apSortCarHolders[i]->insert (sCIter, sCIterEnd);

		// Yes, you can trust your eyes!
		// Any container type within this framework uses the same iterator types...
		sCIter = apSortCarHolders[i]->cbegin ();
		sCIterEnd = apSortCarHolders[i]->cend ();

		::std::cout << "Output sort by " << apszSortCatecory[i] << ::std::endl;

		for (; sCIter < sCIterEnd; ::std::advance (sCIter, 1))
		{
			value_type		sValue = *sCIter;

			::std::cout << sValue.strLastName << "   " << sValue.strLicensePlate << "   " << sValue.strPhoneNumber << ::std::endl;
		}

		::std::cout << ::std::endl;

		apSortCarHolders[i]->clear ();
	}

	generic_type		*apAllContainers[(sizeof (apSortCarHolders) / sizeof (*apSortCarHolders)) + 1];

	// if you want to see something really cool, watch this ...

	// we are now casting our set and array containers to be even more abstract ...
	for (i = 0; i < (sizeof (apSortCarHolders) / sizeof (*apSortCarHolders)); i++)
	{
		apAllContainers[i] = dynamic_cast<generic_type *> (apSortCarHolders[i]);
	}

	apAllContainers[i] = dynamic_cast<generic_type *> (psCarHolders);

	// that way even more abstract deletions are possible, since all 
	// containers in this framework are derived from CBTreeIf ...
	for (i = 0; i < (sizeof (apAllContainers) / sizeof (*apAllContainers)); i++)
	{
		delete apAllContainers[i];
	}
}

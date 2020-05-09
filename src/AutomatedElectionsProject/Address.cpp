#define _CRT_SECURE_NO_WARNINGS

#include "Address.h"
#include <iostream>

using namespace std;

Address::Address(
	const char* city,
	const char* street,
	unsigned int houseNumber)
{
	if (city == nullptr ||
		street == nullptr ||
		houseNumber == 0)
	{
		//future exception handle
	}

	_city = new char[strlen(city) + 1];
	strcpy(_city, city);

	_street = new char[strlen(street) + 1];
	strcpy(_street, street);

	_houseNumber = houseNumber;
}

Address::Address(const Address& other) : Address(other._city, other._street, other._houseNumber)
{
}

Address::~Address()
{
	delete[] _city;
	delete[] _street;
}

ostream& operator<<(ostream& os, const Address& addr)
{
	os << "City: " << addr._city << " Street: " << addr._street << " House Number: " << addr._houseNumber;
	return os;
}

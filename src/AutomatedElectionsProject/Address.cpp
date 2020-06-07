#define _CRT_SECURE_NO_WARNINGS

#include "Address.h"
#include <iostream>

#include "Exception.h"

using namespace std;

Address::Address(
	const string& city,
	const string& street,
	unsigned int houseNumber) noexcept(false) : _city(city) , _street(street), _houseNumber(houseNumber)
{
	if (city.empty() ||
		street.empty() ||
		houseNumber == 0)
	{
		throw Exception("Invalid Address");
	}

}

Address::Address(const Address& other) : Address(other._city, other._street, other._houseNumber)
{
}



ostream& operator<<(ostream& os, const Address& addr)
{
	os << "City: " << addr._city << " Street: " << addr._street << " House Number: " << addr._houseNumber;
	return os;
}

#include "Address.h"
#include <iostream>

using namespace std;

bool Address::Initialize(const char* city, const char* street, unsigned int houseNumber)
{
	if (city == nullptr ||
		street == nullptr ||
		houseNumber == 0)
	{
		return false;
	}

	_city = city;
	_street = street;
	_houseNumber = houseNumber;
	return true;
}

void Address::Show() const
{
	cout << "City: " << _city << " Street: " << _street << " House Number: " << _houseNumber << endl;
}

#define _CRT_SECURE_NO_WARNINGS

#include "Address.h"
#include <iostream>

using namespace std;

bool Address::Initialize(
	const char* city,
	const char* street,
	unsigned int houseNumber)
{
	if (city == nullptr ||
		street == nullptr ||
		houseNumber == 0)
	{
		return false;
	}

	_city = new char[strlen(city) + 1];
	strcpy(_city, city);

	_street = new char[strlen(street) + 1];
	strcpy(_street, city);
	
	_houseNumber = houseNumber;
	return true;
}

void Address::Show() const
{
	cout << "City: " << _city << " Street: " << _street << " House Number: " << _houseNumber << endl;
}

void Address::Free() const
{
	delete[] _city;
	delete[] _street;
}

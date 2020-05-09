#ifndef ADDRESS_H
#define ADDRESS_H

#include <ostream>
using namespace std;

class Address
{
private:
	char* _city;
	char* _street;
	unsigned int _houseNumber;
public:
	Address(const char* city, const char* street, unsigned int houseNumber);
	Address(const Address& other);
	~Address();

	friend ostream& operator<<(ostream& os, const Address& addr);
};
#endif // ADDRESS_H

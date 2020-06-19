#ifndef ADDRESS_H
#define ADDRESS_H
#include <fstream>
#include <ostream>
using namespace std;

class Address
{
private:
	string _city;
	string _street;
	unsigned int _houseNumber;
public:
	Address(const string& city, const string& street, unsigned int houseNumber);
	Address(const Address& other);
	Address(ifstream& file);
	~Address()= default;


	void Save(ofstream& file) const ;

	friend ostream& operator<<(ostream& os, const Address& addr);
};
#endif // ADDRESS_H

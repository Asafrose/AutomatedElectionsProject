#ifndef ADDRESS_H
#define ADDRESS_H

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
	
	void Show() const;
	void Free() const;
};
#endif // ADDRESS_H

#ifndef ADDRESS_H
#define ADDRESS_H

class Address
{
private:
	char* _city;
	char* _street;
	int _houseNumber;
public:
	void Initialize(const char* city, const char* street, int houseNumber);
	void Show();
};
#endif // ADDRESS_H

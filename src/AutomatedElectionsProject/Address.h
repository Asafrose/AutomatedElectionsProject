#ifndef ADDRESS_H
#define ADDRESS_H

class Address
{
private:
	char* _city;
	char* _street;
	unsigned int _houseNumber;
public:
	bool Initialize(
		const char* city,
		const char* street,
		unsigned int houseNumber);
	void Show() const;
	void Free() const;
};
#endif // ADDRESS_H

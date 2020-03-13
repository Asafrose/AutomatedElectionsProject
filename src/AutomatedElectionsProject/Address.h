#ifndef ADDRESS_H
#define ADDRESS_H

class Address
{
private:
	const char* _city;
	const char* _street;
	unsigned int _houseNumber;
public:
	bool Initialize(
		const char* city,
		const char* street,
		unsigned int houseNumber);
	void Show() const;
};
#endif // ADDRESS_H

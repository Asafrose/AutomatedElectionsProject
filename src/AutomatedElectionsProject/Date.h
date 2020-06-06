
#ifndef DATE_H
#define DATE_H
#include <ostream>
#include <chrono>

#include "Duration.h"

using namespace std;
using namespace chrono;

class Date
{
private:
	int _day;
	int _month;
	int _year;
	
public:
	const static Date Now();
	
	Date(unsigned int day, unsigned int month, unsigned int year);
	Date(unsigned int month, unsigned int year);
	Date(unsigned int year);
	Date(istream& in);
	~Date() = default;

	int GetYear() const;

	friend ostream& operator<<(ostream& os, const Date& date);

	Duration operator-(const Date& other) const;
};

#endif // DATE_H

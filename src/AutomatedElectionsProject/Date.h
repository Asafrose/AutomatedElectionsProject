
#ifndef DATE_H
#define DATE_H

class Date
{
private:
	int _day;
	int _month;
	int _year;
	
public:
	Date(unsigned int day, unsigned int month, unsigned int year);
	Date(unsigned int month, unsigned int year);
	Date(unsigned int year);
	Date(const Date& other);
	~Date() = default;
	
	void Show() const;
};

#endif // DATE_H

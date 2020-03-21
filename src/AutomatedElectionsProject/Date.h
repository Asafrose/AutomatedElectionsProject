
#ifndef DATE_H
#define DATE_H

class Date
{
private:
	int _day;
	int _month;
	int _year;
	
public:
	bool SetDate(unsigned int day, unsigned int month, unsigned int year);
	bool SetDate(unsigned int month, unsigned int year);
	bool SetDate(unsigned int year);
	void Show() const;
};

#endif // DATE_H

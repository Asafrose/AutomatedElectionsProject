
#ifndef DATE_H
#define DATE_H

class Date
{
private:
	int Day;
	int Month;
	int Year;
public:
	void SetDate(int day, int month, int year);
	void SetDate(int month, int year);
	void SetDate(int year);
};

#endif // DATE_H

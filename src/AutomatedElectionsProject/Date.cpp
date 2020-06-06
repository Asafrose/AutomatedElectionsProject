#include "Date.h"
#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

bool IsLeapYear(unsigned int year)
{
	//https://docs.microsoft.com/en-us/office/troubleshoot/excel/determine-a-leap-year
	return year % 400 == 0 || (year % 4 == 0 && year % 100 == 0);
}

bool IsValidDay(unsigned int day, unsigned int month, unsigned int year)
{
	if (day == 0)
	{
		return false;
	}

	if (month == 2)
	{
		return IsLeapYear(year)
			       ? day <= 29
			       : day <= 28;
	}

	if (month == 4 ||
		month == 6 ||
		month == 9 ||
		month == 11)
	{
		return day <= 30;
	}

	return day <= 31;
}

bool IsValidYear(unsigned int year)
{
	return year > 0;
}

bool IsValidMonth(unsigned int month)
{
	return month > 0 && month <= 12;
}

const Date Date::Now()
{
	time_t nowT = system_clock::to_time_t(system_clock::now());
	tm now = {};
	localtime_s(&now, &nowT);

	return Date(now.tm_mday, now.tm_mon + 1, now.tm_year + 1900);
}

Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
	if (!IsValidYear(year) ||
		!IsValidMonth(month) ||
		!IsValidDay(day, month, year))
	{
		//future exception handeling
	}

	_day = day;
	_month = month;
	_year = year;
}


Date::Date(unsigned int month, unsigned int year) : Date(1, month, year)
{
}

Date::Date(unsigned int year) : Date(1, year)
{
}

Date::Date(istream& in)
{
	in.read((char*)this, sizeof(*this));
}

int Date::GetYear() const
{
	return _year;
}

Duration Date::operator-(const Date& other) const
{
	tm thisTm = {0, 0, 0, _day, _month - 1, _year - 1900};
	tm otherTm = {0, 0, 0, other._day, other._month - 1, other._year - 1900};

	return Duration::FromDays((int)difftime(mktime(&thisTm), mktime(&otherTm)) / (60 * 60 * 24));
}

ostream& operator<<(ostream& os, const Date& date)
{
	os << date._day << "/" << date._month << "/" << date._year;
	return os;
}

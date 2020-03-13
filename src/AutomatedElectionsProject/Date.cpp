#include "Date.h"

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

bool Date::SetDate(unsigned int day, unsigned int month, unsigned int year)
{
	if (!IsValidYear(year) ||
		!IsValidMonth(month) ||
		!IsValidDay(day, month, year))
	{
		return false;
	}

	_day = day;
	_month = month;
	_year = year;
	return true;
}


bool Date::SetDate(unsigned int month, unsigned int year)
{
	return SetDate(1, month, year);
}

bool Date::SetDate(unsigned int year)
{
	return SetDate(1, 1, year);
}
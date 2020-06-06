#include "Duration.h"

Duration::Duration(const int& days) : _days(days)
{
}

Duration Duration::FromDays(const int& days)
{
	return Duration(days);
}

Duration Duration::FromYears(const int& years)
{
	return Duration(years * 365);
}

bool Duration::operator>=(const Duration& other) const
{
	return _days >= other._days;
}

bool Duration::operator<=(const Duration& other) const
{
	return _days <= other._days;
}

bool Duration::operator<(const Duration& other) const
{
	return _days < other._days;
}

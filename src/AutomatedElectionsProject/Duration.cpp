#include "Duration.h"

Duration::Duration(const double& days) : _days(days)
{
}

Duration Duration::FromDays(const double& days)
{
	return Duration(days);
}

Duration Duration::FromYears(const double& years)
{
	return Duration(years * 365);
}

int Duration::Days() const
{
	return (int)_days;
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

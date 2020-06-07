#ifndef DURATION_H
#define DURATION_H

class Duration
{
private:
	double _days;

	Duration(const double& days);
public:
	static Duration FromDays(const double& days);
	static Duration FromYears(const double& years);

	int Days() const;

	bool operator>=(const Duration& other) const;
	bool operator<=(const Duration& other) const;
	bool operator<(const Duration& other) const;
};
#endif // DURATION_H

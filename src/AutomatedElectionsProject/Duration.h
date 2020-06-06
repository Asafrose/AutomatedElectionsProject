#ifndef DURATION_H
#define DURATION_H

class Duration
{
private:
	int _days;

	Duration(const int& days);
public:
	static Duration FromDays(const int& days);
	static Duration FromYears(const int& years);

	bool operator>=(const Duration& other) const;
	bool operator<=(const Duration& other) const;
	bool operator<(const Duration& other) const;
};
#endif // DURATION_H

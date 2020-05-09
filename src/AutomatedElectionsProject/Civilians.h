
#ifndef CIVILIANS_H
#define CIVILIANS_H

#include "Civilian.h"

class Civilians
{
private:
	Civilian** _array = nullptr;
	int _count = 0;
	int _physicalCount = 0;
	
public:
	Civilians() = default;
	
	~Civilians();
	
	void Add(Civilian* civilian);
	Civilian& Get(int index) const;
	int GetCount() const;

	void operator+=(Civilian* civilian);
};
#endif // CIVILIANS_H

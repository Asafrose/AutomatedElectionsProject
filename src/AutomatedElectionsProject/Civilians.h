
#ifndef CIVILIANS_H
#define CIVILIANS_H

#include "Civilian.h"

class Civilians
{
private:
	Civilian** _array;
	int _count;
	int _physicalCount;
	
public:
	Civilians();
	
	~Civilians();
	
	void Add(Civilian* civilian);
	Civilian& Get(int index) const;
	int GetCount() const;
	void RemoveById(int civilianId);

	void operator+=(Civilian* civilian);
};
#endif // CIVILIANS_H

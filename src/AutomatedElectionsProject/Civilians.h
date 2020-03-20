
#ifndef CIVILIANS_H
#define CIVILIANS_H

#include "Civilian.h"

class Civilians
{
private:
	Civilian** _civilians = nullptr;
	int _count = 0;
	int _physicalCount = 0;
	
public:
	void AddCivilian(Civilian& civilian);
	Civilian& GetCivilian(int index) const;
	int GetCount() const;
	void Free() const;
};
#endif // CIVILIANS_H


#ifndef CIVILIANS_H
#define CIVILIANS_H

#include "Civilian.h"

class Civilians
{
private:
	Civilians** _civilians = nullptr;
	int _count = 0;
	
public:
	void AddCivilian(Civilian civilian);
	Civilian& GetCivilian(int index);
};
#endif // CIVILIANS_H

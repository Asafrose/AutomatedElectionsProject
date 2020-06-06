#ifndef CIVILIANSFILE_H
#define CIVILIANSFILE_H
#include "Civilians.h"
#include <vector>

template<class TItem>
class DataFile
{
private:
	static const string file_name = typeid(TItem).name();
public:
	static vector Load();
	static void Save(const Civilians& civilians);
};

#endif // CIVILIANSFILE_H

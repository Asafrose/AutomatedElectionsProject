#ifndef CIVILIANSFILE_H
#define CIVILIANSFILE_H

#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "FileHelper.h"
#include "ObjectGenerator.h"

using namespace std;

template <class TItem>
class DataFile
{
private:
	static const string file_name;

public:
	static void Save(const vector<TItem*>& items)
	{
		ofstream file;
		file.open(file_name, ios::binary | ios::trunc);

		FileHelper::Write(items.size(), file);
		for (auto iter = items.cbegin(); iter != items.cend(); ++iter)
		{
			(*iter)->Save(file);
		}
		file.close();
	}

	template <class TAdditionalData>
	static vector<TItem*> Load(const TAdditionalData& additionalData)
	{
		vector<TItem*> result;
		ifstream file;
		file.open(file_name, ios::binary);
		
		if (!(!file))
		{
			size_t numberOfElements;
			file.read((char*)&numberOfElements, sizeof(size_t));
			for (int i = 0; i < numberOfElements; ++i)
			{
				result.push_back(ObjectGenerator::CreateObject<TItem>(file,additionalData));
			}
		}
		file.close();
		return result;
	}
};

template <class TItem>
const string DataFile<TItem>::file_name(typeid(TItem).name());

#endif // CIVILIANSFILE_H

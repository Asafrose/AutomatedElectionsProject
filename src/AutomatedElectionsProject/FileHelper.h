#ifndef FILEHELPER_H
#define FILEHELPER_H
#include <fstream>
using namespace std;

class FileHelper
{
public:

	//Reads from file into object by ref
	template <class TItem>
	static void Read(TItem& item, ifstream& file)
	{
		file.read((char*)&item, sizeof(TItem));
	}

	//Write to file from object by ref
	template <class TItem>
	static void Write(const TItem& item, ofstream& file)
	{
		file.write((char*)&item, sizeof(TItem));
	}

	//Reads from file into string by ref
	static void ReadString(string& str, ifstream& file);
	//Write to file from string by ref
	static void WriteString(const string& str, ofstream& file);
};
#endif // FILEHELPER_H

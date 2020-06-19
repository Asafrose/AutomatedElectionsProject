#pragma once
#include <fstream>
using namespace std;

class FileHelper
{
public:

	//file to program 
	template <class TItem>
	static void Read(TItem& item, ifstream& file)
	{
		file.read((char*)&item, sizeof(TItem));
	}

	//program to file  
	template <class TItem>
	static void Write(const TItem& item, ofstream& file)
	{
		file.write((char*)&item, sizeof(TItem));
	}

	static void ReadString(string& str, ifstream& file)
	{
		size_t size;
		Read(size, file);
		char* temp = new char[size + 1];
		file.read(temp, size);
		temp[size] = '\0';
		str = string(temp);
		delete[] temp;
	}
	static void WriteString(const string& str, ofstream& file)
	{
		const size_t size = str.size();
		Write(size, file);
		file.write(str.c_str(), size);
		
	}
};

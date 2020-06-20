#include "FileHelper.h"

void FileHelper::ReadString(string& str, ifstream& file)
{
	size_t size;
	Read(size, file);
	char* temp = new char[size + 1];
	file.read(temp, size);
	temp[size] = '\0';
	str = string(temp);
	delete[] temp;
}

void FileHelper::WriteString(const string& str, ofstream& file)
{
	const size_t size = str.size();
	Write(size, file);
	file.write(str.c_str(), size);
}

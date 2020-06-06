
#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>

using namespace std;

class Exception
{
	string _message;
public:
	Exception(const string& message);

	string GetMessage() const;
};
#endif // EXCEPTION_H

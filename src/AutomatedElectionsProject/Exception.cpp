#include "Exception.h"

Exception::Exception(const string& message): _message(message)
{
}

string Exception::GetMessage() const
{
	return _message;
}

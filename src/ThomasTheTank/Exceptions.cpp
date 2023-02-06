#include "Exceptions.h"


namespace ThomasTheTank
{
	Exception::Exception(std::string _message)
	{
		message = _message;
	}

	const char* Exception::what()
	{
		return message.c_str();
	}
}
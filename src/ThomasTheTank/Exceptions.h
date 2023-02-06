#ifndef THOMASTHETANK_EXCEPTIONS_H
#define THOMASTHETANK_EXCEPTIONS_H

#include <exception>
#include <string>

namespace ThomasTheTank
{

	class Exception : public std::exception
	{
	public:
		Exception(std::string _message);
		

		const char* what();

	private:
		std::string message;
	};
}

#endif // !THOMASTHETANK_EXCEPTIONS_H
#ifndef THOMASTHETANK_EXCEPTIONS_H
#define THOMASTHETANK_EXCEPTIONS_H

#include <exception>
#include <string>

namespace ThomasTheTank
{

	class Exception : public std::exception
	{
	public:
		/**
		* Main constructor of an exception
		* 
		* \param _message STRING message to display when exception thrown
		*/
		Exception(std::string _message);
		

		const char* what(); ///< return the message to display

	private:
		std::string message; ///< stored error message
	};
}

#endif // !THOMASTHETANK_EXCEPTIONS_H
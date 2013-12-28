#include "Excpetion.h"

namespace NAV
{
	Exception::Exception(std::string cause)
	{
		if(cause.length() == 0)
			Exception("Criação de uma exceção com uma causa vazia").raise();

		this->cause = cause;
	}

#ifndef _MSC_VER
	Exception::~Exception() noexcept(true) { }
#endif

#ifdef _MSC_VER
	Exception::~Exception() throw() { }
#endif

	std::string Exception::getCause() const
	{
		return cause;
	}

	void Exception::raise() const
	{
		throw *this;
	}
}

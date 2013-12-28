#ifndef TILESETEXCEPTION_H
#define TILESETEXCEPTION_H

#include <string>

#include "../../Excpetion.h"

namespace NAV
{
	class MapException : public Exception
	{
	public:
		MapException(std::string cause);
	};

}

#endif

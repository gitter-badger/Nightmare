#ifndef EXCPTION_TILESE_NAME_H
#define EXCPTION_TILESE_NAME_H

#include <exception>
#include <string>

#include "../../Excpetion.h"

namespace NAV
{
	class TilesetNameException : public std::exception , public Exception
	{
	public:
		TilesetNameException(std::string cause);
	};
}


#endif

#ifndef TILESETEMPTYNAMEEXCEPTION_H_
#define TILESETEMPTYNAMEEXCEPTION_H_

#include "TilesetNameException.h"

namespace NAV
{

	class TilesetEmptyNameException: public NAV::TilesetNameException
	{
	public:
		TilesetEmptyNameException(std::string cause);
	};

}
#endif

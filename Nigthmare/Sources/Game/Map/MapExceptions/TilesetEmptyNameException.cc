/*
 * TilesetEmptyNameException.cc
 *
 *  Created on: 29/08/2013
 *      Author: Lucas
 */

#include "TilesetEmptyNameException.h"

namespace NAV
{
	TilesetEmptyNameException::TilesetEmptyNameException(std::string cause) : TilesetNameException(cause) { }
}

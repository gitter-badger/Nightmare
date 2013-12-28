#include "Tilemap.h"

#include "Tile.h"
#include "MapArea.h"

namespace NAV
{
	Tilemap::Tilemap(std::shared_ptr<MapArea> parent)
	{

	}

	Tilemap::Tilemap(std::shared_ptr<MapArea> parent, sf::Vector2<int> pos)
	{

	}

	Tilemap::~Tilemap()
	{
		parentArea.reset();
		layer1.clear();
		layer2.clear();
		layer3.clear();
	}
}
#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

namespace NAV
{
	class Tile;
	class MapArea;

	class Tilemap
	{
	public:
		Tilemap(std::shared_ptr<NAV::MapArea> parent);
		Tilemap(std::shared_ptr<NAV::MapArea> parent, sf::Vector2<int> pos);
		virtual ~Tilemap();

	private:
		std::vector<std::vector<NAV::Tile> > layer1;
		std::vector<std::vector<NAV::Tile> > layer2;
		std::vector<std::vector<NAV::Tile> > layer3;
		std::shared_ptr<MapArea> parentArea;
		sf::Vector2<int> mapPos;
	};
}

#endif

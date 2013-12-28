#ifndef MAP_AREA_H
#define MAP_AREA_H

#include <string>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

namespace NAV
{
	class Tilemap;

	class MapArea
	{
	public:
		MapArea(std::string name);
		~MapArea();

	private:
		std::string areaName;
		sf::Rect<int> areaSize;
		std::vector<std::vector<std::unique_ptr<NAV::Tilemap> > > maps;
	};
}

#endif

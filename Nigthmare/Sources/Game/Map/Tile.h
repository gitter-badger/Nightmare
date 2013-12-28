#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

#include <fstream>
#include <memory>

#include "Tileset.h"

namespace NAV
{
	class Tile
	{
	public:
		Tile(std::shared_ptr<Tileset> parent);
		Tile(std::shared_ptr<Tileset> parent, sf::Vector2<int> tileValue);
		Tile(std::ifstream fileStream);
		virtual ~Tile();

		static std::unique_ptr<Tile> load(std::ifstream fileStream);

		virtual void update() = 0;
		void changeParentTileset(std::shared_ptr<Tileset> parent);

		sf::Vector2<int> tileValue() const;
		void tileValue(sf::Vector2<int> value);

		void save(std::ifstream fileStream);

	private:
		std::shared_ptr<Tileset> referenceParent;
		sf::Vector2<int> tileValueOfTileset;
	};
}

#endif

#include "Tile.h"

#include "../Excpetion.h"

namespace NAV
{
	Tile::Tile(std::shared_ptr<Tileset> parent) 
	{ 
		try
		{
			changeParentTileset(parent);
		}
		catch (NAV::Exception &e)
		{
			throw e;
		}

		tileValueOfTileset = sf::Vector2<int>(0, 0);
	}

	Tile::Tile(std::shared_ptr<Tileset> parent, sf::Vector2<int> tileValue)
	{
		try
		{
			changeParentTileset(parent);
		}
		catch (NAV::Exception &e)
		{
			throw e;
		}

		try
		{
			this->tileValue(tileValue);
		}
		catch (NAV::Exception &e)
		{
			throw e;
		}
		
	}

	Tile::~Tile()
	{
		referenceParent.reset();
	}

	void Tile::changeParentTileset(std::shared_ptr<Tileset> parent)
	{
		if (!parent)
			throw NAV::Exception("null pointer parrent");

		referenceParent = parent;
	}

	sf::Vector2<int> Tile::tileValue() const
	{
		return tileValueOfTileset;
	}

	void Tile::tileValue(sf::Vector2<int> value)
	{
		sf::Vector2<int> size = referenceParent->tilesetSize();
		if ((value.x >= size.x) || (value.y >= size.y))
			throw NAV::Exception("Value out of range, value must be smaller than size at least one");

		tileValueOfTileset = value;
	}
}

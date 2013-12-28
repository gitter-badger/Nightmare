#include "LinearPositioner.h"

namespace NAV
{
	LinearPositioner::LinearPositioner(sf::Vector2f size)
	{
		sizeOfBlock = size;
	}

	sf::Vector2f LinearPositioner::blockPosition(sf::Vector2i pos) const
	{
		return sf::Vector2f(pos.x * sizeOfBlock.x, pos.y * sizeOfBlock.y);
	}

	sf::Vector2f LinearPositioner::blockSize() const
	{
		return sizeOfBlock;
	}
}
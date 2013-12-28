#ifndef I_POSITIONER_BLOCK_H
#define I_POSITIONER_BLOCK_H

#include <SFML/Graphics.hpp>

namespace NAV
{
	class IPositioner
	{
	public:
		virtual ~IPositioner() = 0;
		
		/**
		*@para(pos) TEM QUE SER EM TILES NAO EM PIXELS 
		**/
		virtual sf::Vector2f blockPosition(sf::Vector2i pos) const = 0;

		/**
		*@return RETORNA O TAMANO DO TILE/BLOCO EM PIXELS
		**/
		virtual sf::Vector2f blockSize() const = 0;
	};

}

#endif

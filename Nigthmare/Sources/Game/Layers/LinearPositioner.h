#ifndef LINEAR_POSITIONER_H
#define LINEAR_POSITIONER_H

#include <SFML/Graphics.hpp>

#include "IPositioner.h"

namespace NAV
{
	class LinearPositioner : public IPositioner
	{
	public:
		/**
		*@param(size) SIZE TEM QUE SER EM BLOCKS NAO PIXELS
		**/
		LinearPositioner(sf::Vector2f size);

		/**
		*@param(pos) POS TEM Q SER EM TILES/BLOCOS NAO EM PIXELS
		**/
		virtual sf::Vector2f blockPosition(sf::Vector2i pos) const;

		/**
		*@return RETORNA O TAMANO DO BLOCO EM PIXELS
		**/
		virtual sf::Vector2f blockSize() const;

	protected:
		sf::Vector2f sizeOfBlock;
	};
}

#endif

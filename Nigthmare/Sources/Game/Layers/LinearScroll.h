#ifndef LINEAR_SCROLL_H
#define LINEAR_SCROLL_H

#include <memory>

#include <SFML/Graphics.hpp>

#include "IScroller.h"

namespace NAV
{
	class VertexRect;

	class LinearScroll : public IScroller
	{
	public:
		LinearScroll(sf::Vector2f leftScroll, sf::Vector2f rightScroll);

		virtual ~LinearScroll();

		virtual void scroll(sf::Vertex *quad, sf::Vector2f offset);

	private:
		sf::Vector2f left;
		sf::Vector2f right;
	};

}

#endif

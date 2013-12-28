#ifndef I_SCROLLABLE_H
#define I_SCROLLABLE_H

#include <SFML/Graphics.hpp>

namespace NAV
{
	class VertexRect;
	class Layer;

	class IScroller
	{
	public:
		virtual ~IScroller() = 0;

		virtual void scroll(sf::Vertex *quad, sf::Vector2f offset) = 0;
	private:
		friend class Layer;
	};

}

#endif

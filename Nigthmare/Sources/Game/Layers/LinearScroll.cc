#include "LinearScroll.h"

#include "../VertexQuadManipulator.h"

namespace NAV
{
	LinearScroll::LinearScroll(sf::Vector2f leftScroll, sf::Vector2f rightScroll)
	{
		left = leftScroll - sf::Vector2f(64, 64);
		right = rightScroll + sf::Vector2f(64, 64);
	}

	LinearScroll::~LinearScroll() { }

	void LinearScroll::scroll(sf::Vertex *quad, sf::Vector2f offset)
	{
		VertexQuadManipulator rect(quad);
		
		rect.intersects

		sf::Vector2f size = rect.size();
		sf::Vector2f pos = rect.position();
		sf::Vector2f newPos = pos;

		if (((pos.x + offset.x) + size.x) < (left.x))
		{
			newPos.x = right.x;
		}
		else if ((pos.x + offset.x) > right.x)
		{
			newPos.x = (left.x - size.x);
		}
		else
			newPos.x += offset.x;
		
		if (((pos.x + offset.x) + size.x) < (left.x))
		{
			newPos.y = right.y;
		}
		else if ((pos.y + offset.y) > right.y)
		{
			newPos.y = (left.y - size.y);
		}
		else
			newPos.y += offset.y;


		rect.position(newPos);
	}
}

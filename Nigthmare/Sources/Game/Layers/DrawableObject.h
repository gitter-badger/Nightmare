#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H

#include <memory> 

#include <SFML/Graphics.hpp>

namespace NAV
{
	class Layer;

	class DrawableObject
	{
	public:
		DrawableObject(std::shared_ptr<sf::Image> imgPtr, sf::FloatRect imgRect);
		
		virtual ~DrawableObject();

		virtual void update();

		void imagePtr(std::shared_ptr<sf::Image> ptr);
		std::shared_ptr<sf::Image> imagePtr() const;

		void imageRect(sf::FloatRect pos);
		sf::FloatRect imageRect() const;

	protected:
		std::shared_ptr<sf::Image> imgPtr;
		sf::FloatRect imgRect;
	};
}

#endif

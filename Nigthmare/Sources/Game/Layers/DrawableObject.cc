#include "DrawableObject.h"

#include "../Excpetion.h"

namespace NAV
{
	DrawableObject::DrawableObject(std::shared_ptr<sf::Image> imgPtr, sf::FloatRect imgRect)
	{
		DrawableObject::imgPtr = imgPtr;
		DrawableObject::imgRect = imgRect;
	}

	DrawableObject::~DrawableObject() 
	{ 
		imgPtr.reset();
	}

	void DrawableObject::imagePtr(std::shared_ptr<sf::Image> ptr)
	{
		if (ptr == nullptr)
			throw NAV::Exception("ptr da imagem apontando para null");

		imgPtr = ptr;
	}

	void DrawableObject::update() { }
	

	std::shared_ptr<sf::Image> DrawableObject::imagePtr() const
	{
		return imgPtr;
	}

	void DrawableObject::imageRect(sf::FloatRect rect)
	{
		sf::Vector2u imgSize = imgPtr->getSize();
		sf::FloatRect imgRect(0, 0, imgSize.x, imgSize.y);

		if ( (rect.top < 0) || ((rect.top + rect.width) > imgRect.width))
			throw NAV::Exception("retangulo esta fora da area da imagem");		///	 TROCAR PARA UMA EXCEÇÃO MAIS COERENTE COMO FORA DE AREA
		else if ((rect.left < 0) || ((rect.left + rect.height) > imgRect.height))
			throw NAV::Exception("retangulo esta fora da area da imagem");		///	 TROCAR PARA UMA EXCEÇÃO MAIS COERENTE COMO FORA DE AREA
		else
			DrawableObject::imgRect = rect;
	}

	sf::FloatRect DrawableObject::imageRect() const
	{
		return imgRect;
	}
}
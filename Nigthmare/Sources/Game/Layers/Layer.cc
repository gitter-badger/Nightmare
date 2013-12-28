#include "Layer.h"

#include "IPositioner.h"
#include "IScroller.h"
#include "DrawableObject.h"
#include "../VertexQuadManipulator.h"


#include <iostream>

namespace NAV
{
	Layer::Layer(IScroller &scroller, IPositioner &positioner, sf::Vector2i sizeInBlocks) :
		scroller(scroller), positioner(positioner)
	{
		sf::Vector2f layerSize = sf::Vector2f((sizeInBlocks.x * positioner.blockSize().x) + (4 * positioner.blockSize().x),
			(sizeInBlocks.y * positioner.blockSize().y) + (4 * positioner.blockSize().y));

		layerTexture.create((int)layerSize.x, (int)layerSize.y);

		sf::Vector2f blockPos;
		sf::Vector2f texQuadPos;

		Layer::sizeInBlocks = sf::Vector2i((sizeInBlocks.x + 4), (sizeInBlocks.y + 4));

		vertices.setPrimitiveType(sf::Quads);
		vertices.resize(Layer::sizeInBlocks.x * Layer::sizeInBlocks.y * 4);	/// PARA SE TER UMA REPRESENTAÇÃO DE UMA MATRIZ EM UM ARRAY É NECESSARIO TER ISSO
																			/// E COMO É UM ARRAY DE VERTICES É MULTIPLICADO POR 4 PARA REPRESENTAR OS QUADRADOS

		NAV::VertexQuadManipulator quadManipulator(getQuad(0, 0));

		for (int x = 0; x < Layer::sizeInBlocks.x; x++)
		{
			for (int y = 0; y < Layer::sizeInBlocks.y; y++)
			{
				quadManipulator.changeRectQuad(getQuad(x, y));

				quadManipulator.position(sf::Vector2f(0, 0));
				quadManipulator.size(positioner.blockSize());
				
				quadManipulator.position(positioner.blockPosition(sf::Vector2i(x - 2, y - 2)));
				
				if (x == 0 && y == 0)
					quadManipulator.color(sf::Color::Blue);
				else if (x == 0 && y == (Layer::sizeInBlocks.y - 1))
					quadManipulator.color(sf::Color::Blue);
				else if (x == (Layer::sizeInBlocks.x - 1) && y == 0)
					quadManipulator.color(sf::Color::Blue);
				else if (x == (Layer::sizeInBlocks.x - 1) && y == (Layer::sizeInBlocks.y - 1))
					quadManipulator.color(sf::Color::Blue);
				else
					quadManipulator.color(sf::Color::Green);
			}
		}
	}

	Layer::~Layer() { }

	void Layer::scroll(sf::Vector2f offset)
	{
		currentOffset += offset;
	}

	void Layer::update()
	{
		for (int x = 0; x < Layer::sizeInBlocks.x; x++)
		{
			for (int y = 0; y < Layer::sizeInBlocks.y; y++)
				scroller.scroll(getQuad(x, y), currentOffset);
				
		}

		currentOffset.x = 0;
		currentOffset.y = 0;
	}

	void Layer::draw(sf::RenderTarget &target, sf::RenderStates states) const
	{
		//states.texture = &layerTexture;

		target.draw(vertices);
	}

	sf::Vertex* Layer::getQuad(int x, int y)
	{
		return &vertices[(x + y * (sizeInBlocks.x)) * 4];
	}
}

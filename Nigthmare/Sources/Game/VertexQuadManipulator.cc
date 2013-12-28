#include "VertexQuadManipulator.h"

#include "Excpetion.h"

namespace NAV
{
	VertexQuadManipulator::VertexQuadManipulator(sf::Vertex *quad)
	{
		if (quad == nullptr)
			throw NAV::Exception("quad nao pode ser um ponteiro nulo");/// TROCAR PARA UMA EXCEÇÃO MAIS COERENTE

		VertexQuadManipulator::quad = quad;
	}

	VertexQuadManipulator::~VertexQuadManipulator() { }

	void VertexQuadManipulator::position(sf::Vector2f ps)
	{
		sf::Vector2f _size = size();

		quad[0].position = sf::Vector2f(ps.x, ps.y);
		quad[1].position = sf::Vector2f(ps.x + _size.x, ps.y);
		quad[2].position = sf::Vector2f(ps.x + _size.x, ps.y + _size.y);
		quad[3].position = sf::Vector2f(ps.x, ps.y + _size.y);
	}

	sf::Vector2f VertexQuadManipulator::position() const
	{
		return quad[0].position;
	}

	sf::Vector2f VertexQuadManipulator::texPosition() const
	{
		return quad[0].texCoords;
	}

	void VertexQuadManipulator::color(sf::Color color)
	{
		quad[0].color = color;
		quad[1].color = color;
		quad[2].color = color;
		quad[3].color = color;
	}

	void VertexQuadManipulator::texPosition(sf::Vector2f pos)
	{
		sf::Vector2f _size = size();

		quad[0].texCoords = sf::Vector2f(pos.x, pos.y);
		quad[1].texCoords = sf::Vector2f(pos.x + _size.x, pos.y);
		quad[2].texCoords = sf::Vector2f(pos.x + _size.x, pos.y + _size.y);
		quad[3].texCoords = sf::Vector2f(pos.x, pos.y + _size.y);
	}
	
	void VertexQuadManipulator::changeRectQuad(sf::Vertex *quad)
	{
		if (quad == nullptr)
			throw NAV::Exception("quad nao pode ser um ponteiro nulo");/// TROCAR PARA UMA EXCEÇÃO MAIS COERENTE

		VertexQuadManipulator::quad = quad;
	}

	sf::Vector2f VertexQuadManipulator::size() const
	{
		sf::Vector2f _size;
		_size.x = quad[1].position.x - quad[0].position.x;
		_size.y = quad[3].position.y - quad[0].position.y;

		return _size;
	}

	void VertexQuadManipulator::size(sf::Vector2f sz)
	{
		sf::Vector2f ps = position();

		quad[1].position = sf::Vector2f(ps.x + sz.x, ps.y);
		quad[2].position = sf::Vector2f(ps.x + sz.x, ps.y + sz.y);
		quad[3].position = sf::Vector2f(ps.x, ps.y + sz.y);
	}

	bool VertexQuadManipulator::intersect(const sf::Vertex *quad) const
	{
		VertexQuadManipulator rect(const_cast<sf::Vertex*>(quad));

		sf::Vector2f _pos = position();
		sf::Vector2f _size = size();

		sf::FloatRect quadRect(_pos.x, _pos.y, _size.x, _size.y);

		_pos = rect.position();
		_size = rect.size();

		sf::FloatRect rectQuad(_pos.x, _pos.y, _size.x, _size.y);

		return quadRect.intersects(rectQuad);
	}

	bool VertexQuadManipulator::contains(const sf::Vertex vertex) const
	{
		sf::Vector2f _pos = position();
		sf::Vector2f _size = size();

		sf::FloatRect quad(_pos.x, _pos.y, _size.x, _size.y);

		return quad.contains(vertex.position);
	}
}
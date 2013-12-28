#ifndef VERTEX_RECT
#define VERTEX_RECT

#include <SFML/Graphics.hpp>

namespace NAV
{
	class VertexQuadManipulator
	{
	public:
		/**
		* @param(quad) ponteiro para os quatro vertices que o retangulo ira conter
		**/
		VertexQuadManipulator(sf::Vertex *quad);

		virtual ~VertexQuadManipulator();

		void changeRectQuad(sf::Vertex *quad);

		/**
		* @param(siz) novo tamanho que o rectangulo ira ter
		**/
		void size(sf::Vector2f siz);

		/**
		* @return retorna o tamanho atual que o retangulo possui
		**/
		sf::Vector2f size() const;

		/**
		* @param(pos) posição da textura que o retangulo ira represetar
		**/
		void texPosition(sf::Vector2f pos);

		/**
		* @return retorna a posição atual do retangulo para a textura
		**/
		sf::Vector2f texPosition() const;

		/**
		* @param(ps) posisao que o retangulo esta
		**/
		void position(sf::Vector2f ps);

		void color(sf::Color clr);
		
		sf::Color color() const;

		/**
		* @return retorna a posicao atual do retangulo
		**/
		sf::Vector2f position() const;

		/**
		* @param(rect) retangulo de vertices a ser verificado se se possui alguma interceção com este retangulo
		**/
		bool intersect(const sf::Vertex* quad) const;
		
		
		/**
		 * @param const sf::FloatRect rect retangulo para verificar se possui alguma interceção com este retangulo
		 */
		bool intersect(const sf::FloatRect rect) const;

		/**
		* @param(vertex) vertice a ser verificado se esta dentro deste retangulo
		**/
		bool contains(const sf::Vertex vertex) const;

	private:
		sf::Vertex *quad;
	};

}

#endif

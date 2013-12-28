#ifndef LAYER_H
#define LAYER_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>


namespace NAV
{
	class IPositioner;
	class IScroller;
	class DrawableObject;
	class VertexRect;

	class Layer : public sf::Drawable
	{
	public:
		/**
		*@param(scroller) tipo de scroll que a layer utilizara 
		*@param(positioner) tipo de posicionamento que a layer utilizara para construir os blocos nela
		*@param(sizeInBlocks) tamano da layer em blocos/tiles
		**/
		Layer(IScroller &scroller, IPositioner &positioner, sf::Vector2i sizeInBlocks);

		virtual ~Layer();

		void scroll(sf::Vector2f offset);
		void updateTextureArea(DrawableObject &obj, sf::Vector2f pos, int layer);
		void update();

	protected:
		sf::Texture layerTexture;
		sf::Vector2i sizeInBlocks;

		sf::VertexArray vertices;
		
		IPositioner &positioner;
		IScroller &scroller;

		sf::Vector2f currentOffset;

		sf::Vertex* getQuad(int x, int y);

		void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	};
}

#endif

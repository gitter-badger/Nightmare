#ifndef TILESET_H
#define TILESET_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <memory>

namespace NAV
{

	/**
	 * Enum que representa todos os tipos de profundidade em relação a água que um tile pode ter
	 * None quer dizer que ele é um tile normal e nao possui água
	*/
	namespace WaterDepth
	{
		enum WaterDepth
		{
			None = 0,
			Deep1 = 1,
			Deep2 = 2,
			Deep3 = 3
		};
	}

	/// Objetos nao podem ser pontes
	/// DeskTiles so funcionam na direção do personagem
	/// TileJump, representa o tile que possibilita você pular tiles nao passaveis ate o proximo passavel
    class Tileset
    {
    public:
        Tileset(std::string tilesetName, std::string tilesetTextureKey);
        Tileset(std::string tilesetPath);
        ~Tileset(void);

        static const int TileWidthInPixels;
        static const int TileHeightInPixels;

        static std::shared_ptr<Tileset> load(std::string tilesetPath);

		////////////////////////////////////////////////////////////
		/// \brief metodo que retorna o tamanho do tileset em blocos, nao em pixels
		///
		////////////////////////////////////////////////////////////
        sf::Vector2<int> tilesetSize();
        void save();

        void textureKey(std::string value);
        std::string textureKey() const;

        std::string name() const;
        void name(std::string name);

        bool objectTile(sf::Vector2<int> pos) const;
        void objectTile(sf::Vector2<int> pos, bool value);

        void bush(sf::Vector2<int> pos, bool value);
        bool bush(sf::Vector2<int> pos) const;

        void desk(sf::Vector2<int> pos, bool value);
        bool desk(sf::Vector2<int> pos) const;

        void passableTile(sf::Vector2<int> pos, bool value);
        bool passableTile(sf::Vector2<int> pos) const;

        void tileJump(sf::Vector2<int> pos, bool value);
        bool tileJump(sf::Vector2<int> pos) const;

        void waterTileDepth(sf::Vector2<int> pos, WaterDepth::WaterDepth value);
		WaterDepth::WaterDepth waterTileDepth(sf::Vector2<int> pos) const;

    protected:
        std::string tilesetName;
        std::string _textureKey;
        std::vector<std::vector<bool> > objectsTiles;
        std::vector<std::vector<bool> > bushsTiles;
        std::vector<std::vector<bool> > desksTiles;
        std::vector<std::vector<bool> > tilesJump;
        std::vector<std::vector<bool> > passableTiles;
        std::vector<std::vector<int> > waterTilesDepth;
    };
}


#endif

#ifndef CONTENT_H
#define CONTENT_H

#include <SFML/Graphics.hpp>

#include <memory>
#include <iostream>
#include <map>

#include "Map/Tileset.h"

namespace NAV
{
	class Content
	{
	public:
		static Content* getInstance();
		static void DisposeContents();
		
		std::shared_ptr<sf::Image> getImage(std::string folderKey, std::string textureKey);
		std::shared_ptr<NAV::Tileset> getTileset(std::string tilesetKey);

		bool containsTileset(std::string tilesetKey);
		bool containsImageKey(std::string folderKey, std::string textureKey);

	private:
		Content(void);
		///FAZER ALGO PARA CRIPTOGRAFAR A IMAGEM, E DESCRIPTO A IMAGEM
		
		std::map<std::string, std::map<std::string, std::shared_ptr<sf::Image> > > textures;
		static std::string contentRoot;

		void LoadTilesetsTextures();
	};
}


#endif

#include "Content.h"

#include <dirent.h>
#include <sys/types.h>
#include <vector>

#include "../FileOperation.h"
#include "Excpetion.h"

namespace NAV
{
	typedef std::pair<std::string, std::map<std::string, std::shared_ptr<sf::Image> > > firstpair;
	typedef std::pair<std::string, std::shared_ptr<sf::Image> > secondpair;

	std::string Content::contentRoot;

	Content::Content(void)
	{
		FileOperation *currDir = FileOperation::getInstance();

		std::cout << currDir->runnningDir() << std::endl;

		textures.insert(firstpair("Tilesets", std::map<std::string, std::shared_ptr<sf::Image> >()));

		LoadTilesetsTextures();
	}

	Content* Content::getInstance()
	{
		static Content INSTANCE;

		return &INSTANCE;
	}

	std::shared_ptr<sf::Image> Content::getImage(std::string folderKey, std::string textureKey)
	{
		if (!containsImageKey(folderKey, textureKey))
			throw NAV::Exception(
			"Nao existe uma image associada a essa chave:" + textureKey);
		else
			return textures[folderKey][textureKey];
	}

	bool Content::containsImageKey(std::string folderKey, std::string textureKey)
	{
		if (textures.find(folderKey) == textures.end())
			throw NAV::Exception("Nao existe uma pasta associada a essa chave"); ///TROCAR ISSO POR ALGO COMO KEY NOTFOUND
		else
		{
			if (textures.at(folderKey).find(textureKey) == textures.at(folderKey).end())
				return false;
			else
				return true;
		}
	}

	std::shared_ptr<NAV::Tileset> Content::getTileset(std::string tilesetKey)
	{
		return std::shared_ptr<NAV::Tileset>(nullptr);
	}

	void Content::LoadTilesetsTextures()
	{
		std::string dir;
		dir = std::string(contentRoot + "Content/Textures/Tilesets/");

		NAV::FileOperation *fileOp = NAV::FileOperation::getInstance();

		std::vector<std::string> files = fileOp->listFilesInDirectory(dir);

		std::cout << "Quantidade de Texturas Encontradas: " << files.size() << std::endl;

		for (std::string i : files)
		{
			std::cout << "Carregando Texturas: " << i.substr(0, i.length() - 4) << std::endl;

			textures["Tilesets"].insert(secondpair(i.substr(0, i.length() - 4),
				std::shared_ptr<sf::Image>(new sf::Image())));

			textures["Tilesets"][i.substr(0, i.length() - 4)]->loadFromFile(dir + i);
		}
	}
}

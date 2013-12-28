#include "Tileset.h"

#include "MapExceptions/TilesetNameException.h"
#include "MapExceptions/TilesetEmptyNameException.h"

#include "../Content.h"
#include "../../FileOperation.h"

#include <fstream>

#include <cstdio>

namespace NAV
{
	const int Tileset::TileWidthInPixels = 32;
	const int Tileset::TileHeightInPixels = 32;

	Tileset::Tileset(std::string tilesetName, std::string tilesetTextureKey)
	{
		std::string fileName;

		fileName += "Content/Tilesets/";
		fileName += tilesetName;
		fileName += ".ntset";

		FileOperation *check = FileOperation::getInstance();
		if(check->checkExistence(fileName))
			throw TilesetNameException("Tileset Existente");

		try
		{
			name(tilesetName);
		}
		catch(TilesetNameException &e)
		{
			throw TilesetNameException(e);
		}

		Content *content = Content::getInstance();

		if(!content->containsImageKey("Tilesets", tilesetTextureKey))
			throw std::exception();///TROCAR ISSO AKI POR ALGO COMO KEY NOT FOUND]

		_textureKey = tilesetTextureKey;

		sf::Vector2<int> size = tilesetSize();

		for(int y = 0;y < size.y; y++)
		{
			objectsTiles.push_back(std::vector<bool>());
			bushsTiles.push_back(std::vector<bool>());
			desksTiles.push_back(std::vector<bool>());
			passableTiles.push_back(std::vector<bool>());
			tilesJump.push_back(std::vector<bool>());
			waterTilesDepth.push_back(std::vector<int>());
			for(int x = 0; x < size.x; x++)
			{
				objectsTiles[y].push_back(false);
				bushsTiles[y].push_back(false);
				desksTiles[y].push_back(false);
				passableTiles[y].push_back(true);
				tilesJump[y].push_back(false);
				waterTilesDepth[y].push_back(WaterDepth::None);
			}
		}
	}

	Tileset::Tileset(std::string tilesetName)
	{
		std::ifstream file;
		std::string fileName;
		fileName += tilesetName;
		fileName += ".ntset";

		FileOperation *check = FileOperation::getInstance();

		if(!(check->checkExistence(fileName)))
			throw NAV::TilesetNameException("File Not Found");///CRIAR PELO MENOS MAIS DUAS EXCEÇÕES UMA PARA TILESETS EM GERAL E OUTRA PARA FILENOTFOUND

		file.open(fileName, std::ios::in | std::ios::binary );

		std::string nameG, textureKeyG;

		int wordSize = 0;
		char *bufferName = nullptr;
		char *bufferKey = nullptr;

		file.read((char*)&wordSize, sizeof(int));

		bufferName = new char[wordSize + 1];
		file.read(bufferName, sizeof(char)*wordSize);

		bufferName[wordSize] = '\0';

		nameG = bufferName;

		wordSize = 0;
		file.read((char*)&wordSize, sizeof(int));

		bufferKey = new char[wordSize + 1];
		file.read(bufferKey, sizeof(char)*wordSize);

		bufferKey[wordSize] = '\0';

		textureKeyG = bufferKey;

		try
		{
			textureKey(textureKeyG);
		}
		catch(std::exception &e)
		{
			throw std::exception(e);
		}

		try
		{
			name(nameG);
		}
		catch (std::exception &e)
		{
			throw std::exception(e);
		}

		sf::Vector2<int> size = tilesetSize();

		char *boolBuffer = new char;

		for(int y = 0; y < size.y; y++)
		{
			objectsTiles.push_back(std::vector<bool>());
			bushsTiles.push_back(std::vector<bool>());
			desksTiles.push_back(std::vector<bool>());
			passableTiles.push_back(std::vector<bool>());
			tilesJump.push_back(std::vector<bool>());
			waterTilesDepth.push_back(std::vector<int>());
			for (int x = 0; x < size.x; x++)
			{
				waterTilesDepth[y].push_back(0);
				file.read((char*)&waterTilesDepth[y][x], sizeof(int));

				passableTiles[y].push_back(false);
				file.read(boolBuffer, sizeof(char));
				passableTiles[y][x] = (bool)(*boolBuffer);

				tilesJump[y].push_back(false);
				file.read(boolBuffer, sizeof(char));
				tilesJump[y][x] = (bool)(*boolBuffer);

				desksTiles[y].push_back(false);
				file.read(boolBuffer, sizeof(char));
				desksTiles[y][x] = (bool)(*boolBuffer);

				bushsTiles[y].push_back(false);
				file.read(boolBuffer, sizeof(char));
				bushsTiles[y][x] = (bool)(*boolBuffer);

				objectsTiles[y].push_back(false);
				file.read(boolBuffer, sizeof(char));
				objectsTiles[y][x] = (bool)(*boolBuffer);
			}
		}

		file.close();

		delete bufferKey;
		delete bufferName;
		delete boolBuffer;
	}

	Tileset::~Tileset()
	{
		objectsTiles.clear();
		bushsTiles.clear();
		desksTiles.clear();
		passableTiles.clear();
		tilesJump.clear();
		waterTilesDepth.clear();
	}

	std::shared_ptr<Tileset> Tileset::load(std::string name)
    {
		std::shared_ptr<Tileset> tileset;
		try
		{
			tileset = std::shared_ptr<Tileset>(new Tileset(name));
		}
		catch(NAV::Exception &e)
		{
			throw e;
		}

    	return tileset;
    }

	std::string Tileset::name() const
    {
    	return tilesetName;
    }

    sf::Vector2<int> Tileset::tilesetSize()
	{
    	Content *content = Content::getInstance();

    	std::shared_ptr<sf::Image> tilesetTexture;
    	tilesetTexture = content->getImage("Tilesets", _textureKey);

    	return sf::Vector2<int>((int)(tilesetTexture->getSize().x / 32) ,
    			(int)(tilesetTexture->getSize().y / 32));
	}

    void Tileset::name(std::string name)
    {
    	if(name.length() == 0)
    		throw TilesetEmptyNameException("Nome Vazio");

    	tilesetName = name;
    }

    void Tileset::textureKey(std::string value)
    {
    	Content *content = Content::getInstance();

    	if(!(content->containsImageKey("Tilesets", value)))
    		throw std::exception(); /// TROCAR ISSO POR ALGO COMO KEY NOT FOUND
    	else
    		_textureKey = value;

    }

	std::string Tileset::textureKey() const
	{
		return _textureKey;
	}

    void Tileset::save()
    {
    	bool tempFile = false;

    	FileOperation *check = FileOperation::getInstance();

    	std::string fileNameReal;

    	std::string fileName("Content/Tilesets/");
    	fileName += tilesetName;

    	fileNameReal += fileName;
    	fileNameReal += ".ntset";

    	if(check->checkExistence(fileNameReal))
    	{
    		fileName += "_TEMP";
    		tempFile = true;
    	}
    	else
    		fileName += ".ntset";

    	std::ofstream file;
    	file.open(fileName, std::ofstream::app |
    			std::ofstream::binary | std::ofstream::out);

    	char *boolBuffer = new char;

    	int lengStr = (int)tilesetName.length();

    	file.write((char*)&lengStr, sizeof(int));
    	file.write(tilesetName.c_str(), sizeof(char)*tilesetName.length());

    	lengStr = (int)_textureKey.length();
    	file.write((char*)&lengStr, sizeof(int));
    	file.write(_textureKey.c_str(), sizeof(char)*_textureKey.length());

    	sf::Vector2<int> size = tilesetSize();

    	for(int y = 0; y < size.y; y++)
    	{
    		for(int x = 0; x < size.x; x++)
    		{
    			file.write((char*)&waterTilesDepth[y][x], sizeof(int));

    			*boolBuffer = (char)passableTiles[y][x];
    			file.write(boolBuffer, sizeof(char));

    			*boolBuffer = (char)tilesJump[y][x];
    			file.write(boolBuffer, sizeof(char));

    			*boolBuffer = (char)desksTiles[y][x];
    			file.write(boolBuffer, sizeof(char));

    			*boolBuffer = (char)bushsTiles[y][x];
    			file.write(boolBuffer, sizeof(char));

    			*boolBuffer = (char)objectsTiles[y][x];
    			file.write(boolBuffer, sizeof(char));
    		}
    	}

    	file.close();

    	if(tempFile)
    	{
    		std::remove(fileNameReal.c_str());
    		std::rename(fileName.c_str(), fileNameReal.c_str());
    	}
    }

    void Tileset::bush(sf::Vector2<int> pos, bool value)
    {
    	bushsTiles[pos.y][pos.x] = value;
    }

    void Tileset::desk(sf::Vector2<int> pos, bool value)
    {
    	desksTiles[pos.y][pos.x] = value;
    }

    void Tileset::objectTile(sf::Vector2<int> pos, bool value)
	{
		objectsTiles[pos.y][pos.x] = value;
	}

	bool Tileset::objectTile(sf::Vector2<int> pos) const
    {
    	return objectsTiles[pos.y][pos.x];
    }

	bool Tileset::bush(sf::Vector2<int> pos) const
    {
    	return bushsTiles[pos.y][pos.x];
    }

	bool Tileset::desk(sf::Vector2<int> pos) const
    {
    	return desksTiles[pos.y][pos.x];
    }

	void Tileset::passableTile(sf::Vector2<int> pos, bool value)
    {
    	passableTiles[pos.y][pos.x] = value;
    }

	bool Tileset::passableTile(sf::Vector2<int> pos) const
    {
    	return passableTiles[pos.y][pos.x];
    }

	void Tileset::waterTileDepth(sf::Vector2<int> pos, WaterDepth::WaterDepth value)
    {
    	waterTilesDepth[pos.y][pos.x] = (int)value;
    }

	WaterDepth::WaterDepth Tileset::waterTileDepth(sf::Vector2<int> pos) const
    {
    	return (WaterDepth::WaterDepth)waterTilesDepth[pos.y][pos.x];
    }
}

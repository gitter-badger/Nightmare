#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <QApplication>

#include <iostream>
#include <exception>
#include <memory>

#include "Game/Content.h"
#include "Game/Map/Tileset.h"
#include "Game/Map/Tile.h"
#include "Game/Map/MapExceptions/TilesetNameException.h"
#include "Game/Layers/DrawableObject.h"
#include "Game/Layers/Layer.h"
#include "Game/Layers/LinearPositioner.h"
#include "Game/Layers/LinearScroll.h"

int main(int argc, char **argv)
{
	NAV::Content *content = NAV::Content::getInstance();

	std::shared_ptr<sf::RenderWindow> window(new sf::RenderWindow);

	window->create(sf::VideoMode(1024, 768), "Nightmare", sf::Style::Close);
	window->setVerticalSyncEnabled(true);

	NAV::LinearPositioner positioner(sf::Vector2f(32, 32));
	NAV::LinearScroll scroller(sf::Vector2f(0,0), sf::Vector2f(800, 608));

	NAV::Layer layer(scroller, positioner, sf::Vector2i(25, 19));
	bool keyPress[4] {false, false, false, false};

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
					keyPress[0] = true;
				else if (event.key.code == sf::Keyboard::Down)
					keyPress[1] = true;
				
				if (event.key.code == sf::Keyboard::Right)
					keyPress[2] = true;
				else if (event.key.code == sf::Keyboard::Left)
					keyPress[3] = true;
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Up)
					keyPress[0] = false;
				else if (event.key.code == sf::Keyboard::Down)
					keyPress[1] = false;

				if (event.key.code == sf::Keyboard::Right)
					keyPress[2] = false;
				else if (event.key.code == sf::Keyboard::Left)
					keyPress[3] = false;
			}
		}

		if (keyPress[0])
			layer.scroll(sf::Vector2f(0, -1));
		if (keyPress[1])
			layer.scroll(sf::Vector2f(0, 1));
		if (keyPress[2])
			layer.scroll(sf::Vector2f(1, 0));
		if (keyPress[3])
			layer.scroll(sf::Vector2f(-1, 0));

		layer.update();

		window->clear();

		window->draw(layer);

		window->display();
	}
}

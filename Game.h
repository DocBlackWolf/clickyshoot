#pragma once

#include "libs.h"
#include "crosshair.h"
#include "Enemy.h"

class Juego
{
private:

	sf::RenderWindow* _wnd;
	PlayerCrossHair* _player;
	Enemy *_enemies;


public:


	Juego() {
		_wnd = new sf::RenderWindow(sf::VideoMode(1920, 1080), "clicker shooter");
		_player = new PlayerCrossHair();
		_enemies = new Enemy[10];

	}


	void Loop() {
		while (_wnd->isOpen())
		{
			ProcessEvents();
			Update();
			draw();

		}
	}

	void ProcessEvents() {
		sf::Event evt;
		while (_wnd->pollEvent(evt))
		{
			switch (evt.type)
			{
			case sf::Event::Closed:_wnd->close();
				break;

			case sf::Event::MouseButtonPressed:
				if (evt.mouseButton.button == sf::Mouse::Button::Left)
					Shoot();
				break;
			}
		}

	}

	void Update() {
		sf::Vector2i  mousePos = sf::Mouse::getPosition(*_wnd);
		_player->GivePos(mousePos.x, mousePos.y);


	}

	void Shoot() {
		//check colitions (taken from the twich video)

	}

	void draw() {
		_wnd->clear(sf::Color::Cyan);
		_player->Render(_wnd);
		_wnd->display();
	}


};

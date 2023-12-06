#pragma once

#include "libs.h"
#include "crosshair.h"
#include "Enemy.h"

class Juego
{
private:

	sf::Texture House;
	sf::Sprite Hspr;
	sf::RenderWindow* _wnd;
	PlayerCrossHair* _player;
	Enemy* _enemy;


public:

	
	Juego() {
		_wnd = new sf::RenderWindow(sf::VideoMode(1920, 1080), "clicker shooter");
		_player = new PlayerCrossHair();
		_enemy = new Enemy();

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
			}

		}

	}

	void Update(){
		sf::Vector2i mousePos = sf::Mouse::getPosition(*_wnd);
		_player->GivePos(mousePos.x, mousePos.y);
		

	}

	void draw() {
		_wnd->clear(sf::Color::Cyan);
		_player->Render(_wnd);
		_enemy->Render(_wnd);
		_wnd->display();
	}

};

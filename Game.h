#pragma once

#include "libs.h"
#include "crosshair.h"

class Juego
{
private:

	sf::RenderWindow* _wnd;
	PlayerCrossHair* _player;



public:

	
	Juego() {
		_wnd = new sf::RenderWindow(sf::VideoMode(1920, 1080), "clicker shooter");
		_player = new PlayerCrossHair();

	}


	void Loop() {
		while (_wnd->isOpen())
		{
			ProcessEvents();
			Update();
			Draw();

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

	void Draw() {
		_wnd->clear(sf::Color::Cyan);
		_player->Render(_wnd);
		_wnd->display();
	}

};

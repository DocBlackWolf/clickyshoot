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
		_enemies = new Enemy[5];



		_enemies[1].SetOrigin(100, 100);
		_enemies[2].SetOrigin(-6000, -6000);
		_enemies[3].SetOrigin(-4000, -4000);


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
		//check colitions and logic (tomado del vid de twich)
		sf::Vector2f playerPos = _player->GetPos();
		for (int i = 0; i < 5; i++) {
			if (_enemies[i].IsAlive()) {
				if (_enemies[i].OnTop(playerPos.x, playerPos.y))
					_enemies[i].Kill();
			}
		}

	}



	void draw() {
		_wnd->clear(sf::Color::Cyan);
		for (int i = 0; i < 5; i++) {
			if(_enemies[i].IsAlive())
			_enemies[i].Render(_wnd);
		}
		_player->Render(_wnd);
		_wnd->display();

		
	}


};

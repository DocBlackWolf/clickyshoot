#pragma once

#include "libs.h"
#include "crosshair.h"
#include "Enemy.h"
#include "Scene.h"
#include <random>

class Juego
{
private:

	sf::RenderWindow* _wnd;
	PlayerCrossHair* _player;
	Enemy *_enemies;
	Scenario* _scene;
	int EnemySize;
	


public:


	Juego() {
		//sf::VideoMode desktopmode = sf::VideoMode::getDesktopMode(); ventanas ajustables no se manejan muy bien
		_wnd = new sf::RenderWindow(sf::VideoMode(800,600), "clicker shooter", sf::Style::Titlebar | sf::Style::Close);
		_scene = new Scenario();
		_player = new PlayerCrossHair();
		EnemySize = 5; //aqui determinas el monto de enemigos (tiene otros usos aparte del monto de inicializacion como el index de respawn)
		_enemies = new Enemy[EnemySize];
		std::srand(static_cast<unsigned>(std::time(nullptr))); //esto lo consegui con IA



		_enemies[0].SetOrigin(-1000, -1500);
		_enemies[1].SetOrigin(-2000, -2500);
		_enemies[2].SetOrigin(-3000, -4500);
		_enemies[3].SetOrigin(-5000, -5500);
		_enemies[4].SetOrigin(-6000, -6500);



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


		//std::cout << "Sprite position in world coordinates: x = " << _enemies[0].GetPos().x << ", y = " << _enemies[0].GetPos().y << std::endl; //(debug tool)

		Respawns();

	}

	void Respawns() {

		//Si, ya se que esta todo en ingles pero me confundo menos si escribo todo en un solo idioma

		// Genera un indice random, eso es para elegir el enemigo
		
		int randomIndex = std::rand() % EnemySize;

		// revisar si esta vivo o no
		if (_enemies[randomIndex].IsAlive()) {
			return; // If alive, ignore
		}
		
		sf::Clock respawnT;
		std::random_device rd;
		std::mt19937 gen(rd());

		sf::Time respawnDelay = sf::seconds(std::uniform_real_distribution<>(1.0, 5.0)(gen));
		
		
		if (respawnT.getElapsedTime().asSeconds() >= respawnDelay.asSeconds()) {

			respawnT.restart();

				// imprime info de respawn, es puramente para testeo
				std::cout << "Respawning enemy at index " << randomIndex << " in " << respawnDelay.asSeconds() << " seconds." << std::endl;

				// Revive al enemigo con el indice correspondiente
				_enemies[randomIndex].Revive();

				if (randomIndex > 5) {
					std::cout << "Error: Invalid random index generated, RUN BRO" << std::endl;
				}
		}
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
		_scene->Build(_wnd);
		_player->Render(_wnd);
		_wnd->display();

		
	}


};

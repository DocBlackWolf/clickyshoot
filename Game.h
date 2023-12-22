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
	Inocent* _inocents;
	Scenario* _scene;
	int EnemySize;
	sf::Clock respawnT;
	sf::Text _puntaje;
	int _points;
	sf::Font _font;
	
	void _UpdateScore() {
		char pts[100];
		_itoa_s(_points, pts, 10);
		_puntaje.setString(pts);
	}


public:


	Juego() {
		_wnd = new sf::RenderWindow(sf::VideoMode(800,800), "clicker shooter", sf::Style::Titlebar | sf::Style::Close);
		_wnd->setMouseCursorVisible(false);
		_scene = new Scenario();
		_player = new PlayerCrossHair();
		EnemySize = 5; //aqui determinas el monto de enemigos (tiene otros usos aparte del monto de inicializacion como el index de respawn aunque el pocicionamiento es manual)
		_enemies = new Enemy[EnemySize];
		_inocents = new Inocent[EnemySize];
		std::srand(static_cast<unsigned>(std::time(nullptr))); //esto es para el RAND , de IA
		_font.loadFromFile("assets/arial.ttf");
		_points = 0;
		_puntaje.setPosition(60.0f,700.0f);
		_puntaje.setCharacterSize(50.f);
		_puntaje.setFillColor(sf::Color::White);
		_puntaje.setFont(_font);





		_enemies[0].SetOrigin(-1000, -1500);
		_enemies[1].SetOrigin(-800, -3500);
		_enemies[2].SetOrigin(-5000, -1500);
		_enemies[3].SetOrigin(-3000, -3500);
		_enemies[4].SetOrigin(-5500, -3500);
		_inocents[0].SetOrigin(-1000, -1500);
		_inocents[1].SetOrigin(-800, -3500);
		_inocents[2].SetOrigin(-5000, -1500);
		_inocents[3].SetOrigin(-3000, -3500);
		_inocents[4].SetOrigin(-5500, -3500);



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
				_UpdateScore();
					
				break;
			}
		}

	}

	void Update() {
		sf::Vector2i  mousePos = sf::Mouse::getPosition(*_wnd);
		_player->GivePos(mousePos.x, mousePos.y);


		//std::cout << "Sprite position in world coordinates: x = " << _enemies[0].GetPos().x << ", y = " << _enemies[0].GetPos().y << std::endl; //(debug tool)

		Respawns();
		Despawn();

	}

	void Respawns() {

		
		
		int randomIndex = std::rand() % EnemySize; // Genera y sostiene un indice random, eso es para elegir el enemigo

		// revisar si esta vivo o no
		if (_enemies[randomIndex].IsAlive()) {
			return; // If alive, ignore
		}
		

		sf::Time respawnDelay = sf::seconds(std::rand() % 5 + 1); //genera un numero entre 1 y 5 para el delay de respawn
		
		
		if (respawnT.getElapsedTime().asSeconds() >= respawnDelay.asSeconds()) { //paso el tiempo necesario ejecutar 

			respawnT.restart();


				// imprime info de respawn, debug tool
				/*std::cout << "Respawning enemy at index " << randomIndex << " in " << respawnDelay.asSeconds() << " seconds." << std::endl;*/

				// Revive al enemigo con el indice correspondiente
		
				std::random_device rd; //class gen, IA
				std::mt19937 gen(rd()); //Gen, IA
				std::uniform_real_distribution<double> dis(0.0, 1.0); //float entre 0 y 100(1)
				double randomNumber = dis(gen); //double para estimar un % de cual aparece hostil o enemigo


				if (randomNumber < 0.8) {
					if (_inocents[randomIndex].IsAlive() == false) {
						_enemies[randomIndex].Revive();
					}
				}
				else {
					if (_enemies[randomIndex].IsAlive() == false) {
						_inocents[randomIndex].Revive();
					}
				}

		}
	}

	void Despawn() {


		for (size_t i = 0; i < 5; i++) {

			if (_enemies[i].TimeAlive() > 5) {
				_enemies[i].Kill();
			}
			if (_inocents[i].TimeAlive() > 3) {
				_inocents[i].Kill();
			}
		}
	}


	void Shoot() {
		//check colitions and logic, para ambos
		sf::Vector2f playerPos = _player->GetPos();
		for (int i = 0; i < 5; i++) {
			if (_enemies[i].IsAlive()) {
				if (_enemies[i].OnTop(playerPos.x, playerPos.y)) {
					_enemies[i].Kill();
					_points++;
				}
			}
			if (_inocents[i].IsAlive()) {
				if (_inocents[i].OnTop(playerPos.x, playerPos.y)) {

			
					_inocents[i].Kill();
				_points--;
				}
			}
		}
	}



	void draw() {
		_wnd->clear(sf::Color::Black);
		_scene->BuildBa(_wnd);
		
		for (size_t i = 0; i < EnemySize; i++) {
			if(_enemies[i].IsAlive())
			_enemies[i].Render(_wnd);
		}
		_scene->Build(_wnd);
		for (size_t i = 0; i < EnemySize; i++)
		{
			if (_inocents[i].IsAlive()) 
				_inocents[i].Render(_wnd);
		}


		
		_player->Render(_wnd);
		_wnd->draw(_puntaje);
		_wnd->display();

		
	}


};
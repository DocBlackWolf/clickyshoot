#pragma once

#include "libs.h"

class Enemy
{

private:
	sf::Texture _EnemTex;
	sf::Sprite _EnemSpr;
	sf::Clock clock;
	bool _Alive;
	bool _Looking;
	float _timeLooking;
	float _timeDead;


public:
	Enemy() {
		_EnemTex.loadFromFile("assets/gunman.png");
		_EnemSpr.setTexture(_EnemTex);
		_EnemSpr.setScale(1.0f, 1.0f);
		_Alive = true;
		_Looking = true;
		_timeLooking = 0;
		_timeDead = 0;



	}


	bool Living() {
		return _Alive;
	}

	bool Looking() {
		return _Looking;

	}

	void Render(sf::RenderWindow *wnd) {
		wnd->draw(_EnemSpr);
	}

};
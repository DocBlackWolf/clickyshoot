#pragma once

#include "libs.h"

class Enemy
{

private:
	sf::Texture _EnemTex;
	sf::Sprite _EnemSpr;
	sf::Clock _clock;
	bool _Alive;

	


public:
	Enemy() {
		_EnemTex.loadFromFile("assets/chemmalo.png");
		_EnemSpr.setTexture(_EnemTex);
		_EnemSpr.setScale(0.10f, 0.10f);
		_Alive = true;
	}

	bool IsAlive() {
		return _Alive;
	}

	bool OnTop(float x, float y) {
		sf::FloatRect bounds = _EnemSpr.getGlobalBounds();
		return bounds.contains(x, y);
	}

};
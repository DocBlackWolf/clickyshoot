#pragma once

#include "libs.h"

class Enemy
{

private:

	sf::Texture _House;
	sf::Sprite _HouseSpr;
	sf::Texture _EnemTex;
	sf::Sprite _EnemSpr;
	sf::Clock _clock;
	bool _Alive;
	

	


public:
	Enemy() {
		
		_House.loadFromFile("assets/casitatiro.png");
		_HouseSpr.setTexture(_House);
		_EnemTex.loadFromFile("assets/gunman.png");
		_EnemSpr.setTexture(_EnemTex);
		_EnemSpr.setScale(0.10f, 0.10f);
		_Alive = true;
	}

	void SetOrigin(float x, float y) {

		_EnemSpr.setOrigin(x, y);
	}

	bool IsAlive() {
		return _Alive;
	}
	
	void Kill() {
		_Alive = false;
	}

	void RenderScene(sf::RenderWindow* wnd) {
		wnd->draw(_HouseSpr);
	}

	void Render(sf::RenderWindow *wnd) {
		wnd->draw(_EnemSpr);
	}

	bool OnTop(float x, float y) {
		sf::FloatRect bounds = _EnemSpr.getGlobalBounds();
		return bounds.contains(x, y);
	}


};
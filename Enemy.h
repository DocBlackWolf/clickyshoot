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
		_Alive = false;
	}

	void SetOrigin(float x, float y) {

		_EnemSpr.setOrigin(x, y);
	}

	float TimeAlive() {
		return _clock.getElapsedTime().asSeconds();
	}

	bool IsAlive() {
		return _Alive;
	}

	sf::Vector2f GetPos() {
		return _EnemSpr.getPosition();

	}
	
	void Kill() {
		_Alive = false;
	}

	void Revive() {
		_Alive = true;
		_clock.restart();
	}


	void Render(sf::RenderWindow *wnd) {
		wnd->draw(_EnemSpr);
	}

	bool OnTop(float x, float y) {
		sf::FloatRect bounds = _EnemSpr.getGlobalBounds();
		return bounds.contains(x, y);
	}


};



class Inocent : public Enemy
{
private:
	sf::Texture _InocentTex;
	sf::Sprite _InocentSpr;
	sf::Clock _clock;
	bool _Alive;

public:

	Inocent() {

		_InocentTex.loadFromFile("assets/chembueno.jpg");
		_InocentSpr.setTexture(_InocentTex);
		_InocentSpr.setScale(0.8f, 0.8f);
		_Alive = false;

	}

	void SetOrigin(float x, float y) {

		_InocentSpr.setOrigin(x, y);
	}

	void Render(sf::RenderWindow* wnd) {
		wnd->draw(_InocentSpr);
	}

	bool OnTop(float x, float y) {
		sf::FloatRect bounds = _InocentSpr.getGlobalBounds();
		return bounds.contains(x, y);
	}

	sf::Vector2f GetPos() {
		return _InocentSpr.getPosition();

	}

};

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

	sf::Vector2f GetPos() {
		return _EnemSpr.getPosition();

	}
	
	void Kill() {
		_Alive = false;
	}

	void Revive() {
		_Alive = true;
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

public:
	
	Inocent() : Enemy()
	{
		
	}


};

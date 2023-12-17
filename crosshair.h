#pragma once
#include "libs.h"
#include <iostream>

class PlayerCrossHair
{
private:

	sf::Texture _crossTex;
	sf::Sprite _crossSprite;


public:

	PlayerCrossHair()
	{
		_crossTex.loadFromFile("assets/crosshair.png");
		_crossSprite.setTexture(_crossTex);
		sf::Vector2u size = _crossTex.getSize();
		_crossSprite.setOrigin(size.x / 2.0f, size.y / 2.0f);
		_crossSprite.setScale(0.1f, 0.1f);
	}

	void Render(sf::RenderWindow *wnd) {
		wnd->draw(_crossSprite);
	}


	void GivePos(float x, float y) {
		return _crossSprite.setPosition(x,y);
	}

	sf::Vector2f GetPos() {
		return _crossSprite.getPosition();
		
	}

};
#pragma once
#include "libs.h"

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
	}

};

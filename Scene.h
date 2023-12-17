#pragma once
#include "libs.h"

class Scenario
{
private:

	sf::Texture _houseTex;
	sf::Texture _housebaTex;
	sf::Sprite _housebaSpr;
	sf::Sprite _houseSpr;
	




public:

	Scenario(){
		_houseTex.loadFromFile("assets/casitatirosmall.png");
		_houseSpr.setTexture(_houseTex);
		_houseSpr.setOrigin(30, 0);
		_houseSpr.setScale(1.07f, 1.07f);
		_housebaTex.loadFromFile("assets/casitatirobackground.png");
		_housebaSpr.setTexture(_housebaTex);
		_houseSpr.setOrigin(30, 0);
		_houseSpr.setScale(1.07f, 1.07f);

	}

	void Build(sf::RenderWindow* wnd) {
		wnd->draw(_houseSpr);
		//wnd->draw(_housebaSpr);
	};


};
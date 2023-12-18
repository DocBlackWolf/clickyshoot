#pragma once
#include "libs.h"

class Scenario
{
private:

	sf::Texture _houseTex;
	sf::Texture _housebaTex;
	sf::Texture _background;
	sf::Sprite _housebaSpr;
	sf::Sprite _houseSpr;
	sf::Sprite _backgroundSpr;
	
	




public:

	Scenario(){
		_houseTex.loadFromFile("assets/casitatirosmall.png");
		_houseSpr.setTexture(_houseTex);
		_houseSpr.setOrigin(30, 0);
		_houseSpr.setScale(1.07f, 1.07f);
		_housebaTex.loadFromFile("assets/housebackgroundsmall.png");
		_housebaSpr.setTexture(_housebaTex);
		_housebaSpr.setOrigin(30, 0);
		_housebaSpr.setScale(1.07f, 1.07f);
		_background.loadFromFile("assets/backgroundnt.jpg");
		_backgroundSpr.setTexture(_background);
		_backgroundSpr.setOrigin(30, 0);
		_backgroundSpr.setScale(1.07f, 1.07f);


	}
	
	void Build(sf::RenderWindow* wnd) {
		wnd->draw(_houseSpr);
	};

	void BuildBa(sf::RenderWindow* wnd) {
		wnd->draw(_backgroundSpr);
		wnd->draw(_housebaSpr);
	};


};
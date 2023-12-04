#pragma once

#include "libs.h"
#include "crosshair.h"

class Juego
{
private:

	sf::RenderWindow* _wnd;



public:

	Juego() {
		_wnd = new sf::RenderWindow(sf::VideoMode(1920, 1080), "clicker shooter");

	}


	void Loop() {
		while (_wnd->isOpen())
		{

		}
	}

	void ProcessEvents() {

	}

	void Update(){
		

	}

	void Draw() {

	}

};

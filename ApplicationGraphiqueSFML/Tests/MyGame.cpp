#include "Header.h"
#include "MyGame.h" 
#include "Poisson.h"
#include "Caravel.h"
#include "Collision.h"
#include "ScoreBar.h"
#include "Levels.h"
#include "Level1.h"


using namespace mygame;

MyGame::MyGame() : window(sf::VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), "Fisher man") {
	window.setFramerateLimit(60);

	levels = new Level1();

	while (window.isOpen())
	{
		ProcessEvents();
		ProcessStates();
		DrawScreen();
	}
}

MyGame::~MyGame() {
}

void MyGame::DrawScreen() {
	window.clear(LIGHT_GRAY);
	levels->DrawScreen(window);
	window.display();
}

void MyGame::ProcessEvents() {
	sf::Event Event;
	while (window.pollEvent(Event)) {
		if (Event.type == sf::Event::Closed
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			window.close();
		}
	}
	levels->ProcessEvents();
}

void MyGame::ProcessStates() {
	levels->ProcessStates();
}
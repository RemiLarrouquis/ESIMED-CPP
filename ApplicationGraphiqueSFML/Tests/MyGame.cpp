#include "Header.h"
#include "MyGame.h" 
#include "Poisson.h"
#include "Caravel.h"
#include "Collision.h"
#include "ScoreBar.h"
#include "Levels.h"
#include "Level1.h"
#include "Level2.h"


using namespace mygame;

MyGame::MyGame() : window(sf::VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), "Fisher man") {
	window.setFramerateLimit(60);

	gameStart = false;
	delaiEnd = false;
	count = 0;

	levels = new Level1();
	levels->score.setLevelValue(1);
	levelNum = 1;

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
	if (gameStart) {
		if (delaiEnd) {
			levels->DrawScreen(window);
		}
		else {
			trans.drawTextLevels(window, levels->getLevelName());
			wait(DELAI_TRANSITION);
		}
	}
	else {
		trans.drawMenuStart(window);
	}
	window.display();
}

void MyGame::ProcessEvents() {
	sf::Event Event;
	while (window.pollEvent(Event)) {
		if (Event.type == sf::Event::Closed
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			gameStart = true;
		}
	}
	levels->ProcessEvents();
}

void MyGame::ProcessStates() {
	if (gameStart) {
		levels->ProcessStates();
		if (levels->getScore() > END_LEVEL_1 && levelNum == 1) {
			// Récupère le score en cours
			int score = levels->getScore();
			delete levels;
			// On passe au niveau suivant
			levels = new Level2();
			levels->score.addScoreValue(score);
			levels->score.setLevelValue(2);
			levelNum = 2;
			// Permet d'afficher le message de transition
			delaiEnd = false;
		}
	}
}

void MyGame::wait(int delai) {
	if ((count++) == delai) {
		count = 0;
		delaiEnd = true;
	}
}


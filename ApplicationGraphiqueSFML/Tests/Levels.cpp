#include "Levels.h"
#include "Header.h"
#include "MyGame.h" 
#include "Poisson.h"
#include "Caravel.h"
#include "Collision.h"
#include "ScoreBar.h"
#include "Levels.h"

Levels::Levels() {
	setGameBoard();
}

Levels::~Levels() {

}

void Levels::ProcessEvents() {
	// Up - Down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		caravel.nextMove(0, -SPEED_CARAVEL);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		caravel.nextMove(0, SPEED_CARAVEL);
	}
	// Left - Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		caravel.nextMove(-SPEED_CARAVEL, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		caravel.nextMove(SPEED_CARAVEL, 0);
	}
}

void Levels::ProcessStates() {
	
	caravel.confirmMove(gameBoard);
	for (vector<Poisson>::iterator it = poissons.begin(); it != poissons.end();) {
		if (Collision::PixelPerfectTest(caravel, *it)) {
			if ((*it).getRecompense() < 0) {
				score.changeLife(true);
			}
			score.addScoreValue((*it).getRecompense());
			it = poissons.erase(it);
		}
		else if ((*it).outOfBound(gameBoard)) {
			it = poissons.erase(it);
		}
		else {
			(*it).Move();
			it++;
		}
	}

	generatePoisson(gameBoard);
}

void Levels::DrawScreen(sf::RenderWindow &window) {
	// Affiche la barre de score
	score.drawBoard(window);
	// Affiche le nom du Niveau
	window.draw(levelName);
	// Affiche l'emplacement du jeu
	window.draw(gameBoard);
	// Affiche le bateau
	window.draw(caravel);
	// Affiche les poissons
	for (vector<Poisson>::iterator it = poissons.begin(); it != poissons.end(); it++) {
		window.draw(*it);
		(*it).Update(); // Sprite animation
	}
}

void Levels::setGameBoard() {
	// La zone de jeu
	gameBoard.setSize(sf::Vector2f(WIDTH_GAME, HEIGHT_GAME));
	gameBoard.setPosition((WIDTH_WINDOW - WIDTH_GAME) / 2, (HEIGHT_WINDOW - HEIGHT_GAME) / 2);
	gameBoard.setOutlineThickness(2);
	gameBoard.setOutlineColor(sf::Color::Black);
	gameBoard.setFillColor(GRAY);
}

int Levels::getScore() {
	return score.getScore();
}

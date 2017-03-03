#include "Header.h"
#include "Caravel.h"

Caravel::Caravel() : sf::Sprite(imageCaravel)
{
	setPosition(150, 150);
	initSpeed(SPEED_CARAVEL);

	setOrigin(imageCaravel.getSize().x / 2, imageCaravel.getSize().y / 2);
	nextMoveCaravel.x = getPosition().x;
	nextMoveCaravel.y = getPosition().y;
}

Caravel::~Caravel()
{

}

void Caravel::nextMove(int offX, int offY) {
	nextMoveCaravel.x = nextMoveCaravel.x + offX;
	nextMoveCaravel.y = nextMoveCaravel.y + offY;
	if (nextMoveCaravel.x < getPosition().x) {
		setScale(-1.f, 1.f);
	}
	else {
		setScale(1.f, 1.f);
	}
}

void Caravel::confirmMove(sf::RectangleShape gameBoard) {
	// Confirm X mouvement
	if (nextMoveCaravel.x + getGlobalBounds().width / 2 < (gameBoard.getSize().x + 100)
		&& nextMoveCaravel.x - getGlobalBounds().width / 2 > gameBoard.getPosition().x) {
		setPosition(nextMoveCaravel.x, getPosition().y);
	}
	// Confirm Y mouvement
	if (nextMoveCaravel.y + getGlobalBounds().height / 2 < (gameBoard.getSize().y + 100)
		&& nextMoveCaravel.y - getGlobalBounds().height / 2> gameBoard.getPosition().y) {
		setPosition(getPosition().x, nextMoveCaravel.y);
	}
	nextMoveCaravel.x = getPosition().x;
	nextMoveCaravel.y = getPosition().y;
}

// Initialise la vitesse entre x et y
void Caravel::initSpeed(int speed) {
	vitesse = speed;
}

sf::Texture Caravel::imageCaravel;
void Caravel::setCaravelImg() {
	if (!imageCaravel.loadFromFile("../ressources/caravel.png")) {
		cerr << "Impossible de charger caravel.png" << endl;
		return;
	}
}

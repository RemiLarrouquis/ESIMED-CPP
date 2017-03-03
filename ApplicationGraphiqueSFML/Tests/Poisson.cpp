#include "Header.h"
#include "Poisson.h"

Poisson::Poisson(int x, int y, int color) : AniSprite(imagePoisson, imagePoisson.getSize().x / 3, imagePoisson.getSize().y)
{
	setPosition(x, y);
	initSpeed(1, 8, false);
	bonusPoint = 1;

	switch (color)
	{
	case 1:
	case 2:
		setColor(sf::Color::Red);
		bonusPoint = (-15);
		initSpeed(1, 10, true);
		break;
	case 3:
		setColor(sf::Color::Yellow); 
		bonusPoint = 10;
		initSpeed(8, 10, true);
		break;
	default:break;
	}
	
	// Animation
	SetLoopSpeed(5);
	Play();
}

Poisson::~Poisson()
{

}

void Poisson::Move() {
	if ((etatDeplacement--) == 0) {
		etatDeplacement = vitesse;
		move(-vitesse, 0);
	}
}

bool Poisson::outOfBound(sf::RectangleShape gameBoard) {
	if (getPosition().x < gameBoard.getPosition().x - 5)
		return true;
	return false;
}

// Initialise la vitesse entre x et y
void Poisson::initSpeed(int x, int y, bool special) {
	vitesse = RAND_X_Y(x, y);
	if (special) {
		etatDeplacement = vitesse / 2;
	}
	else {
		etatDeplacement = vitesse;
	}
}

int Poisson::getRecompense() {
	return bonusPoint;
}

sf::Texture Poisson::imagePoisson ;
void Poisson::setPoissonImg() {
	if (!imagePoisson.loadFromFile("../ressources/fish2mw5.png")) {
		cerr << "Impossible de charger fish2mw5.png" << endl;
		return;
	}
}

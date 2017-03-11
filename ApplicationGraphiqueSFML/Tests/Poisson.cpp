#include "Header.h"
#include "Poisson.h"

Poisson::Poisson(int x, int y) : AniSprite(imagePoisson, imagePoisson.getSize().x / 3, imagePoisson.getSize().y)
{
	setPosition(x, y);
		
	// Valeurs par défault
	setRatio(1, 3, 6);
	setPoints(10, -15, 1);
	initPoisson();

	// Animation
	SetLoopSpeed(5);
	Play();
}

Poisson::~Poisson()
{

}

// Génère un mouvement pour le poisson
void Poisson::Move() {
	if ((etatDeplacement--) == 0) {
		etatDeplacement = vitesse;
		move(-vitesse, 0);
	}
}

// Vérifie que le poisson reste dans la zone de jeu
bool Poisson::outOfBound(sf::RectangleShape gameBoard) {
	if (getPosition().x < gameBoard.getPosition().x - 5)
		return true;
	if (getPosition().y < gameBoard.getPosition().y - 5)
		return true;
	return false;
}

// Initialise la vitesse entre x et y
void Poisson::initSpeed(int x, int y) {
	vitesse = RAND_X_Y(x, y);
	etatDeplacement = vitesse / 2;
}

// Défini le ration d'aparition des couleurs de poisson
void Poisson::setRatio(int gold, int red, int blue) {
	// On part de 0
	numberOfGold = gold;
	numberOfRed  = gold + red;
	numberOfBlue = gold + red + blue;
	// NumberOfBlue donne aussi le nombre max pour le rand de génération
}

void Poisson::setPoints(int gold, int red, int blue) {
	pointOfRed = red;
	pointOfGold = gold;
	pointOfBlue = blue;
}

void Poisson::initPoisson() {
	int color = RAND_X_Y(0, numberOfBlue);
	if (color < numberOfGold) {
		setColor(sf::Color::Yellow);
		bonusPoint = pointOfGold;
		initSpeed(5, 8);
	}
	else if (color < numberOfRed) {
		setColor(sf::Color::Red);
		bonusPoint = pointOfRed;
		initSpeed(1, 8);
	}
	else if (color < numberOfBlue) {
		bonusPoint = pointOfBlue;
		initSpeed(1, 8);
	}
}

// Retourne les points gagné avec ce poisson
int Poisson::getRecompense() {
	return bonusPoint;
}

sf::Texture Poisson::imagePoisson ;
void Poisson::setPoissonImg() {
	if (!imagePoisson.loadFromFile(IMG_POISSON)) {
		cerr << "Impossible de charger fish2mw5.png" << endl;
		return;
	}
}

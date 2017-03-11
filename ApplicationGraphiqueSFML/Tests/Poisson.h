#if (!defined POISSON_H)
#define POISSON_H 1

#include "Header.h"
#include "AniSprite.h"

class Poisson : public AniSprite
{
public:
	Poisson(int x, int y);
	~Poisson();

	// Déplace le poisson
	void Move();

	// Vérifie que le poisson ne sort pas des limites
	bool outOfBound(sf::RectangleShape gameBoard);

	// Retourne le nombre de points gagné
	int getRecompense();

	// Défini l'image du poisson
	static void setPoissonImg();

	// Défini le ration d'aparition des couleurs de poisson
	void setRatio(int gold, int red, int blue);

	// Défini les points pour chaques couleurs
	void setPoints(int gold, int red, int blue);

	// Défini la vitesse. Aléatoire en x et y
	void initSpeed(int x, int y);

	// Initialise les poissons
	void initPoisson();

private:
	int vitesse;
	int bonusPoint;
	int etatDeplacement;

	// Ratio d'aparition des poissons
	int numberOfRed;
	int numberOfGold;
	int numberOfBlue;
	// Points défini par couleur
	int pointOfRed;
	int pointOfGold;
	int pointOfBlue;
	
	static sf::Texture imagePoisson;
};

#endif // (!defined POISSON_H)


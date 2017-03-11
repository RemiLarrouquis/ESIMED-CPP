#if (!defined POISSON_H)
#define POISSON_H 1

#include "Header.h"
#include "AniSprite.h"

class Poisson : public AniSprite
{
public:
	Poisson(int x, int y);
	~Poisson();

	// D�place le poisson
	void Move();

	// V�rifie que le poisson ne sort pas des limites
	bool outOfBound(sf::RectangleShape gameBoard);

	// Retourne le nombre de points gagn�
	int getRecompense();

	// D�fini l'image du poisson
	static void setPoissonImg();

	// D�fini le ration d'aparition des couleurs de poisson
	void setRatio(int gold, int red, int blue);

	// D�fini les points pour chaques couleurs
	void setPoints(int gold, int red, int blue);

	// D�fini la vitesse. Al�atoire en x et y
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
	// Points d�fini par couleur
	int pointOfRed;
	int pointOfGold;
	int pointOfBlue;
	
	static sf::Texture imagePoisson;
};

#endif // (!defined POISSON_H)


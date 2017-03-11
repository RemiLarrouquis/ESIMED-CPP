#if (!defined POISSON_H)
#define POISSON_H 1

#include "Header.h"
#include "AniSprite.h"

class Poisson : public AniSprite
{
public:
	Poisson(int x, int y, int color);
	~Poisson();

	// D�place le poisson
	void Move();

	// V�rifie que le poisson ne sort pas des limites
	bool outOfBound(sf::RectangleShape gameBoard);

	// D�fini la vitesse. Al�atoire en x et y
	void initSpeed(int x, int y, bool special);

	// Retourne le nombre de points gagn�
	int getRecompense();

	// D�fini l'image du poisson
	static void setPoissonImg();

private:
	int vitesse;
	int bonusPoint;
	int etatDeplacement;
	static sf::Texture imagePoisson;
};

#endif // (!defined POISSON_H)


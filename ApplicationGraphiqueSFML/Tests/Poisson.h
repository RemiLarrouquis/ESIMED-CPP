#if (!defined POISSON_H)
#define POISSON_H 1

#include "Header.h"
#include "AniSprite.h"

class Poisson : public AniSprite
{
public:
	Poisson(int x, int y, int color);
	~Poisson();

	void Move();
	bool outOfBound(sf::RectangleShape gameBoard);
	void initSpeed(int x, int y, bool special);
	int getRecompense();
	static void setPoissonImg();
private:
	static sf::Texture imagePoisson;

	int vitesse;
	int etatDeplacement;
	int bonusPoint;
};

#endif // (!defined POISSON_H)


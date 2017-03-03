#if (!defined CARAVEL_H)
#define CARAVEL_H 1

#include "Header.h"

#define WIDTH_CARAVEL  100
#define HEIGHT_CARAVEL 100
#define SPEED_CARAVEL 2

class Caravel : public sf::Sprite
{
public:
	Caravel();
	~Caravel();

	void initSpeed(int speed);
	void nextMove(int offX, int offY);
	void confirmMove(sf::RectangleShape gameBoard);
	static void setCaravelImg();
private:
	static sf::Texture imageCaravel;

	int vitesse;
	sf::Vector2f nextMoveCaravel;
};

#endif


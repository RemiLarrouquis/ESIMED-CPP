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

	// Défini les vitesse de la caravel
	void initSpeed(int speed);

	// Indique le prochain mouvement
	void nextMove(int offX, int offY);

	// Confirme qu'il s'agit d'une mouvmeent conforme
	void confirmMove(sf::RectangleShape gameBoard);

	// Défini l'image de la caravel
	static void setCaravelImg();
private:
	int vitesse;
	sf::Vector2f nextMoveCaravel;
	static sf::Texture imageCaravel;
};

#endif


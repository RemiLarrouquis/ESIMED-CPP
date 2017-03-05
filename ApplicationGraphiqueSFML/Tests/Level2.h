#if (!defined LEVEL2_H)
#define LEVEL2_H 1

#include "Header.h"
#include "Levels.h"
#include "Poisson.h"
#include "Caravel.h"
#include "ScoreBar.h"

class Level2 : public Levels {
public:
	Level2();
	~Level2();

private:

	// Level
	string getLevelName();

	//Poisson
	void generatePoisson(sf::RectangleShape gameBoard);

};

#endif
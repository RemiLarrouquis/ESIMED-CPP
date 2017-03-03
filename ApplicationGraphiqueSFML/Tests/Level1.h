#if (!defined LEVEL1_H)
#define LEVEL1_H 1

#include "Header.h"
#include "Levels.h"
#include "Poisson.h"
#include "Caravel.h"
#include "ScoreBar.h"

class Level1 : public Levels {
public:
	Level1();
	~Level1();

private:

	// Level
	void setLevelName();

	//Poisson
	void generatePoisson(sf::RectangleShape gameBoard);

};

#endif
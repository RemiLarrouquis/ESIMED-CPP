#include "Level1.h"
#include "Levels.h"

Level1::Level1() : Levels() {
	
}

Level1::~Level1() {

}

void Level1::generatePoisson(sf::RectangleShape gameBoard) {
	if (RAND_X_Y(0, 50) == 0) {
		poissons.push_back(
			Poisson(gameBoard.getSize().x + gameBoard.getPosition().x - 20,
				RAND_X_Y(100 + 10, HEIGHT_GAME - 20)
			)
		);
	}
}

string Level1::getLevelName() {
	return "Level 1 : Fish Paradise";
}

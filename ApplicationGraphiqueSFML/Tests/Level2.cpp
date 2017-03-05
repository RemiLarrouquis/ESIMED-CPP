#include "Level2.h"
#include "Levels.h"
#include "Transition.h"

Level2::Level2() : Levels() {
	
}

Level2::~Level2() {

}

void Level2::generatePoisson(sf::RectangleShape gameBoard) {
	if (RAND_X_Y(0, 50) == 0) {
		poissons.push_back(
			Poisson(gameBoard.getSize().x + gameBoard.getPosition().x - 20,
				RAND_X_Y(100 + 10, HEIGHT_GAME - 30),
				RAND_X_Y(1, 10)
			)
		);
	}
}

string Level2::getLevelName() {
	return "Level 2 : Fish Revenge";
}
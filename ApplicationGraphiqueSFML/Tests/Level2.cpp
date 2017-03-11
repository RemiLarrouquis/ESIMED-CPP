#include "Level2.h"
#include "Levels.h"
#include "Transition.h"

Level2::Level2() : Levels() {
	
}

Level2::~Level2() {

}

void Level2::generatePoisson(sf::RectangleShape gameBoard) {
	if (RAND_X_Y(0, 35) == 0) {
		Poisson *newPoisson = new Poisson(
			gameBoard.getSize().x + gameBoard.getPosition().x - 20,
			RAND_X_Y(100 + 10, HEIGHT_GAME - 20)
		);
		newPoisson->setRatio(1, 5, 0);
		newPoisson->setPoints(15, -10, 0);
		newPoisson->initPoisson();
		poissons.push_back(*newPoisson);
	}
}

string Level2::getLevelName() {
	return "Level 2 : Fish Revenge";
}
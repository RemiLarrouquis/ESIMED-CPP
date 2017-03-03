#include "Level2.h"
#include "Levels.h"

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

void Level2::setLevelName() {
	ostringstream msg;
	msg << "Fish Revenge";
	levelName.setString(msg.str());
}
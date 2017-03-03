#if (!defined LEVELS_H)
#define LEVELS_H 1

#include "Header.h"
#include "Poisson.h"
#include "Caravel.h"
#include "ScoreBar.h"

class Levels {
public:
	Levels();
	~Levels();

	// Fonctions
	void ProcessEvents();
	void ProcessStates();
	void DrawScreen(sf::RenderWindow &window);

	// Membres publics
	vector<Poisson> poissons;
	ScoreBar score;
	sf::Text levelName;
	
private:
	// Membres
	Caravel caravel;
	sf::RectangleShape gameBoard;

	// Level
	virtual void setLevelName() = 0;

	// Poisson
	virtual void generatePoisson(sf::RectangleShape gameBoard) = 0;

	// Emplacement du jeu
	void setGameBoard();
};

#endif
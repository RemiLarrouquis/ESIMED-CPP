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

	// R�cup�re le score
	ScoreBar* getScore();

	// Membres publics
	vector<Poisson> poissons;
	ScoreBar score;
	
	// D�finie le nom du niveau
	virtual string getLevelName() = 0;

private:
	// Membres
	Caravel caravel;
	sf::Text levelName;
	sf::RectangleShape gameBoard;

	// Emplacement du jeu
	void setGameBoard();


	// Fonction de g�n�ration des poissons
	virtual void generatePoisson(sf::RectangleShape gameBoard) = 0;
};

#endif
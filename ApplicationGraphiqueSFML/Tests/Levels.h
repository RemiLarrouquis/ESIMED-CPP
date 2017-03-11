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

	// Récupère le score
	ScoreBar* getScore();

	// Membres publics
	vector<Poisson> poissons;
	ScoreBar score;
	
	// Définie le nom du niveau
	virtual string getLevelName() = 0;

private:
	// Membres
	Caravel caravel;
	sf::Text levelName;
	sf::RectangleShape gameBoard;

	// Emplacement du jeu
	void setGameBoard();


	// Fonction de génération des poissons
	virtual void generatePoisson(sf::RectangleShape gameBoard) = 0;
};

#endif
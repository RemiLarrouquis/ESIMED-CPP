#if (!defined SCOREBAR_H)
#define SCOREBAR_H 1

#include "Header.h"
#include "AniSprite.h"

class ScoreBar {
public:
	ScoreBar();
	~ScoreBar();

	// Affiche la bare de score
	void drawBoard(sf::RenderWindow &window);

	// Score
	// Initialise le score
	void initScoreValue();
	// Ajoute une valeur au score
	void addScoreValue(int value);
	// Retourne le score
	int getScore();

	// Level
	// Initialise le niveau
	void initLevelValue();
	// Défini la valeur
	void setLevelValue(int value);

	// Life
	// Initialise la bare de vie
	void setSpriteLife(int x, int y);
	// Change l'état ed la vie (true la vie diminue)
	void changeLife(bool loose);
	// Charge l'image de la vie
	static void initLifeImg();
	// Font
	static void initFontText();

private:
	// Bare en top
	static sf::Font textFont;
	sf::RectangleShape barreTop;
	// Score
	sf::Text scoreValue;
	// Level
	sf::Text levelValue;
	// Life
	AniSprite *spriteLife;
	static sf::Texture imageLife;

	// Conteurs
	int score;
};

#endif
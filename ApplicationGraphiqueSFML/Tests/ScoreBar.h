#if (!defined SCOREBAR_H)
#define SCOREBAR_H 1

#include "Header.h"
#include "AniSprite.h"

class ScoreBar {
public:
	ScoreBar();
	~ScoreBar();

	void drawBoard(sf::RenderWindow &window);
	// Score
	void initScoreValue();
	void addScoreValue(int value);
	int getScore();
	// Level
	void initLevelValue();
	void setLevelValue(int value);
	// Life
	static void initLifeImg();
	void setSpriteLife(int x, int y);
	void changeLife(bool loose);
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
	static sf::Texture imageLife;
	AniSprite *spriteLife;

	// Conteurs
	int score;
};

#endif
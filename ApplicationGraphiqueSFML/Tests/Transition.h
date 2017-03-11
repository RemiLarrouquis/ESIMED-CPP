#if(!defined TRANSITION_H)
#define TRANSITION_H 1

#include "Header.h"

class Transition
{
public:
	Transition();
	~Transition();

	// Affiche le titre du niveau
	void drawTextLevels(sf::RenderWindow &window, string texte);

	// Permet d'afficher le menu de d�marage
	void drawMenuStart(sf::RenderWindow &window);

	// Affiche l'ecran de fin. (si true, affiche la victoire)
	void drawEndScrean(sf::RenderWindow &window, bool goodEnding);

	// Initialise l'�cran de d�marage
	void initStartScrean();

	// Initialise l'�cran de fin (game over)
	void initGameOverScrean();

	// Initialise l'�cran de fin (victoire)
	void initWinScrean();

	// Permet de centrer les messages
	void centreText(sf::Text *texte, float offsetX, float offsetY);

	static void initFont();
	static void initBackgroundImg();
private:

	static sf::Texture imageBackground;
	static sf::Font textFont;

	sf::Sprite *spriteBackground;
	sf::Text *textTitre;
	sf::Text *textStart;
	sf::Text *textReStart;
	sf::Text *textGameOver;
	sf::Text *textWin;
};


#endif

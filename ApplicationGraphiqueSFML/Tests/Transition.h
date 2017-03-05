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

	// Permet d'afficher le menu de démarage
	void drawMenuStart(sf::RenderWindow &window);

	void getTitre();
	void getStart();

	static void initFont();
	static void initBackgroundImg();
private:

	static sf::Texture imageBackground;
	static sf::Font textFont;

	sf::Sprite *spriteBackground;
	sf::Text *textTitre;
	sf::Text *textStart;
};

#endif

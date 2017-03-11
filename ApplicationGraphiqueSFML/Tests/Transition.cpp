#include "Header.h"
#include "Transition.h"

Transition::Transition() {
	
	initStartScrean();
	initGameOverScrean();
	initWinScrean();

	// Image de fond
	spriteBackground = new sf::Sprite(imageBackground);
	spriteBackground->setScale(2, 3);
	spriteBackground->setPosition(0, 0);
}

Transition::~Transition() {
	delete textTitre;
	delete textStart;
}

void Transition::drawTextLevels(sf::RenderWindow &window, string texte) {
	sf::Text *name = new sf::Text(texte, textFont, TITRES_SIZE);
	// On centre le titre dans la fenetre
	centreText(name, 0.0f, -100.0f);
	// On l'affiche
	window.draw(*name);
}

void Transition::drawMenuStart(sf::RenderWindow &window) {
	window.draw(*spriteBackground);
	window.draw(*textTitre);
	window.draw(*textStart);
}

void Transition::drawEndScrean(sf::RenderWindow &window, bool goodEnding) {
	if (goodEnding) {
		window.draw(*spriteBackground);
		window.draw(*textWin);
		window.draw(*textReStart);
	}
	else {
		window.draw(*textGameOver);
		window.draw(*textReStart);
	}
}

void Transition::initStartScrean() {
	ostringstream *msg;

	// Défini le titre
	msg = new ostringstream("Fisher Man : La vie d'un pêcheur");
	textTitre = new sf::Text(msg->str(), textFont, TITRES_SIZE);

	// On centre le titre dans la fenetre
	centreText(textTitre, 0.0f, -100.0f);

	// Défini l'action pour démarer le jeu
	msg = new ostringstream("PRESS [SPACE] TO START");
	textStart = new sf::Text(msg->str(), textFont, SS_TITRES_SIZE);

	// Centre le texte
	centreText(textStart, 0.0f, 0.0f);

	// Défini l'action pour redémarerle jeu
	msg = new ostringstream("[R] RESTART");
	textReStart = new sf::Text(msg->str(), textFont, SS_TITRES_SIZE);

	// Centre le texte
	centreText(textReStart, 0.0f, 0.0f);
}

void Transition::initGameOverScrean() {
	ostringstream *msg;

	// Défini le titre
	msg = new ostringstream("GAME OVER");
	textGameOver = new sf::Text(msg->str(), textFont, TITRES_SIZE);
	textGameOver->setFillColor(sf::Color(187, 10, 30, 200));

	// On centre le titre dans la fenetre
	centreText(textGameOver, 0.0f, -100.0f);
}

void Transition::initWinScrean() {
	ostringstream *msg;

	// Défini le titre
	msg = new ostringstream("YOU WIN");
	textWin = new sf::Text(msg->str(), textFont, TITRES_SIZE);

	// On centre le titre dans la fenetre
	centreText(textWin, 0.0f, -100.0f);
}

void Transition::centreText(sf::Text *texte, float offsetX, float offsetY) {
	sf::FloatRect textRect = texte->getLocalBounds();
	texte->setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	texte->setPosition(sf::Vector2f((WIDTH_WINDOW / 2.0f) + offsetX, (HEIGHT_WINDOW / 2.0f) + offsetY));
}

sf::Font Transition::textFont;
void Transition::initFont() {
	textFont.loadFromFile(FONT_GOODDOG);
}

sf::Texture Transition::imageBackground;
void Transition::initBackgroundImg() {
	if (!imageBackground.loadFromFile(IMG_FONDMARIN)) {
		cerr << "Impossible de charger fullFondMarin.jpg" << endl;
		return;
	}
}
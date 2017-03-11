#include "Header.h"
#include "Transition.h"

Transition::Transition() {
	ostringstream *msg;
	// Défini le titre
	msg = new ostringstream("Fisher Man : La vie d'un pêcheur");
	textTitre = new sf::Text(msg->str(), textFont, TITRES_SIZE);

	// On centre le titre dans la fenetre
	sf::FloatRect textRect = textTitre->getLocalBounds();
	textTitre->setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	textTitre->setPosition(sf::Vector2f(WIDTH_WINDOW / 2.0f, (HEIGHT_WINDOW / 2.0f) - 100.0f));

	// Défini l'action pour démarer le jeu
	msg = new ostringstream("PRESS SPACE TO START");
	textStart = new sf::Text(msg->str(), textFont, SS_TITRES_SIZE);

	// Centre le texte
	textRect = textStart->getLocalBounds();
	textStart->setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	textStart->setPosition(sf::Vector2f(WIDTH_WINDOW / 2.0f, HEIGHT_WINDOW / 2.0f));

	// Image de fond
	spriteBackground = new sf::Sprite(imageBackground);
	spriteBackground->setScale(2, 3);
	spriteBackground->setPosition(0, 0);
}

void Transition::drawTextLevels(sf::RenderWindow &window, string texte) {
	sf::Text name = sf::Text(texte, textFont, TITRES_SIZE);
	// On centre le titre dans la fenetre
	sf::FloatRect textRect = name.getLocalBounds();
	name.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	name.setPosition(sf::Vector2f(WIDTH_WINDOW / 2.0f, (HEIGHT_WINDOW / 2.0f) - 100.0f));
	// On l'affiche
	window.draw(name);
}

void Transition::drawMenuStart(sf::RenderWindow &window) {
	window.draw(*spriteBackground);
	window.draw(*textTitre);
	window.draw(*textStart);
}

Transition::~Transition() {
	delete textTitre;
	delete textStart;
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
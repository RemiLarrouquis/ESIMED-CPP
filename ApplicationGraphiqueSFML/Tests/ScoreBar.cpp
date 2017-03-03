#include "ScoreBar.h"

ScoreBar::ScoreBar() {
	setScoreValue();
	setLevelValue();
	setSpriteLife(550, 30);
}

ScoreBar::~ScoreBar() {

}

void ScoreBar::drawBoard(sf::RenderWindow &window) {
	window.draw(scoreValue);
	window.draw(levelValue);
	window.draw(*spriteLife);
}

void ScoreBar::setScoreValue() {
	scoreValue.setFont(textFont);
	scoreValue.setFillColor(sf::Color::Black);
	scoreValue.setPosition(100, 30);
	score = 0;
	addScoreValue(0);
}

void ScoreBar::addScoreValue(int value) {
	ostringstream msg;
	score = score + value;
	msg << "Score : " << score;
	scoreValue.setString(msg.str());
}

void ScoreBar::setLevelValue() {
	levelValue.setFont(textFont);
	levelValue.setFillColor(sf::Color::Black);
	levelValue.setPosition(WIDTH_WINDOW - 300, 30);
	level = 1;
	addLevelValue(0);
}

void ScoreBar::addLevelValue(int value) {
	ostringstream msg;
	msg << "Level : " << (level += value);
	levelValue.setString(msg.str());
}

void ScoreBar::setSpriteLife(int x, int y) {
	spriteLife = new AniSprite(imageLife, 32, 32);
	spriteLife->setPosition(x, y);
	// Animation
	spriteLife->SetLoopSpeed(1);
	spriteLife->Play();
}

void ScoreBar::changeLife(bool loose) {
	if (loose) {
		spriteLife->UpdateMan(1);
	}
	else {
		spriteLife->UpdateMan(-1);
	}
}

sf::Font ScoreBar::textFont;
void ScoreBar::setFontText() {
	textFont.loadFromFile("../ressources/verdana.ttf");
}

sf::Texture ScoreBar::imageLife;
void ScoreBar::setLifeImg() {
	if (!imageLife.loadFromFile("../ressources/hearts.png")) {
		cerr << "Impossible de charger hearts.png" << endl;
		return;
	}
}
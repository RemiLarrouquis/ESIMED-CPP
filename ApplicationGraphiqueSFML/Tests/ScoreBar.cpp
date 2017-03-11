#include "ScoreBar.h"

ScoreBar::ScoreBar() {
	initScoreValue();
	initLevelValue();
	setSpriteLife(550, 30);
	life = 5;
}

ScoreBar::~ScoreBar() {

}

void ScoreBar::drawBoard(sf::RenderWindow &window) {
	window.draw(scoreValue);
	window.draw(levelValue);
	window.draw(*spriteLife);
}

void ScoreBar::initScoreValue() {
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

void ScoreBar::initLevelValue() {
	levelValue.setFont(textFont);
	levelValue.setFillColor(sf::Color::Black);
	levelValue.setPosition(WIDTH_WINDOW - 300, 30);
}

void ScoreBar::setLevelValue(int value) {
	ostringstream msg;
	msg << "Level : " << value;
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
		life--;
	}
	else {
		spriteLife->UpdateMan(-1);
		life++;
	}
}

int ScoreBar::getScore() {
	return score;
}

int ScoreBar::getLife() {
	return life;
}

sf::Font ScoreBar::textFont;
void ScoreBar::initFontText() {
	textFont.loadFromFile(FONT_VERDANA);
}

sf::Texture ScoreBar::imageLife;
void ScoreBar::initLifeImg() {
	if (!imageLife.loadFromFile(IMG_LIFE)) {
		cerr << "Impossible de charger hearts.png" << endl;
		return;
	}
}
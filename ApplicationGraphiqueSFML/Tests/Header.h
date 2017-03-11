#if (!defined HEADER_H)
#define HEADER_H 1

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

#define RAND_X_Y(x,y) (rand()%y+x)

// Colors
#define LIGHT_GRAY (sf::Color(66,66,66,128))
#define GRAY (sf::Color(33, 33, 33, 128))

// Window
#define WIDTH_WINDOW 1200
#define HEIGHT_WINDOW 800

// Game Place
#define WIDTH_GAME 1000
#define HEIGHT_GAME 600

// Levels
#define END_LEVEL_1 50
#define END_LEVEL_2 100
#define DELAI_TRANSITION 60

// Texts
#define TITRES_SIZE 80
#define SS_TITRES_SIZE 50

// Files
#define IMG_POISSON "../ressources/fish2mw5.png"
#define IMG_CARAVEL "../ressources/caravel.png"
#define IMG_LIFE "../ressources/hearts.png"
#define IMG_FONDMARIN "../ressources/fullFondMarin.jpg"
#define FONT_VERDANA "../ressources/verdana.ttf"
#define FONT_GOODDOG "../ressources/GoodDog.otf"

#endif
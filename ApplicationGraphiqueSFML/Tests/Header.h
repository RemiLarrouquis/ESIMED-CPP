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
#define DELAI_TRANSITION 50

// Texts
#define TITRES_SIZE 80
#define SS_TITRES_SIZE 50

#endif
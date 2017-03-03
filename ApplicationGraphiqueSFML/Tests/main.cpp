#include "Header.h"
#include "MyGame.h"

using namespace mygame;

int main(int argc, char *argv[]) { 

	/* initialize random seed: */
	srand(time(NULL));

	// Initialise Static value
	Poisson::setPoissonImg();
	Caravel::setCaravelImg();
	
	ScoreBar::setLifeImg();
	ScoreBar::setFontText();

	MyGame(); 
	return 0; 
}


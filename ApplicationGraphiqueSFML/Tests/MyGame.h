#if (!defined MYGAME_H)
#define MYGAME_H 1

#include "Header.h"
#include "MyGame.h" 
#include "Poisson.h"
#include "Caravel.h"
#include "ScoreBar.h"
#include "Levels.h"
#include "Transition.h"

namespace mygame { 

	class MyGame { 
		public: 
			MyGame();
			virtual ~MyGame();

		private: 
			// Membres
			sf::RenderWindow window; 

			// Gestion des niveaux
			Levels *levels;
			int levelNum;

			// Gestion des transitions (menu + changement niveaux)
			Transition trans;
			bool gameStart;

			// Fonctions
			void ProcessEvents();
			void ProcessStates();
			void DrawScreen();
	}; 
}

#endif // (!defined MYGAME_H)
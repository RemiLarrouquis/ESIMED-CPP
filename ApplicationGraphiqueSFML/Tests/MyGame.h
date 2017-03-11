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

			// Démarage du jeu
			void initGameStart();

			// Gestion des niveaux
			Levels *levels;
			int levelNum;

			// Gestion des transitions (menu + changement niveaux)
			Transition trans;
			bool gameStart;
			bool ending;
			bool goodEnding;
			// Delai messages
			int count;
			int delaiEnd;
			// Fonction de temporisation
			void wait(int delai);

			// Fonctions
			void ProcessEvents();
			void ProcessStates();
			void DrawScreen();
	}; 
}

#endif // (!defined MYGAME_H)
#include <SDL/SDL.h>
struct Hero
{

	SDL_Surface *IdleR;
	SDL_Surface *IdleL;
	SDL_Surface *spriteR[15];
	SDL_Surface *spriteL[15];
	SDL_Rect posHero;
	int Idle; //1:idle,0:moving
	int direction ;//0:left,1:right
	int health;

};
typedef struct Hero Hero;

int LoadHero(Hero *chuck);
void InitHero(Hero *chuck);
void FreeHero(Hero *chuck);
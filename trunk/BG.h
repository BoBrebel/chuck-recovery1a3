#include <SDL/SDL.h>
#include "Defs.h"

struct Level
{
	SDL_Surface *map;
	SDL_Surface *clmap;
	SDL_Rect posBG;
	SDL_Rect srcBG;

} ;
typedef struct Level Level;

int LoadBG(Level *level1);
void InitBG(Level *level1);
void FreeBG(Level *level1);
void BlitBG(Level *level1,SDL_Surface *screen);
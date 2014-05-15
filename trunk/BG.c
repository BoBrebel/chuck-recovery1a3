#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "BG.h"
#include "Defs.h"


int LoadBG(Level *level1)
{
level1->map =IMG_Load("Level1/Level1.png");
if(level1->map == NULL) {
	printf("unable to load map:%s\n",SDL_GetError());
	return(-1);
}
level1->clmap =IMG_Load("Level1/Level1cl.png");
if(level1->clmap == NULL) {
	printf("unable to load clmap:%s\n",SDL_GetError());
	return(-1);
}
return(0);
}

void InitBG(Level *level1)
{
	level1->srcBG.x=0;
	level1->srcBG.y=0;
	level1->srcBG.w=SCREEN_W;
	level1->srcBG.h=SCREEN_H;

	level1->posBG.x = 0;
	level1->posBG.y = 0;


}

void BlitBG(Level *level1,SDL_Surface *screen)
{
	if(level1->srcBG.x>level1->map->w-SCREEN_W)
		level1->srcBG.x=0;
	if(level1->srcBG.x>level1->clmap->w-SCREEN_W)
		level1->srcBG.x=0;

	if(level1->srcBG.x<0)
		level1->srcBG.x=level1->map->w-SCREEN_W;
	if(level1->srcBG.x<0)
		level1->srcBG.x=level1->clmap->w-SCREEN_W;
	SDL_BlitSurface(level1->clmap,&(level1->srcBG),screen,&(level1->posBG));
	SDL_BlitSurface(level1->map,&(level1->srcBG),screen,&(level1->posBG));
}

void FreeBG(Level *level1)
{
	SDL_FreeSurface(level1->map);
	SDL_FreeSurface(level1->clmap);
}
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "Hero.h"
#include "level1.h"
#include "Defs.h"

int LoadHero(Hero *chuck)
{
	int i;
	
	chuck->IdleR=IMG_Load("Sprite/1.png");
 	chuck->IdleL=IMG_Load("Sprite/1l.png");
 	
 	chuck->spriteR[0]=IMG_Load("Sprite/Right/4.png");
 	chuck->spriteR[1]=IMG_Load("Sprite/Right/6.png");
 	chuck->spriteR[2]=IMG_Load("Sprite/Right/8.png");
 	chuck->spriteR[3]=IMG_Load("Sprite/Right/10.png");
 	chuck->spriteR[4]=IMG_Load("Sprite/Right/12.png");
 	chuck->spriteR[5]=IMG_Load("Sprite/Right/14.png");
 	chuck->spriteR[6]=IMG_Load("Sprite/Right/16.png");
 	chuck->spriteR[7]=IMG_Load("Sprite/Right/18.png");
 	chuck->spriteR[8]=IMG_Load("Sprite/Right/20.png");
 	chuck->spriteR[9]=IMG_Load("Sprite/Right/22.png");
 	chuck->spriteR[10]=IMG_Load("Sprite/Right/24.png");
 	chuck->spriteR[11]=IMG_Load("Sprite/Right/26.png");
 	chuck->spriteR[12]=IMG_Load("Sprite/Right/28.png");
 	chuck->spriteR[13]=IMG_Load("Sprite/Right/30.png");


 	chuck->spriteL[0]=IMG_Load("Sprite/Left/4l.png");
 	chuck->spriteL[1]=IMG_Load("Sprite/Left/6l.png");
 	chuck->spriteL[2]=IMG_Load("Sprite/Left/8l.png");
 	chuck->spriteL[3]=IMG_Load("Sprite/Left/10l.png");
 	chuck->spriteL[4]=IMG_Load("Sprite/Left/12l.png");
 	chuck->spriteL[5]=IMG_Load("Sprite/Left/14l.png");
 	chuck->spriteL[6]=IMG_Load("Sprite/Left/16l.png");
 	chuck->spriteL[7]=IMG_Load("Sprite/Left/18l.png");
 	chuck->spriteL[8]=IMG_Load("Sprite/Left/20l.png");
 	chuck->spriteL[9]=IMG_Load("Sprite/Left/22l.png");
 	chuck->spriteL[10]=IMG_Load("Sprite/Left/24l.png");
 	chuck->spriteL[11]=IMG_Load("Sprite/Left/26l.png");
 	chuck->spriteL[12]=IMG_Load("Sprite/Left/28l.png");
 	chuck->spriteR[13]=IMG_Load("Sprite/Left/30l.png");

 	if(chuck->IdleR == NULL) {
	printf("unable to load idler:%s\n",SDL_GetError());
	return(-1);}
	if(chuck->IdleL == NULL) {
	printf("unable to load idlel:%s\n",SDL_GetError());
	return(-1);}

	for(i=0;i<14;i++){
		if(chuck->spriteL[i] == NULL) {
		printf("unable to load sprite l%d:%s\n",i,SDL_GetError());
		return(-1);
				}

		if(chuck->spriteR[i] == NULL) {
		printf("unable to load sprite r%d:%s\n",i,SDL_GetError());
		return(-1);
				}
	}
}

void InitHero(Hero *chuck)
{
	chuck->posHero.x=100;
	chuck->posHero.y=450;
	chuck->posHero.w=100;
	chuck->posHero.h=100;

	chuck->Idle = 1;
	chuck->direction = 1;

	chuck->health = 20;
}

void FreeHero(Hero *chuck)
{
	int i;
	for(i=0;i<14;i++)
	{
		SDL_FreeSurface(chuck->spriteL[i]);
		SDL_FreeSurface(chuck->spriteR[i]);
	}
		SDL_FreeSurface(chuck->IdleR);
		SDL_FreeSurface(chuck->IdleL);

}
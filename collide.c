#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "head.h"
#include "BG.h"
#include "Hero.h"
#include "level1.h"
#include "Defs.h"
#include "collide.h"

//1:collision à gauche 2: collision a droite 0:collision en bas 3: collision haut
int Collide(SDL_Surface *clmap,SDL_Rect posHero)
{
	int c1,c2,c3,c4,c5,c6,c7,c8;
	Uint8 r1,r2,r3,r4,r5,r6,r7,r8,g1,g2,g3,g4,g5,g6,g7,g8,b1,b2,b3,b4,b5,b6,b7,b8;

	if(posHero.x>0 && posHero.y >0){
		int bpp = clmap->format->BytesPerPixel;
		Uint8 *p1 = (Uint8 *)clmap->pixels + posHero.y * clmap->pitch + posHero.x * bpp;
		Uint8 *p2 = (Uint8 *)clmap->pixels + (posHero.y+posHero.w)2) * clmap->pitch + posHero.x * bpp;
		Uint8 *p3 = (Uint8 *)clmap->pixels + posHero.w * clmap->pitch + posHero.x * bpp;
		Uint8 *p4 = (Uint8 *)clmap->pixels + posHero.w * clmap->pitch + (posHero.x+posHero.h/2) * bpp;
		Uint8 *p5 = (Uint8 *)clmap->pixels + posHero.w * clmap->pitch + posHero.h * bpp;
		Uint8 *p6 = (Uint8 *)clmap->pixels + (posHero.y+posHero.w/2) * clmap->pitch + posHero.h * bpp;
		Uint8 *p7 = (Uint8 *)clmap->pixels + posHero.y * clmap->pitch + posHero.h * bpp;
		Uint8 *p8 = (Uint8 *)clmap->pixels + posHero.y * clmap->pitch + (posHero.x+posHero.h/2) * bpp;



		SDL_GetRGB(*(Uint32 *)p,clmap->format, r1, g1, b1);
		SDL_GetRGB(*(Uint32 *)p,clmap->format, r2, g2, b2);
		SDL_GetRGB(*(Uint32 *)p,clmap->format, r3, g3, b3);
		SDL_GetRGB(*(Uint32 *)p,clmap->format, r4, g4, b4);
		SDL_GetRGB(*(Uint32 *)p,clmap->format, r5, g5, b5);
		SDL_GetRGB(*(Uint32 *)p,clmap->format, r6, g6, b6);
		SDL_GetRGB(*(Uint32 *)p,clmap->format, r7, g7, b7);
		SDL_GetRGB(*(Uint32 *)p,clmap->format, r8, g8, b8);


		if(r1==255 && g1==255 & b1==255){
			c1==1
		}
		if(r2==255 && g2==255 & b2==255){
			c2==1
		}
		if(r3==255 && g3==255 & b3==255){
			c3==1
		}
		if(r4==255 && g4==255 & b4==255){
			c4==1
		}
		if(r5==255 && g5==255 & b5==255){
			c5==1
		}
		if(r6==255 && g6==255 & b6==255){
			c6==1
		}
		if(r7==255 && g7==255 & b7==255){
			c7==1
		}
		if(r8==255 && g8==255 & b8==255){
			c8==1
		}

			if(c1==1 || c8==1 || c7==1){
				return(1);
			}
			if(c1==1 || c2==1 || c3==1){
				return(3);
			}
			if(c3==1 || c4==1 || c5==1){
				return(2);
			}
			if(c5=1 || c6==1 || c7==1){
				return(0);
			}
}





	/* if(x>0 && y>0 && x<map->w && y<map->h)
    {
        int bpp = map->format->BytesPerPixel;
      
        Uint8 *p = (Uint8 *)map->pixels + y * map->pitch + x * bpp;
        SDL_GetRGB(*(Uint32 *)p,map->format, r, g, b);
 
    }
    else // sinon on renvoie noir, pour éviter de planter dans certains cas
    {
        r = 255;
        g = 255;
        b = 255;
    }*/
}
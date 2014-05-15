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

int Level1(){
	int continuer = 0;
 	int i = 0,j = 0;

  int ground = 0;

  Uint32 t_prev,dt=1;

  Level level1;
  Hero chuck ;

  SDL_Surface *hero = NULL ,*screen = NULL;
  
  SDL_Event event;
  int keysHeld[323]={0};

  if(LoadBG(&level1) == -1){
    printf("error loading level\n");
    return(-1);
  }

  if(LoadHero(&chuck) == -1){
    printf("error loading Chuck\n");
  }

  InitBG(&level1);
  InitHero(&chuck);
  hero = chuck.IdleR;

  SDL_Init(SDL_INIT_VIDEO);
  screen=SDL_SetVideoMode(800,600,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Chuck",NULL);


  SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);

  while(!continuer){
    t_prev = SDL_GetTicks();
    while(SDL_PollEvent(&event)) {
      ground = 0;
      if(chuck.posHero.y<450){chuck.posHero.y+=10;}
      if(chuck.posHero.y == 450){ground=1;}
      switch(event.type) {
         case SDL_QUIT:
          continuer = 1;
         break;
         case SDL_KEYDOWN:
          chuck.Idle = 0;
          keysHeld[event.key.keysym.sym] = 1;
          if(event.key.keysym.sym == SDLK_UP && ground)
          {
            chuck.posHero.y-=50;
          }
         break;
         case SDL_KEYUP:
          keysHeld[event.key.keysym.sym] = 0;
          chuck.Idle = 1;
         break; 
      }
      if(keysHeld[SDLK_ESCAPE])
            continuer = 1;
      if(keysHeld[SDLK_RIGHT])
      {
        chuck.posHero.x+=4;
        chuck.direction = 1;
        i++;
      }
      if(keysHeld[SDLK_LEFT])
      {
        chuck.posHero.x-=4;
        chuck.direction = 0;
        j++;
      }
     /* if(keysHeld[SDLK_UP] && ground)
      {
        chuck.posHero.y -=50;
      }*/
    }
    if(i > 13){i=0;}
    if(j > 13){j=0;}

    if(chuck.Idle == 1 && chuck.direction == 1)
    {
      hero = chuck.IdleR;
    }
    if(chuck.Idle == 1 && chuck.direction == 0)
    {
      hero = chuck.IdleL;
    }
    if(chuck.Idle == 0 && chuck.direction == 1)
    {
      hero = chuck.spriteR[i];
      j==0;
    }
    if(chuck.Idle == 0 && chuck.direction == 0)
    {
      hero = chuck.spriteL[j];
      i==0;
    }
    if (Collide(&clmap,chuck.posHero) == 1){
      chuck.posHero.x+=1;
    }
    if (Collide(&clmap,chuck.posHero) == 2){
      chuck.posHero.x-=1;
    }
    if (Collide(&clmap,chuck.posHero) == 3){
      chuck.posHero.y+=1;
    }

    BlitBG(&level1,screen);
    SDL_BlitSurface(hero,NULL,screen,&chuck.posHero);
    SDL_Flip(screen);
    dt=(SDL_GetTicks()-t_prev);

    if(1000/FPS > SDL_GetTicks() - t_prev)
      SDL_Delay(1000/FPS - (SDL_GetTicks() - t_prev));
  } 
FreeBG(&level1);
FreeHero(&chuck);
SDL_FreeSurface(hero);
return (0);


}















































































   	/*SDL_Surface *IdleR;
	SDL_Surface *IdleL;
	SDL_Surface *spriteR[15];
	SDL_Surface *spriteL[15];
	int health;
   	SDL_Surface *level1map;
	SDL_Surface *level1clmap;
	SDL_Rect posPlayer;
  	SDL_Event event;
 	SDL_Surface *ecran = NULL ;

 	level1map=IMG_Load("Level1/Level1.png");
 	level1clmap=IMG_Load("Level1/Level1cl.png");
 	
 	posPlayer.x = 100;
 	posPlayer.y = 10;

 	
 	IdleR=IMG_Load("Sprite/1.png");
 	IdleL=IMG_Load("Sprite/1l.png");
 	
 	spriteR[0]=IMG_Load("Sprite/Right/4.png");
 	spriteR[1]=IMG_Load("Sprite/Right/6.png");
 	spriteR[2]=IMG_Load("Sprite/Right/8.png");
 	spriteR[3]=IMG_Load("Sprite/Right/10.png");
 	spriteR[4]=IMG_Load("Sprite/Right/12.png");
 	spriteR[5]=IMG_Load("Sprite/Right/14.png");
 	spriteR[6]=IMG_Load("Sprite/Right/16.png");
 	spriteR[7]=IMG_Load("Sprite/Right/18.png");
 	spriteR[8]=IMG_Load("Sprite/Right/20.png");
 	spriteR[9]=IMG_Load("Sprite/Right/22.png");
 	spriteR[10]=IMG_Load("Sprite/Right/24.png");
 	spriteR[11]=IMG_Load("Sprite/Right/26.png");
 	spriteR[12]=IMG_Load("Sprite/Right/28.png");
 	spriteR[13]=IMG_Load("Sprite/Right/30.png");


 	spriteL[0]=IMG_Load("Sprite/Left/4l.png");
 	spriteL[1]=IMG_Load("Sprite/Left/6l.png");
 	spriteL[2]=IMG_Load("Sprite/Left/8l.png");
 	spriteL[3]=IMG_Load("Sprite/Left/10l.png");
 	spriteL[4]=IMG_Load("Sprite/Left/12l.png");
 	spriteL[5]=IMG_Load("Sprite/Left/14l.png");
 	spriteL[6]=IMG_Load("Sprite/Left/16l.png");
 	spriteL[7]=IMG_Load("Sprite/Left/18l.png");
 	spriteL[8]=IMG_Load("Sprite/Left/20l.png");
 	spriteL[9]=IMG_Load("Sprite/Left/22l.png");
 	spriteL[10]=IMG_Load("Sprite/Left/24l.png");
 	spriteL[11]=IMG_Load("Sprite/Left/26l.png");
 	spriteL[12]=IMG_Load("Sprite/Left/28l.png");
 	spriteR[13]=IMG_Load("Sprite/Left/30l.png");

 	health = 10;

 	SDL_Rect posLevel;
 	SDL_Rect srcLevel;

 	posLevel.x=0;
 	posLevel.y=0;

 	srcLevel.x=0;
 	srcLevel.y=0;
 	srcLevel.w=800;
 	srcLevel.h=600;

 	SDL_Init(SDL_INIT_VIDEO);
 if (SDL_Init(SDL_INIT_VIDEO)==-1)
    {
    	fprintf(stderr, "erreur dinitialisation%s\n",SDL_GetError() );
    	exit(EXIT_FAILURE);
    }
    else{
    	ecran=SDL_SetVideoMode(800,600,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    	SDL_WM_SetCaption("Chuck",NULL);

   		SDL_BlitSurface(clmap,&srcLevel,ecran,posLevel);
   		SDL_BlitSurface(map,&srcLevel,ecran,posLevel);
   		SDL_BlitSurface(IdleR,NULL,ecran,posPlayer);
   		SDL_Flip(ecran);

    }



return EXIT_SUCCESS;

}*/

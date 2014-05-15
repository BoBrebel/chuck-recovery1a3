#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "head.h"
#include "level1.h"


void Menu(){
	int i=0,j;
	int x=-1,y=-1;
	int menu=1;

	SDL_Event event;
	SDL_Surface *screen=NULL,*back=NULL,*Tiles[5],*Tilescl[5];
	SDL_Rect posBack;
	SDL_Rect posTile;

	posBack.x = 0;
	posBack.y = 0;

	posTile.x = 0;
	posTile.y = 0;


	SDL_Init(SDL_INIT_VIDEO);
	if (SDL_Init(SDL_INIT_VIDEO)== -1)
	{
		fprintf(stderr, "erreure d'initialisation:%s\n",SDL_GetError() );
		exit(EXIT_FAILURE);
	}
	else
	{
		screen=SDL_SetVideoMode(800,600,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
		SDL_WM_SetCaption("Chuck",NULL);

		back=IMG_Load("MainMenu/main menup2.png");
		Tiles[0]=IMG_Load("MainMenu/main menu Start Game.png");
		Tiles[1]=IMG_Load("MainMenu/main menu how to play.png");
		Tiles[2]=IMG_Load("MainMenu/main menuoption.png");
		Tiles[3]=IMG_Load("MainMenu/main menu Credit.png");
		Tiles[4]=IMG_Load("MainMenu/main menu Quit.png");

		Tilescl[0]=IMG_Load("MainMenu/main menu Start Game cl.png");
		Tilescl[1]=IMG_Load("MainMenu/main menu how to play cl.png");
		Tilescl[2]=IMG_Load("MainMenu/main menuoption cl.png");
		Tilescl[3]=IMG_Load("MainMenu/main menu Credit cl.png");
		Tilescl[4]=IMG_Load("MainMenu/main menu Quit cl.png");

		
		SDL_BlitSurface(back,NULL,screen,&posBack);
		SDL_BlitSurface(Tiles[0],NULL,screen,&posTile);
		SDL_BlitSurface(Tiles[1],NULL,screen,&posTile);
		SDL_BlitSurface(Tiles[2],NULL,screen,&posTile);
		SDL_BlitSurface(Tiles[3],NULL,screen,&posTile);
		SDL_BlitSurface(Tiles[4],NULL,screen,&posTile);

		SDL_Flip(screen);


	while(menu)
		{
			  SDL_WaitEvent(&event);
    		      if (event.type == SDL_QUIT){menu = 0;}
                    else{
                        if(event.type == SDL_KEYDOWN){
                            if(event.key.keysym.sym == SDLK_UP){
                            	i--;
                            }
                            if(event.key.keysym.sym == SDLK_DOWN){
                            	i++;
                            }
                            if((event.key.keysym.sym == SDLK_RETURN)&&(i==5)){
                            	menu = 0;
                            }
                            if((event.key.keysym.sym == SDLK_RETURN)&&(i==1)){
                            	menu = 0;
                            	


                            }
                        }
                    }

                    if(i<1){i=5;}
                    if(i>5){i=1;}
                   //printf("i=%d \n",i);
               SDL_BlitSurface(back,NULL,screen,&posBack);

                    for(j=0;j <= 4; ++j){
                    	if(j+1==i){
							
                    		SDL_BlitSurface(Tilescl[j],NULL,screen,&posTile);
                    	}
                    	else{
							
                    		SDL_BlitSurface(Tiles[j],NULL,screen,&posTile);
                    	}
                    }
							
                    		SDL_Flip(screen);
                    		







                }
            }

		if (i==1){Level1();}
		for(i=0;i<5;i++){
			SDL_FreeSurface(Tiles[i]);
			SDL_FreeSurface(Tilescl[i]);
			}

			SDL_FreeSurface(back);
			
			SDL_Quit();

}
/*int Level1(){
	Uint32 t_prev,dt=1;
	int continuer = 1,direction,rp=0,lp=0,jump;
 	int i = 0,j=0;
 	int G=2;
   	SDL_Surface *IdleR;
	SDL_Surface *IdleL;
	SDL_Surface *spriteR[15];
	SDL_Surface *spriteL[15];
	int health;
   	SDL_Surface *level1map;
	SDL_Surface *level1clmap;
	SDL_Surface *hero;
	SDL_Rect posPlayer;
  	SDL_Event event;
 	SDL_Surface *ecran = NULL ;

 	level1map=IMG_Load("Level1/Level1.png");
 	level1clmap=IMG_Load("Level1/Level1cl.png");
 	
 	posPlayer.x = 100;
 	posPlayer.y = 450;

 	
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
 	spriteL[13]=IMG_Load("Sprite/Left/30l.png");

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
		hero=IdleR;
   		SDL_BlitSurface(level1clmap,&srcLevel,ecran,&posLevel);
   		SDL_BlitSurface(level1map,&srcLevel,ecran,&posLevel);
   		SDL_BlitSurface(hero,NULL,ecran,&posPlayer);
   		SDL_Flip(ecran);
   			
   		while(continuer)
		{
		t_prev = SDL_GetTicks();
		rp=0;lp=0;jump=0;
			 if(posPlayer.y<450 ){posPlayer.y+=G;}
			 		SDL_PollEvent(&event);
    		      if (event.type == SDL_QUIT){continuer = 0;}
		                    else{
		                        if(event.type == SDL_KEYDOWN){
		                            if(event.key.keysym.sym == SDLK_RIGHT){
		                            	direction=1;
		                            	//posPlayer.x+=3;
		                            	//SDL_Delay(35);
		                            	rp=1;
		                            	i++;
		                            }
		                            if(event.key.keysym.sym == SDLK_LEFT){
		                            	direction=2;
		                            	//posPlayer.x-=3;
		                            	//SDL_Delay(35);
		                            	lp=1;
		                            	j++;}
		                      		if(event.key.keysym.sym == SDLK_UP){
		                      			jump=1;
		                      		}
		                        }
		                    	else if(event.type == SDL_KEYUP){
		                    		if(event.key.keysym.sym == SDLK_RIGHT){
		                    			
		                    			rp=0;
		                    		}
		                    		if(event.key.keysym.sym == SDLK_LEFT){
		                    			
		                    			lp=0;
		                    		}
		                    	}

		                    }

    		  
		        if((posPlayer.x > 400)&& rp==1){srcLevel.x +=7;}
		        if((posPlayer.x < 400)&& lp==1){srcLevel.x -=7;}
		        if(srcLevel.x <=0){srcLevel.x=0;}
		        if(posPlayer.x >=700){posPlayer.x=700;}
		        if(jump==1){posPlayer.y-=7;}
		        if(rp==1){posPlayer.x+=4;}
		        if(lp==1){posPlayer.x-=4;}
		        
		        
		        if(i>13){i=0;}
		        if(j>13){j=0;}
		        if(direction==1){
		        	hero=spriteR[i];
		        if(rp==0){hero=IdleR;}
		    	}
		        if(direction==2){
		        	hero=spriteL[j];
		        if(lp==0){hero=IdleL;}
		    	}
    		  	//printf("x=%d y=%d",posPlayer.x,posPlayer.y);
    		  	SDL_BlitSurface(level1clmap,&srcLevel,ecran,&posLevel);
   				SDL_BlitSurface(level1map,&srcLevel,ecran,&posLevel);
    		    SDL_BlitSurface(hero,NULL,ecran,&posPlayer);
    		    SDL_Flip(ecran);
    		    
    		    dt=SDL_GetTicks()-t_prev; //à la fin de la game loop
							if(1000/24 > dt)
								SDL_Delay(1000/60 - dt);


    		  }

    }
    	SDL_FreeSurface(level1map);
    	SDL_FreeSurface(level1clmap);
    	SDL_FreeSurface(hero);
    	for(i=0;i<14;i++){
    		SDL_FreeSurface(spriteR[i]);
    		SDL_FreeSurface(spriteL[i]);
    	}
    	SDL_FreeSurface(IdleR);
    	SDL_FreeSurface(IdleL);

return EXIT_SUCCESS;

}*/
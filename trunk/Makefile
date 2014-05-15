Chuck:main.o menu.o level1.o Hero.o BG.o collide.o
	gcc main.o menu.o level1.o Hero.o BG.o collide.o -lSDL -lSDL_image -lSDL_mixer -o Chuck -g
main.o:main.c 
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -g
menu.o:menu.c
	gcc -c menu.c -lSDL -lSDL_image -lSDL_mixer -g
level1.o:level1.c
	gcc -c level1.c -lSDL -lSDL_image -lSDL_mixer -g
Hero.o:Hero.c
	gcc -c Hero.c -lSDL -lSDL_image -lSDL_mixer -g
BG.o:BG.c
	gcc -c BG.c -lSDL -lSDL_image -lSDL_mixer -g
collide.o:collide.c
	gcc -c collide.c -lSDL -lSDL_image -lSDL_mixer -g
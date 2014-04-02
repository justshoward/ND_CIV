/////////////////////////////////////////
//FUND 2 Final Project
//
//prototpye.cpp
//Just trying to get a map to show up.
//
//Sean Howard and Nick Sayre
///////////////////////////////////////
//
//


#include "SDL/SDL.h"
#include "Map.h"
//#include "Piece.h"
//#include "Unit.h"
#include <iostream>

//Create SDL Event structure to be used
SDL_Event event;


int main(int argc, char*args[])
{

	Map test("tile_map.txt",30);
	test.applyMap(0,0);
	test.flipMap();

	int x_corner=0;
	int y_corner=0;

	int quit=0;

	while(quit!=1)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_KEYDOWN)
			{
				switch(event.key.keysym.sym)
				{
					case SDLK_UP:{
							if(x_corner>=5)
							{
								x_corner-=5;
							}
							} break;
					case SDLK_DOWN:{
							if(x_corner<=70)
							{
								x_corner+=5;
							}
							} break;
					case SDLK_RIGHT:{
							if(y_corner<=70)
							{
								 y_corner+=5;
							}
							} break;
					case SDLK_LEFT:{
							if(y_corner>=5)
							{
							 	y_corner-=5;
							}
							} break;
				}
			
			}
			//update the map
			test.applyMap(x_corner,y_corner);
			

			//Flip the map
			test.flipMap();
			
			//Quit on the pressing of the exit button
			if(event.type==SDL_QUIT)
			{
				quit=1;
			}
		
		}
	}
			
	return 0;
			
			

}











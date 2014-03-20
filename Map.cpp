//////////////////////////////////////////////////////
//FUND 2 Final Project
//
//Map.cpp Implementation of the map class
//
//Sean Howard and Nick Sayre
////////////////////////////////////////////////////////



#include "SDL/SDL.h"

#include "Map.h"
#include <vector>
#include <iostream>


using namespace std;

//Constructor taking the height and width of the board
Map::Map(int w, int h,int p):mapWidth(w),mapHeight(h),pixelsper(p)
{
	
	//Put the screen pointer to null
	screen=NULL;

	//Start up SDL subsystems, assign screen and caption
	initialize();
	
	//Go through each element of the map and instantiate
	//a Piece for the element
	for(int i=0; i<mapWidth; i++)
	{	//Add temporary Piece column vector
		vector<Piece*> tempcol;
		mapPiece.push_back(tempcol);
	}

	//Create Rect object dimesnsion so images will fit one square
	clip_dimensions.x=0;
	clip_dimensions.y=0;
	clip_dimensions.w=p;
	clip_dimensions.h=p;

}

//Prototype to get board functionality
void Map::grassMap()
{
	Piece grass("grass.png");
	Piece* ptrGrass=&grass;
	
	for(int i=0; i<mapWidth; i++)
	{
		for(int j=0; j<mapHeight; j++)
		{
			mapPiece[i].push_back(ptrGrass);
		}
	}
}

int Map::initialize()
{
	//Initialize all sdl subsystems
	if(SDL_Init(SDL_INIT_EVERYTHING)==-1)
	{
		return 0;
	}
	
	//Set the screen. The size of the screen is determined by the constructor variable
	//pixels per
	screen=SDL_SetVideoMode(mapWidth*pixelsper,mapHeight*pixelsper,32, SDL_SWSURFACE);

	if(screen==NULL)
	{
		return 0;
	}


	//Set the caption for the screen
	SDL_WM_SetCaption("ND_CIV prototype",NULL);

	return 1;
}





void Map::displayMap()
{
	for(int i=0; i<mapWidth; i++)
	{
		for(int j=0; j<mapHeight; j++)
		{
			apply_surface(i*pixelsper,j*pixelsper,(*(mapPiece[i][j])).getSurface(),screen,&clip_dimensions);
			SDL_Flip(screen);
		}
	}
	

	//apply_surface(0,0,(*(mapPiece[0][0])).getSurface(),screen,&clip_dimensions);
	SDL_Flip(screen);
	SDL_Delay(1000);

}

//Takes a coordinate on the screen and applies a surface to a destination. Takes a clip as an argument to 
//divide up a surface
void Map::apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect *clip=NULL)
{
	//Create a SDL_Rect object to work with the placing of the image
	SDL_Rect offset;

	offset.x=x;
	offset.y=y;

	SDL_BlitSurface(source, clip, destination,&offset);
}

void Map::clean_up()
{
	(*(mapPiece[0][0])).clean_Piece();
	SDL_Quit();
}
	
	















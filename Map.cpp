//////////////////////////////////////////////////////
//FUND 2 Final Project
//
//Map.cpp Implementation of the map class
//
//Sean Howard and Nick Sayre
////////////////////////////////////////////////////////


//The dimensions of square pieces applied to the map
#define SCREEN_DIM 25

#include "SDL/SDL.h"

#include "Map.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

//Constructor taking the height and width of the board
Map::Map(string filename , int p):pixelsper(p)
{
	
	//Put the screen pointer to null
	screen=NULL;

	get_dimensions("tile_map.txt",mapWidth,mapHeight);
	
	//Start up SDL subsystems, assign screen and caption
	initialize();

	load_text("tile_map.txt");	

	//Create Rect object dimesnsion so images will fit one square
	clip_dimensions.x=0;
	clip_dimensions.y=0;
	clip_dimensions.w=p;
	clip_dimensions.h=p;
	
	
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
	screen=SDL_SetVideoMode(SCREEN_DIM*pixelsper,SCREEN_DIM*pixelsper,32, SDL_SWSURFACE);

	if(screen==NULL)
	{
		return 0;
	}


	//Set the caption for the screen
	SDL_WM_SetCaption("ND_CIV prototype",NULL);

	return 1;
}



//Function to load a text file into a map
//Respective Pieces for the map are designated be a
//g for grass
//r for road
//c for dirt (cemetary)
//w for water
void Map::load_text(string filename)
{
	
	//Load the Piece's from image files, assign pointer, keep Piece object as private variable
	Piece grassload("grass.png");
        grass=grassload;
	Piece *ptrGrass;
        ptrGrass=&grass;

        Piece waterload("water.jpg");
        water=waterload;
	Piece *ptrWater;
        ptrWater=&water;

	Piece dirtload("Dirt.bmp");
	dirt=dirtload;
	Piece *ptrDirt;
	ptrDirt=&dirt;

	Piece roadload("road.jpg");
	road=roadload;
	Piece *ptrRoad;
	ptrRoad=&road;

	//Debugging the pointer values
	/*cout<<"water surface ptr:"<<water.getSurface()<<" grass prt:"<<grass.getSurface()<<endl;
	cout<<"water ptr:"<<ptrWater<<" grass ptr "<<ptrGrass<<endl;
	cout<<"road ptr:"<<ptrRoad<<endl;
	cout<<"Dirt ptr:"<<ptrDirt<<endl;*/	

	//Reading the text from the file to make a map
	ifstream maptext(filename.c_str());
        
	string buffer;
        if(maptext.is_open())
        {
                int row_num=0;
		//Read the text line by line
                while(getline(maptext,buffer))
                {
                        //Add a temporary vector to mapPiece to account for the new row
			vector<Piece*> tempvec;
			mapPiece.push_back(tempvec);

			int tile=0;
			//for each letter, add pointer associated to that letter
			for(int i=0; i<buffer.length(); i++)
                        {
				
                                if(buffer[tile]=='g')
                                {
                                        mapPiece[row_num].push_back(ptrGrass);
                                }
                                else if(buffer[tile]=='w')
                                {
                                        mapPiece[row_num].push_back(ptrWater);
                                }
                                else if(buffer[tile]=='r')
				{
					mapPiece[row_num].push_back(ptrRoad);
				}
				else if(buffer[tile]=='c')
				{
					mapPiece[row_num].push_back(ptrDirt);
				}
				tile++;
                        }
			row_num++;
                	        
		}
	}
	//Close ifstream object
	maptext.close();
}

//Get dimesnsions of mapPiece from txt file, assuming square map
void Map::get_dimensions(string filename,int &mapW,int &mapH)
{	
	//open the maptext file
	ifstream maptext(filename.c_str());

	//get the first line, since square map, that will give width and height
	string buffer;

	getline(maptext,buffer);
	
	mapW=buffer.length();

	mapH=mapW;

	maptext.close();
}



//Applies a 25x25 section of the map, allowing to move around map based upon the integer
//input
void Map::applyMap(int x_corner, int y_corner)
{
	if(x_corner>=0 && x_corner<=mapWidth-SCREEN_DIM && y_corner>= 0 && y_corner<=mapHeight-SCREEN_DIM)
	{
		for(int i=0; i<SCREEN_DIM; i++)
		{
			for(int j=0; j<SCREEN_DIM; j++)
			{
				apply_surface(i*pixelsper,j*pixelsper,(*(mapPiece[j+x_corner][i+y_corner])).getSurface(),screen,&clip_dimensions);
			}
		}
	}
}


void Map::flipMap()
{
	SDL_Flip(screen);
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
	
	















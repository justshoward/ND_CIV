////////////////////////////////////////////////////////////////
//Header for the Board Class to be used in the ND Civilization game
//
//FUND 2 Final Project 
//
//Sean Howard and Nick Sayre
/////////////////////////////////////////////////////////////////


#ifndef MAP_H
#define MAP_H

#include <vector>
#include "Piece.h"
#include "Unit.h"
#include "SDL/SDL.h"


using namespace std;
class Map
{

	public:
		//Constructor with inputs of Width and Height of Map
		Map(int,int,int);
		
		//Create a map of just grass
		void grassMap();
		
		//Display the map (pieces only at this point) onto the
		//screen
		void displayMap();

		//Free surfaces
		void clean_up();

	private:
		////////////////////////////////////////
		//VARIABLES
		//////////////////////////////////////
		//Store the dimensions of the Map,immuatable
		const int mapHeight, mapWidth, pixelsper;

		//2D vector to store various static units, i.e. buildings, grass, etc.
		//to be displayed to the screen. 
		vector<vector<Piece*> > mapPiece;

		//1D vector/list to store dynamic units, mainly the student class. Each unit will have position as
		//private variable
		vector<Unit*>  mapUnit;

		//Screen to be used for displaying
		SDL_Surface * screen;
		
		//Container for the various clips to be used;
		SDL_Rect clip_dimensions;

		/////////////////////////////////////////
		//FUNCTIONS
		////////////////////////////////////////
		
		//Function to apply an individual piece to the screen
		void apply_surface(int, int, SDL_Surface*, SDL_Surface*, SDL_Rect*);

		//Initialize all of the SDL_Environment
		int initialize();
};


#endif





















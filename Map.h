////////////////////////////////////////////////////////////////
//Header for the Board Class to be used in the ND Civilization game
//
//FUND 2 Final Project 
//
//Sean Howard and Nick Sayre
/////////////////////////////////////////////////////////////////


#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include "Piece.h"
#include "Unit.h"
#include "SDL/SDL.h"


using namespace std;
class Map
{

	public:
		//Constructor with inputs of Width and Height of Map
		Map(string,int);
		
		//Apply the pieces onto the screen
		void applyMap(int,int);
		
		//Flips the screen to the window
		void flipMap();

		//Free surfaces
		void clean_up();


	private:
		////////////////////////////////////////
		//VARIABLES
		//////////////////////////////////////
		//Store the dimensions of the Map,immuatable
		int mapHeight, mapWidth, pixelsper;

		//2D vector to store various static units, i.e. buildings, grass, etc.
		//to be displayed to the screen. 
		vector<vector<Piece*> > mapPiece;

		//1D vector/list to store dynamic units, mainly the student class. Each unit will have position as
		//private variable
		vector<Unit*>  mapUnit;

		//Piece's for the tile map to avoid a nasty copy constructor
		Piece grass;
		Piece water;
		Piece dirt;
		Piece road;		

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

		//Load file for the map
		void load_text(string);

		//Get dimensions of the map from the text file
		//Need to intialize screen, which is needed for 
		//loading images
		void get_dimensions(string,int&,int&);
	
};


#endif





















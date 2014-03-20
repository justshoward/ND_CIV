///////////////////////////////////////////
//FUND 2 FINAL Project
//
//Piece.h Header for the class of constant enviroment pieces to
//be used in the Map class
//
//Sean Howard and Nick Sayre
////////////////////////////////////////////


#ifndef PIECE_H
#define PIECE_H

#include <string>
#include "SDL/SDL.h"

class Piece
{
	public:
		//Default constructor to be used in the map
		//constructor
		Piece(std::string);

		//Accessor for the image of the piece
		SDL_Surface* getSurface();

		void clean_Piece();

	private:
		//Load the image to be used in the map
		SDL_Surface* load_image(std::string);

		//Type of piece to be used in prototypings
		SDL_Surface *pType;


};

#endif








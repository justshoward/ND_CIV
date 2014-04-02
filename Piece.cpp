///////////////////////////////////////
//Fund 2 Final Project
//
//Piece.cpp Implementation of a Piece class that will
//be the constant elements of the Map Board
//
//Sean Howard and Nick Sayre
////////////////////////////////////////


#include "Piece.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>

Piece::Piece(std::string filename)
{
	pType=NULL;
	pType=load_image(filename);
}

Piece::Piece()
{
	pType=NULL;
}

SDL_Surface* Piece::getSurface()
{
	return pType;
}

SDL_Surface* Piece::load_image(std::string filename)
{
	//Initialize the pointers to the initial load
	//and the final surface to be returned
	SDL_Surface * loaded_image=NULL;
	SDL_Surface * optimized_image=NULL;

	//load the image for the piece regardless of file
	//type
	loaded_image=IMG_Load(filename.c_str());
	
	if(loaded_image!=NULL)
	{
		//Optimize the loaded image
		optimized_image=SDL_DisplayFormat(loaded_image);

		//Free the initial surface pointer
		SDL_FreeSurface(loaded_image);

		//if SDL_DisplayFormat worked, color key the surface.
		if(optimized_image!=NULL)
		{
			SDL_SetColorKey( optimized_image, SDL_SRCCOLORKEY, SDL_MapRGB( optimized_image->format, 0, 0xFF, 0xFF ) );
		}
			
	}
	else
	{
		std::cout<<"Couldn't load image\n";
	}		
	if(optimized_image==NULL)
	{
		std::cout<<"Couldn't optimize image\n";
	}
	return optimized_image;
}

void Piece::clean_Piece()
{
	SDL_FreeSurface(pType);
}




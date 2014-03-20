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

#include "Map.h"
#include "Piece.h"
#include "Unit.h"
#include <iostream>

int main(int argc, char*args[])
{

	Map test(10,10,50);
	test.grassMap();
	test.displayMap();
	test.clean_up();
}











///////////////////////////////////////////
//Fund 2 Final Project
//
//Unit.h Header file for the Unit class, which will
//be the objects that can move around the map and
//interact with Pieces and other Units
//
//Sean Howard Nick Sayre
////////////////////////////////////////////


#ifndef UNIT_H
#define UNIT_H

class Unit
{
	//Overload of copy constructor for moving the Units around the board
	//Unit& operator=(const Unit&);
	
	public:
		//Default constructor to be used for prototyping
		Unit();
		//Necessary Copy constructor for when moving units
		Unit(const Unit&);	
		
		//Return prototype value
		char getType();

		//Set to prototype value to one different than initial
		void setType(char);

	private:
		//Private variable to be used for prototyping
		char uType;
};

#endif

















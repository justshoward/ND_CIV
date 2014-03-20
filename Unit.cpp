//////////////////////////////////////////
//Fund 2 Final Project
//
//Unit.cpp Implementation of the Unit class, 
//which will have a heirarchy of students that will
//be able to move around the map and do things. Eventually...
//
//Sean Howard and Nick Sayre
///////////////////////////////////////////


#include "Unit.h"

Unit::Unit()
{
	uType=' ';
}

Unit::Unit(const Unit &copyUnit)
{
	uType=copyUnit.uType;
}

/*Unit& Unit::operator=(const Unit &copyUnit)
{
	uType=copyUnit.uType;
}*/

char Unit::getType()
{
	return uType;
}

void Unit::setType(char newtype)
{
	uType=newtype;
}







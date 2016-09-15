/*
	Author:		Garry Griggs & Greg Hughes
	Date:		September 11th, 2016
	Project:	Reflex Agent
	Filename:	TileRec.h
	Purpose:	This file contains all the details regarding vBot's room down to each tile
*/

#ifndef TILEREC_H
#define TILEREC_H

// Details pertaining to each of the tiles in the room
struct TileDetails
{
	bool hasDirt;				// Predicates if a tile has dirt on location
	bool hasFurniture;			// Predicates if a tile has a furiture on location
	bool isGoal;				// Predicates if the location is a goal location
	bool isValid;				// Predicates if a location is valid
};

#endif // !TILEREC_H
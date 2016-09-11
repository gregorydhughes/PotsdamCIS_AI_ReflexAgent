/*
	Author:		Garry Griggs & Greg Hughes
	Date:		September 11th, 2016
	Project:	Reflex Agent
	Filename:	TileRec.h
	Purpose:	This file contains all the details regarding vBot's room down to each tile
*/

#ifndef TILEREC_H
#define TILEREC_H

const int MAX_ROOM_SIZE = 10;	// The Maximum size of the room
const int BORDER_SIZE = 1;		// The size of the border

// Details pertaining to each of the tiles in the room
struct TileDetails
{
	bool hasDirt;				// Predicates if a tile has dirt on location
	bool hasFurniture;			// Predicates if a tile has a furiture on location
	bool isGoal;				// Predicates if the location is a goal location
	bool isValid;				// Predicates if a location is valid
};

// The Maximum size of the room with borders
const int ROOM_SIZE_WITH_BORDERS = MAX_ROOM_SIZE + BORDER_SIZE + BORDER_SIZE;

// The Maximum room size as a record
typedef TileDetails RoomRec[ROOM_SIZE_WITH_BORDERS][ROOM_SIZE_WITH_BORDERS];

#endif // !TILEREC_H
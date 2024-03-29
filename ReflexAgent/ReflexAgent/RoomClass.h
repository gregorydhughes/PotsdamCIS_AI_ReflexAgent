/*
	Author:		Garry Griggs & Gregory Hughes
	Date:		9/11/2016
	Project:	ReflexAgent
	FileName:	RoomClass.h
	Purpose:	This file contains the definitions for the RoomClass Object
*/

#include "LocRec.h"
#include "TileRec.h"
#include "PerceptRec.h"
#include "ExceptionClass.h"
#include <string>

const int MAX_ROOM_SIZE = 10;	// The Maximum size of the room
const int BORDER_SIZE = 1;		// The size of the border
								
// The Maximum size of the room with borders
const int ROOM_SIZE_WITH_BORDERS = MAX_ROOM_SIZE + BORDER_SIZE + BORDER_SIZE;

class RoomClass
{
public:
	// DC - Default constuctor
	RoomClass();
	
	// NDC - Non-Default Constructor
	RoomClass(int size);

	// Returns the percepts to the vBot on location
	PerceptRec GetPercepts(LocRec loc);

	// vacuums a tile
	void CleanTile(LocRec loc);

	// Sets a tile's dirt value
	void SetDirtOnLocation(LocRec loc);

	// Sets a tile's furniture value
	void SetFurnitureOnLocation(LocRec loc);

	// Sets a tile's goal value
	void SetGoalOnLocation(LocRec loc);

	// Returns the size (length and width) of the room
	int GetRoomSize();

	std::string GetRoomString(LocRec currLoc, Direction dir);

private:
	// Fills the 2-d array of the room for both the DC and the NDC
	void BuildRoom(int size);

	// Returns a string representation of the northern and southern walls.
	std::string GetTopAndBottomWalls();
	
	// The Maximum room size as a record
	typedef TileDetails RoomRec[ROOM_SIZE_WITH_BORDERS][ROOM_SIZE_WITH_BORDERS];
	
	int roomSize;		// The lenght and width of the room
	RoomRec room;		// The room
};



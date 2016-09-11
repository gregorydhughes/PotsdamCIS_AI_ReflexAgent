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
#include <string>

class RoomClass
{
public:
	// DC
	RoomClass();
	
	// NDC
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

	std::string PrintRoom(LocRec currLoc);

private:
	// Fills the 2-d array of the room for both the DC and the NDC
	void BuildRoom(int size);

	
	int roomSize;		// The lenght and width of the room
	RoomRec room;		// The room
};



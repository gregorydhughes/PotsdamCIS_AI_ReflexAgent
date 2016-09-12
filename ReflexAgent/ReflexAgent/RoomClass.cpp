/*
	Author:		Garry Griggs & Gregory Hughes
	Date:		9/11/2016
	Project:	ReflexAgent
	FileName:	RoomClass.cpp
	Purpose:	This file contains the implementation for the RoomClass Object
*/

#include "RoomClass.h"
#include "ExceptionClass.h"

RoomClass::RoomClass()
{
	roomSize = MAX_ROOM_SIZE;
	BuildRoom(MAX_ROOM_SIZE);
}

RoomClass::RoomClass(int size)
{
	roomSize = size;
	BuildRoom(size);
}

void RoomClass::BuildRoom(int size)
{
	for (int i = 0; i < ROOM_SIZE_WITH_BORDERS; i++)
	{
		for (int j = 0; j < ROOM_SIZE_WITH_BORDERS; j++)
		{
			room[i][j].isValid = false;
			room[i][j].hasDirt = false;
			room[i][j].hasFurniture = false;
			room[i][j].isGoal = false;
		}
	}

	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			room[i][j].isValid = true;
		}
	}
}

PerceptRec RoomClass::GetPercepts(LocRec loc)
{
	PerceptRec ans;

	// Check Touch
	if (room[loc.x][loc.y].hasFurniture || !room[loc.x][loc.y].isValid)
		ans.touch = 1;
	else
		ans.touch = 0;

	// Check under
	if (room[loc.x][loc.y].hasDirt)
		ans.dUnder = 1;
	else
		ans.dUnder = 0;

	if (room[loc.x][loc.y].isGoal)
		ans.gUnder = 1;
	else
		ans.gUnder = 0;

	// Check front
	if (room[loc.x + 1][loc.y].hasDirt)
		ans.dNorth = 1;
	else
		ans.dNorth = 0;

	if (room[loc.x + 1][loc.y].isGoal)
		ans.dNorth = 1;
	else
		ans.dNorth = 0;

	// Check Back
	if (room[loc.x - 1][loc.y].hasDirt)
		ans.dSouth = 1;
	else
		ans.dSouth = 0;

	if (room[loc.x - 1][loc.y].isGoal)
		ans.gSouth = 1;
	else
		ans.gSouth = 0;

	// Check Left
	if (room[loc.x][loc.y - 1].hasDirt)
		ans.dWest = 1;
	else
		ans.dWest = 0;

	if (room[loc.x][loc.y - 1].isGoal)
		ans.gWest = 1;
	else
		ans.gWest = 0;

	// Check Right
	if (room[loc.x][loc.y + 1].hasDirt)
		ans.dEast = 1;
	else
		ans.dEast = 0;

	if (room[loc.x][loc.y + 1].isGoal)
		ans.gEast = 1;
	else
		ans.gEast = 0;

	return ans;
}

void RoomClass::CleanTile(LocRec loc)
{
	room[loc.x][loc.y].hasDirt = false;
}

void RoomClass::SetDirtOnLocation(LocRec loc)
{
	room[loc.x][loc.y].hasDirt = true;
}

void RoomClass::SetFurnitureOnLocation(LocRec loc)
{
	room[loc.x][loc.y].hasFurniture = true;
}

void RoomClass::SetGoalOnLocation(LocRec loc)
{
	room[loc.x][loc.y].isGoal = true;
}

int RoomClass::GetRoomSize()
{
	return roomSize;
}

std::string RoomClass::PrintRoom(LocRec currLoc, Direction dir)
{
	std::string ans = "";

	// Print top wall
	ans = ans + PrintFirstAndLastLines()+ "\n";

	for (int i = roomSize; i > 0; i--)
	{
		ans = ans + "|";

		for (int j = 1; j <= roomSize; j++)
		{
			if (room[i][j].hasDirt)
				ans = ans + "#";

			if (room[i][j].hasFurniture)
				ans = ans + "X";

			if (room[i][j].isGoal)
				ans = ans + "$";

			if (currLoc.x == i && currLoc.y == j)
			{
				switch (dir)
				{
				case NORTH:
					ans = ans + "^";
					break;
				case SOUTH:
					ans = ans + "v";
					break;
				case EAST:
					ans = ans + ">";
					break;
				case WEST:
					ans = ans + "<";
					break;
				default:
					ans = ans + "o";
					break;
				}
				
			}

			if (j != roomSize)
				ans = ans + " ";
		}

		ans = ans + "|\n";

		for (int j = 1; j <= roomSize; j++)
		{
			ans = ans + "+";

			if (j != roomSize)
				ans = ans + " ";
		}

		ans = ans + "\n";
	}

	// Print bottom wall
	ans = ans + PrintFirstAndLastLines() + "\n";

	return ans;
}

std::string RoomClass::PrintFirstAndLastLines()
{
	std::string ans = "";

	for (int i = 0; i < roomSize; i++)
		ans = ans + "+-";

	ans = ans + "+";

	return ans;
}
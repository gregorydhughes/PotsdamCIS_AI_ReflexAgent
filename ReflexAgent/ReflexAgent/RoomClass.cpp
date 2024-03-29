/*
	Author:		Garry Griggs & Gregory Hughes
	Date:		9/11/2016
	Project:	ReflexAgent
	FileName:	RoomClass.cpp
	Purpose:	This file contains the implementation for the RoomClass Object
*/

#include "RoomClass.h"


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
	if (room[loc.row][loc.col].hasFurniture || !room[loc.row][loc.col].isValid)
		ans.touch = 1;
	else
		ans.touch = 0;

	// Check under
	if (room[loc.row][loc.col].hasDirt)
		ans.dUnder = 1;
	else
		ans.dUnder = 0;

	if (room[loc.row][loc.col].isGoal)
		ans.gUnder = 1;
	else
		ans.gUnder = 0;

	// Check front
	if (room[loc.row + 1][loc.col].hasDirt)
		ans.dNorth = 1;
	else
		ans.dNorth = 0;

	if (room[loc.row + 1][loc.col].isGoal)
		ans.gNorth = 1;
	else
		ans.gNorth = 0;

	// Check Back
	if (room[loc.row - 1][loc.col].hasDirt)
		ans.dSouth = 1;
	else
		ans.dSouth = 0;

	if (room[loc.row - 1][loc.col].isGoal)
		ans.gSouth = 1;
	else
		ans.gSouth = 0;

	// Check Left
	if (room[loc.row][loc.col - 1].hasDirt)
		ans.dWest = 1;
	else
		ans.dWest = 0;

	if (room[loc.row][loc.col - 1].isGoal)
		ans.gWest = 1;
	else
		ans.gWest = 0;

	// Check Right
	if (room[loc.row][loc.col + 1].hasDirt)
		ans.dEast = 1;
	else
		ans.dEast = 0;

	if (room[loc.row][loc.col + 1].isGoal)
		ans.gEast = 1;
	else
		ans.gEast = 0;

	return ans;
}

void RoomClass::CleanTile(LocRec loc)
{
	room[loc.row][loc.col].hasDirt = false;
}

void RoomClass::SetDirtOnLocation(LocRec loc)
{
	room[loc.row][loc.col].hasDirt = true;
}

void RoomClass::SetFurnitureOnLocation(LocRec loc)
{
	room[loc.row][loc.col].hasFurniture = true;
}

void RoomClass::SetGoalOnLocation(LocRec loc)
{
	room[loc.row][loc.col].isGoal = true;
}

int RoomClass::GetRoomSize()
{
	return roomSize;
}

std::string RoomClass::GetRoomString(LocRec currLoc, Direction dir)
{
	std::string ans = "";

	// Print top wall
	ans += GetTopAndBottomWalls()+ "\n";

	for (int i = roomSize; i > 0; i--)
	{
		ans += "|";

		for (int j = 1; j <= roomSize; j++)
		{
			if (room[i][j].hasDirt)
				ans = ans + "#";

			else if (room[i][j].hasFurniture)
				ans = ans + "X";

			else if (room[i][j].isGoal)
				ans = ans + "$";

			else if (currLoc.row == i && currLoc.col == j)
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
			else
				ans = ans + " ";

			// add space after each
			if (j != roomSize)
				ans = ans + " ";
		}

		ans = ans + "|\n";

		if (i != 1)
		{
			for (int j = 0; j <= roomSize; j++)
			{
				ans = ans + "+";

				if (j != roomSize)
					ans = ans + " ";
			}

			ans = ans + "\n";
		}
	}

	// Print bottom wall
	ans = ans + GetTopAndBottomWalls() + "\n";

	return ans;
}

std::string RoomClass::GetTopAndBottomWalls()
{
	std::string ans = "";

	for (int i = 0; i < roomSize; i++)
		ans = ans + "+-";

	ans = ans + "+";

	return ans;
}
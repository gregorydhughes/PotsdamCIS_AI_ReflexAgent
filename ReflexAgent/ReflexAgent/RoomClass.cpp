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
	if (room[loc.x][loc.y].isValid) {
		
		PerceptRec ans;

		// Check Touch
		if (room[loc.x][loc.y].hasFurniture)
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
	else
		throw OutOfBoundsOfRoomException();
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
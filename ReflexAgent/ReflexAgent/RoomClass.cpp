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
			ans.dFront = 1;
		else
			ans.dFront = 0;

		if (room[loc.x + 1][loc.y].isGoal)
			ans.dFront = 1;
		else
			ans.dFront = 0;

		// Check Back
		if (room[loc.x - 1][loc.y].hasDirt)
			ans.dBack = 1;
		else
			ans.dBack = 0;

		if (room[loc.x - 1][loc.y].isGoal)
			ans.gBack = 1;
		else
			ans.gBack = 0;

		// Check Left
		if (room[loc.x][loc.y - 1].hasDirt)
			ans.dLeft = 1;
		else
			ans.dLeft = 0;

		if (room[loc.x][loc.y - 1].isGoal)
			ans.gLeft = 1;
		else
			ans.gLeft = 0;

		// Check Right
		if (room[loc.x][loc.y + 1].hasDirt)
			ans.dRight = 1;
		else
			ans.dRight = 0;

		if (room[loc.x][loc.y + 1].isGoal)
			ans.gRight = 1;
		else
			ans.gRight = 0;


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
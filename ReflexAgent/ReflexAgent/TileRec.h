#ifndef TILEREC_H
#define TILEREC_H

const int MAX_ROOM_SIZE = 10;

struct TileDetails
{
	bool hasDirt;
	bool hasFurniture;
	bool isGoal;
	bool isValid;
};

typedef TileDetails RoomRec[MAX_ROOM_SIZE][MAX_ROOM_SIZE];

#endif // !TILEREC_H
#ifndef TILEREC_H
#define TILEREC_H

const int MAX_ROOM_SIZE = 10;
const int BORDER_SIZE = 1;

struct TileDetails
{
	bool hasDirt;
	bool hasFurniture;
	bool isGoal;
	bool isValid;
};

const int ROOM_SIZE_WITH_BORDERS = MAX_ROOM_SIZE + BORDER_SIZE + BORDER_SIZE;

typedef TileDetails RoomRec[ROOM_SIZE_WITH_BORDERS][ROOM_SIZE_WITH_BORDERS];

#endif // !TILEREC_H
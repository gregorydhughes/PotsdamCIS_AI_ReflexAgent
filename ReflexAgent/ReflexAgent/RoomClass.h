#include "LocRec.h"
#include "TileRec.h"
#include "PerceptRec.h"

class RoomClass
{
public:
	RoomClass();
	
	RoomClass(int size);

	PerceptRec GetPercepts(LocRec loc);

	void CleanTile(LocRec loc);

	void SetDirtOnLocation(LocRec loc);

	void SetFurnitureOnLocation(LocRec loc);

	void SetGoalOnLocation(LocRec loc);

	int GetRoomSize();

private:
	void BuildRoom(int size);

	int roomSize;
	RoomRec room;
};



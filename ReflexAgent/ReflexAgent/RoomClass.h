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

private:
	RoomRec room;
};


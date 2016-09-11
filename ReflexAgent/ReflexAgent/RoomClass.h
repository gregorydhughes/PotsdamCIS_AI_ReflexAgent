#include "LocRec.h"
#include "TileRec.h"
#include "PerceptRec.h"

class RoomClass
{
public:
	RoomClass();
	
	PerceptRec GetPercepts(LocRec loc);

private:
	RoomRec room;
};



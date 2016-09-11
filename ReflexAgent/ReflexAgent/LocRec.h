#ifndef LOCREC_H
#define LOCREC_H

// establishes the direction of the vBot
enum Direction
{
	NORTH,		//
	SOUTH,
	EAST,
	WEST
};

// Structure to hold a 2-d location in room(2d array)
struct LocRec
{
	int x;		// X location in x-y plane
	int y;		// Y location in x-y plane
};

#endif // !LOCREC_H

/*
	Author:		Garry Griggs & Gregory Hughes
	Date:		9/11/2016
	Project:	ReflexAgent
	FileName:	LocRec.h
	Purpose:	This file contains the definitions for each of the locations and directions within the room
*/

#ifndef LOCREC_H
#define LOCREC_H

// establishes the direction of the vBot
enum Direction
{
	NORTH,		// vBot is looking North
	SOUTH,		// vBot is looking South
	EAST,		// vBot is looking East
	WEST		// vBot is looking West
};

// Structure to hold a 2-d location in room(2d array)
struct LocRec
{
	int row;		// Row location
	int col;		// Col location
};

#endif // !LOCREC_H

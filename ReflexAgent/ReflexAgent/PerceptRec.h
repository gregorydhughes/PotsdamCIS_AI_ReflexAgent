/*
	Author:		Garry Griggs & Gregory Hughes
	Date:		9/11/2016
	Project:	ReflexAgent
	FileName:	PerceptRec.h
	Purpose:	This file contains the definitions for all exceptions thrown by RoomClass
*/

#ifndef PERCEPTREC_H
#define PERCEPTREC_H

// Record to hold the percepts on a location
struct PerceptRec
{
	_int8 touch;		// Predicates if the agent has touched furniture, 1 if yes, 0 otherwise
	_int8 dUnder;		// Predicates if the agent is on top of dirt, 1 if yes, 0 otherwise
	_int8 dNorth;		// Predicates if the agent is south of dirt, 1 if yes, 0 otherwise
	_int8 dSouth;		// Predicates if the agent is norht of dirt, 1 if yes, 0 otherwise
	_int8 dWest;		// Predicates if the agent is east of dirt, 1 if yes, 0 otherwise
	_int8 dEast;		// Predicates if the agent is west of dirt, 1 if yes, 0 otherwise
	_int8 gUnder;		// Predicates if the agent in on top of the goal tile, 1 if yes, 0 otherwise
	_int8 gNorth;		// Predicates if the agent is south of the goal tile, 1 if yes, 0 otherwise
	_int8 gSouth;		// Predicates if the agent is in north of the goal, 1 if yes, 0 otherwise
	_int8 gWest;		// Predicates if the agent is east of the goal, 1 if yes, 0 otherwise
	_int8 gEast;		// Predicates if the agent is west of the goal, 1 if yes, 0 otherwise
};

#endif // !PERCEPTREC_H

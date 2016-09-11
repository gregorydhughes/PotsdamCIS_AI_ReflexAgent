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
	/// <summary>Predicates if the agent has touched furniture, 1 if yes, 0 otherwise</summary>
	_int8 touch;

	/// <summary>Predicates if the agent has touched furniture, 1 if yes, 0 otherwise</summary>
	_int8 dUnder;		// Predicates if the agent is on top of dirt, 1 if yes, 0 otherwise

	/// <summary>Predicates if the agent has touched furniture, 1 if yes, 0 otherwise</summary>
	_int8 dFront;		// Predicates if the agent is behind dirt, 1 if yes, 0 otherwise

	/// <summary>Predicates if the agent has touched furniture, 1 if yes, 0 otherwise</summary>
	_int8 dBack;		// Predicates if the agent is in front of dirt, 1 if yes, 0 otherwise

	/// <summary>Predicates if the agent has touched furniture, 1 if yes, 0 otherwise</summary>
	_int8 dLeft;		// Predicates if the agent is to the right of dirt, 1 if yes, 0 otherwise
	_int8 dRight;		// Predicates if the agent is to the left of dirt, 1 if yes, 0 otherwise
	_int8 gUnder;		// Predicates if the agent in on top of the goal tile, 1 if yes, 0 otherwise
	_int8 gFront;		// Predicates if the agent is behind the goal tile, 1 if yes, 0 otherwise
	_int8 gBack;		// Predicates if the agent is in front of the goal, 1 if yes, 0 otherwise
	_int8 gLeft;		// Predicates if the agent is to the right of the goal, 1 if yes, 0 otherwise
	_int8 gRight;		// Predicates if the agent is to the left of the goal, 1 if yes, 0 otherwise
};

#endif // !PERCEPTREC_H

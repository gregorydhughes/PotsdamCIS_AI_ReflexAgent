/*
	Author:		Garry Griggs & Gregory Hughes 
	Date:		9/11/2016
	Project:	ReflexAgent
	FileName:	ExceptionClass.h
	Purpose:	This file contains the definitions for all exceptions thrown by RoomClass
*/

// Thrown when there is an attempt to move outside the bounds of room
class OutOfBoundsOfRoomException {};

// Thrown in client for default case in switch, 
//		which will never happen, being that they are switching on an enumerated type
class IllegalArgumentException {};
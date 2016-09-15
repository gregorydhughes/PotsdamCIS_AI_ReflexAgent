/*
	Author:		Garry Griggs & Gregory Hughes
	Date:		9/11/2016
	Project:	ReflexAgent
	FileName:	RoomClass.cpp
	Purpose:	This file contains the implementation for the RoomClass Object
*/

#include <iostream>
#include <fstream>
#include "RoomClass.h" 

using namespace std;

// Enum for agent actions
enum Action {
	GOFORWARD,
	TURNRIGHT90,
	TURNLEFT90,
	VACUUMUPDIRT,
	TURNOFF
};

// Parameters: &rc - room object to be constructed and filled
//             with stuff
// Post-Condition: Builds room for agent to explore and clean
void buildRoom(RoomClass &rc);

// Parameters: shiftRec - current percepts based on location
// Returns: curAct - the current action to do based on percepts
Action getCurrentAction(PerceptRec shiftRec);

// Parameters: temper - the cardinal percepts before shifting
//                dir - the direction agent is facing
// Returns:  shiftRec - the percepts after shifting
PerceptRec shiftPercepts(PerceptRec temper, Direction dir);

// Parameters:   cur - the current location of the bot
//               dir - the direction agent is facing
// Returns:    north - the square agent moves to
LocRec getNorth(LocRec cur, Direction dir);

int main() {
	// Initialize room object
	RoomClass rc;
	buildRoom(rc);
	srand(1);

	// Set continue conditions
	int moves = rc.GetRoomSize() * rc.GetRoomSize() * 10;
	bool goal = false;

	int points = 0;

	// Set start location
	LocRec currentLocation;
	currentLocation.x = 1;
	currentLocation.y = 1;

	Direction dir = NORTH;
	
	// Clean room
	while (moves > 0 && !goal) {
		PerceptRec shiftRec = shiftPercepts(rc.GetPercepts(currentLocation), dir);
		Action curAction = getCurrentAction(shiftRec);
		switch (curAction) {
		case GOFORWARD:
			currentLocation = getNorth(currentLocation, dir);			
			break;
		case TURNRIGHT90:
			switch (dir) {
			case NORTH:
				dir = EAST;
				break;
			case SOUTH:
				dir = WEST;
				break;
			case EAST:
				dir = SOUTH;
				break;
			case WEST:
				dir = NORTH;
				break;
			default:
				break;
			}
			break;
		case TURNLEFT90:
			switch (dir) {
			case NORTH:
				dir = WEST;
				break;
			case SOUTH:
				dir = EAST;
				break;
			case EAST:
				dir = NORTH;
				break;
			case WEST:
				dir = SOUTH;
				break;
			default:
				break;
			}
			break;
		case VACUUMUPDIRT:
			rc.CleanTile(currentLocation);
			points += 100;
			break;
		case TURNOFF:
			if (shiftRec.gUnder == 0)
				points -= 1000;
			else
				goal = !goal;
			break;
		default:
			break;
		}
		for (int i = 0; i < 1000000000; i++);
		cout << rc.GetRoomString(currentLocation, dir) << endl;
		points--;
		moves--;
	}

	if (goal)
	{		
		cout << "Congrats you made the goal!\n Total Points: " << points << endl;
	}
	else
	{		
		cout << "Sorry, you didn't make the goal.\n Total Points: " << points << endl;
	}

	
	///////////////////////////////////////////////////////////////////////////////////////
	//                    This line must be deleted before submission!                   //
	///////////////////////////////////////////////////////////////////////////////////////
	system("pause");

	return 0;
}


// Parameters:   cur - the current location of the bot
//               dir - the direction agent is facing
// Returns:    north - the square agent moves to
LocRec getNorth(LocRec cur, Direction dir) {
	LocRec north;
	switch (dir) {
	case NORTH:
		// Set north coord
		north.x = cur.x;
		north.y = cur.y + 1;
		break;
	case SOUTH:
		// Set north coord
		north.x = cur.x;
		north.y = cur.y - 1;
		break;
	case EAST:
		// Set north coord
		north.x = cur.x + 1;
		north.y = cur.y;
		break;
	case WEST:
		// Set north coord
		north.x = cur.x - 1;
		north.y = cur.y;
		break;
	default:
		break;
	}
	return north;
}

// Parameters: prec - current percepts based on location
// Returns: the current action to do based on percepts
Action getCurrentAction(PerceptRec shiftRec) {

	cout << "Touch: " << shiftRec.touch << endl;
	cout << "dUnder: " << shiftRec.dUnder << endl;
	cout << "dNorth: " << shiftRec.dNorth << endl;
	cout << "dSouth: " << shiftRec.dSouth << endl;
	cout << "dEast: " << shiftRec.dEast << endl;
	cout << "dWest: " << shiftRec.dWest << endl;
	cout << "gUnder: " << shiftRec.gUnder << endl;
	cout << "gNorth: " << shiftRec.gNorth << endl;
	cout << "gSouth: " << shiftRec.gSouth << endl;
	cout << "gWest: " << shiftRec.dWest << endl;
	cout << "gEast: " << shiftRec.gEast << endl;
	
	if (shiftRec.touch == 1) {
		if (rand() & 1)
			return TURNLEFT90;
		else
			return TURNRIGHT90;
	}		
	if (shiftRec.dUnder == 1)
		return VACUUMUPDIRT;
	if (shiftRec.dNorth == 1)
		return GOFORWARD;
	if (shiftRec.dSouth == 1)
		return TURNRIGHT90;
	if (shiftRec.dWest == 1)
		return TURNLEFT90;
	if (shiftRec.dEast == 1)
		return TURNRIGHT90;	
	if (shiftRec.gUnder == 1)
		return TURNOFF;
	if (shiftRec.gNorth == 1)
		return GOFORWARD;
	if (shiftRec.gSouth == 1)
		return TURNRIGHT90;
	if (shiftRec.gWest == 1)
		return TURNLEFT90;
	if (shiftRec.gEast == 1)
		return TURNRIGHT90;

	if (rand() % 3 == 0)
		return TURNLEFT90;
	else if (rand() % 3 == 1)
		return TURNRIGHT90;
	else
		return GOFORWARD;

}

// Parameters: temper - the cardinal percepts before shifting
//                dir - the direction agent is facing
// Returns:  shiftRec - the percepts after shifting
PerceptRec shiftPercepts(PerceptRec temper, Direction dir) {
	PerceptRec shiftRec;
	shiftRec.dUnder = temper.dUnder;
	shiftRec.gUnder = temper.gUnder;
	shiftRec.touch = temper.touch;
	switch (dir) {
	case NORTH:
		shiftRec = temper;
		break;
	case SOUTH:
		// Swap front and back values
		shiftRec.dNorth = temper.dSouth;
		shiftRec.dSouth = temper.dNorth;
		shiftRec.dEast = temper.dWest;
		shiftRec.dWest = temper.dEast;
		// Assign left and right values the same
		shiftRec.gNorth = temper.gSouth;
		shiftRec.gSouth = temper.gNorth;
		shiftRec.gEast = temper.gWest;
		shiftRec.gWest = temper.gEast;
		break;
	case EAST:
		// Swap front and back values
		shiftRec.dNorth = temper.dEast;
		shiftRec.dSouth = temper.dWest;
		shiftRec.dEast = temper.dSouth;
		shiftRec.dWest = temper.dNorth;
		// Assign left and right values the same
		shiftRec.gNorth = temper.gEast;
		shiftRec.gSouth = temper.gWest;
		shiftRec.gEast = temper.gSouth;
		shiftRec.gWest = temper.gNorth;
		break;
	case WEST:
		// Swap front and back values
		shiftRec.dNorth = temper.dWest;
		shiftRec.dSouth = temper.dEast;
		shiftRec.dEast = temper.dNorth;
		shiftRec.dWest = temper.dSouth;
		// Assign left and right values the same
		shiftRec.gNorth = temper.gWest;
		shiftRec.gSouth = temper.gEast;
		shiftRec.gEast = temper.gNorth;
		shiftRec.gWest = temper.gSouth;
		break;
	default:
		break;
	}
	return shiftRec;
}

// Parameters: &rc - room object to be constructed and filled
//             with stuff
// Post-Condition: Builds room for agent to explore and clean
void buildRoom(RoomClass &rc) {
	// Read in from file
	cout << "Please enter file name: or not..." << endl;
	string file = "input1.txt";
	//cin >> file;
	ifstream fin;
	fin.open(file.c_str());

	// Set values from file;
	int n, numberOfFurniture, numberOfDirtPiles;
	fin >> n >> numberOfFurniture >> numberOfDirtPiles;

	// Build room
	rc = RoomClass(n);

	// Set goal
	LocRec goal;
	fin >> goal.x >> goal.y;
	rc.SetGoalOnLocation(goal);

	// Place furniture
	for (int i = 0; i < numberOfFurniture; i++) {
		LocRec temp;
		fin >> temp.x >> temp.y;
		
		// Array is one based
		temp.x += 1;
		temp.y += 1;
		
		rc.SetFurnitureOnLocation(temp);
	}

	// Place dirt
	for (int i = 0; i < numberOfDirtPiles; i++) {
		LocRec temp;
		fin >> temp.x >> temp.y;

		// Array is one based
		temp.x += 1;
		temp.y += 1;

		rc.SetDirtOnLocation(temp);
	}
}
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                                   //
//                                                             Begin Prototypes                                                      //
//                                                                                                                                   //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

string ActionEnumToString(/*in*/Action act);

// Pre:		The actions, score and percepts of the vBot have been determined for each Time slice.
// Post:	The actions, socre and percepts for each Time slice are printed to a file.
void PrintOutputFile(/*in/out*/ofstream &fout,				// File stream to write to
						/*in*/int t,						// Time
						/*in*/PerceptRec pr,				// Percepts at Time
						/*in*/Action act,					// Action at Time
						/*in*/int score);					// Score at Time

// Pre:		An Action Enumerated type is determined
// Post:	A string representation of the Action Enum type is returned to caller
string ActionEnumToString(/*in*/Action act);				// Enum action to convert

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                                   //
//                                                           Begin vBot and Main                                                     //
//                                                                                                                                   //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	// Initialize room object
	RoomClass rc;
	buildRoom(rc);
	srand(1);

	// Set continue conditions
	int maxMoves = rc.GetRoomSize() * rc.GetRoomSize() * 10;
	int currTime = 0;
	bool goal = false;

	int points = 0;

	// Set start location
	LocRec currentLocation;
	currentLocation.row = 1;
	currentLocation.col = 1;

	LocRec prevLocation = currentLocation;

	Direction dir = NORTH;

	string fileOut = "prog1_log.txt";

	ofstream fout;

	fout.open(fileOut.c_str());
	
	// Clean room
	while (currTime < maxMoves && !goal) {
		// Get the current percept records and then shift for direction
		PerceptRec shiftRec = shiftPercepts(rc.GetPercepts(currentLocation), dir);

		// Select best action based on percept recs
		Action curAction = getCurrentAction(shiftRec);

		// check for furniture bumbs if so move to prev location
		if (shiftRec.touch == 1) {
			cout << rc.GetRoomString(currentLocation, dir) << endl;
			currentLocation = prevLocation;
			continue;
		} else
			cout << rc.GetRoomString(currentLocation, dir) << endl;

		// Perform best action selected
		switch (curAction) {
		case GOFORWARD:
			prevLocation = currentLocation;
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
		
		if (currTime == 0)
			PrintOutputFile(fout, currTime, shiftRec, curAction, points);
		
		// Decrement points and increment current time
		points--;
		currTime++;

		PrintOutputFile(fout, currTime, shiftRec, curAction, points);

	}

	if (goal)
	{		
		cout << "Congrats you made the goal!\n Total Points: " << points << endl;
	}
	else
	{
		// not on goal penalty
		points -= 1000;

		// print regrets
		cout << "Sorry, you didn't make the goal.\n Total Points: " << points << endl;
	}

	// Close the streams
	fout.close();

	return 0;
}


// Parameters:   cur - the current location of the bot
//               dir - the direction agent is facing
// Returns:    north - the square the agent will move to
LocRec getNorth(LocRec cur, Direction dir) {
	LocRec north;
	switch (dir) {
	case NORTH:
		// Set north coord
		north.row = cur.row + 1;
		north.col = cur.col;
		break;
	case SOUTH:
		// Set north coord
		north.row = cur.row - 1;
		north.col = cur.col;
		break;
	case EAST:
		// Set north coord
		north.row = cur.row;
		north.col = cur.col + 1;
		break;
	case WEST:
		// Set north coord
		north.row = cur.row;
		north.col = cur.col - 1;
		break;
	default:
		break;
	}
	return north;
}

// Parameters: prec - current percepts based on location
// Returns: the current action to do based on percepts
Action getCurrentAction(PerceptRec shiftRec) {

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
// Post-Condition: builds a PerceptRec based on the direction of agent
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
	fin >> goal.row >> goal.col;
	rc.SetGoalOnLocation(goal);

	// Place furniture
	for (int i = 0; i < numberOfFurniture; i++) {
		LocRec temp;
		fin >> temp.row >> temp.col;
		
		// Array is one based
		temp.row += 1;
		temp.col += 1;
		
		rc.SetFurnitureOnLocation(temp);
	}

	// Place dirt
	for (int i = 0; i < numberOfDirtPiles; i++) {
		LocRec temp;
		fin >> temp.row >> temp.col;

		// Array is one based
		temp.row += 1;
		temp.col += 1;

		rc.SetDirtOnLocation(temp);
	}

	fin.close();
}

// Pre:		The actions, score and percepts of the vBot have been determined for each Time slice.
// Post:	The actions, socre and percepts for each Time slice are printed to a file.
void PrintOutputFile(/*in/out*/ofstream &fout,				// File Stream to write to
						/*in*/int t,						// Time
						/*in*/PerceptRec pr,				// Percepts at Time
						/*in*/Action act,					// Action at Time
						/*in*/int score)					// Score at Time
{
	string actionStr = ActionEnumToString(act);

	if (t == 0)
	{
		fout << "Time\t<B Du Df Db Dr Dl Gu Gf Gb Gr Gl>\t\tAction\tScore" << endl;
		fout << "----\t---------------------------------\t\t------\t-----" << endl;

		actionStr = "N/A";
	}

	fout << t << "\t< " << pr.touch << "  " << pr.dUnder << "  " << pr.dNorth << "  " << pr.dSouth << "  " << pr.dWest << "  "
		<< pr.dEast << "  " << pr.gUnder << "  " << pr.gNorth << "  " << pr.gSouth << "  " << pr.gWest << "  " << pr.gEast << " >\t"
		<< "\t" << actionStr << "\t" << score << endl;

}

// Pre:		An Action Enumerated type is determined
// Post:	A string representation of the Action Enum type is returned to caller
string ActionEnumToString(/*in*/Action act)				// Enum action to convert
{
	switch (act)
	{
	case GOFORWARD:
		return "Go forward";
		break;
	case TURNRIGHT90:
		return "Turn Right";
		break;
	case TURNLEFT90:
		return "Turn Left";
		break;
	case VACUUMUPDIRT:
		return "Vacuum Tile";
		break;
	case TURNOFF:
		return "Turn Off";
		break;
	default:
		throw NoApplicableStringException();
		break;
	}
}
#include <iostream>
#include <fstream>
#include <string>
#include "RoomClass.h" 

using namespace std;

// Parameters: &rc - room object to be constructed and filled
//             with stuff
// Post-Condition: Builds room for agent to explore and clean
void buildRoom(RoomClass &rc);

int main() {
	// Initialize room object
	RoomClass rc;
	buildRoom(rc);

	// Set continue conditions
	int moves = rc.getRoomSize() * rc.getRoomSize();
	bool goal = false;

	// Set start location
	LocRec currentLocation;
	currentLocation.x = 0;
	currentLocation.y = 0;

	Direction dir = NORTH;

	// Clean room
	while (moves > 0 && !goal) {
		PerceptRec tempRec = rc.GetPercepts(currentLocation);
		

		moves--;
	}
}

// Parameters: &rc - room object to be constructed and filled
//             with stuff
// Post-Condition: Builds room for agent to explore and clean
void buildRoom(RoomClass &rc) {
	// Read in from file
	cout << "Please enter file name: " << endl;
	string file;
	cin >> file;
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
		rc.SetFurnitureOnLocation(temp);
	}

	// Place dirt
	for (int i = 0; i < numberOfDirtPiles; i++) {
		LocRec temp;
		fin >> temp.x >> temp.y;
		rc.SetDirtOnLocation(temp);
	}
}
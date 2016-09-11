#include <iostream>
#include <fstream>
#include <string>
#include "RoomClass.h" 

using namespace std;

// Post-Condition: Builds room for agent to explore and clean
void buildRoom() {
	buildRoom();
	cout << "Please enter file name: " << endl;
	string file;
	cin >> file;
	ifstream fin;
	fin.open(file.c_str());

	int n, numberOfFurniture, numberOfDirtPiles;
	fin >> n >> numberOfFurniture >> numberOfDirtPiles;
	LocRec goal;
	fin >> goal.x >> goal.y;

	RoomClass rc(n);

	for (int i = 0; i < numberOfFurniture; i++) {
		LocRec temp;
		fin >> temp.x >> temp.y;
		rc.SetFurnitureOnLocation(temp);
	}

	for (int i = 0; i < numberOfDirtPiles; i++) {
		LocRec temp;
		fin >> temp.x >> temp.y;
		rc.SetDirtOnLocation(temp);
	}
}

int main() {

	

	while (moves > 0 && !goal) {
		
	}
}
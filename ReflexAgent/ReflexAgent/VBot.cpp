#include <string>
using namespace std;

class VBot {
	
	bool bumper = false;
	                 // Du, Df, Db, Dl, Dr, Gu, Gf, Gb, Gl, Gr.
	int percepts[11] = {0,  0,  0,  0,  0,  0,  0,  0,  0,  0};

public:
	VBot() {}

	void GetPecepts() {
		checkUnder();
		checkFront();
		checkBehind();
		checkLeft();
		checkRight();
	}

	void checkUnder() {
		if ()
	}




};
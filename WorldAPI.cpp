#include "WorldAPI.h"

#include <iostream>
#include <string>

using namespace std;
/*
WorldAPI::WorldAPI() {
	cout << "Initializing World API " << endl;
}

WorldAPI::~WorldAPI() {
	cout << "Destructing World API " << endl;
}
*/

void WorldAPI::createObject(int object) {
	cout << "Created object: " + to_string(object) << endl;
}

int WorldAPI::createPlayer(int player) {
	cout << "Created player: " + to_string(player) << endl;
	return player + 1;
}
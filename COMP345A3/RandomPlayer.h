#pragma once
#include "Strategy.h"

class RandomPlayer : public Strategy {
public:
	void powerHouses(std::string color, std::vector<City*> owned) {
		using namespace std;

		vector<City*> citiesToPower = vector<City*>();

		for (City* c : owned) {
			// Random [0 , 1]
			int random = rand() % 2;
			
			// 50% of the time power city
			if (random == 1) {
				citiesToPower.push_back(c);
			}
			
		}

		if (!citiesToPower.empty()) {
			for (City* c : citiesToPower) {
				cout << "Powering " << c->getName() << endl;
			}
		}
		else {
			cout << "Nothing powered" << endl;
		}
		
	}
};
#pragma once
#include "Strategy.h"

class DefencivePlayer : public Strategy {
public:
	// Only power cities with no adjacent players
	void powerHouses(std::string color, std::vector<City*> owned) {
		using namespace std;

		vector<City*> citiesToPower = vector<City*>();

		// Check all owned cities
		for (City* c : owned) {
			bool hasAdjOpp = false;

			// Check all connections for that city
			for (pair<City*, int> conn : c->getConnections()) {

				// Check all owners
				for (string s : conn.first->getOwners()) {
					// Not same owner
					if (s.compare(color) != 0) {
						hasAdjOpp = true;
					}
				}
			}

			if (!hasAdjOpp) {
				// list doesnt already contain value
				if (std::find(citiesToPower.begin(), citiesToPower.end(), c) == citiesToPower.end()) {
					citiesToPower.push_back(c);
				}
			}
		}

		for (City* c : citiesToPower) {
			cout << "Powering " << c->getName() << endl;
		}
	}
};

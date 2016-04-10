#include "stdafx.h"
#include "City.h"


City::City(std::string name)
{
	this->name = name;
}

void City::addConnection(City* city, int price) {
	connections.insert(std::pair<City*, int>(city, price));
}

const std::string City::getName() {
	return name;
}

std::map<City*, int> City::getConnections() {
	return connections;
}

int City::getPrice() {
	if (owners.empty()) {
		return 10;
	}
	else {
		if (owners.size() == 1) {
			return 15;
		}
		else {
			if (owners.size() == 2) {
				return 20;
			}
			else {
				return -1;
			}
		}
	}
}

void City::addOwner(std::string color) {
	owners.push_back(color);
}

std::vector<std::string> City::getOwners() {
	return owners;
}
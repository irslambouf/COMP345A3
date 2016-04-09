#include "stdafx.h"
#include "City.h"


City::City(std::string name)
{
	this->name = name;
}

void City::addConnection(Connection* connection) {
	connections.push_back(connection);
}

const std::string City::getName() {
	return name;
}

std::vector<Connection*> City::getConnections() {
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
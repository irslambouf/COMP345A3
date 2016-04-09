#pragma once
#include <string>
#include <vector>
#include "Connection.h"

class City
{
public:
	City(std::string name);
	void addConnection(Connection* connection);
	const std::string getName();
	std::vector<Connection*> getConnections();
	int getPrice();
	void addOwner(std::string color);
private:
	std::string name;
	std::vector<Connection*> connections;
	std::vector<std::string> owners;
};


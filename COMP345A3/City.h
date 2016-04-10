#pragma once
#include <string>
#include <vector>
#include <map>

class City
{
public:
	City(std::string name);
	void addConnection(City* city, int price);
	const std::string getName();
	std::map<City* , int> getConnections();
	int getPrice();
	void addOwner(std::string color);
	std::vector<std::string> getOwners();
private:
	std::string name;
	std::map<City*, int> connections;
	std::vector<std::string> owners;
};


#pragma once
#include <string>
#include <vector>
#include "City.h"
#include "Strategy.h"

// Player class with specific strategy
class Player
{
public:
	Player(std::string color);
	const int getElectro();
	const int getCoal();
	const int getOil();
	const int getUranium();
	const int getGarbadge();
	const std::string getColor();
	std::vector<City*> getOwned();
	void buyCity(City* city);
	void showPlayer();
	void powerCity(City* city);
	void setStrategy(Strategy* strategy);
	void executeStrategy();
private:
	std::string color;
	int electro;
	int coal;
	int oil;
	int uranium;
	int garbadge;
	std::vector<City*> owned;
	Strategy* strategy;
};


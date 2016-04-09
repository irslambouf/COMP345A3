#pragma once
#include <string>
#include <vector>
#include "City.h"

class Player
{
public:
	Player(std::string color);
	const int getElectro();
	const int getCoal();
	const int getOil();
	const int getUranium();
	const int getGarbadge();
	std::vector<City*> getOwned();
	void buyCity(City* city);
	void showPlayer();
private:
	std::string color;
	int electro;
	int coal;
	int oil;
	int uranium;
	int garbadge;
	std::vector<City*> owned;
};


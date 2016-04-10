#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "City.h"

// Abstract interface
class Strategy
{
public:
	virtual void powerHouses(std::string color, std::vector<City*> owned) = 0 {};
};


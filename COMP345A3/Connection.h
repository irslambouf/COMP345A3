#pragma once
#include <string>

class Connection
{
public:
	Connection(std::string cityName, int price);
	const int getPrice();
	const std::string getCityName();
private:
	int price;
	std::string cityName;
};


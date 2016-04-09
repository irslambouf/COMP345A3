#include "stdafx.h"
#include "Connection.h"


Connection::Connection(std::string cityName, int price)
{
	this->cityName = cityName;
	this->price = price;
}

const int Connection::getPrice() {
	return price;
}

const std::string Connection::getCityName() {
	return cityName;
}


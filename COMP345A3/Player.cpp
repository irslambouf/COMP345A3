#include "stdafx.h"
#include "Player.h"
#include <iostream>

Player::Player(std::string color)
{
	this->color = color;
	coal = 0;
	oil = 0;
	uranium = 0;
	garbadge = 0;
	electro = 50;
}

const int Player::getCoal() {
	return coal;
}

const int Player::getOil() {
	return oil;
}

const int Player::getElectro() {
	return electro;
}

const int Player::getUranium() {
	return uranium;
}

const int Player::getGarbadge() {
	return garbadge;
}

std::vector<City*> Player::getOwned() {
	return owned;
}

void Player::buyCity(City* city) {
	std::cout << color << " - trying to purchase " << city->getName() << std::endl;

	int cityPrice = city->getPrice();

	// City is not full
	if (cityPrice > 0) {
		if (owned.size() != 0) {
			int connectionPrice = -1;

			// Check if connection between owned and new city
			for (City* c : owned) {
				for (std::pair<City*, int> conn: c->getConnections()) {
					// Connection end is same as city name
					if (conn.first->getName().compare(city->getName()) == 0) {
						connectionPrice = conn.second;
					}
				}
			}

			// Connection exists
			if (connectionPrice > 0) {
				int totalPrice = connectionPrice + cityPrice;

				if (totalPrice <= electro) {
					owned.push_back(city);
					city->addOwner(color);
					electro -= totalPrice;

					std::cout << "Purchase successfull - " << totalPrice << std::endl;
				}
				else {
					std::cout << "Not enough electro to purchase this city | electro=" << electro << ", total cost=" << totalPrice << std::endl;
				}


			}
			else {
				std::cout << "Cant find connection to desired city, please try again" << std::endl;
			}
		}
		else {
			if (electro >= cityPrice) {
				owned.push_back(city);
				city->addOwner(color);
				electro -= cityPrice;

				std::cout << "Purchase successfull - " << cityPrice << std::endl;
			}
			else {
				std::cout << "Not enough electro to purchase this city | electro=" << electro << ", city cost=" << cityPrice << std::endl;
			}
		}
		

	}
	else {
		std::cout << city->getName() << " is full, cant purchase" << std::endl;
	}
}

void Player::showPlayer() {
	using namespace std;

	cout << endl << "Player: " << color << endl;
	cout << "Coal: " << coal << endl;
	cout << "Uranium " << uranium << endl;
	cout << "Oil " << oil << endl;
	cout << "Garbadge: " << garbadge << endl;
	cout << "Electro: " << electro << endl;
	cout << "--Cities owned--" << endl;
	for (City* c : getOwned()) {
		cout << " - " << c->getName() << endl;
	}
	cout << endl;
}

const std::string Player::getColor() {
	return color;
}

void Player::powerCity(City* city) {
	using namespace std;

	cout << "Powering " << city->getName() << endl;
}

void Player::setStrategy(Strategy* strategy) {
	this->strategy = strategy;
}

void Player::executeStrategy() {
	strategy->powerHouses(color, owned);
}
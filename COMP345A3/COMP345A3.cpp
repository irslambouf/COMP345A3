// COMP345A3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Player.h"
#include "AgressivePlayer.h"
#include "DefencivePlayer.h"
#include "RandomPlayer.h"

int main()
{
	// Setup players
	Player* yellow = new Player("yellow");
	Player* green = new Player("Green");
	Player* red = new Player("Red");

	// Set strategies
	yellow->setStrategy(new AgressivePlayer());
	green->setStrategy(new DefencivePlayer());
	red->setStrategy(new RandomPlayer());

	// Setup Cities
	City* sanDiego = new City("San Diego");
	City* pheonix = new City("Pheonix");
	City* lasVegas = new City("Las Vegas");
	City* losAngeles = new City("Los Angeles");
	City* sanFran = new City("San Francisco");

	// Setup connections between cities
	sanDiego->addConnection(pheonix, 14);
	sanDiego->addConnection(lasVegas, 9);
	sanDiego->addConnection(losAngeles, 3);

	pheonix->addConnection(sanDiego, 14);
	pheonix->addConnection(lasVegas, 15);

	lasVegas->addConnection(pheonix, 15);
	lasVegas->addConnection(sanDiego, 9);
	lasVegas->addConnection(losAngeles, 9);
	lasVegas->addConnection(sanFran, 14);

	losAngeles->addConnection(sanDiego, 3);
	losAngeles->addConnection(lasVegas, 9);
	losAngeles->addConnection(sanFran, 9);

	sanFran->addConnection(losAngeles, 9);
	sanFran->addConnection(lasVegas, 14);

	// Purchase cities
	yellow->buyCity(sanDiego);
	yellow->buyCity(pheonix);
	yellow->showPlayer();

	red->buyCity(pheonix);
	red->showPlayer();

	green->buyCity(losAngeles);
	green->buyCity(sanFran);
	green->showPlayer();

	// Should only power san diego
	std::cout << "Executing yellow(agressive) strategy" << std::endl;
	yellow->executeStrategy();

	// Should power pheonix
	std::cout << "Executing yellow(defencive) strategy" << std::endl;
	yellow->setStrategy(new DefencivePlayer());
	yellow->executeStrategy();

	// Should only power san francisco
	std::cout << "Executing green(defencive) strategy" << std::endl;
	green->executeStrategy();

	// Might or might not power pheonix
	std::cout << "Executing red(random) strategy x5 to show randomness" << std::endl;
	red->executeStrategy();
	red->executeStrategy();
	red->executeStrategy();
	red->executeStrategy();
	red->executeStrategy();

	system("pause");
}


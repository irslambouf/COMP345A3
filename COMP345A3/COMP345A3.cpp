// COMP345A3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Player.h"
#include "AgressivePlayer.h"
#include "DefencivePlayer.h"

int main()
{
	// Setup players
	Player* yellow = new Player("yellow");
	Player* green = new Player("Green");
	Player* red = new Player("Red");

	yellow->setStrategy(new AgressivePlayer());
	green->setStrategy(new DefencivePlayer());

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
	yellow->executeStrategy();

	// Should only power san francisco
	green->executeStrategy();

	system("pause");
}


// COMP345A3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Player.h"


int main()
{
	Player* yellow = new Player("yellow");
	Player* green = new Player("Green");
	Player* red = new Player("Red");
	Player* black = new Player("Black");

	City* sanDiego = new City("San Diego");
	City* pheonix = new City("Pheonix");
	City* lasVegas = new City("Las Vegas");
	City* losAngeles = new City("Los Angeles");

	Connection* sd1 = new Connection("Pheonix", 14);
	Connection* sd2 = new Connection("Las Vegas", 9);
	Connection* sd3 = new Connection("Los Angeles", 3);
	sanDiego->addConnection(sd1);
	sanDiego->addConnection(sd2);
	sanDiego->addConnection(sd3);

	Connection* p1 = new Connection("San Diego", 14);
	Connection* p2 = new Connection("Las Vegas", 15);
	pheonix->addConnection(p1);
	pheonix->addConnection(p2);

	Connection* lv1 = new Connection("Peonix", 15);
	Connection* lv2 = new Connection("San Diego", 9);
	Connection* lv3 = new Connection("Los Angeles", 9);
	lasVegas->addConnection(lv1);
	lasVegas->addConnection(lv2);
	lasVegas->addConnection(lv3);

	Connection* la1 = new Connection("San Diego", 3);
	Connection* la2 = new Connection("Las Vegas", 9);
	losAngeles->addConnection(la1);
	losAngeles->addConnection(la2);

	yellow->buyCity(sanDiego);
	yellow->showPlayer();
	yellow->buyCity(pheonix);
	yellow->showPlayer();

	red->buyCity(sanDiego);
	red->showPlayer();

	black->buyCity(sanDiego);
	black->showPlayer();

	green->buyCity(sanDiego);
	green->showPlayer();

	system("pause");
}


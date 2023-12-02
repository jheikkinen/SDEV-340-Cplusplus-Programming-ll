/* Week 7: Course Final Project 
*  James Heikkinen
*  Champlain College
*  25 AUG 2023
*  Description: Interface class that contains menu functionality 
*/

#pragma once
#include <iostream>

class Interface {
protected:
	char menuInput = 0; //Enter value for menus
	bool quit = false;  //Quit when user decides to


public:
	Interface(); // Default constructor
	Interface(char menuInput, bool quit); // Constructor for Interface Class

	~Interface(); // Destructor
	
	// Main menu with sub menus for each device
	void mainMenu();
	void thermostatMenu();
	void securitySystemMenu();
	void televisionMenu();
	void lightsMenu();
	void robotVacuumMenu();
};
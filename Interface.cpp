/* Week 7: Course Final Project 
*  James Heikkinen
*  Champlain College
*  25 AUG 2023
*  Description: Interface class that contains menu functionality
*/

#include <iostream>
#include "Interface.h"
#include "SmartDevice.h"
#include "SmartThermostats.h"
#include "SecuritySystem.h"
#include "Television.h"
#include "Lights.h"
#include "RobotVacuum.h"


Interface::Interface() {} // Default constructor

Interface::Interface(char menuInput, bool quit) : menuInput(menuInput), quit(quit) {} // Constructor for Interface Class
 
Interface::~Interface() {} // Destructor

// Main menu function
void Interface::mainMenu() {
	do {
		//Print Menu
		std::cout << "------ Menu ------" << std::endl;
		std::cout << "1. Go to thermostat settings" << std::endl;
		std::cout << "2. Go to security system settings" << std::endl;
		std::cout << "3. Go to television settings" << std::endl;
		std::cout << "4. Go to lights settings" << std::endl;
		std::cout << "5. Go to robot vacuum settings" << std::endl;
		std::cout << "6. Quit Program " << std::endl;

		//Print statement to inform user to select menu option.
		std::cout << "Please enter a number for your menu selection: " << std::endl;

		//Collect user input for menu
		std::cin >> menuInput;

		//Switch to determine if user wants to change any device settings. Any non valid input gets rejected and user has to try again. 
		switch (menuInput) {
		case '1':
			thermostatMenu(); //Call thermostat menu
			break;
		case '2':
			securitySystemMenu(); //Call security system menu
			break;
		case '3':
			televisionMenu(); //Call television menu
			break;
		case '4':
			lightsMenu(); //Call lights menu
			break;
		case '5':
			robotVacuumMenu(); //Call robot vacuum menu
			break;
		case '6':
			std::cout << "Good Bye!";
			quit = true;
			break;
		default:
			std::cout << "Incorrect input" << std::endl;
			break;
		}
	} while (!quit); //Exit program when quit equals true
}

void Interface::thermostatMenu() {
	SmartThermostats thermo;
	
	do {
		//Print Menu
		std::cout << "------ Menu ------" << std::endl;
		std::cout << "1. Activate thermostat" << std::endl;
		std::cout << "2. Set thermostat day temperature" << std::endl;
		std::cout << "3. Set thermostat evening temperature" << std::endl;
		std::cout << "4. Manually change temperature" << std::endl;
		std::cout << "5. Go back" << std::endl;

		//Print statement to inform user to select menu option.
		std::cout << "Please enter a number for your menu selection: " << std::endl;

		//Collect user input for menu
		std::cin >> menuInput;

		//Switch to determine if user wants to calculate the scores or quit program. Any non valid input gets rejected and user has to try again. 
		switch (menuInput) {
		case '1':
			thermo.powerOnOff(); //Call function to power on or off device
			break;
		case '2':
			do {
				//Print Menu
				std::cout << "------ Menu ------" << std::endl;
				std::cout << "1. Save beginning and end times" << std::endl;
				std::cout << "2. Read current time settings" << std::endl;
				std::cout << "5. Go back to main menu" << std::endl;

				//Print statement to inform user to select menu option.
				std::cout << "Please enter a number for your menu selection: " << std::endl;

				//Collect user input for menu
				std::cin >> menuInput;

				switch (menuInput) {
				case '1':
					thermo.setOnOffTime(); //Set the temperature for the day time
					break;
				case '2':
					thermo.getOnOffTime();
					break;
				case '5':
					mainMenu();
					break;
				default:
					std::cout << "Incorrect input" << std::endl;
					break;
				}
			} while (!quit); //Exit program when quit equals true

			break;
		case '3':
			thermo.getOnOffTime();
			break;
		case '4':
			thermo.setEveningTemp();  //Set the temperature for the evening
			break;
		case '5':
			thermo.manualTempAdjust();  //Set the temperature manually
			break;
		case '6':
			mainMenu();
			break;
		default:
			std::cout << "Incorrect input" << std::endl;
			break;
		}
	} while (!quit); //Exit program when quit equals true
}

void Interface::securitySystemMenu() {
	SecuritySystem sec;

	do {
		//Print Menu
		std::cout << "------ Menu ------" << std::endl;
		std::cout << "1. Power on or off security system" << std::endl;
		std::cout << "2. Set alarm times" << std::endl;
		std::cout << "3. Manually turn alarm on or off" << std::endl;
		std::cout << "4. Set security system sensitivity" << std::endl;
		std::cout << "5. Go back" << std::endl;

		//Print statement to inform user to select menu option.
		std::cout << "Please enter a number for your menu selection: " << std::endl;

		//Collect user input for menu
		std::cin >> menuInput;

		//Switch to determine if user wants to calculate the scores or quit program. Any non valid input gets rejected and user has to try again. 
		switch (menuInput) {
		case '1':
			sec.powerOnOff(); //Call function to power on or off device
			break;
		case '2':
			do {
				//Print Menu
				std::cout << "------ Menu ------" << std::endl;
				std::cout << "1. Save beginning and end times" << std::endl;
				std::cout << "2. Read current time settings" << std::endl;
				std::cout << "5. Go back to main menu" << std::endl;

				//Print statement to inform user to select menu option.
				std::cout << "Please enter a number for your menu selection: " << std::endl;

				//Collect user input for menu
				std::cin >> menuInput;

				switch (menuInput) {
				case '1':
					sec.setOnOffTime(); //Call function to set the time for turning on or off the alarm
					break;
				case '2':
					sec.getOnOffTime();
					break;
				case '5':
					mainMenu();
					break;
				default:
					std::cout << "Incorrect input" << std::endl;
					break;
				}
			} while (!quit); //Exit program when quit equals true

			break;
		case '3':
			sec.startStopAlarm(); //Start or stop the alarm manually
			break;
		case '4':
			sec.setSecuritySensistivity(); //Set security sensitivity level
			break;
		case '5':
			mainMenu();
			break;
		default:
			std::cout << "Incorrect input" << std::endl;
			break;
		}
	} while (!quit); //Exit program when quit equals true
}

void Interface::televisionMenu() {
	Television tv;

	do {
		//Print Menu
		std::cout << "------ Menu ------" << std::endl;
		std::cout << "1. Power TV on or off" << std::endl;
		std::cout << "2. Set TV on off times" << std::endl;
		std::cout << "3. Change channel" << std::endl;
		std::cout << "5. Go back" << std::endl;

		//Print statement to inform user to select menu option.
		std::cout << "Please enter a number for your menu selection: " << std::endl;

		//Collect user input for menu
		std::cin >> menuInput;

		//Switch to determine if user wants to calculate the scores or quit program. Any non valid input gets rejected and user has to try again. 
		switch (menuInput) {
		case '1':
			tv.powerOnOff(); //Call function to power on or off device
			break;
		case '2':
			do {
				//Print Menu
				std::cout << "------ Menu ------" << std::endl;
				std::cout << "1. Save beginning and end times" << std::endl;
				std::cout << "2. Read current time settings" << std::endl;
				std::cout << "5. Go back to main menu" << std::endl;

				//Print statement to inform user to select menu option.
				std::cout << "Please enter a number for your menu selection: " << std::endl;

				//Collect user input for menu
				std::cin >> menuInput;

				switch (menuInput) {
				case '1':
					tv.setOnOffTime(); //Call function to set the time for powering on or off the tv
					break;
				case '2':
					tv.getOnOffTime();
					break;
				case '5':
					mainMenu();
					break;
				default:
					std::cout << "Incorrect input" << std::endl;
					break;
				}
			} while (!quit); //Exit program when quit equals true
			
			break;
		case '3':
			tv.setChannel(); //Set the channel for the television
			break;
		case '5':
			mainMenu();
			break;
		default:
			std::cout << "Incorrect input" << std::endl;
			break;
		}
	} while (!quit); //Exit program when quit equals true
}

void Interface::lightsMenu() {
	Lights lt;

	do {
		//Print Menu
		std::cout << "------ Menu ------" << std::endl;
		std::cout << "1. Power lights on or off" << std::endl;
		std::cout << "2. Set lights on or off times" << std::endl;
		std::cout << "5. Go back" << std::endl;

		//Print statement to inform user to select menu option.
		std::cout << "Please enter a number for your menu selection: " << std::endl;

		//Collect user input for menu
		std::cin >> menuInput;

		//Switch to determine if user wants to calculate the scores or quit program. Any non valid input gets rejected and user has to try again. 
		switch (menuInput) {
		case '1':
			lt.powerOnOff(); //Call function to power on or off device
			break;
		case '2':
			do {
				//Print Menu
				std::cout << "------ Menu ------" << std::endl;
				std::cout << "1. Save beginning and end times" << std::endl;
				std::cout << "2. Read current time settings" << std::endl;
				std::cout << "5. Go back to main menu" << std::endl;

				//Print statement to inform user to select menu option.
				std::cout << "Please enter a number for your menu selection: " << std::endl;

				//Collect user input for menu
				std::cin >> menuInput;

				switch (menuInput) {
				case '1':
					lt.setOnOffTime(); //Call function to set the time for powering on or off the lights
					break;
				case '2':
					lt.getOnOffTime();
					break;
				case '5':
					mainMenu();
					break;
				default:
					std::cout << "Incorrect input" << std::endl;
					break;
				}
			} while (!quit); //Exit program when quit equals true

			break;
		case '5':
			mainMenu();
			break;
		default:
			std::cout << "Incorrect input" << std::endl;
			break;
		}
	} while (!quit); //Exit program when quit equals true
}

void Interface::robotVacuumMenu() {
	RobotVacuum vac;

	do {
		//Print Menu
		std::cout << "------ Menu ------" << std::endl;
		std::cout << "1. Turn robot vacuum system on" << std::endl;
		std::cout << "2. Set vacuum run schedule" << std::endl;
		std::cout << "3. Manually run vacuum" << std::endl;
		std::cout << "5. Go back" << std::endl;

		//Print statement to inform user to select menu option.
		std::cout << "Please enter a number for your menu selection: " << std::endl;

		//Collect user input for menu
		std::cin >> menuInput;

		//Switch to determine if user wants to calculate the scores or quit program. Any non valid input gets rejected and user has to try again. 
		switch (menuInput) {
		case '1':
			vac.powerOnOff(); //Call function to power on or off device
			break;
		case '2':
			do {
				//Print Menu
				std::cout << "------ Menu ------" << std::endl;
				std::cout << "1. Save beginning and end times" << std::endl;
				std::cout << "2. Read current time settings" << std::endl;
				std::cout << "5. Go back to main menu" << std::endl;

				//Print statement to inform user to select menu option.
				std::cout << "Please enter a number for your menu selection: " << std::endl;

				//Collect user input for menu
				std::cin >> menuInput;

				switch (menuInput) {
				case '1':
					vac.setOnOffTime(); //Call function to set the time for the vacuum to make its rounds for cleaning
					break;
				case '2':
					vac.getOnOffTime();
					break;
				case '5':
					mainMenu();
					break;
				default:
					std::cout << "Incorrect input" << std::endl;
					break;
				}
			} while (!quit); //Exit program when quit equals true
			break;
		case '3':
			vac.manuallyStartStopVacuum(); //Manually send the vacuum to go on its rounds for cleaning
			break;
		case '5':
			mainMenu();
			break;
		default:
			std::cout << "Incorrect input" << std::endl;
			break;
		}
	} while (!quit); //Exit program when quit equals true
}
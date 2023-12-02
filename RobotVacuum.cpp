/* Week 7: Course Final Project 
*  James Heikkinen
*  Champlain College
*  25 AUG 2023
*  Description: Robot vacuum class that contains device specific functions
*/


#include <iostream>
#include "RobotVacuum.h"
#include <string>
#include "UserDefinedTemplate.cpp"
#include <fstream>

RobotVacuum::RobotVacuum() {} // Default constructor
RobotVacuum::RobotVacuum(bool startVacuum) : startVacuum(startVacuum) {} // Constructor for robot vacuum Class
RobotVacuum::RobotVacuum(bool power, char userInput, int beginTime, int endTime, std::string message,
	bool startVacuum, std::string beginTimeStr, std::string endTimeStr, int time)
	: SmartDevice(power, userInput, beginTime, endTime, message, beginTimeStr, endTimeStr, time), startVacuum(startVacuum) {}  // Overloaded constructor for robot vacuum

RobotVacuum::~RobotVacuum() {} //Destructor


//Start or stop vacuum from making its rounds manually
void RobotVacuum::manuallyStartStopVacuum() {
	//Start or stop vacuum
	if (power == false && startVacuum == false) {
		powerOnOff(); //Turn on vacuum before operating.
		startVacuum = true;
		message = "Robot vacuum has started its rounds to clean the house.";
	}
	else if (startVacuum == false) {
		startVacuum = true;
		message = "Robot vacuum has started its rounds to clean the house.";
	}
	else {
		startVacuum = false;
		message = "Robot vacuum has stopped cleaning the house and will return to home base.";
	}
	//Send message
	simulatedResult(message);
}

//Power security system on or off
void RobotVacuum::powerOnOff() {
	// Turn device on or off	
	if (power == false) {
		power = true;
		message = "Robot vacuum has been turned on.";
	}
	else {
		power = false;
		message = "Robot vacuum has been turned off.";
	}
	//Send message
	simulatedResult(message);
}

//Setter
void RobotVacuum::setOnOffTime() {
	// Set device on at certain times
	message = "RobotVacuum"; //Name of class to append to text document name

	std::cout << "Enter the starting time for smart device:"; //Prompt user

	beginTime = inputHandlingTime(); //Call function to verify time input

	beginTimeStr = std::to_string(beginTime); //Convert to string

	std::cout << "Enter the ending time for smart device:"; //Prompt user

	endTime = inputHandlingTime(); //Call function to verify time input

	endTimeStr = std::to_string(endTime); //Convert to string

	SetTime<std::string> time(beginTimeStr, endTimeStr, message);  //Call SetTime template function to input info in file
	time.time();
}

//Getter
int RobotVacuum::getOnOffTime() {
	// Get device on at certain times
	message = "RobotVacuum";

	FileRead<std::string> ReadFile(message); //Call template function to read file

	simulatedResult(ReadFile.ReadFile()); //Call template function to read file

	return 0;
}

//Used to simulate the result of device action via print statment due to no actual device.
void RobotVacuum::simulatedResult(std::string ms) {
	//Print message from applicable function that was executed by user 
	std::cout << ms << std::endl;
}

int RobotVacuum::inputHandlingTime() {

	//Input time value
	std::cin >> time;

	//Get last two digits
	//JSchlather, . (2010, September 22). How to cut off leading digits? C++. iomanip - How to cut off leading digits? C++ - Stack Overflow. 
	//Retrieved August 25, 2023, from https://stackoverflow.com/questions/3765877/how-to-cut-off-leading-digits-c
	int lastTwoDigits = time % 100;


	do {
		try {
			//Print statement asking for time
			std::cout << "Choose a time in the range 0000 - 2359 for device activity: " << std::endl;
			std::cin >> time;

			//Throw error if the input is not valid datatype.
			if (std::cin.fail()) {
				throw std::runtime_error("Input is not a valid integer.");
			}
			//Time 0000 - 2359.
			if (time < 0 || time > 2359) {
				throw std::range_error("Please enter a time in the range of 0000 to 2359.");
			}

			//Verify minutes are within in the 60 minutes range
			if (lastTwoDigits < 0 || lastTwoDigits >= 60) {
				throw std::range_error("Please enter a time where the minutes are in the range 00 to 59.");
			}

			//Break loop when input is legit
			break;
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;

			//Used to prevent looping from other datatypes
			//Peter87. (2017, June 12). How to use cin.ignore. How to use cin.ignore - C++ Forum. 
			//Retrieved August 25, 2023, from https://cplusplus.com/forum/beginner/217812/
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (true); //Keep looping until in range

	return time;
}
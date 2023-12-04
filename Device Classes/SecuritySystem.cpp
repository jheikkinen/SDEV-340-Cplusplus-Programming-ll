/* Week 7: Course Final Project 
*  James Heikkinen
*  Champlain College
*  25 AUG 2023
*  Description: Security System class that contains device specific functions
*/

#include <iostream>
#include "SecuritySystem.h"
#include <string>
#include <stdexcept>
#include "UserDefinedTemplate.cpp"
#include <fstream>

SecuritySystem::SecuritySystem() {} // Default constructor
SecuritySystem::SecuritySystem(int sensitivityLevel) : sensitivityLevel(sensitivityLevel) {} // Constructor for Security Systems Class
SecuritySystem::SecuritySystem(bool power, char userInput, int beginTime, int endTime, std::string message,
	int sensitivityLevel, bool alarm, std::string beginTimeStr, std::string endTimeStr, int time)
	: SmartDevice(power, userInput, beginTime, endTime, message, beginTimeStr, endTimeStr, time), sensitivityLevel(sensitivityLevel), alarm(alarm) {} // Overloaded constructor for Security System

SecuritySystem::~SecuritySystem() {} //Destructor

//Start or stop the alarm manually
void SecuritySystem::startStopAlarm() {
	//Turn alarm on or off
	if (alarm == false) {
		alarm = true;
		message = "Alarm has been activated. Sensitivy level is " + std::to_string(getSecuritySensitivity());
	}
	else {
		alarm = false;
		message = "Alarm has been deactivated.";
	}
	//Send message
	simulatedResult(message);
}

//Setter
void SecuritySystem::setSecuritySensistivity() {
	//Exceptions handling to ensure I only get inputs of a range from 1 - 5
	do {
		try {
			std::cout << "Enter the sensitivty level:" << std::endl;
			std::cin >> sensitivityLevel;

			if (std::cin.fail()) {
				throw std::runtime_error("Input is not a valid integer.");
			}

			if (sensitivityLevel < 1 || sensitivityLevel > 5) {
				throw std::range_error("Please enter a senstivity level in the range of 1 to 5.");
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
	} while (!(sensitivityLevel >= 1 && sensitivityLevel <= 5));

	//Select the applicable sensitivity level based on user input
	if (sensitivityLevel == 1) {
		message = "Barely detects anything.";
	}
	else if (sensitivityLevel == 2) {
		message = "Alarm goes off when people are running through the house.";
	}
	else if (sensitivityLevel == 3) {
		message = "Alarm and motion-activated lights go off when a human walks by sensor.";
	}
	else if (sensitivityLevel == 4) {
		message = "Alarm and motion-activated lights go off when a mouse walks by sensor.";
	}
	else if (sensitivityLevel == 5) {
		message = "Alarm and motion-activated lights go off when dust particle movement is detected by the sensor. Intentionally making your life more miserable.";
	}
	//Send message
	simulatedResult(message);
}

//Getter
int SecuritySystem::getSecuritySensitivity() {
	return sensitivityLevel; //Needed to maintain last sensitivity level
}

//Power security system on or off
void SecuritySystem::powerOnOff() {
	// Turn device on or off
	if (power == false) {
		power = true;
		message = "Security system has been turned on.";
	}
	else {
		power = false;
		message = "Security system has been turned off.";
	}
	//Send message
	simulatedResult(message);
}

//Setter
void SecuritySystem::setOnOffTime() {
	// Set device on at certain times
	message = "SecuritySystem"; //Name of class to append to text document name

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
int SecuritySystem::getOnOffTime() {
	// Get device on at certain times
	message = "SecuritySystem";

	FileRead<std::string> ReadFile(message); //Call template function to read file

	simulatedResult(ReadFile.ReadFile()); //Call template function to read file

	return 0;
}

//Used to simulate the result of device action via print statment due to no actual device.
void SecuritySystem::simulatedResult(std::string ms) {

	//Print message from applicable function that was executed by user 
	std::cout << ms << std::endl;

}

int SecuritySystem::inputHandlingTime() {

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

/* Week 7: Course Final Project 
*  James Heikkinen
*  Champlain College
*  25 AUG 2023
*  Description: Parent class for all five devices in the program
*/

#include <iostream>
#include "SmartDevice.h"
#include <string>
#include <fstream>
//#include "UserDefinedTemplate.h"
#include "UserDefinedTemplate.cpp"

SmartDevice::SmartDevice() {} // Default constructor

SmartDevice::SmartDevice(bool power, char userInput, int beginTime, int endTime, std::string message, std::string beginTimeStr, std::string endTimeStr, int time)
	: power(power), userInput(userInput), beginTime(beginTime), endTime(endTime), message(message), beginTimeStr(beginTimeStr), endTimeStr(endTimeStr), time(time) {} // Constructor for SmartDevice Class


//Destructor
SmartDevice::~SmartDevice() {}

//Power on or off device
void SmartDevice::powerOnOff() {
	// Turn device on or off
	if (power == false) {
		power = true;
		message = "Smart device has been turned on.";
	}
	else {
		power = false;
		message = "Smart device has been turned off.";
	}
	//Send message
	simulatedResult(message);
}

//Setter
void SmartDevice::setOnOffTime() {	
	// Set device on at certain times
	message = "Smart Device"; //Name of class to append to text document name

	std::cout << "Enter the starting time for smart device:"; //Prompt user
	
	beginTime = inputHandlingTime(); //Call function to verify time input

	beginTimeStr = std::to_string(beginTime); //Convert to string

	std::cout << "Enter the ending time for smart device:"; //Prompt user

	endTime = inputHandlingTime(); //Call function to verify time input

	endTimeStr = std::to_string(beginTime); //Convert to string

	SetTime<std::string> time(beginTimeStr, endTimeStr, message); //Call SetTime template function to input info in file
	time.time();
}

//Getter
int SmartDevice::getOnOffTime() {
	// Get device on at certain times
	message = "Smart Device"; //Name of class to find text document with name.

	FileRead<std::string> ReadFile(message); //Call template function to read file

	simulatedResult(ReadFile.ReadFile()); //Call template function to read file
	
	return 0;
}

//Used to simulate the result of device action via print statment due to no actual device.
void SmartDevice::simulatedResult(std::string ms) {
	//Send message
	std::cout << ms << std::endl;
}

int SmartDevice::inputHandlingTime() {

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
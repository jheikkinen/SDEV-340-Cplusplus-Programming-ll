/* Week 7: Course Final Project 
*  James Heikkinen
*  Champlain College
*  25 AUG 2023
*  Description: Smart Thermostat class that contains device specific functions
*/

#include <iostream>
#include "SmartThermostats.h"
#include <string>
#include <stdexcept>
#include "UserDefinedTemplate.cpp"
#include <fstream>


SmartThermostats::SmartThermostats() {} // Default constructor
SmartThermostats::SmartThermostats(int tempInput, int dayTemp, int eveningTemp) 
	: tempInput(tempInput), dayTemp(dayTemp), eveningTemp(eveningTemp) {} // Constructor for Smart Thermostat Class
SmartThermostats::SmartThermostats(bool power, char userInput, int beginTime, int endTime, std::string message, int tempInput, int dayTemp, int eveningTemp,
	std::string beginTimeStr, std::string endTimeStr, int time) : SmartDevice(power, userInput, beginTime, endTime, message, beginTimeStr, endTimeStr, time),
	tempInput(tempInput), dayTemp(dayTemp), eveningTemp(eveningTemp) {} // Overloaded constructor for SmartThermostat

SmartThermostats::~SmartThermostats() {} //Destructor

//Manually change the temperature
void SmartThermostats::manualTempAdjust() {
	
	//Print statement asking for temperature
	std::cout << "Enter a temperature (F) that you would like to set for your home: " << std::endl;
	
	//Send temp input to getter for thermostat to use
	tempExceptionHandling();

	//Create message to simulate result
	message = "Temperature has been set to " + std::to_string(tempInput);

	//Send message
	simulatedResult(message);
}

//Setter
void SmartThermostats::setDayTemp() {

	//Print statement asking for temperature
	std::cout << "Enter a day time temperature (F) that you would like to set for your home: " << std::endl;

	//Call function that allows user to input temp and verify if valid
	tempExceptionHandling();

	//Send temp input to getter for thermostat to use
	dayTemp = tempInput;

	//Create message to simulate result
	message = "Day time temperature has been set to " + std::to_string(tempInput);

	//Send message
	simulatedResult(message);
}

//Getter
int SmartThermostats::getDayTemp() {
	return dayTemp; //Used for thermostat to change temperature based on time of day.
}

//Setter
void SmartThermostats::setEveningTemp() {	
	//Print statement asking for temperature
	std::cout << "Enter a evening time temperature (F) that you would like to set for your home: " << std::endl;

	//Call function that allows user to input temp and verify if valid
	tempExceptionHandling();

	//Send temp input to getter for thermostat to use
	eveningTemp = tempInput;

	//Create message to simulate result
	message = "Evening time temperature has been set to " + std::to_string(tempInput);

	//Send message
	simulatedResult(message);
}

//Getter
int SmartThermostats::getEveningTemp() {
	return eveningTemp; //Used for thermostat to change temperature based on time of day.
}

//Power device on or off
void SmartThermostats::powerOnOff() {
	// Turn device on or off
	if (power == false) {
		power = true;
		message = "Thermostat has been turned on.";
	}
	else {
		power = false;
		message = "Thermostat has been turned off.";
	}
	//Send message
	simulatedResult(message);
}

//Setter
void SmartThermostats::setOnOffTime() {
	// Set device on at certain times
	message = "SmartThermostats"; //Name of class to append to text document name

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
int SmartThermostats::getOnOffTime() {
	// Get device on at certain times
	message = "SmartThermostats";

	FileRead<std::string> ReadFile(message); //Call template function to read file

	simulatedResult(ReadFile.ReadFile()); //Call template function to read file

	return 0;
}

//Used to simulate the result of device action via print statment due to no actual device.
void SmartThermostats::simulatedResult(std::string ms) {
	//Print message from applicable function that was executed by user 
	std::cout << ms << std::endl;
}

//Funtion to handle multiple user inputs from several different functions
int SmartThermostats::tempExceptionHandling() {
	//Exception handling for temperature input.
	do {
		try {

			std::cin >> tempInput;

			//Throw error if the input is not valid datatype.
			if (std::cin.fail()) {
				throw std::runtime_error("Input is not a valid integer.");
			}
			//Trying to consider people who like extreme temperatures lol.
			if (tempInput < 50 || tempInput > 100) {
				throw std::range_error("Please enter a senstivity level in the range of 50 to 100.");
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
	} while (!(tempInput >= 50 && tempInput <= 100));

	return tempInput;
}

int SmartThermostats::inputHandlingTime() {

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
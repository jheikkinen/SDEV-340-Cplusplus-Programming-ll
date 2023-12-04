/* Week 7: Course Final Project 
*  James Heikkinen
*  Champlain College
*  25 AUG 2023
*  Description: Parent class for all five devices in the program
*/


#pragma once
#include <iostream>
#include <string>


class SmartDevice {
protected:
	bool power = false;       //Turn on or off device
	char userInput = '\0';    //Used when user inputs desired settings
	int beginTime = 0;        //Enter beginning time
	int endTime = 0;          //Enter end time
	std::string message = ""; //Used to pass simulated device response
	std::string beginTimeStr = "";
	std::string endTimeStr = "";
	int time = 0;

public:
	SmartDevice(); // Default constructor
	SmartDevice(bool power, char userInput, int beginTime, int endTime, std::string message, std::string beginTimeStr, std::string endTimeStr, int time); // Constructor for SmartDevice Class

	//Destructor
	~SmartDevice();

	//Virtual methods to be passed down to child classes
	virtual void powerOnOff();
	virtual void setOnOffTime();
	virtual int getOnOffTime();
	virtual void simulatedResult(std::string message); //Used to simulate the result of device action via print statment due to no actual device.
	virtual int inputHandlingTime();
};

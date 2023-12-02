/* Week 7: Course Final Project 
*  James Heikkinen
*  Champlain College
*  25 AUG 2023
*  Description: Lights class that contains device specific functions
*/

#pragma once
#include "SmartDevice.h"
#include <string>

class Lights: public SmartDevice {
protected:

public:
	Lights(); // Default constructor
	Lights(bool power, char userInput, int beginTime, int endTime, std::string message
		, std::string beginTimeStr, std::string endTimeStr, int time); // Constructor for SmartDevice Class

	//Destructor
	~Lights();

	//Overridden methods received from the Smart device class
	void powerOnOff() override;
	void setOnOffTime() override;
	int getOnOffTime() override;
	void simulatedResult(std::string message) override; //Used to simulate the result of device action via print statment due to no actual device.
	int inputHandlingTime() override;
};
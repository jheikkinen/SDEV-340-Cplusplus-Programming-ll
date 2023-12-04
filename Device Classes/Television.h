/* Week 7: Course Final Project 
*  James Heikkinen
*  Champlain College
*  25 AUG 2023
*  Description: Television class that contains device specific functions
*/

#pragma once
#include "SmartDevice.h"
#include <string>

class Television: public SmartDevice {
protected:
	int channel = 1; //Used to change channel. Defaulted to 1 so it is in range.

public:
	Television(); // Default constructor
	Television(int channel); // Constructor for Television Class
	Television(bool power, char userInput, int beginTime, int endTime, std::string message, int channel, 
		std::string beginTimeStr, std::string endTimeStr, int time); // Overloaded constructor for Television

	//Destructor
	~Television();

	//Change channel setter and getter
	void setChannel();
	int getChannel();

	//Overridden methods received from the Smart device class
	void powerOnOff() override;
	void setOnOffTime() override;
	int getOnOffTime() override;
	void simulatedResult(std::string message) override; //Used to simulate the result of device action via print statment due to no actual device.
	int inputHandlingTime() override;
};

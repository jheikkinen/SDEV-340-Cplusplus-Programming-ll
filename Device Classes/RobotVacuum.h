/* Week 7: Course Final Project 
*  James Heikkinen
*  Champlain College
*  25 AUG 2023
*  Description: Robot vacuum class that contains device specific functions
*/

#pragma once
#include "SmartDevice.h"
#include <string>


class RobotVacuum : public SmartDevice {
protected:
	bool startVacuum = false; //Activate vacuum to making its rounds for cleaning


public:
	RobotVacuum(); // Default constructor
	RobotVacuum(bool startVacuum); // Constructor for robot vacuum Class
	RobotVacuum(bool power, char userInput, int beginTime, int endTime, std::string message, bool startVacuum
		, std::string beginTimeStr, std::string endTimeStr, int time);  // Overloaded constructor for robot vacuum

	//Destructor
	~RobotVacuum();

	//Method for robot vacuum
	void manuallyStartStopVacuum();

	//Overridden methods received from the Smart device class
	void powerOnOff() override;
	void setOnOffTime() override;
	int getOnOffTime() override;
	void simulatedResult(std::string message) override; //Used to simulate the result of device action via print statment due to no actual device.
	int inputHandlingTime() override;
};

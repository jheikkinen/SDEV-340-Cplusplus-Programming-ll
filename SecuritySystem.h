/* Week 7: Course Final Project 
*  James Heikkinen
*  Champlain College
*  25 AUG 2023
*  Description: Security System class that contains device specific functions
*/

#pragma once
#include "SmartDevice.h"
#include <string>

class SecuritySystem: public SmartDevice {
protected:
	int sensitivityLevel = 1; //Used to change sensitivity level of security settings
	bool alarm = false;       //Used to determin if the security system is on or off

public:
	SecuritySystem(); // Default constructor
	SecuritySystem(int sensitivityLevel); // Constructor for Security Systems Class
	SecuritySystem(bool power, char userInput, int beginTime, int endTime, std::string message, int sensitivityLevel, bool alarm
		, std::string beginTimeStr, std::string endTimeStr, int time); // Overloaded constructor for Security System

	//Destructor
	~SecuritySystem();

	//Methods for security system
	void startStopAlarm();
	void setSecuritySensistivity();
	int getSecuritySensitivity();
	
	//Overridden methods received from the Smart device class
	void powerOnOff() override;
	void setOnOffTime() override;
	int getOnOffTime() override;
	void simulatedResult(std::string message) override; //Used to simulate the result of device action via print statment due to no actual device.
	int inputHandlingTime() override;
};
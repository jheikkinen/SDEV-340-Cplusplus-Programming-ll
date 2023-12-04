/* Week 7: Course Final Project 
*  James Heikkinen
*  Champlain College
*  25 AUG 2023
*  Description: Smart Thermostat class that contains device specific functions
*/

#pragma once
#include <iostream>
#include "SmartDevice.h"
#include <string>

class SmartThermostats: public SmartDevice {
protected:
	int tempInput = 0;   //Used to change temperature
	int dayTemp = 0;     //Used to set day temperature
	int eveningTemp = 0; //Used to set evening temperature


public:
	SmartThermostats(); // Default constructor
	SmartThermostats(int tempInput, int dayTemp, int eveningTemp); // Constructor for Smart Thermostat Class
	SmartThermostats(bool power, char userInput, int beginTime, int endTime, std::string message, int tempInput, int dayTemp, int eveningTemp,
		std::string beginTimeStr, std::string endTimeStr, int time); // Overloaded constructor for SmartThermostat

	//Destructor
	~SmartThermostats();

	//Methods for Smart Thermostat
	void manualTempAdjust();
	void setDayTemp();
	int getDayTemp();
	void setEveningTemp();
	int getEveningTemp();
	int tempExceptionHandling();

	//Overridden methods received from the Smart device class
	void powerOnOff() override;
	void setOnOffTime() override;
	int getOnOffTime() override;
	void simulatedResult(std::string message ) override; //Used to simulate the result of device action via print statment due to no actual device.
	int inputHandlingTime() override;
};

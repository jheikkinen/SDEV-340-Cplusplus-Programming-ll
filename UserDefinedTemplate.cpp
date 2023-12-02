/* Week 7: Course Final Project 
*  James Heikkinen
*  Champlain College
*  25 AUG 2023
*  Description: Template class designed for common functionalities of the program
*/


#include <iostream>
#include "UserDefinedTemplate.h"
#include <fstream>
#include <string>
#include <iostream>


template<typename T>
class SetTime {
private:
	T beginTime = ""; //Used for begin time
	T endTime = "";   //Used for end time
	T fileName = "";

public:
	SetTime() {} // Default constructor
	SetTime(const T beginTime, const T EndTime, const T fileName) : beginTime(beginTime), endTime(EndTime), fileName(fileName){} // Constructor for UserDefinedTemplate Class

	//Destructor
	~SetTime() {}

	//Set time
	std::string time() { 
		
		std::string message = "Start time is " + beginTime + " and end time is " + endTime + ".";

		std::ofstream outputFile(fileName + ".txt");

		if (!outputFile.is_open()) {
			std::cerr << "Error opening the file." << std::endl;
			return "Error";
		}

		// Write content to the file
		outputFile << message << std::endl;


		// Close the file
		outputFile.close();

		std::cout << message << std::endl;
		std::cout << "Data is saved." << std::endl;

		return message;
	}
};


template<typename T>
class setDay {
private:

	T day = "";  //Used to determine with days are active or not


public:
	setDay() {} // Default constructor
	setDay(T day) : day(day) {}// Constructor for UserDefinedTemplate Class

	//Destructor
	~setDay() {}

	//Methods for common algorithms
	
	std::string Day() {
	
		std::string message = "The time is set for the day" + day;

		/*if (!outputFile.is_open()) {
			std::cerr << "Error opening the file." << std::endl;
			return 1;
		}*/


		// Write content to the file
	//	outputFile << day << std::endl;


		// Close the file
	//	outputFile.close();

		std::cout << "Data is saved." << std::endl;
	
		return message;
	}
};

template<typename T>
class FileRead {
private:

	T fileName = "";  //Used to determine with days are active or not
	std::string content = "";

public:
	FileRead() {} // Default constructor
	FileRead(T fileName) : fileName(fileName) {}// Constructor for UserDefinedTemplate Class

	//Destructor
	~FileRead() {}

	//Methods for common algorithms

	std::string ReadFile() {

		std::ifstream inputFile(fileName + ".txt");

		if (!inputFile.is_open()) {
			std::cerr << "Error opening the file." << std::endl;
			return "Error";
		}
		
		// Read content from text file
		std::string data;
		while (std::getline(inputFile, data)) {
			content += data + '\n';
			std::cout << data << std::endl;
		}

		// Close the file
		inputFile.close();

		return content;
	}
};



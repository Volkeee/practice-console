#include "stdafx.h"
#include "Logger.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

//Constructor without parameters to create a log with default name
Logger::Logger(void)
{
	this->logPath = "log.txt";
}

Logger::~Logger(void) {

}

//Constructor with file path\name parameter
Logger::Logger(std::string filePath) {
	this->logPath = filePath;
}

//Function to write  message with "INFO" label
void Logger::i(std::string textToWrite) {
	std::ofstream fout(this->logPath, std::ios_base::app | std::ofstream::trunc);
	fout << "[" << getTime().wHour << ":" << getTime().wMinute << ":" << getTime().wSecond << " INFO] " << textToWrite << std::endl;
	fout.close();
}

//Function to write  message with "Error" label
void Logger::e(std::string textToWrite) {
	std::ofstream fout(this->logPath, std::ios_base::app);
	fout << "[" << getTime().wHour << ":" << getTime().wMinute << ":" << getTime().wSecond << " ERROR] " << textToWrite << std::endl;
	fout.close();
}

//Function to write  message with "Alarm" label
void Logger::a(std::string textToWrite) {
	std::ofstream fout(this->logPath, std::ios_base::app);
	fout << "[" << getTime().wHour << ":" << getTime().wMinute << ":" << getTime().wSecond << " ALARM] " << textToWrite << std::endl;
	fout.close();
}

//Function to clear the log
void Logger::clearLog() {
	std::ofstream ofs;
	ofs.open(this->logPath, std::ofstream::out | std::ofstream::trunc);
	ofs.close();
}

SYSTEMTIME Logger::getTime() {
	SYSTEMTIME lt;

	GetLocalTime(&lt);
	return lt;
}
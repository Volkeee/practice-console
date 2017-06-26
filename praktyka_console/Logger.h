#pragma once
#include <iostream>
#include <string>
#include <windows.h>
class Logger
{
public:
	Logger(void);
	Logger(std::string filePath);
	~Logger(void);
public:
	std::string Logger::logPath;
public:
	void Logger::e(std::string textToWrite);
	void Logger::i(std::string textToWrite);
	void Logger::a(std::string textToWrite);
	void Logger::clearLog();
	SYSTEMTIME Logger::getTime();
};


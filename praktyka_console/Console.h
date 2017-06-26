#pragma once
#include <cstring>
#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;

class Console
{
public:
	static void setCursor(int x, int y);

	static void setSize(int cols, int lines);

	static void setColor(int text, int background);

	static void setCursorColor(int text, int background);
	
	static HANDLE hConsole();

	static char toCyrillic(char ñ);

	virtual ~Console(void);
};


#pragma once
#include "Console.h"

class Button
{
public:
	~Button(void);

	Button(int X, int Y, int sizeX, int sizeY, 
		string text = "btn" , int text_color = 1, int background_color = 15);

	int Focus(int text_color, int background_color);

private:
	string text;

	int X, Y, sizeX, sizeY,
		text_color, background_color;

	void Draw(int text_color, int background_color);

};
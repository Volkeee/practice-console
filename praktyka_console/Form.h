#pragma once
#include "Console.h"
#include "Label.h"
#include "TextBox.h"
#include "Button.h"

class Form
{
public:
	void Draw(int sizeX, int sizeY, char * title = "���������",
		int text_color = 7, int background_color = 0);
};

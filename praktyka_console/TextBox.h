#pragma once
#include "Console.h"

class TextBox
{
public:
	~TextBox(void);

	TextBox(int x, int y, int size, int text_color,
		int background_color);

	void setText(char * str);

	char * TextBox::getText();

	int Focus(int text_color, int background_color);

private:
	int lenText,
		x, y, size,
		text_color, background_color;
	char text[255];

	void Draw(int text_color, int background_color);
};
#include "stdafx.h"
#include "Form.h"

void Form::Draw(int sizeX, int sizeY, char * title, int text_color, int background_color)
{
	Console::setColor(text_color, background_color);
	Console::setSize(sizeX,sizeY);

	for (int i = 1; i < sizeX-1; i++)
	{
		Console::setCursor(i, 1);
		putchar(205);
		Console::setCursor(i, 3);
		putchar(205);
		Console::setCursor(i, sizeY-2);
		putchar(205);
	}

	for (int i = 1; i < sizeY-1; i++)
	{
		Console::setCursor(1, i);
		putchar(186);
		Console::setCursor(sizeX-2, i);
		putchar(186);
	}

	Console::setCursor(1, 1); 
	putchar(201);
	Console::setCursor(1, 3); 
	putchar(204);
	Console::setCursor(sizeX-2, 3); 
	putchar(185);
	Console::setCursor(1, sizeY-2);
	putchar(200);
	Console::setCursor(sizeX-2, 1); 
	putchar(187);
	Console::setCursor(sizeX-2, sizeY-2);
	putchar(188);

	new Label(((sizeX-1)/2)-((strlen(title)-1)/2), 2, title, background_color, text_color);

	Console::setCursor(0, 0);
}
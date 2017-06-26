#include "stdafx.h"
#include "Button.h"

Button::Button(int X, int Y, int sizeX, int sizeY, string text,
				 int text_color, int background_color)
{
	Button::X = X;
	Button::Y = Y;
	Button::sizeX = sizeX;
	Button::sizeY = sizeY;
	Button::text = text;
	Button::text_color = text_color;
	Button::background_color = background_color;
	Draw(text_color, background_color);
}

int Button::Focus(int text_color, int background_color)
{
	Draw(text_color, background_color);

	int key;
	bool pressed = false;

	while(!pressed)
	{
		switch (_getch()) 
		{
			case 13: 
				key = 0;
				pressed = true;
				break;
			case 72:
				key = -1;
				pressed = true;
				break;
			case 80:
				key = 1;
				pressed = true;
				break;
		}
	}

	Draw(Button::text_color, Button::background_color);
	return key;
}

void Button::Draw(int text_color, int background_color)
{
	Console::setCursorColor(text_color,background_color);

	Console::setCursor(X,Y);
	putchar(218);
	for (int i = X; i < (X + sizeX)-1; i++) 
		putchar(196);
	putchar(191);

	for (int i = Y+1; i < (Y + sizeY); i++)
	{
		Console::setCursor(X,i);
		putchar(179);
		Console::setCursor((X+sizeX),i);
		putchar(179);
	}

	Console::setCursor(X, Y + sizeY);
	putchar(192);
	for (int i = X; i+1 < (X+sizeX); i++) 
		putchar(196);
	putchar(217);
	
	for (int i = X+1; i < (X+sizeX); i++)
		for (int j = Y+1; j < (Y + sizeY); j++) {
			Console::setCursor(i ,j);
			putchar(' ');
		}

	if((sizeX > text.length())&&(text.find_last_of('\n')==-1))
	{
		Console::setCursor((sizeX - text.length()) / 2 + X + 1, ((sizeY) / 2) + Y);
		for(int i = 0; text[i] != '\0'; i++)
			putchar(Console::toCyrillic(text[i]));
	}
	else
	{
		int row_length = text.find_first_of('\n');
		if(sizeX > row_length) {
			Console::setCursor((sizeX - row_length) / 2 + X + 1, (sizeY / 2) + Y);
			for(int i = 0; i < row_length; i++)
				putchar(Console::toCyrillic(text[i]));
		}
		if(sizeX > (text.length()-row_length+1)) {
			Console::setCursor((sizeX - (text.length()-(row_length+1))) / 2 + X + 1, sizeY + Y - 1);
			for(int i = row_length+1; text[i] != '\0'; i++)
				putchar(Console::toCyrillic(text[i]));
		}
	}
	Console::setCursor(0 ,0);
}
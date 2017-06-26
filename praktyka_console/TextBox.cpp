#include "stdafx.h"
#include "TextBox.h"

TextBox::TextBox(int x, int y, int size, int text_color, int background_color)
{
	TextBox::x = x;
	TextBox::y = y;
	TextBox::size = size;
	TextBox::lenText = 0;
	TextBox::text_color = text_color;
	TextBox::background_color = background_color;
	Draw(text_color, background_color);
}

void TextBox::setText(char * str)
{
	int count = 0;
	strcpy_s(text, str);
	while (*(str++) !='\0') count++;
	lenText = count;
	Draw(text_color, background_color);
}

char * TextBox::getText()
{
	return text;
}

int TextBox::Focus(int text_color, int background_color)
{
	Draw(text_color,background_color);
	int ret = 0; char c = '\0';
	while(lenText < 255)
	{
		text[lenText+1] = '\0';
		c = _getch();
		switch ((int)c) 
		{
		case 13: 
			{
				Draw(TextBox::text_color, TextBox::background_color);
				return 1;
			}
		case 72:
		case 75: 
			{
				text[--lenText] = '\0';
				Draw(TextBox::text_color, TextBox::background_color);
				return -1;
			}
		case 77:
		case 80: 
			{
				text[--lenText] = '\0';
				Draw(TextBox::text_color, TextBox::background_color);
				return 1;
			}
		}

		text[lenText] = c;
		if((int)text[lenText]==8) { if(lenText>0) lenText--; } else lenText++;

		Console::setCursor(x+1, y+1);
		for (int a = 0; a < size; a++) putchar(' ');

		Console::setCursor(x + 1, y + 1);
		if(lenText>size)
			for (int j = lenText-size; j < lenText; j++) putchar(text[j]);
		else 
			for (int j = 0; j < lenText; j++) putchar(text[j]);

	}
	return 0;
}

void TextBox::Draw(int text_color, int background_color)
{
	Console::setCursorColor(text_color, background_color);
	Console::setCursor(x,y);
	std::cout << (char)218;
	for (int i = 0; i < size; i++) std::cout << (char)196;
	std::cout << (char)191;

	Console::setCursor(x,y+1);
	std::cout << (char)179;
	for (int i = 0; i < size; i++) std::cout << " ";
	std::cout << (char)179;

	Console::setCursor(x,y+2);
	std::cout << (char)192;
	for (int i = 0; i < size; i++) std::cout << (char)196;
	std::cout << (char)217;
	Console::setCursorColor(TextBox::text_color,background_color);
	Console::setCursor(x+1, y+1);
	for (int a = 0; a < size; a++) putchar(' ');

	Console::setCursor(x + 1, y + 1);
	if(lenText>size)
		for (int j = lenText-size; j < lenText; j++) putchar(text[j]);
	else 
		for (int j = 0; j < lenText; j++) putchar(text[j]);
}
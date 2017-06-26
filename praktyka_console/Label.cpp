#include "stdafx.h"
#include "Label.h"
#include "Console.h"


Label::Label(int X, int Y, char * text = "Label", int text_color = 12, int background_color=15)
{
	Label::X = X; Label::Y = Y;
	Label::text = text;
	Label::text_color = text_color; 
	Label::background_color = background_color;
	Draw(text);
}

void Label::setText(char * text = "Label", int text_color = 12, int background_color=15)
{
	Label::text_color = text_color; 
	Label::background_color = background_color;
	Draw(text);
}

void Label::Draw(char * text)
{
	Console::setCursor(X, Y);
	Console::setCursorColor(text_color, background_color);
	while (*text != '\0')
		putchar(Console::toCyrillic(*(text++)));
}


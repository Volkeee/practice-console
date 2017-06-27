#pragma once
#include "Form.h"

class FormMsg : Form
{
public:
	FormMsg(char * title, char * msg, int color, int bg)
	{
		int sizeX = 40, sizeY=13, labelCoordX, labelCoordY = 5, buttonSixeX = 19, buttonSixeY = 2, buttonCoordX, buttonCoordY = 7;
		labelCoordX = ((sizeX-1)/2)-((strlen(msg)-1)/2);
		buttonCoordX = ((sizeX-1)/2)-((buttonSixeX-1)/2);
		Draw(sizeX, sizeY, title, color, bg);
		new Label(labelCoordX, labelCoordY, msg, bg,color);
		new Button(buttonCoordX, buttonCoordY, buttonSixeX, buttonSixeY, "OK", bg, color);
		getch();
	}

};

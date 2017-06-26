#pragma once
#include "Position.h"
#include "Size.h"

class GuiElementBase
{
public:
	GuiElementBase(Position* p, Size* s);
	~GuiElementBase(void);
	Position getPosition();
	Position setPosition();
private:
	GuiElementBase::Position position;
	GuiElementBase::Size size;
};


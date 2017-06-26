#include "stdafx.h"
#include "GuiElementBase.h"

GuiElementBase::GuiElementBase(Position* p, Size* s) :
	position(p->getX(), p->getY()),
	size(s->getHeight(), s->getWidth())
{

}


GuiElementBase::~GuiElementBase(void)
{
		delete this;
}

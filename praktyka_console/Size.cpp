#include "stdafx.h"
#include "Size.h"


Size::Size(int height, int width)
{
	this->height = height;
	this->width = width;
}

Size::~Size(void)
{
	delete this;
}

int Size::getHeight() {
	return this->height;
}

int Size::getWidth() {
	return this->width;
}

void Size::setWidth(int width) {
	this->width = width;
}

void Size::setHeight(int height) {
	this->height = height;
}

void Size::setValues(Size* value) {
	this->height = value->getHeight();
	this->width = value->getWidth();
}

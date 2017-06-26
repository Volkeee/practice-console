#include "stdafx.h"
#include "Position.h"


Position::Position(int x, int y) {
	this->setCoords(x, y);
};

Position::~Position(void)
{
	delete this;
}

int Position::getX() {
	return this->x;
};

int Position::getY() {
	return this->y;
};

void Position::setCoords(int x, int y) {
	this->x = x;
	this->y = y;
};

void Position::setCoords(Position* position) {
	this->x = position->getX();
	this->y = position->getY();
}



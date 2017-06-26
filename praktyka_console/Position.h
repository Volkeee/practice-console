#pragma once
class Position {
	int x, y;

public:
	Position::Position(int x, int y);
	Position::~Position();

	int Position::getX();
	int Position::getY();

	void setCoords(int x, int y);
	void Position::setCoords(Position* position);
	};


#pragma once
class Size {
		int height, width;
public:
		Size::Size(int height, int width);
		Size::~Size();
		int Size::getHeight();
		int Size::getWidth();
		void Size::setHeight(int width);
		void Size::setWidth(int height);
		void Size::setValues(Size* value);
	};


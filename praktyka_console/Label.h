#pragma once

class Label
{
public:
	~Label(void);

	Label(int X, int Y, char * text,
		int text_color, int background_color);
	
	void setText(char * text,
		int text_color, int background_color);

private:
	int X, Y,
		text_color,
		background_color;
	char * text;
	
	void Draw(char * text);
};


#pragma once

class Label
{
public:
	//Деструктор
	~Label(void);

	//Створює Label за вказаними параметрами
	Label(int X, int Y, char * text,
		int text_color, int background_color);
	
	//Змінює колір та надпис
	void setText(char * text,
		int text_color, int background_color);

private:
	//Кординати
	int X, Y,
		text_color,
		background_color;
	char * text;
	
	//Перемальовує напис
	void Draw(char * text);
};


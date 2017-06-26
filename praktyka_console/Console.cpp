#include "stdafx.h"
#include "Console.h"

void Console::setCursor(int x, int y)
{
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(hConsole(), position);
}

void Console::setSize(int cols, int lines)
{
	char str[256];
	sprintf_s(str, "%s%d%s%d","mode con cols=",cols," lines=",lines);
	system(str);
}

void Console::setColor(int text, int background)
{
	char str[256];
	sprintf_s(str, "%s%d%d", "color ", text, background);
	system(str);
}

void Console::setCursorColor(int text, int background)
{
	SetConsoleTextAttribute(hConsole(), (WORD)((background << 4) | text));
}

HANDLE Console::hConsole() {
	return GetStdHandle(STD_OUTPUT_HANDLE);
}

char Console::toCyrillic(char с)
{
	switch (с) {
	case 'à': с = char(-96); break;
	case 'á': с = char(-95); break;
	case 'â': с = char(-94); break;
	case 'ã': с = char(-93); break;
	case 'ä': с = char(-92); break;
	case 'å': с = char(-91); break;
	case 'º': с = char(-243); break;
	case 'æ': с = char(-90); break;
	case 'ç': с = char(-89); break;
	case 'è': с = char(-88); break;
	case '³': с = 'i';  break;
	case 'é': с = char(-87); break;
	case 'ê': с = char(-86); break;
	case 'ë': с = char(-85); break;
	case 'ì': с = char(-84); break;
	case 'í': с = char(-83); break;
	case 'î': с = char(-82); break;
	case 'ï': с = char(-81); break;
	case 'ð': с = char(-32); break;
	case 'ñ': с = char(-31); break;
	case 'ò': с = char(-30); break;
	case 'ó': с = char(-29); break;
	case 'ô': с = char(-28); break;
	case 'õ': с = char(-27); break;
	case 'ö': с = char(-26); break;
	case '÷': с = char(-25); break;
	case 'ø': с = char(-24); break;
	case 'ù': с = char(-23); break;
	case 'ü': с = char(-20); break;
	case 'þ': с = char(-18); break;
	case 'ÿ': с = char(-17); break;
	case 'À': с = char(-128); break;
	case 'Á': с = char(-127); break;
	case 'Â': с = char(-126); break;
	case 'Ã': с = char(-125); break;
	case 'Ä': с = char(-124); break;
	case 'Å': с = char(-123); break;
	case 'ª': с = char(-242); break;
	case 'Æ': с = char(-122); break;
	case 'Ç': с = char(-121); break;
	case 'È': с = char(-120); break;
	case 'É': с = char(-119); break;
	case 'Ê': с = char(-118); break;
	case 'Ë': с = char(-117); break;
	case 'Ì': с = char(-116); break;
	case 'Í': с = char(-115); break;
	case 'Î': с = char(-114); break;
	case 'Ï': с = char(-113); break;
	case 'Ð': с = char(-112); break;
	case 'с': с = char(-111); break;
	case 'Ò': с = char(-110); break;
	case 'Ó': с = char(-109); break;
	case 'Ô': с = char(-108); break;
	case 'Õ': с = char(-107); break;
	case 'Ö': с = char(-106); break;
	case '×': с = char(-105); break;
	case 'Ø': с = char(-104); break;
	case 'Ù': с = char(-103); break;
	case 'Ü': с = char(-100); break;
	case 'Þ': с = char(-98);  break;
	case 'ß': с = char(-97);  break;
	}
	return с;
}

Console::~Console(void)
{
}

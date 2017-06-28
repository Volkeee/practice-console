#pragma once
#include "form.h"
#include "Tools.h"
#include <fstream>
#include <iostream>
#include <sstream>

class FormHelp :
	public Form
{
public:
	FormHelp(void) {
	}

	~FormHelp(void) {

	}

	void Initialize() {
		bool exit = false;
		
			std::vector<char*> lines;

			std::ifstream ifs("help.txt");
			Logger* logger = new Logger();
			auto line = std::string();

			int maxLength = 0, iterator = 0;
			while(std::getline(ifs, line)) {
				char * charValue = new char[line.size()+1];
				charValue[line.size()] = '\0';
				std::copy(line.begin(), line.end(), charValue);
				lines.push_back(charValue);
				if(maxLength < line.size()) {
					maxLength = line.size();
				}
			}
			Draw(maxLength+6, lines.size()+8, "Help");

			std::vector<char*>::iterator it = lines.begin();
			while (it !=lines.end()) {
				new Label(3, iterator+5, *it, 0,7);
				it++; iterator++;
			}
		while(!exit) {
			if(_getch() == 8) exit = true;
		}
	}
};


#pragma once
#include "Form.h"
#include "Tools.h"
#include "FormEntrySelected.h"

class FormList : public Form 
{
private:
	std::vector<WebsiteEntry*> *entries;
	FileWorker *worker;
	FormEntrySelected *formSelected;
	Logger *logger;
public:
	FormList()
	{
		worker = new FileWorker();
		entries = new std::vector<WebsiteEntry*>();
		logger = new Logger();
		formSelected = new FormEntrySelected();
	}

	void Print()
	{
		worker->readEntries(entries);
		Draw(85, 25, "Ñïèñîê");
		new Label(3, 4, "ID          ", 15, 0);
		new Label(15, 4, "Name                     ", 15, 0);
		new Label(40, 4, "Type           ", 15, 0);
		new Label(55, 4, "Views          ", 15, 0);
		new Label(70, 4, "Pagerank    ", 15, 0);

		std::vector<WebsiteEntry*>::const_iterator it = entries->begin();
		int i = 0;
		while(it != entries->end()) {
			std::string entry = std::to_string((*it)->getID());
			char * charValue = new char[entry.size()+1];
			charValue[entry.size()] = '\0';
			std::copy(entry.begin(), entry.end(), charValue);
			new Label(3, 5+i, charValue, 0, 7);
			
			entry = (*it)->getName();
			charValue = new char[entry.size()+1];
			charValue[entry.size()] = '\0';
			std::copy(entry.begin(), entry.end(), charValue);
			new Label(15, 5+i, charValue, 0, 7);

			entry = (*it)->getType();
			charValue = new char[entry.size()+1];
			charValue[entry.size()] = '\0';
			std::copy(entry.begin(), entry.end(), charValue);
			new Label(40, 5+i, charValue, 0, 7);

			entry = std::to_string((*it)->getViews());
			charValue = new char[entry.size()+1];
			charValue[entry.size()] = '\0';
			std::copy(entry.begin(), entry.end(), charValue);
			new Label(55, 5+i, charValue, 0, 7);

			entry = std::to_string((*it)->getPagerank());
			charValue = new char[entry.size()+1];
			charValue[entry.size()] = '\0';
			std::copy(entry.begin(), entry.end(), charValue);
			new Label(70, 5+i, charValue, 0, 7);
			i++; it++;
		}
		bool exit = false; int iterator = 5;
		while(!exit) {
			new Label(1, iterator, "X", 0, 7);
			switch(_getch()) {
			case 72: Console::setCursor(1, iterator); putchar(186); iterator--; break;
			case 80: Console::setCursor(1, iterator); putchar(186); iterator++; break;
//TODO: Call FormEdit
			case 13:
				WebsiteEntry* entry = entries->at(iterator-5); 
				formSelected->Initialize(entry);
				break;
			}
			if(iterator > entries->size()+4) iterator = 5;
			if(iterator < 5) iterator = entries->size()+4;
		}
	}

	~FormList(void)
	{
	}
};
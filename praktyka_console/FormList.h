﻿#include "Form.h"
#include "Tools.h"
#include "FormEntrySelected.h"

class FormList : public Form 
{
private:
	std::vector<WebsiteEntry*> *entries;
	FileWorker *worker;
	FormEntrySelected *formSelected;
	FormAdd *formAdd;
	Logger *logger;
public:
	FormList()
	{
		worker = new FileWorker();
		entries = new std::vector<WebsiteEntry*>();
		logger = new Logger();
		formSelected = new FormEntrySelected();
		formAdd = new FormAdd();
	}

	void Print(std::vector<WebsiteEntry*> *entries, bool edit)
	{
		Draw(85, entries->size()+8, "Ñïèñîê");
		new Label(3, 4, "ID          ", 15, 0);
		new Label(15, 4, "Name                     ", 15, 0);
		new Label(40, 4, "Type           ", 15, 0);
		new Label(55, 4, "Views          ", 15, 0);
		new Label(70, 4, "Pagerank    ", 15, 0);

		std::vector<WebsiteEntry*>::const_iterator it = entries->begin();
		int i = 0;
		new Label(3, 5, "1", 0, 7);
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
			
			int index = (*it)->getID() + 1;
			entry = std::to_string(index);			
			charValue = new char[entry.size()+1];
			charValue[entry.size()] = '\0';
			std::copy(entry.begin(), entry.end(), charValue);

			i++; it++;
			if (edit) {
				if(it == entries->end()) {
					new Label(3, 5+i, charValue, 0, 7);
				}
			}
		}
		bool exit = false; int iterator = 5;
		if(edit) {
			while(!exit) {
				new Label(1, iterator, "X", 0, 7);
				switch(_getch()) {
				case 72: Console::setCursor(1, iterator); putchar(186); iterator--; break;
				case 80: Console::setCursor(1, iterator); putchar(186); iterator++; break;
				case 13:
					if(!entries->empty()) {
						if(iterator-5 < entries->size()) {
							WebsiteEntry* entry = entries->at(iterator-5); 
							formSelected->Initialize(entry);
							formSelected->Show();
							worker->readEntries(entries);
							this->Print(entries, true);
							exit = true;
						} else {
							WebsiteEntry* entry = new WebsiteEntry();
							entry->setID(iterator-4);
							formAdd->Initialize(entry);
							worker->readEntries(entries);
							this->Print(entries, true);
							exit = true;
						}
					} else {
							WebsiteEntry* entry = new WebsiteEntry();
							entry->setID(iterator-4);
							formAdd->Initialize(entry);
							worker->readEntries(entries);
							this->Print(entries, true);
							exit = true;
					}
					break;
				case 8: 
					exit = true;
					break;
				case 73:
					Console::setCursor(1, iterator); 
					putchar(186);
					iterator-=10;
					break;
				case 81:
					Console::setCursor(1, iterator); 
					putchar(186);
					iterator+=10;
					break;
				case 71:
					Console::setCursor(1, iterator); 
					putchar(186);
					iterator=5;
					break;
				case 79:
					Console::setCursor(1, iterator); 
					putchar(186);
					iterator=entries->size()+5;
					break;
				}
				if(iterator > entries->size()+5) iterator = 5;
				if(iterator < 5) iterator = entries->size()+5;
			} 
		} else {
			bool editExit = false;
			while(!exit)
				if(_getch() == 8) 
					exit = true;
		}
	}

	~FormList(void)
	{
	}
};
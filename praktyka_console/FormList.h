#pragma once
#include "Form.h"
#include "Tools.h"

class FormList : public Form 
{
private:
	std::vector<WebsiteEntry*> *entries;
	FileWorker *worker;
public:
	FormList()
	{
		worker = new FileWorker();
		entries = new std::vector<WebsiteEntry*>();
	}

	void Print()
	{
		worker->readEntries(entries);
		Draw(100, 100, "Список");
		new Label(3 , 4, "Iм'я         "  , 15, 0);
		new Label(15, 4, "Прізвище       ", 15, 0);
		new Label(30, 4, "Номер       "   , 15, 0);
		new Label(45, 4, "Номер       "   , 15, 0);
		new Label(60, 4, "Номер       "   , 15, 0);

		std::vector<WebsiteEntry*>::const_iterator it = entries->begin();
		int i = 0;
		while(it != entries->end()) {
			std::string str = std::to_string((*it)->getID());
			char * charValue = new char[str.size() + 1];
			std::copy(str.begin(), str.end(), charValue);
			new Label(3, 5+i, charValue, 0, 7);
			
			str = (*it)->getName();
			charValue = new char[str.size() +1];
			std::copy(str.begin(), str.end(), charValue);
			new Label(15, 5+i, charValue, 0, 7);

			str = (*it)->getType();
			charValue = new char[str.size() +1];
			std::copy(str.begin(), str.end(), charValue);
			new Label(30, 5+i, charValue, 0, 7);

			str = (*it)->getViews();
			charValue = new char[str.size() +1];
			std::copy(str.begin(), str.end(), charValue);
			new Label(45, 5+i, charValue, 0, 7);

			str = (*it)->getPagerank();
			charValue = new char[str.size() +1];
			std::copy(str.begin(), str.end(), charValue);
			new Label(60, 5+i, charValue, 0, 7);
			i++; it++;
		}
		_getch();
	}

	~FormList(void)
	{
	}
};
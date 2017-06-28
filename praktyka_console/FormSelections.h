#pragma once
#include "form.h"
class FormSelections :
	public Form
{
public:
	FormList *formList;
	FormSelections(void) {
		//Initialize();
	}

	~FormSelections(void){

	}

	void Initialize() {
		formList = new FormList();
		Show();
	}

	void Show()
	{
		bool exit = false;
		FileWorker* worker = new FileWorker();
		std::vector<WebsiteEntry*> *entries = new std::vector<WebsiteEntry*>();
		
		//TODO: Resize console
		Draw(29, 43, "Websites");
		//TODO: Change the names of buttons and create additional butts
		Button * eB1 = new Button(4, 5, 20, 3, "Selection1", 0, 7);
		Button * eB2 = new Button(4, 10, 20, 3,"Selection2", 0 ,7);
		Button * eB3 = new Button(4, 15, 20, 3,"Selection3", 0 ,7);
		Button * eB4 = new Button(4, 20, 20, 3,"Selection4", 0 ,7);
		Button * eB5 = new Button(4, 25, 20, 3,"Selection4", 0 ,7);
		Button * eB6 = new Button(4, 30, 20, 3,"Selection4", 0 ,7);
		Button * eB7 = new Button(4, 37, 20, 2,"Back", 0 ,7);

		int ret, menu = 0; 
		while(!exit)
		{
			worker->readEntries(entries);
			//TODO: Add more cases
			switch(menu)
			{
			case 0:
				if((ret=eB1->Focus(7, 0))==0) {
					std::vector<WebsiteEntry*>::const_iterator i = entries->begin();
					while (i != entries->end()) {
						if((*i)->getPagerank() <= 0.5) {
							i = entries->erase(i);
						} else i++;
					}
					formList->Print(entries, false);
					this->Show();
					exit = true;
				}
				break;
			case 1:
				if((ret=eB2->Focus(7, 0))==0) {
					std::vector<WebsiteEntry*>::const_iterator i = entries->begin();
					float maxPagerank = 0;

					while (i != entries->end()) {
						if((*i)->getPagerank() > maxPagerank) {
							maxPagerank = (*i)->getPagerank();
							i++;
						} else i++;
					}

					i = entries->begin();
					while (i != entries->end()) {
						if((*i)->getPagerank() != maxPagerank) {
							i = entries->erase(i);
						} else i++;
					}
					formList->Print(entries, false);
					this->Show();
					exit = true;
				}
				break;
			case 2:
				if((ret=eB3->Focus(7, 0))==0) {
					std::vector<WebsiteEntry*>::const_iterator i = entries->begin();
					while (i != entries->end()) {
						if((*i)->getViews() <= 50) {
							i = entries->erase(i);
						} else i++;
					}

					formList->Print(entries, false);
					this->Show();
					exit = true;
				}
				break;
			case 3: 
				if((ret=eB4->Focus(7, 0))==0) {
					std::vector<WebsiteEntry*>::const_iterator i = entries->begin();
					while (i != entries->end()) {
						if((*i)->getType().compare("blog")) {
							i = entries->erase(i);
						} else i++;
					}

					formList->Print(entries, false);
					this->Show();
					exit = true;
				}
				break;
			case 4: 
				if((ret=eB5->Focus(7, 0))==0) {					
					std::vector<WebsiteEntry*>::const_iterator i = entries->begin();
					while (i != entries->end()) {
						std::string string = (*i)->getName();
						if((string.substr(string.find_last_of(".") + 1).compare("ua"))
							&& (string.substr(string.find_last_of(".") + 1).compare("com"))) {
								i = entries->erase(i);
						} else i++;
					}

					formList->Print(entries, false);
					this->Show();
					exit = true;
				}
				break;
			case 5: 
				if((ret=eB6->Focus(7, 0))==0) {
					std::vector<WebsiteEntry*>::const_iterator i = entries->begin();
					while (i != entries->end()) {
						std::string string = (*i)->getName();
						if((string.substr(string.find_last_of(".") + 1).compare("ua"))
							|| (*i)->getPagerank() <= 0.7) {
								i = entries->erase(i);
						} else i++;
					}

					formList->Print(entries, false);
					this->Show();
					exit = true;
				}
				break;
			case 6:
				if((ret=eB7->Focus(7, 0))==0) {
					exit = true;
				}
				break;
			}
			//TODO: Change the values for suiting the buttons count
			menu+=ret;
			if(menu < 0) 
				menu = 6;
			if(menu > 6) 
				menu = 0;
		}
	}
};


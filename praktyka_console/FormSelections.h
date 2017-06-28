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
		worker->readEntries(entries);
		//TODO: Resize console
		Draw(29, 35, "Websites");
		//TODO: Change the names of buttons and create additional butts
		Button * eB1 = new Button(4, 5, 20, 3, "Selection1", 0, 7);
		Button * eB2 = new Button(4, 10, 20, 3,"Selection2", 0 ,7);
		Button * eB3 = new Button(4, 15, 20, 3,"Selection3", 0 ,7);
		Button * eB4 = new Button(4, 20, 20, 3,"Selection4", 0 ,7);
		Button * eB5 = new Button(4, 29, 20, 2,"Back", 0 ,7);

		int ret, menu = 0; 
		while(!exit)
		{
			//TODO: Add more cases
			switch(menu)
			{
			case 0:
				if((ret=eB1->Focus(7, 0))==0) {
					//TODO: Sort the vector and "feed" it to the ->Print Method with "false" as second argument
					formList->Print(entries, false);
					this->Show();
					exit = true;
				}
				break;
			case 1:
				if((ret=eB2->Focus(7, 0))==0) {
					//TODO: Sort the vector and "feed" it to the ->Print Method with "false" as second argument					
					formList->Print(entries, false);
					this->Show();
					exit = true;
				}
				break;
			case 2:
				if((ret=eB3->Focus(7, 0))==0) {
					//TODO: Sort the vector and "feed" it to the ->Print Method with "false" as second argument
					formList->Print(entries, false);
					this->Show();
					exit = true;
				}
				break;
			case 3: 
				if((ret=eB4->Focus(7, 0))==0) {
					//TODO: Sort the vector and "feed" it to the ->Print Method with "false" as second argument
					formList->Print(entries, false);
					this->Show();
					exit = true;
				}
				break;
			case 4:
				if((ret=eB5->Focus(7, 0))==0) {
					exit = true;
				}
				break;
			}
			//TODO: Change the values for suiting the buttons count
			menu+=ret;
			if(menu < 0) 
				menu = 4;
			if(menu > 4) 
				menu = 0;
		}
	}
};


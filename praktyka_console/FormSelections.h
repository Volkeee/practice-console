#pragma once
#include "form.h"
class FormSelections :
	public Form
{
public:
	FormList *formList;
	FormSelections(void) {
		Initialize();
	}

	~FormSelections(void){

	}

	void Initialize() {
		formList = new FormList();
		Show();
	}

	void Show()
	{
		FileWorker* worker = new FileWorker();
		std::vector<WebsiteEntry*> *entries = new std::vector<WebsiteEntry*>();
		//TODO: Resize console
		Draw(29, 31, "Websites");
		//TODO: Change the names of buttons and create additional butts
		Button * eB1 = new Button(4, 5, 20, 3, "Selections", 0, 7);
		Button * eB2 = new Button(4, 10, 20, 3,"Create/open\nnew file", 0 ,7);
		Button * eB3 = new Button(4, 15, 20, 3,"Website\nlist", 0 ,7);
		Button * eB4 = new Button(4, 20, 20, 2,"Exit", 0 ,7);

		int ret, menu = 0;
		while(true)
		{
			//TODO: Add more cases
			switch(menu)
			{
			case 0:
				if((ret=eB1->Focus(7, 0))==0) {
					//TODO: Sort the vector and "feed" it to the ->Print Method with "false" as second argument
					formList->Print();
				}
				break;
			case 1:
				if((ret=eB2->Focus(7, 0))==0) {
					//TODO: Sort the vector and "feed" it to the ->Print Method with "false" as second argument
					formList->Print();
				}
				break;
			case 2:
				if((ret=eB3->Focus(7, 0))==0) {
					//TODO: Sort the vector and "feed" it to the ->Print Method with "false" as second argument
					formList->Print();
				}
				break;
			case 3: 
				if((ret=eB4->Focus(7, 0))==0) {
					//TODO: Sort the vector and "feed" it to the ->Print Method with "false" as second argument
					formList->Print();
				}
				break;
			}
			//TODO: Change the values for suiting the buttons count
			if(ret==0) 
				Show();
			menu+=ret;
			if(menu < 0) 
				menu = 3;
			if(menu > 3) 
				menu = 0;
		}
	}
};


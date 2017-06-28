#include "Form.h"
#include "FormOpen.h"
#include "FormList.h"
#include "FormSelections.h"

class FormMenu : public Form
{
public:
	FormMenu(void)
	{
		Initialize();		
	}

	~FormMenu()
	{
		delete formOpen;
		delete formList;
	}

	char file [255]; 
	FormOpen *formOpen;
	FormList *formList;
	FormSelections *formSelections;

	void Initialize()
	{
		formOpen = new FormOpen();
		formList = new FormList();
		formSelections = new FormSelections();
		Show();
	}

	void Show()
	{
		FileWorker* worker = new FileWorker();
		std::vector<WebsiteEntry*> *entries = new std::vector<WebsiteEntry*>();
		Draw(29, 31, "Websites");
		Button * eB2 = new Button(4, 5, 20, 3, "Selections", 0, 7);
		Button * eB3 = new Button(4, 10, 20, 3,"Create/open\nnew file", 0 ,7);
		Button * eB4 = new Button(4, 15, 20, 3,"Website\nlist", 0 ,7);
		Button * eB5 = new Button(4, 20, 20, 2,"Exit", 0 ,7);

		int ret, menu = 0;
		while(true)
		{
			switch(menu)
			{
			case 0: 
				if((ret=eB2->Focus(7, 0))==0) {
					formSelections->Show();
				}

				break;
			case 1: if((ret=eB3->Focus(7, 0))==0) formOpen->Initialize();
				break;
			case 2: 
				if((ret=eB4->Focus(7, 0))==0) {
					worker->readEntries(entries);
					formList->Print(entries, true);
				}
				break;
			case 3: if((ret=eB5->Focus(7, 0))==0) exit(0);
				break;
			}

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

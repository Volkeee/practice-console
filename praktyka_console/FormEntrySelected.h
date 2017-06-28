#include "FormAdd.h"
#include "Tools.h"

class FormEntrySelected :
	public Form
{
public:
	FormAdd *formAdd;
	FormAdd *formEdit;
	FileWorker *worker;
	WebsiteEntry* entry;

	FormEntrySelected() {
	}

	~FormEntrySelected(void) {

	}

	void Initialize(WebsiteEntry* entry) {
		formAdd = new FormAdd();
		formEdit = new FormAdd();
		worker = new FileWorker();
		this->entry = entry;
	}

	void Show() {
		int ret, menu = 0;
		bool exit = false;
		Draw(29, 22, "Choose action");
		Button * eB1 = new Button(4, 5, 20, 3,"Edit selected", 0 ,7);
		Button * eB2 = new Button(4, 10, 20, 3,"Add at\nselected position", 0 ,7);
		Button * eB3 = new Button(4, 15, 20, 3,"Delete selected", 0 ,7);

		while(!exit)
		{
			switch(menu)
			{
			case 0: 
				if((ret=eB1->Focus(7, 0))==0) {
					formEdit->InitializeForEdit(entry);
					exit = true;
				}
				break;
			case 1: 
				if((ret=eB2->Focus(7, 0))==0) {
					formAdd->Initialize();
					exit = true;
				}
				break;
			case 2: 
				if((ret=eB3->Focus(7, 0))==0) {
					worker->deleteEntry(entry);
					new FormMsg("Message","Entry has been deleted",7,2);
					exit = true;
				}
				break;
			}

			menu+=ret;
			if(menu < 0)
				menu = 2;
			if(menu > 2) 
				menu = 0;
		}
	}
};


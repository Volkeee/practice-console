#include "FormAdd.h"

class FormEntrySelected :
	public Form
{
public:
	FormAdd *formAdd;
	FormAdd *formEdit;
	WebsiteEntry* entry;

	FormEntrySelected() {
	}

	~FormEntrySelected(void) {

	}

	void Initialize(WebsiteEntry* entry) {
		formAdd = new FormAdd();
		formEdit = new FormAdd();
		this->entry = entry;
	}

	void Show() {
		Draw(29, 31, "Choose action");
		Button * eB1 = new Button(4, 5, 20, 3,"Edit selected", 0 ,7);
		Button * eB2 = new Button(4, 10, 20, 3,"Add at\nselected position", 0 ,7);
		Button * eB3 = new Button(4, 15, 20, 3,"Delete selected", 0 ,7);

		int ret, menu = 0;
		while(true)
		{
			switch(menu)
			{
			case 0: if((ret=eB1->Focus(7, 0))==0) formAdd->Initialize();
				break;
			case 1: if((ret=eB2->Focus(7, 0))==0) formEdit->InitializeForEdit(entry);
				break;
			}
	}
	}
};


#include "Form.h"
#include "FormOpen.h"
#include "FormList.h"

class FormMenu : public Form
{
public:
	FormMenu(void)
	{
		Initialize();
	}

	~FormMenu()
	{
		delete f_add;
		delete f_open;
		delete f_print;
	}

	char file [255]; 
	FormAdd  *f_add;
	FormOpen *f_open;
	FormList *f_print;

	void Initialize()
	{
		f_open = new FormOpen();
		f_add = new FormAdd();
		f_print = new FormList();
		Show();
	}

	void Show()
	{
		Draw(29, 31, "Websites");
		Button * eB2 = new Button(4, 5, 20, 3,"Add new\nwebsite", 0 ,7);
		Button * eB3 = new Button(4, 10, 20, 3,"Create/open\nnew file", 0 ,7);
		Button * eB4 = new Button(4, 15, 20, 3,"Website\nlist", 0 ,7);
		Button * eB5 = new Button(4, 20, 20, 2,"Exit", 0 ,7);

		int ret, menu = 0;
		while(true)
		{
			switch(menu)
			{
			case 0: if((ret=eB2->Focus(7, 0))==0) f_add->Initialize();
				break;
			case 1: if((ret=eB3->Focus(7, 0))==0) f_open->Initialize();
				break;
			case 2: if((ret=eB4->Focus(7, 0))==0) f_print->Print();
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

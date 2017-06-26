#pragma once
#include "Form.h"
#include "WebsiteEntry.h"
#include <vector>
#include <algorithm>


class FormAdd : public Form
{
public:
	Label* label1;
	Label* label2;
	Label* label3;
	Label* label4;

	TextBox* textBox1;
	TextBox* textBox2;
	TextBox* textBox3;
	TextBox* textBox4;

	Button* button1;
	Button* button2;

	FormAdd()
	{
		//Initialize();
	}

	int Initialize(char * F)
	{
		Draw(40, 21, "Добавлення запису");

		label1 = new Label(4,6, "Domain:",0,7);
		label2 = new Label(4,9, "Type:",0,7);
		label3 = new Label(4,12,"Views:",0,7);
		label4 = new Label(4, 15, "Pagerank:",0,7);

		textBox1 = new TextBox(13,5,21,0,7);
		textBox2 = new TextBox(13,8,21,0,7);
		textBox3 = new TextBox(13,11,21,0,7);
		textBox4 = new TextBox(13,14,21,0,7);

		button1 = new Button(4, 15, 15, 2, "Добавити", 0 ,7);
		button2 = new Button(20,15, 15, 2, "Відміна", 0 ,7);

		//cBase<Contact> *bs = new cBase<Contact>(F);
		std::vector<WebsiteEntry*> *entries = new std::vector<WebsiteEntry*>();
		switch(menu())
		{
		case 1:
			{
				WebsiteEntry* entry = new WebsiteEntry();				

				entry->setName(textBox1->getText());
				entry->setType(textBox2->getText());
				entry->setViews(stol(textBox3->getText()));
				entry->setPagerank(stof(textBox4->getText()));

				entries->push_back(entry);

			}
		case 2:
			{

			}
		}
		return 0;
	}

	int menu()
	{
		int ret = 1, m = 0, ex = 1;
		while(ex)
		{
			switch(m)
			{
			case 0: ret = textBox1->Focus(1, 7);
				break;
			case 1: ret = textBox2->Focus(1, 7);
				break;
			case 2: ret = textBox3->Focus(1, 7);
				break;
			case 3: if((ret = button1->Focus(1, 7))==0) return 1;
				break;
			case 4: if((ret = button2->Focus(1, 7))==0) return 2;
				break;
			}

			m+=ret;
			if(m < 0) m = 4;
			if(m > 4) m = 0;
		}
		return 0;
	}

};
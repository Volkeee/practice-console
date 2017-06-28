#include "Form.h"
#include "WebsiteEntry.h"
#include "Tools.h"
#include <vector>
#include <algorithm>


class FormAdd : public Form
{
public:
	Label* label1;
	Label* label2;
	Label* label3;
	Label* label4;
	Label* label5;

	TextBox* textBox1;
	TextBox* textBox2;
	TextBox* textBox3;
	TextBox* textBox4;
	TextBox* textBox5;

	Button* button1;
	Button* button2;

	FormAdd()
	{
	}

	int InitializeForEdit(WebsiteEntry* entry) {
		FileWorker *worker = new FileWorker();
		Draw(40, 24, "Edit selected entry");

		label1 = new Label(4,6, "Domain:",0,7);
		label2 = new Label(4,9, "Type:",0,7);
		label3 = new Label(4,12,"Views:",0,7);
		label4 = new Label(4, 15, "Pagerank:",0,7);

		std::string string = entry->getName();
		char * charValue = new char[string.size()+1];
		charValue[string.size()] = '\0';
		std::copy(string.begin(), string.end(), charValue);
		textBox1 = new TextBox(13,5,21,0,7);
		textBox1->setText(charValue);

		string = entry->getType();
		charValue = new char[string.size()+1];
		charValue[string.size()] = '\0';
		std::copy(string.begin(), string.end(), charValue);
		textBox2 = new TextBox(13,8,21,0,7);
		textBox2->setText(charValue);

		string = std::to_string(entry->getViews());
		charValue = new char[string.size()+1];
		charValue[string.size()] = '\0';
		std::copy(string.begin(), string.end(), charValue);
		textBox3 = new TextBox(13,11,21,0,7);
		textBox3->setText(charValue);

		string = std::to_string(entry->getPagerank());
		charValue = new char[string.size()+1];
		charValue[string.size()] = '\0';
		std::copy(string.begin(), string.end(), charValue);
		textBox4 = new TextBox(13,14,21,0,7);
		textBox4->setText(charValue);

		button1 = new Button(4, 18, 15, 2, "Edit", 0 ,7);
		button2 = new Button(20,18, 15, 2, "Cancel", 0 ,7);

		//cBase<Contact> *bs = new cBase<Contact>(F);
		switch(menu())
		{
		case 1:
			{
				WebsiteEntry* entry1 = new WebsiteEntry();

				entry1->setID(entry->getID());
				entry1->setName(textBox1->getText());
				entry1->setType(textBox2->getText());
				entry1->setViews(std::stol(textBox3->getText()));
				entry1->setPagerank(std::stof(textBox4->getText()));

				worker->editEntry(entry1);
			}
		case 2:
			{

			}
		}
		return 0;
	}

	int Initialize()
	{
		FileWorker *worker = new FileWorker();
		Draw(40, 50, "Add new entry");

		label1 = new Label(4,6, "Domain:",0,7);
		label2 = new Label(4,9, "Type:",0,7);
		label3 = new Label(4,12,"Views:",0,7);
		label4 = new Label(4, 15, "Pagerank:",0,7);

		textBox1 = new TextBox(13,5,21,0,7);
		textBox2 = new TextBox(13,8,21,0,7);
		textBox3 = new TextBox(13,11,21,0,7);
		textBox4 = new TextBox(13,14,21,0,7);

		button1 = new Button(4, 18, 15, 2, "Add", 0 ,7);
		button2 = new Button(20,18, 15, 2, "Cancel", 0 ,7);

		//cBase<Contact> *bs = new cBase<Contact>(F);
		switch(menu())
		{
		case 1:
			{
				WebsiteEntry* entry = new WebsiteEntry();

				entry->setID(worker->getIDIncrement()+1);
				entry->setName(textBox1->getText());
				entry->setType(textBox2->getText());
				entry->setViews(std::stol(textBox3->getText()));
				entry->setPagerank(std::stof(textBox4->getText()));

				worker->writeToEnd(entry);
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
			case 3: ret = textBox4->Focus(1, 7); 
				break;
			case 6: if((ret = button1->Focus(1, 7))==0) return 1;
				break;
			case 7: if((ret = button2->Focus(1, 7))==0) return 2;
				break;
			}

			m+=ret;
			if(m < 0) m = 7;
			if(m > 8) m = 0;
		}
		return 0;
	}

};
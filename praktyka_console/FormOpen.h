#include "form.h"
#include "Message.h"
#include "Tools.h"

class FormOpen : public Form
{
public:
	FormOpen()
	{
		Initialize();
	}

	TextBox *tb1;

	void Initialize()
	{
		Draw(30, 10, "Type the path to file");
		tb1 = new TextBox(3,5,22,0,7);

		tb1->Focus(0,7);
		if(tb1->getTextLength() != 0)
			FileWorker::filePath = tb1->getText();
		else FileWorker::filePath = "data.txt";
	}
};

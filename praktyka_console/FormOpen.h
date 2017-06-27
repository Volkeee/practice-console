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

		while(tb1->Focus(0,7)!=2)
		FileWorker::filePath = tb1->getText();
	}
};

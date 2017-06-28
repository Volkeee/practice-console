#include "stdafx.h"
#include "FormMenu.h"
#include <algorithm>
#include <vector>

std::vector<WebsiteEntry*> *entriesVector;
FileWorker* fileWorker;
Logger* logger;

int _tmain(int argc, _TCHAR* argv[]) 
{
	
	logger = new Logger("log.txt");
	logger->clearLog();
	new FormMenu();
};
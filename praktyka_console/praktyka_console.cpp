// praktyka_console.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Logger.h"
#include "WebsiteEntry.h"
#include "Tools.h"
#include <algorithm>
#include <vector>

vector<WebsiteEntry*> *entriesVector;
FileWorker* fileWorker;
Logger* logger;

int _tmain(int argc, _TCHAR* argv[]) 
{
	logger = new Logger("log.txt");
	logger->clearLog();
	entriesVector = new std::vector<WebsiteEntry*>();

	FileWorker* fileWorker = new FileWorker("data1.txt");

	fileWorker->readEntries(entriesVector);

	size_t count = 0;
	std::for_each(entriesVector->begin(), entriesVector->end(), [&count](WebsiteEntry* entry) {
		logger->i("Object on position " + std::to_string(count) + " in \"entriesVector\": " + entry->toString());
		++count;
	});

	WebsiteEntry* deletedEntry = new WebsiteEntry(99, "deleted", "deleted", 99999, 0.0 );
	entriesVector->push_back(deletedEntry);

	fileWorker->writeEntries(*entriesVector);
	WebsiteEntry* editedEntry = new WebsiteEntry(99, "yeah", "rrroooooock", 1488, 2.28 );

	fileWorker->editEntry(entriesVector, editedEntry);
}
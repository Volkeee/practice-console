#pragma once
#include "WebsiteEntry.h"
#include "Logger.h"
#include <vector>

class FileWorker {
	private:
		Logger* logger;
		std::string dataFilePath;
	public:
		FileWorker::FileWorker(std::string filePath);
		FileWorker::~FileWorker();
		void FileWorker::writeEntries(std::vector<WebsiteEntry*> entries);
		void FileWorker::readEntries(std::vector<WebsiteEntry*> *entries);
		void FileWorker::deleteEntry(std::vector<WebsiteEntry*> *entries, WebsiteEntry* entry);
		void FileWorker::editEntry(std::vector<WebsiteEntry*> *entries, WebsiteEntry* entry);
		bool FileWorker::checkIDUnicity(std::vector<WebsiteEntry* > *entries, WebsiteEntry* entry);
};

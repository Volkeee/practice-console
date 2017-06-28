#pragma once
#include "WebsiteEntry.h"
#include "Logger.h"
#include <vector>

class FileWorker {
	private:
		Logger* logger;
	public:
		static std::string FileWorker::filePath;
		FileWorker::FileWorker(std::string file);
		FileWorker::FileWorker();
		FileWorker::~FileWorker();
		void FileWorker::writeEntries(std::vector<WebsiteEntry*> *entries);
		void FileWorker::writeToBegin(WebsiteEntry* entry);
		void FileWorker::writeToEnd(WebsiteEntry* entry);
		void FileWorker::writeAtPos(WebsiteEntry* entry, int position);
		void FileWorker::readEntries(std::vector<WebsiteEntry*> *entries);
		void FileWorker::deleteEntry(WebsiteEntry* entry);
		void FileWorker::editEntry(WebsiteEntry* entry);
		bool FileWorker::checkIDUnicity(WebsiteEntry* entry);
		int FileWorker::getIDIncrement();
		void FileWorker::rearrange();
};

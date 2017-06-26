#include "stdafx.h"
#include "Tools.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <sstream>

#pragma region FileWorker
	std::string FileWorker::filePath;
	
	FileWorker::FileWorker(string file) {
		this->logger = new Logger();
		FileWorker::filePath = file;
	}

	FileWorker::FileWorker() {
		this->logger = new Logger();
	}

	FileWorker::~FileWorker() {
		//delete FileWorker::entries;
		//delete FileWorker::filePath;
			delete this;
	}

	void FileWorker::writeEntries(std::vector<WebsiteEntry*> *entries) {
		std::ofstream ofs;
		ofs.open(this->filePath, std::ofstream::out | std::ofstream::trunc);
		ofs.close();

		std::ofstream o(FileWorker::filePath, std::ios_base::app);
		std::vector<WebsiteEntry*>::const_iterator s = entries->begin();
		while (s != entries->end()) {
			o << (*s)->getID() << ";" << (*s)->getName() << ";"  << (*s)->getType() << ";"  << (*s)->getViews() << ";"  << (*s)->getPagerank() << "\n";
			s++;
		}
		o.close();
	}

	void FileWorker::readEntries(std::vector<WebsiteEntry*> *entries) {
		ifstream ifs(FileWorker::filePath);
		Logger* logger = new Logger();
		auto line = std::string();
		std::string::size_type sz;
		entries->clear();
		//stoi, stol and stof converts string type to int, long and float correspondly
		while(std::getline(ifs, line)) {
			WebsiteEntry* entry = new WebsiteEntry();
			std::istringstream iss(line);
			std::string token;
			int counter = 0;
			while (std::getline(iss, token, ';')) {
				switch(counter) {
				case 0: entry->setID(stoi(token)); break;
				case 1: entry->setName(token); break;
				case 2: entry->setType(token); break;
				case 3: entry->setViews(stol(token)); break;
				case 4: entry->setPagerank(stof(token)); break;
				default: break;
				}
				counter++;
			}
			entries->push_back(entry);
			counter = 0;
		}
		ifs.close();
	}

	void FileWorker::deleteEntry(WebsiteEntry* entry) {
		std::vector<WebsiteEntry*> *entries = new std::vector<WebsiteEntry*>();
		readEntries(entries);

		std::vector<WebsiteEntry*>::const_iterator i = entries->begin();
		while (i != entries->end()) {
			if((*i)->compare(entry)) {
				logger->a("Entry has been deleted: " + (*i)->toString());
				i = entries->erase(i);
			} else i++;
		}
		writeEntries(entries);
	}

	void FileWorker::editEntry(WebsiteEntry* entry) {
		std::vector<WebsiteEntry*> *entries = new std::vector<WebsiteEntry*>();
		readEntries(entries);

		std::vector<WebsiteEntry*>::const_iterator i = entries->begin();
		while (i != entries->end()) {
			if((*i)->compareByID(entry)) {
				logger->a("Entry has been edited: " + (*i)->toString());
				(*i)->setName(entry->getName());
				(*i)->setType(entry->getType());
				(*i)->setViews(entry->getViews());
				(*i)->setPagerank(entry->getPagerank());
				logger->a("Changed to: " + (*i)->toString());
				break;
			} else i++;
		}
		writeEntries(entries);
	}

	bool FileWorker::checkIDUnicity(WebsiteEntry* entry) {
		std::vector<WebsiteEntry*> *entries = new std::vector<WebsiteEntry*>();
		readEntries(entries);

		std::vector<WebsiteEntry*>::const_iterator i = entries->begin();
		while (i != entries->end()) {
			if((*i)->compareByID(entry)) {
				return true;
			} else return false;
		}
	}

	int FileWorker::getIDIncrement() {
		std::vector<WebsiteEntry*> *entries = new std::vector<WebsiteEntry*>();
		std::vector<WebsiteEntry*>::const_iterator i = entries->begin();

		int maxID = 0;
		while (i != entries->end()) {
			if((*i)->getID() > maxID) {
				maxID = (*i)->getID();
			}
		}
		return maxID;
	}

	void FileWorker::writeToBegin(WebsiteEntry* entry) {
		
	}

	void FileWorker::writeToEnd(WebsiteEntry* entry) {
		std::vector<WebsiteEntry*> *entries = new std::vector<WebsiteEntry*>();
		readEntries(entries);

		std::ofstream o(FileWorker::filePath, std::ios_base::app);
		std::vector<WebsiteEntry*>::const_iterator s = entries->begin();
		while (s != entries->end()) {
			o << (*s)->getID() << ";" << (*s)->getName() << ";"  << (*s)->getType() << ";"  << (*s)->getViews() << ";"  << (*s)->getPagerank() << "\n";
			s++;
		}
		o.close();
	}

	void FileWorker::writeAtPos(WebsiteEntry* entry, int position) {
		std::vector<WebsiteEntry*> *entries = new std::vector<WebsiteEntry*>();
		readEntries(entries);

		std::vector<WebsiteEntry*>::const_iterator it;
		if(!entries->empty()) {
			it = entries->begin()+position;
			it = entries->insert (it, entry);
			writeEntries(entries);
		}
	}

#pragma endregion FileClass

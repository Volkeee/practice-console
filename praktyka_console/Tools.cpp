#include "stdafx.h"
#include "Tools.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <sstream>

#pragma region FileWorker
	FileWorker::FileWorker(string filePath) {
		this->logger = new Logger();
	}

	FileWorker::~FileWorker() {
		delete this;
	}

	void FileWorker::writeEntries(std::vector<WebsiteEntry*> entries) {
		std::ofstream o("data1.txt");
		for(WebsiteEntry* s: entries) {
			o << s->getID() << ";" << s->getName()<< ";"  << s->getType()<< ";"  << s->getViews()<< ";"  << s->getPagerank() << "\n";
		}
		o.close();
	}

	void FileWorker::readEntries(std::vector<WebsiteEntry*> *entries) {
		ifstream ifs("data1.txt");
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
	}

	void FileWorker::deleteEntry(std::vector<WebsiteEntry*> *entries, WebsiteEntry* entry) {
		std::vector<WebsiteEntry*>::const_iterator i = entries->begin();
		while (i != entries->end()) {
			if((*i)->compare(entry)) {
				logger->a("Entry has been deleted: " + (*i)->toString());
				i = entries->erase(i);
			} else i++;
		}
		writeEntries(*entries);
	}

	void FileWorker::editEntry(std::vector<WebsiteEntry*> *entries, WebsiteEntry* entry) {
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
		writeEntries(*entries);
	}

	bool FileWorker::checkIDUnicity(std::vector<WebsiteEntry* > *entries, WebsiteEntry* entry) {
		std::vector<WebsiteEntry*>::const_iterator i = entries->begin();
		while (i != entries->end()) {
			if((*i)->compareByID(entry)) {
				return true;
			} else return false;
		}
	}

#pragma endregion FileClass

#include "stdafx.h"
#include "WebsiteEntry.h"
#include "Logger.h"



WebsiteEntry::WebsiteEntry(int id, string name, string type, long views, float pagerank)
{
	this->setID(id);
	this->setName(name);
	this->setType(type);
	this->setViews(views);
	this->setPagerank(pagerank);
}

WebsiteEntry::WebsiteEntry() {}

WebsiteEntry::~WebsiteEntry() {
		delete this;
}

void WebsiteEntry::setID(int id) {
	this->identificator = id;
}

void WebsiteEntry::setName(string name) {
	this->name = name;
}

void WebsiteEntry::setType(string type) {
	this->type = type;
}

void WebsiteEntry::setViews(long views) {
	this->views = views;
}

void WebsiteEntry::setPagerank(float pagerank) {
	this->pagerank = pagerank;
}

int WebsiteEntry::getID() {
	return this->identificator;
}

string WebsiteEntry::getName() {
		return this->name;
}
	
string WebsiteEntry::getType() {
		return this->type;
}
	
long WebsiteEntry::getViews() {
		return this->views;
}

float WebsiteEntry::getPagerank() {
	return this->pagerank;
}

string WebsiteEntry::toString() {
	return "\n\tWebsiteEntry: {\n\t\tid: " + to_string(this->getID())
		+ ";\n\t\tname: " + this->getName()
		+ ";\n\t\ttype: " + this->getType()
		+ ";\n\t\tviews " + to_string(this->getViews())
		+ ";\n\t\tpagerank: " + to_string(this->getPagerank())
		+ "\n\t}";
}

WebsiteEntry* WebsiteEntry::fromString(string input) {
	WebsiteEntry* entry = new WebsiteEntry(2,"name1","type1",5678, 0.1);
	return entry;
}

	bool WebsiteEntry::compare(WebsiteEntry* entry) {
		int equality = 0;
		if(this->getID() == entry->getID()) equality++;
		if(this->getName() == entry->getName()) equality++;
		if(this->getType() == entry->getType()) equality++;
		if(this->getViews() == entry->getViews()) equality++;
		if(this->getPagerank() == entry->getPagerank()) equality++;
	
	if(equality == 5) return true;
	else return false;
	}

	bool WebsiteEntry::compareByID(WebsiteEntry* entry) {
		if(this->identificator == entry->getID()) return true;
		else return false;
	}




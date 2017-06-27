#pragma once
#include <iostream>
#include <string>

class WebsiteEntry
{
	friend bool operator== (WebsiteEntry& left, WebsiteEntry& right);
public:
	WebsiteEntry();
	WebsiteEntry(int id, std::string name, std::string type, long views, float pagerank);
	~WebsiteEntry();
private:
	int identificator;
	std::string name;
	std::string type;
	long views;
	float pagerank;
public:
	void setID(int id),
		setName(std::string name),
		setType(std::string type),
		setViews(long views),
		setPagerank(float pagerank);
	int getID();
	std::string getName();
	std::string getType();
	long getViews();
	float getPagerank();
public:
	std::string WebsiteEntry::toString();
	WebsiteEntry* WebsiteEntry::fromString(std::string input);
public:
	bool WebsiteEntry::compare(WebsiteEntry* entry);
	bool WebsiteEntry::compareByID(WebsiteEntry* entry);
};

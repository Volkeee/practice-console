#pragma once
#include <iostream>
#include <string>
using namespace std;

class WebsiteEntry
{
	friend bool operator== (WebsiteEntry& left, WebsiteEntry& right);
public:
	WebsiteEntry();
	WebsiteEntry(int id, string name, string type, long views, float pagerank);
	~WebsiteEntry();
private:
	int identificator;
	string name;
	string type;
	long views;
	float pagerank;
public:
	void setID(int id),
		setName(string name),
		setType(string type),
		setViews(long views),
		setPagerank(float pagerank);
	int getID();
	string getName();
	string getType();
	long getViews();
	float getPagerank();
public:
	string WebsiteEntry::toString();
	WebsiteEntry* WebsiteEntry::fromString(string input);
public:
	bool WebsiteEntry::compare(WebsiteEntry* entry);
	bool WebsiteEntry::compareByID(WebsiteEntry* entry);
};

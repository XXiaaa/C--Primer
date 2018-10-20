#pragma once

#include <string>
#include <set>

using namespace std;

class Folder;

class Message
{
	friend class Folder;
	friend void swap(Message&, Message&);
public:
	explicit Message(const string &str = "") :contents(str) {}
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	void save(Folder&);
	void remove(Folder&);
	void addFolder(Folder*);
	void remFolder(Folder*);

private:
	string contents;
	set<Folder*> folders;

	void add_to_Folders(const Message&);
	void remove_from_Folders();
};


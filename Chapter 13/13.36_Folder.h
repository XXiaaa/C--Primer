#pragma once

#include "Message.h"

class Folder
{
public:
	Folder();
	~Folder();
	void addMsg(Message *m);
	void remMsg(Message *m);

private:
	set<Message*> messages;
};


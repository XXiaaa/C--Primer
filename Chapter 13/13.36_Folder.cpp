#include "Folder.h"



Folder::Folder() = default;

Folder::~Folder()
{
	for (auto m : messages)
		m->remove(*this);
}

void Folder::addMsg(Message *m)
{
	messages.insert(m);
}

void Folder::remMsg(Message *m)
{
	messages.erase(m);
}
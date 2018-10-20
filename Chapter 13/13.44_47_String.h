#pragma once

#include <utility>
#include <memory>
#include <iostream>

using namespace std;

class String
{
public:
	String(const char* = "");
	String(const String&);
	String& operator=(const String&);
	~String();

private:
	static allocator<char> alloc;
	void free();
	pair<char*, char*> alloc_n_copy(const char*, const char*);

	char *elements;
	char *end;
};

allocator<char> String::alloc;


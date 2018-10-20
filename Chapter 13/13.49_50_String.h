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
	String(String &&s) noexcept :elements(s.elements), end(s.end)
	{
		cout << "String(String &&s)" << endl;
		s.elements = s.end = nullptr;
	}
	String& operator=(String &&rhs)
	{
		if (this != &rhs) {
			cout << "String& operator=(String &&rhs)" << endl;
			free();
			elements = rhs.elements;
			end = rhs.end;
		}
	}
	~String();

private:
	static allocator<char> alloc;
	void free();
	pair<char*, char*> alloc_n_copy(const char*, const char*);

	char *elements;
	char *end;
};


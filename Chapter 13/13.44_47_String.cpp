#include "String.h"

pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
	auto str = alloc.allocate(e - b);
	return { str,uninitialized_copy(b,e,str) };
}

String::String(const char *b)
{
	auto e = b;
	while (*e)
		++e;
	auto newStr = alloc_n_copy(b, e);
	elements = newStr.first;
	end = newStr.second;
}

String::String(const String &str)
{
	cout << "String(const String &str)" << endl;
	auto newStr = alloc_n_copy(str.elements, str.end);
	elements = newStr.first;
	end = newStr.second;
}

void String::free()
{
	if (elements) {
		for (auto p = end; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, end - elements);
	}
}

String & String::operator=(const String &rhs)
{
	cout << "String::operator=(const String &rhs)" << endl;
	auto newStr = alloc_n_copy(rhs.elements, rhs.end);
	free();
	elements = newStr.first;
	end = newStr.second;
	return *this;
}

String::~String()
{
	free();
}
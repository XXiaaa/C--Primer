#pragma once

#include <string>
#include <memory>
#include <utility>

using namespace std;

class StrVec
{
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(initializer_list<string>);
	StrVec(const StrVec&);
	StrVec &operator=(const StrVec&);
	~StrVec();
	
	void push_back(const string&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; } 
	void reserve(size_t);
	void resize(size_t);
	string *begin() const { return elements; }
	string *end() const { return first_free; }

private:
	static allocator<string> alloc;
	void chk_n_alloc()
	{
		if (size() == capacity())
			reallocate();
	}
	
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();
	void reallocate();
	void newcapacity(size_t n);

	string *elements;
	string *first_free;
	string *cap;
};
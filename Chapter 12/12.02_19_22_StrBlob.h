#pragma once

#include <vector>
#include <string>
#include <memory>

using namespace std;

class StrBlobPtr;

class StrBlob
{
	friend class StrBlobPtr;

public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &t) { data->push_back(t); }
	void pop_back();
	string& front();
	string& back();
	const string& front() const;
	const string& back() const;
	StrBlobPtr begin();
	StrBlobPtr end();

private:
	void check(size_type i, const string &msg) const;

	shared_ptr<vector<string>> data;
};

class StrBlobPtr
{
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) {}
	StrBlobPtr(const StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) {}
	string& deref() const;
	StrBlobPtr& incr();

private:
	shared_ptr<vector<string>> check(size_t i, const string& msg) const;

	weak_ptr<vector<string>> wptr;
	size_t curr;
};


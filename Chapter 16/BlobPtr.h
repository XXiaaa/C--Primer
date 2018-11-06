#pragma once

#include <memory>
#include <vector>
#include "Blob.h"

using namespace std;

template<typename T>
class BlobPtr {
public:
	BlobPtr() :curr(0) {}
	BlobPtr(Blob<T> &a, size_t sz = 0) :wptr(a.data), curr(sz) {}

	T& operator*() const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}

	BlobPtr& operator++();
	BlobPtr& operator--();
	BlobPtr operator++(int);
	BlobPtr operator--(int);

private:
	shared_ptr<vector<T>> check(size_t, const string&) const;

	weak_ptr<vector<T>> wptr;
	size_t curr;
};

template<typename T>
inline BlobPtr<T> & BlobPtr<T>::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

template<typename T>
inline BlobPtr<T> & BlobPtr<T>::operator--()
{
	--curr;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}

template<typename T>
inline BlobPtr<T> BlobPtr<T>::operator++(int)
{
	BlobPtr ret = *this;
	++*this;
	return ret;
}

template<typename T>
inline BlobPtr<T> BlobPtr<T>::operator--(int)
{
	BlobPtr ret = *this;
	--*this;
	return ret;
}

template<typename T>
inline shared_ptr<vector<T>> BlobPtr<T>::check(size_t, const string &) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}
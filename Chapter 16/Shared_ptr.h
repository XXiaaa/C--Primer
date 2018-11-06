#pragma once

#include <functional>

using namespace std;

template<typename T>
class Shared_ptr {
public:
	Shared_ptr(T *ptr = new T()) :p(ptr), count(new unsigned(1)) {}
	Shared_ptr(T *ptr, function<void(T*)> d) :p(ptr), count(new unsigned(1)), del(d) {}

	Shared_ptr(const Shared_ptr& sp) : p(sp.p), count(sp.count), del(sp.del) { ++*count; }
	
	Shared_ptr& operator=(const Shared_ptr&);

	~Shared_ptr();


private:
	T *p;
	unsigned *count;
	function<void(T*)> del;
};

template<typename T>
Shared_ptr<T> & Shared_ptr<T>::operator=(const Shared_ptr<T> & rhs)
{
	++*count;
	if (--*count == 0) {
		del ? del(p) : delete p;
		delete count;
	}
	p = rhs.p;
	count = rhs.count;
	del = rhs.del;
}

template<typename T>
Shared_ptr<T>::~Shared_ptr()
{
	if (--*count == 0) {
		del ? del(p) : delete p;
		delete count;
	}
}
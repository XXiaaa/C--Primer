#pragma once

using namespace std;

template<typename T>
class Del{
public:
	void operator()(T *p)
	{
		delete p;
	}
};


template<typename T,typename D = Del<T>>
class Unique_ptr {
public:
	Unique_ptr(T *ptr = new T(), D d = D()) :p(ptr), del(d) {}

	Unique_ptr(const Unique_ptr&) = delete;
	Unique_ptr& operator=(const Unique_ptr&) = delete;

	~Unique_ptr()
	{
		del(p);
	}

private:
	T *p;
	D del;
};
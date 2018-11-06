#pragma once

#include <string>
#include <initializer_list>
#include <vector>
#include <memory>

using namespace std;

template <typename> class BlobPtr;
template <typename> class Blob;

template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T> 
class Blob {
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);

public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;

	Blob();
	Blob(initializer_list<T> il);
	template <typename It> Blob(It b, It e);

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const T &t) { data->push_back(t); }
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();

	T& bgein();
	T& back();
	const T& bgein() const;
	const T& back() const;

	T& operator[](size_type);

private:
	void check(size_type i, const string &msg) const;
	
	shared_ptr<vector<T>> data;

};

template<typename T>
inline bool operator==(const Blob<T>& lhs, const Blob<T>& rhs)
{
	return lhs.data == rhs.data;
}

template<typename T>
inline Blob<T>::Blob() :data(make_shared<vector<T>>())
{
}

template<typename T>
inline Blob<T>::Blob(initializer_list<T> il) : data(make_shared<vector<T>>(il))
{
}

template<typename T>
template<typename It>
inline Blob<T>::Blob(It b, It e) :data(make_shared<vector<T>>(b, e))
{
}

template<typename T>
inline void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

template<typename T>
inline T & Blob<T>::bgein()
{
	check(0, "begin on empty Blob");
	return data->begin();
}

template<typename T>
inline T & Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
inline const T & Blob<T>::bgein() const
{
	check(0, "begin on empty Blob");
	return data->begin();
}

template<typename T>
inline const T & Blob<T>::back() const
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
inline T & Blob<T>::operator[](size_type i)
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
inline void Blob<T>::check(size_type i, const string & msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}
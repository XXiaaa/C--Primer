#include "StrVec.h"

allocator<string> StrVec::alloc;

StrVec::StrVec(initializer_list<string> il)
{
	for (const auto &s : il)
		push_back(s);
}

void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);
	return { data,uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
	if (elements) {
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const StrVec &s)
{
	auto newData = alloc_n_copy(s.begin(), s.end());
	elements = newData.first;
	first_free = cap = newData.second;
}

StrVec::~StrVec()
{
	free();
}

StrVec& StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::newcapacity(size_t n)
{
	auto newcapacity = n;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void StrVec::reallocate()
{
	newcapacity(size() ? 2 * size() : 1);
}

void StrVec::reserve(size_t n)
{
	if (n > capacity())
		newcapacity(n);
}

void StrVec::resize(size_t n)
{
	while (n < size())
		alloc.destroy(--first_free);
	while (n > size()) {
		chk_n_alloc();
		alloc.construct(first_free++);
	}
}
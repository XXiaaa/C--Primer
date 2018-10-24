#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class A {
public:
	bool operator()(const string &a, const string &b) { return a.size() < b.size(); }
};

class B {
public:
	B(size_t s = 0) :sz(s) {}
	bool operator()(const string &a) { return a.size() >= sz; }

private:
	size_t sz;
};

class C {
public:
	void operator()(const string &a) { cout << a << " "; }
};

int main()
{
	vector<string> vec{ "hello","world","world","aaaaaaaaaaaa","cccc","ccc","ccc"};
	sort(vec.begin(), vec.end());
	auto end_unique = unique(vec.begin(), vec.end());
	vec.erase(end_unique, vec.end());
	stable_sort(vec.begin(), vec.end(), A());
	cout << count_if(vec.begin(), vec.end(), B(5)) << endl;
	auto wc = find_if(vec.begin(), vec.end(), B(5));
	for_each(wc, vec.end(), C());
}

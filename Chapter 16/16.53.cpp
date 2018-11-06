#include <iostream>
#include <string>

using namespace std;

template<typename T>
ostream &print(ostream &os, const T &t)
{
	return os << t;
}

template<typename T,typename...Args>
ostream &print(ostream &os, const T &t, const Args&...rest)
{
	os << t << ", ";
	return print(os, rest...);
}

int main()
{
	const string s("world");
	print(cout, "hello") << endl;
	print(cout, "hello", s) << endl;
	print(cout, "hello", s, 1, 2.0, unsigned(0)) << endl;
}
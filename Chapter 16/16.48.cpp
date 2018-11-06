#include <iostream>
#include <sstream>

using namespace std;

template<typename T>
string debug_rep(const T &t)
{
	ostringstream ret;
	ret << t;
	return ret.str();
}

template<typename T>
string debug_rep(T *p)
{
	ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p);
	else
		ret << " null pointer";
	return ret.str();
}

string debug_rep(const string &s)
{
	return '"' + s + '"';
}

string debug_rep(char *p)
{
	return debug_rep(string(p));
}

string debug_rep(const char *p)
{
	return debug_rep(string(p));
}

int main()
{
	int i = 1, *p = &i;
	char s[] = "Eeeee";
	const char s2[] = "xixixi";

	cout << debug_rep(i) << endl;
	cout << debug_rep(p) << endl;
	cout << debug_rep(s) << endl;
	cout << debug_rep(s2) << endl;
}
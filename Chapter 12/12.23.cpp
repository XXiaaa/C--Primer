#include <iostream>
#include <string>

using namespace std;

int main()
{
	char *p1 = new char[strlen("hello ") + strlen("world!") + 1];
	strcpy(p1, "hello ");
	strcat(p1, "world");
	cout << p1 << endl;
	delete[] p1;

	string s1("hello "), s2("world!!");
	char *p2 = new char[s1.length() + s2.length() + 1];
	strcpy(p2, s1.c_str());
	strcat(p2, s2.c_str());
	cout << p2 << endl;
	delete[] p2;
}
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string in;
	cin >> in;
	char *input = new char[in.length() + 1];
	strcpy(input, in.c_str());
	cout << input << endl;
	delete[] input;
}
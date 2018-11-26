#include <iostream>
#include <string>

using namespace std;

int main()
{
	int arr[10];
	string s;

	cout << typeid(arr).name() << endl;
	cout << typeid(s).name() << endl;
}
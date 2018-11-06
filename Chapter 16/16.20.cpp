#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print(T t)
{
	for (auto iter = t.begin(); iter != t.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}

int main()
{
	vector<int> vec = { 1,2,3,4,5 };
	print(vec);
}
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print(T t)
{
	for (typename T::size_type i = 0; i != t.size(); ++i)
		cout << t[i] << " ";
	cout << endl;
}

int main()
{
	vector<int> vec = { 1,2,3,4,5 };
	print(vec);
}
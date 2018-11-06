#include <iostream>

using namespace std;

template <typename T, unsigned U>
T* Begin(const T(&arr)[U])
{
	return const_cast<T*>(arr + 0);
}

template <typename T, unsigned U>
T* End(const T(&arr)[U])
{
	return const_cast<T*>(arr + U);
}

int main()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	auto beg = Begin(arr);
	auto end = End(arr);
	while (beg != end) {
		cout << *beg << endl;
		++beg;
	}
}
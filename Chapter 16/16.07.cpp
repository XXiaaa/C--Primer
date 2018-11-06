#include <iostream>
#include <vector>

using namespace std;

template <typename T, unsigned U>
constexpr unsigned Size(const T (&arr)[U])
{
	return U;
}

int main()
{
	int arr[] = { 1,2,3,4,5 };
	cout << Size(arr) << endl;
}
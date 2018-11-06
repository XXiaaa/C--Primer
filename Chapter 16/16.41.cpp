#include <iostream>
#include <vector>

using namespace std;

template <typename T>
auto sum(const T &x,const T &y) -> decltype(x+y)
{
	return x + y;
}

int main()
{
	cout << sum(12345678922222222, 9876543211111111) << endl;
}
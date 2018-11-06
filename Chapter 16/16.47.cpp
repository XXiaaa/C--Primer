#include <iostream>
#include <utility>

using namespace std;

template <typename F,typename T1,typename T2>
void flip(F f, T1 &&t1, T2 &&t2)
{
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void f(int &v, int&&)
{
	++v;
	cout << "ok" << endl;
}

int main()
{
	int v = 1;
	flip(f, 42, v);
	cout << v << endl;
}
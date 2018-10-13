#include <iostream>
#include <vector>

using namespace std;

class X {
public:
	X() { cout << "X()" << endl; }
	X(const X&) { cout << "X(const X&)" << endl; }
	X& operator=(const X&) { cout << "operator=(const X&)" << endl; return *this; }
	~X() { cout << "~X()" << endl; }
};

void test(X &x1, X x2) {}

void test2()
{
	cout << "1: ";
	X x1;
	cout << "2: ";
	X x2 = x1;
	cout << "3: ";
	X x3;
	cout << "4: ";
	x3 = x1;
	cout << "5: ";
	test(x1, x2);
	cout << "6: ";
	X *x4 = new X();
	vector<X> v;
	cout << "7: ";
	v.push_back(x1);
	cout << "8: ";
	delete x4;
}

int main()
{
	test2();
}
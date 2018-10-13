#include <iostream>

using namespace std;

class numbered {
	friend void f(numbered s);

public:
	static int val;
	numbered() :mysn(val) { ++val; };

private:
	int mysn;
};

int numbered::val = 1;

void f(numbered s)
{
	cout << s.mysn << endl;
}

int main()
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
}
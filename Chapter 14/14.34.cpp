#include <iostream>

using namespace std;

class Test
{
public:
	int operator()(bool b, int x, int y)
	{
		return b ? x:y;
	}
};

int main()
{
	Test test;
	cout << test(true, 2, 1) << endl;
}
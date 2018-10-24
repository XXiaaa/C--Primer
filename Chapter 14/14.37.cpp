#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Test {
public:
	Test(int v = 0) :val(v) {}

	bool operator()(int a) const
	{
		return (a == val) ? true: false;
	}

private:
	int val;
};

int main()
{
	Test test(5);
	vector<int> vec{ 1,2,2,3,3,3,4,4,4,4,5,5,5,5,5 };
	replace_if(vec.begin(), vec.end(), test, 0);

	for (auto v : vec)
		cout << v << endl;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Test {
public:
	Test(int v = 0) :val(v) {}

	bool operator()(string s) const
	{
		return (s.size() == val) ? true: false;
	}

private:
	int val;
};

int main()
{
	vector<string> vec{ "1","22","22","333","4444","4444","4444" ,"3333333333333333333" };
	for (int i = 0; i < 10; ++i) {
		cout << count_if(vec.begin(), vec.end(), Test(i + 1)) << endl;
	}
}

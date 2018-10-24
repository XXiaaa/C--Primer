#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	vector<int> vec{ 3,6,9,12 };
	auto p = find_if(vec.begin(), vec.end(), bind(modulus<int>(),placeholders::_1,3));
	cout << (p == vec.end() ? "yes" : "no");
}

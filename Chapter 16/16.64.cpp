#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T,typename V>
void Count(const T &vec,const V &val)
{
	cout << count(vec.begin(), vec.end(), val) << endl;
}

template<>
void Count(const vector<const char*> &vec, const char* const &val)
{
	unsigned c = 0;
	for (auto v : vec) {
		if (strcmp(v, val) == 0)
			++c;
	}
	cout << c << endl;
}

int main()
{
	vector<double> v1 = { 1.1,1.2,1.3,1.3,1.4 };
	Count(v1, 1.3);
	vector<int> v2 = { 1,1,1,1,2,3,4 };
	Count(v2, 1);
	vector<string> v3 = { "33","hehe","hehe" };
	Count(v3, "hehe");

	vector<const char*> v4 = { "hehe","xixi","haha","xixi","xixi" };
	Count(v4, "xixi");

}
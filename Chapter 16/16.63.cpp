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

int main()
{
	vector<double> v1 = { 1.1,1.2,1.3,1.3,1.4 };
	Count(v1, 1.3);
	vector<int> v2 = { 1,1,1,1,2,3,4 };
	Count(v2, 1);
	vector<string> v3 = { "33","hehe","hehe" };
	Count(v3, "hehe");
}
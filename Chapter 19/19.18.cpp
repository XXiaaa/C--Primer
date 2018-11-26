#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main()
{
	vector<string> v{ "","","eee","","adeada" };
	cout << count_if(v.begin(), v.end(), mem_fn(&string::empty)) << endl;
}
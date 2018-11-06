#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T1,typename T2>
T1 Find(const T1 &iter1, const T1 &iter2, const T2 &val)
{
	auto iter = iter1;
	while (iter != iter2) {
		if (*iter == val)
			return iter;
		++iter;
	}
	return iter;
}

int main()
{
	vector<int> v1 = { 1,2,3,4,5,6,7,8,9,0 };
	auto iter = Find(v1.begin(), v1.end(), 2);
	cout << *iter << endl;

	vector<string> v2 = { "1","2","3","4","5","6","7","8","9","0" };
	auto iter2 = Find(v2.begin(), v2.end(), "2");
	cout << *iter2 << endl;
}
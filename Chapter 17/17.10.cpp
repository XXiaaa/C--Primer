#include <bitset>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	string s = "00000000001000000010000100101110";
	bitset<32> bs(s);
	cout << bs << endl;

	vector<int> vec = { 1,2,3,5,8,13,21 };
	bitset<32> bs2;
	for (auto v : vec)
		bs2.set(v);
	cout << bs2 << endl;

}

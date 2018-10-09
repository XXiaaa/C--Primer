#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> create()
{
	return make_shared<vector<int>>();
}

void input(shared_ptr<vector<int>> vec)
{
	int i;
	while (cin >> i) {
		vec->push_back(i);
	}
}

void output(shared_ptr<vector<int>> vec)
{
	for (auto v : *vec) {
		cout << v << " ";
	}
	cout << endl;
}

int main()
{
	auto vec = create();
	input(vec);
	output(vec);
}
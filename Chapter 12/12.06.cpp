#include <iostream>
#include <vector>

using namespace std;

vector<int> * create()
{
	return new vector<int>;
}

void input(vector<int> *vec) 
{
	int i;
	while (cin >> i) {
		vec->push_back(i);
	}
}

void output(vector<int> *vec)
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
	delete vec;
	return 0;
}
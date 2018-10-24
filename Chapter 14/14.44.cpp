#include <functional>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	map<string, function<double(double, double)>> binops = {
		{"+",plus<double>()},
		{"-",minus<double>()},
		{"*",multiplies<double>()},
		{"/",divides<double>()},
		{"%",modulus<int>()},
	};
	string op;
	double a, b;
	while (true) {
		cout << "op(+,-,*,/,%) or exit(e): ";
		cin >> op;
		if (op == "e") break;
		cout << "number: ";
		cin >> a >> b;
		cout << binops[op](a, b) << endl;
	}
}
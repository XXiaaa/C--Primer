#pragma once

#include <string>
#include <iostream>

using namespace std;

class Sales_data
{
	friend istream& operator>>(istream&, Sales_data&);
	friend ostream& operator<<(ostream&, const Sales_data&);
	friend Sales_data operator+(const Sales_data&, const Sales_data&);

public:
	Sales_data() = default;
	Sales_data(const string &s) :bookNo(s) {}
	Sales_data(const string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p*n) {}
	Sales_data(istream &is);

	Sales_data& operator+=(const Sales_data&);

private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


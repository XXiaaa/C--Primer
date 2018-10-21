#pragma once

#include <string>
#include <iostream>

using namespace std;

class Date
{
	friend istream& operator>>(istream&, Date&);
	friend ostream& operator<<(ostream&, const Date&);

public:
	Date() = default;
	Date(string y) :year(y) {}
	Date(string y, string m) :year(y), month(m) {}
	Date(string y, string m, string d) :year(y), month(m), day(d) {}

private:
	string year = "1";
	string month = "1";
	string day = "1";
};


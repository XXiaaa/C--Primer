#include "Sales_data.h"

Sales_data::Sales_data(istream & is)
{
	is >> *this;
}

istream & operator>>(istream &is, Sales_data &data)
{
	double price;
	is >> data.bookNo >> data.units_sold >> price;
	data.revenue = price * data.units_sold;
	return is;
}

ostream & operator<<(ostream &os, const Sales_data &data)
{
	os << data.bookNo << " " << data.units_sold << " " << data.revenue << " " << (data.units_sold ? data.revenue / data.units_sold : 0);
	return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum;
	sum.bookNo = lhs.bookNo;
	sum.revenue = lhs.revenue + rhs.revenue;
	sum.units_sold = lhs.units_sold + rhs.units_sold;
	return sum;
}

Sales_data & Sales_data::operator+=(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
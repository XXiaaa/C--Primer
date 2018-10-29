#pragma once

#include <string>
#include <iostream>

using namespace std;

class Quote
{
public:
	Quote() = default;
	Quote(const string &book, double sales_price) :bookNo(book), price(sales_price) {}

	Quote(const Quote&) = default;
	Quote(Quote&&) = default;
	Quote& operator=(const Quote&) = default;
	Quote& operator=(Quote&&) = default;

	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() && { return new Quote(move(*this)); }

	string isbn() const { return bookNo; }

	virtual double net_price(size_t n) const { return n * price; }

	virtual void debug() const;

	virtual ~Quote() = default;

private:
	string bookNo;

protected:
	double price = 0.0;
};

double print_total(ostream&, const Quote&, size_t);
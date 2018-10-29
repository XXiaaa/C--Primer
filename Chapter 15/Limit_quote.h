#pragma once
#include "Disc_quote.h"
class Limit_quote :
	public Disc_quote
{
public:
	Limit_quote() = default;
	Limit_quote(const string& book, double p, size_t qty, double disc) :Disc_quote(book, p, qty, disc) {}

	double net_price(size_t) const override;

	void debug() const override;
};


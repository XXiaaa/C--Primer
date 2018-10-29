#pragma once
#include "Disc_quote.h"

class Bulk_quote :
public Disc_quote
{
public:
	using Disc_quote::Disc_quote;
	Bulk_quote() = default;
	Bulk_quote(const string& book, double p, size_t qty, double disc) :Disc_quote(book, p, qty, disc) {}

	Bulk_quote(const Bulk_quote&) = default;
	Bulk_quote(Bulk_quote&&) = default;
	Bulk_quote& operator=(const Bulk_quote&) = default;
	Bulk_quote& operator=(Bulk_quote&&) = default;
	~Bulk_quote() = default;

	Bulk_quote* clone() const & { return new Bulk_quote(*this); }
	Bulk_quote* clone() && { return new Bulk_quote(move(*this)); }
	
	double net_price(size_t) const override;

	void debug() const override;
};


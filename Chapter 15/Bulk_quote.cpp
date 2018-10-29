#include "Bulk_quote.h"

double Bulk_quote::net_price(size_t cnt) const
{
	if (cnt >= quantity)
		return cnt * (1 - discount)*price;
	else
		return cnt * price;
}

void Bulk_quote::debug() const
{
	cout << "Bulk_Quote" << endl;
	cout << "bookNo: " << isbn() << endl;
	cout << "price: " << price << endl;
	cout << "min_qty: " << quantity << endl;
	cout << "discount: " << discount << endl;
}
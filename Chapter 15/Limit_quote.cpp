#include "Limit_quote.h"

double Limit_quote::net_price(size_t cnt) const
{
	if (cnt <= quantity)
		return cnt * (1 - discount)*price;
	else
		return quantity * (1 - discount)*price + (cnt - quantity)*price;
}

void Limit_quote::debug() const
{
	cout << "Limit_Quote" << endl;
	cout << "bookNo: " << isbn() << endl;
	cout << "price: " << price << endl;
	cout << "max_qty: " << quantity << endl;
	cout << "discount: " << discount << endl;
}
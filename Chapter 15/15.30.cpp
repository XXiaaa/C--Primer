#include "Bulk_quote.h"
#include "Quote.h"
#include <vector>
#include <iostream>
#include <memory>
#include "Basket.h"

using namespace std;

int main()
{
	Basket basket;
	for (size_t i = 0; i < 20; ++i)
		basket.add_item(Bulk_quote("0000", 20, 20, 0.1));
	basket.add_item(Quote("1111", 50));
	basket.total_receipt(cout);
}
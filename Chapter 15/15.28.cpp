#include "Bulk_quote.h"
#include "Quote.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<Quote> basket;
	basket.push_back(Bulk_quote("123",20,20,0.1));
	for (auto b : basket)
		cout << b.net_price(20) << endl;
}
#include "Bulk_quote.h"
#include "Quote.h"
#include <vector>
#include <iostream>
#include <memory>

using namespace std;

int main()
{
	vector<shared_ptr<Quote>> basket;
	basket.push_back(make_shared<Bulk_quote>("123",20,20,0.1));
	for (auto b : basket)
		cout << b->net_price(20) << endl;
}
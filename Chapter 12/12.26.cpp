#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main()
{
	allocator<string> alloc;
	auto const p = alloc.allocate(1);
	auto q = p;
	string s1("hello "), s2("world");
	alloc.construct(q, s1 + s2);
	cout << *q << endl;
	alloc.destroy(q);
	alloc.deallocate(p,1);
}
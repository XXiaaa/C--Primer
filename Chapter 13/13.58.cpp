#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Foo {
public:
	Foo(initializer_list<int> il) :data(il) {}

	Foo sorted() && ;
	Foo sorted() const &;

private:
	vector<int> data;
};

Foo Foo::sorted() &&
{
	cout << "&&" << endl;
	sort(data.begin(), data.end());
	return *this;
}

Foo Foo::sorted() const &
{
	cout << "const &" << endl;
	return Foo(*this).sorted();
	//Foo ret(*this);
	//return ret.sorted();

}

int main()
{
	Foo foo({ 2,3,4,1,6,5,9 });
	foo.sorted();
}
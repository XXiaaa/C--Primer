#include <string>
#include <iostream>

using namespace std;

class HasPtr {
public:
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &orig) :ps(new string(*orig.ps)), i(orig.i) {}
	
	HasPtr(HasPtr &&orig)noexcept :ps(orig.ps), i(orig.i)
	{
		orig.ps = nullptr;
	}
	
	HasPtr& operator=(const HasPtr &rhs)
	{
		auto newp = new string(*rhs.ps);
		delete ps;
		ps = newp;
		i = rhs.i;
		return *this;
	}

	HasPtr& operator=(HasPtr &&rhs) noexcept
	{
		auto newp = rhs.ps;
		delete ps;
		ps = newp;
		i = rhs.i;
		rhs.ps = nullptr;
		return *this;
	}
	
	~HasPtr() { delete ps; }

private:
	string *ps;
	int i;
};

int main()
{
	HasPtr p1("p1"), p2("p2"), p3("p3");
	swap(p1, p2);
	swap(p2, p3);
}
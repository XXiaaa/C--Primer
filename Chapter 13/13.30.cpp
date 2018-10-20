#include <string>
#include <iostream>

using namespace std;

class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &orig) :ps(new string(*orig.ps)), i(orig.i) {}
	HasPtr& operator=(const HasPtr &rhs)
	{
		auto newp = new string(*rhs.ps);
		delete ps;
		ps = newp;
		i = rhs.i;
		return *this;
	}
	~HasPtr() { delete ps; }

private:
	string *ps;
	int i;
};

inline void swap(HasPtr& lhs, HasPtr& rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	cout << "swap:" << *rhs.ps << " " << *lhs.ps <<endl;
}

int main()
{
	HasPtr p1("p1"), p2("p2"), p3("p3");
	swap(p1, p2);
	swap(p2, p3);
}
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

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

	bool operator<(const HasPtr &rhs)
	{
		cout << "< is called" << endl;
		if (*ps < *rhs.ps)
			return true;
		else
			return false;
	}

	~HasPtr() { delete ps; }
	string *ps;

private:
	
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
	vector<HasPtr> vec{ HasPtr("4"),HasPtr("1"),HasPtr("3"),HasPtr("2") };
	sort(vec.begin(), vec.end());
}
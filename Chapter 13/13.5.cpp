#include <string>

using namespace std;

class HasPtr {
public:
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &orig) :ps(new string(*orig.ps)), i(orig.i) {}

private:
	string *ps;
	int i;
};
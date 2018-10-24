#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ReadString
{
public:
	ReadString(istream &i = cin) :is(i) {}

	string operator()() const
	{
		string str;
		getline(is, str);
		return is ? str : string();
	}

private:
	istream &is;
};

int main()
{
	ReadString rs;
	vector<string> vec;
	string s;
	while ((s = rs()) != "") {
		vec.push_back(s);
		cout << s << endl;
	}
}
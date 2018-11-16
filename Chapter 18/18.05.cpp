#include <exception>
#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	try {
		throw bad_cast();
	}
	catch (exception &e) {
		cout << e.what() << endl;
		abort();
	}
}
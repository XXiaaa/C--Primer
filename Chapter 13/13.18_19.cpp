#include <string>

using namespace std;

class Employee {
public:
	static int number;
	
	Employee() :id(number) {
		++number;
	}

	Employee(const string &n) :id(number), name(n) {
		++number;
	}

	Employee(const Employee&) = delete;
	Employee& operator=(const Employee&) = delete;

private:
	int id;
	string name;
};

int Employee::number = 1;
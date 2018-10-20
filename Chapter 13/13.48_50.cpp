#include "String.h"
#include <vector>

int main()
{
	vector<String> vec;
	cout << "size: " << vec.size() << "\tcapacity: " << vec.capacity() << endl;
	
	vec.push_back(String("hello"));
	cout << "size: " << vec.size() << "\tcapacity: " << vec.capacity() << endl;
	
	vec.push_back(String("world"));
	cout << "size: " << vec.size() << "\tcapacity: " << vec.capacity() << endl;

	vec.push_back(String("!"));
	cout << "size: " << vec.size() << "\tcapacity: " << vec.capacity() << endl;

	vec.push_back(String("!!"));
	cout << "size: " << vec.size() << "\tcapacity: " << vec.capacity() << endl;

	vec.push_back(String("!!!"));
	cout << "size: " << vec.size() << "\tcapacity: " << vec.capacity() << endl;

	vec.push_back(String("!!!!"));
	cout << "size: " << vec.size() << "\tcapacity: " << vec.capacity() << endl;
}
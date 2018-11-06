#include <iostream>

using namespace std;

template <typename T, unsigned U>
void print(const T (&arr)[U])
{
	for (auto elem : arr)
		cout << elem << endl;
}

int main()
{
	char s1[] = "hello,world!";
	char s2[] = "hahaha";
	int s3[] = { 1,2,3 };
	print(s1);
	cout << "-----" << endl;
	print(s2);
	cout << "-----" << endl;
	print(s3);
}
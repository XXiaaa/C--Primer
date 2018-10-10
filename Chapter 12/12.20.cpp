#include <fstream>
#include <iostream>

#include "StrBlob.h"

int main()
{
	StrBlob sb;
	ifstream in("12.20_input.txt");
	string line;

	while (getline(in, line)) {
		sb.push_back(line);
	}

	size_t curr = 0;
	for (StrBlobPtr sbp(sb); curr != sb.size(); sbp.incr()) {
		cout << sbp.deref() << endl;
		++curr;
	}
}
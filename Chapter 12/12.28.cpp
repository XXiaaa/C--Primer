#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main()
{
	ifstream infile("input.txt");
	vector<string> text;
	string line;
	while (getline(infile, line)) {
		text.push_back(line);
	}

	map < string, set<decltype(text.size())>> wm;

	for (decltype(text.size()) line_number = 0; line_number != text.size(); ++line_number) {
		istringstream input(text[line_number]);
		string word;
		while (input >> word) {
			wm[word].insert(line_number + 1);
		}
	}

	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string word;
		if (!(cin >> word) || word == "q")
			break;
		auto p = wm.find(word);
		if (p != wm.end()) {
			cout << word << " occurs " << (p->second).size() << ((p->second).size() > 1 ? " times" : " time") << endl;
			for (auto s : (p->second)) {
				cout << "	(line " << s << ") " << text[s - 1] << endl;
			}
		}
		else
			cout << "find no word" << endl;
	}
}
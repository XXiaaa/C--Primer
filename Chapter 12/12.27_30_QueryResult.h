#pragma once

#include <memory>
#include <string>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

class QueryResult
{
	friend ostream& print(ostream&, const QueryResult);

public:
	using line_no = vector<string>::size_type;
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) : sought(s), lines(p), file(f) {}

private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
};

ostream& print(ostream&, const QueryResult);

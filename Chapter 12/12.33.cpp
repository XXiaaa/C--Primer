//add
//QueryResult.h
//public
set<line_no>::iterator begin() { return lines->begin(); }
set<line_no>::iterator end() { return lines->end(); }
set<line_no>::const_iterator begin() const { return lines->cbegin(); }
set<line_no>::const_iterator end() const { return lines->cend(); }
shared_ptr<vector<string>> get_file() { return file; }
#pragma once

#include <string>
#include <iostream>

using namespace std;

template<unsigned, unsigned> class Screen;

template<unsigned H, unsigned W> istream& operator>>(istream&, Screen<H, W>&);
template<unsigned H, unsigned W> ostream& operator<<(ostream&, const Screen<H, W>&);

template<unsigned H,unsigned W>
class Screen {
	friend istream& operator>> <H, W> (istream &is, Screen<H,W>&);
	friend ostream& operator<< <H, W> (ostream &os, const Screen<H, W>&);

public:
	Screen(string c = "") :content(c), hight(H), width(W) {}

private:
	string content;
	unsigned hight;
	unsigned width;
};

template<unsigned H, unsigned W>
istream & operator>>(istream &is, Screen<H,W> &s)
{
	is >> s.content;
	return is;
}

template<unsigned H, unsigned W>
ostream & operator<<(ostream &os, const Screen<H, W> &s)
{
	os << s.content;
	return os;
}
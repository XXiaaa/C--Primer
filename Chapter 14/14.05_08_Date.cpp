#include "Date.h"

istream & operator>>(istream &is, Date &date)
{
	is >> date.year >> date.month >> date.day;
	return is;
}

ostream & operator<<(ostream &os, const Date &date)
{
	os << date.year << "/" << date.month << "/" << date.day;
	return os;
}
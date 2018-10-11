#include "QueryResult.h"

ostream& print(ostream& os, const QueryResult qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " " << (qr.lines->size() > 1 ? " times" : " time") << endl;
	for (auto num : *qr.lines) {
		os << "\t(line " << num + 1 << ") " << StrBlobPtr(qr.file, num).deref() << endl;
	}
	return os;
}

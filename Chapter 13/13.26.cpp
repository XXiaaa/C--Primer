//add

StrBlob(const StrBlob &orig) :data(make_shared<vector<string>>(*orig.data)) {}
StrBlob& operator=(const StrBlob &rhs)
{
	auto newData = make_shared<vector<string>>(*rhs.data);
	data = newData;
	return *this;
}
#include <bitset>
#include <vector>
#include <iostream>

using namespace std;

template<size_t N>
class Quiz
{
	template<size_t N>
	friend ostream& operator<<(ostream&, const Quiz<N>&);

	template<size_t N>
	friend size_t grade(const Quiz<N> &l, const Quiz<N> &r);

public:
	Quiz() = default;
	Quiz(const bitset<N> &bs) :answer(bs) {}

	void update(size_t n, bool as)
	{
		answer.set(n, as);
	}

private:
	bitset<N> answer;
};

template<size_t N>
ostream & operator<<(ostream &os, const Quiz<N>& q)
{
	os << q.answer;
	return os;
}

template<size_t N>
size_t grade(const Quiz<N>& l, const Quiz<N>& r)
{
	bitset<N> b = ~(l.answer^r.answer);
	return b.count();
}

int main()
{
	Quiz<5> answer(bitset<5>("10111"));
	cout << answer << endl;

	answer.update(0, false); //10110
	cout << answer << endl;

	Quiz<5> r(bitset<5>("10111"));
	cout << grade(answer, r) << endl;
}

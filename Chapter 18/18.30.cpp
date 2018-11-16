class Class {};

class Base :public Class
{
public:
	Base() = default;
	Base(const Base &b) = default;
	Base(int a) :Class(), val(a) {}

protected:
	int val;
};

class D1 :virtual public Base {
public:
	D1() :Base() {}
	D1(const D1 &d) :Base(d) {}
	D1(int a) :Base(a) {}
};

class D2 :virtual public Base {
public:
	D2() :Base() {}
	D2(const D2 &d) :Base(d) {}
	D2(int a) :Base(a) {}
};

class MI :public D1, public D2 {
public:
	MI() :Base(), D1(), D2() {}
	MI(const MI &mi) :Base(mi), D1(mi), D2(mi) {}
	MI(int a) : Base(a), D1(a), D2(a) {}
};

class Final :public MI, public Class {
	Final() :Base(), MI(), Class() {}
	Final(const Final &f) :Base(f), MI(f),Class() {}
	Final(int a) :Base(a), MI(a), Class() {}
};
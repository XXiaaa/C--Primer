class Square {
public:
	Square(double l, double w) :length(l), width(w) {}

	virtual double area();
	virtual double circumference();

protected:
	double length;
	double width;
};

double Square::area()
{
	return length * width;
}

double Square::circumference()
{
	return 2 * (width + length);
}

class Cuboid:
	public Square
{
public:
	Cuboid(double l, double w, double h) :Square(l, w), height(h) {}

	double area() override { return Square::area() * 2 + height * length * 2 + height * width * 2; }
	double circumference() override { return Square::circumference() * 2 + 4 * height; }

protected:
	double height;
};
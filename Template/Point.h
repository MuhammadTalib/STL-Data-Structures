class point {
public:
	point()
	{
		this->a = 0;
		this->b = 10;
	}
	int geta()
	{
		return this->a;
	}
	friend ostream& operator <<(ostream&o, point& P)
	{
		return o << P.a << endl << P.b << endl;
	}
private:
	int a;
	int b;
};
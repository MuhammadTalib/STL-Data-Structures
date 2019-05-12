#include<iostream>
using namespace std;

template<class t> class base {
protected:
	t a;
public:
	base(t aa) {
		a = aa;
		cout << "base " << a << endl;
	}
};

template <class t> class derived : public base<t> {
public:
	derived(t a) : base<t>(a) {
	}

	void sampleMethod() {
		cout << "In sample Method" << endl;
	}
};

int main() {
	derived<int> q(1);
	q.sampleMethod();

	system("pause");
}
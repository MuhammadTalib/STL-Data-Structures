#include<iostream>
using namespace std;

template <class T>
T GetMax(T a, T b) {

	return (a > b ? a : b);
}

int main() {
	int i = 5, j = 6, k;
	char l = '1', m = '5', n;
	k = GetMax(i, j);
	n = GetMax(l, m);
	cout << k << endl;
	cout << n << endl;

	system("pause");
	return 0;
}
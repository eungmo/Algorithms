#include <iostream>

using namespace std;

int fib(int a) {
	if (a <= 1) return 1;
	return fib(a-1) + fib(a-2);
}

int main(void) {

	cout << fib(5) << endl;

	return 0;
}
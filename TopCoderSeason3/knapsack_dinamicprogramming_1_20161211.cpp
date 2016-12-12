#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_WAGE = 10;
int wage[] = { 3, 4, 1, 2, 3 };
int value[] = { 2, 3, 2, 3, 6 };

// The function make from binary 00000 to binary 11111
int makeBinary(int value) {
	int remainder, result = 0, i;
	for (i = 1; value > 1; i*=10) {
		remainder = value % 2;
		value = value / 2;
		result += remainder * i;
	}
	result += value * i;
	return result;
}

// The function calculate value using binary
int calcValue(int binary) {
	int v = 0, w = 0, num = sizeof(wage) / sizeof(wage[0]);

	for (int i = 0; i < num; i++) {
		if (binary % 10 == 1) {
			v += value[num-1-i];
			w += wage[num - 1 - i];
		}
		binary /= 10;
	}

	if (w > 10)
		return 0;
	else
		return v;
}

int main(void) {
	int binary, max = 0;

	for (int i = 0; i < 32; i++) {
		binary = makeBinary(i);
		max = std::max(max, calcValue(binary));
	}

	cout << max << endl;


	return 0;
}
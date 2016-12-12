#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_WAGE = 10;
int wage[] = { 3, 4, 1, 2, 3 };
int value[] = { 2, 3, 2, 3, 6 };

// The function calculate value
int calcValue(int b) {
	int v = 0, w = 0, num = sizeof(wage) / sizeof(wage[0]);

	for (int i = 0; i < num; i++) {
		if (b % 2 == 1) {
			// trasfer to binary and add knapsack's value and wage
			v += value[num - 1 - i];
			w += wage[num - 1 - i];
		} 
 		b /= 2;
	}

	if (w > MAX_WAGE)
		return 0;
	else
		return v;
}

int main(void) {
	int max = 0;

	// check all probability of choosing knapsack
	for (int i = 0; i < 32; i++) {
		max = std::max(max, calcValue(i));
	}

	cout << max << endl;


	return 0;
}
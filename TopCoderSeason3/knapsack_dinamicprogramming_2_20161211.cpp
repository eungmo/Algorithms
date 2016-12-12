#include <iostream>
#include <algorithm>

using namespace std;

int weight[5] = { 3, 4, 1, 2, 3 };
int value[5] = { 2, 3, 2, 3, 6 };
int maxw = 10;
int ret = 0;

void knapsack(int n, int w, int v) {
	if (w > maxw) return; // fail condition1
	ret = max(ret, v); // seek max value
	if (n >= 5) return; // end condition
	knapsack(n + 1, w, v); // no add to nth knapsack
	knapsack(n + 1, w + weight[n], v + value[n]); // add to nth knapsack
}

int main(void) {
	// check all probability of choosing knapsack
	knapsack(0, 0, 0);
	cout << ret << endl;

	return 0;
}
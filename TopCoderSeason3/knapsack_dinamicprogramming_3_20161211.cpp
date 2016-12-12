#include <iostream>
#include <algorithm>

using namespace std;

int weight[5] = { 3, 4, 1, 2, 3 };
int value[5] = { 2, 3, 2, 3, 6 };
int maxw = 10;

int knapsack(int n, int w) {
	if (w > maxw) return -1;
	if (n >= 5) return 0;

	int v1 = knapsack(n + 1, w);	// when I don't choose (n+1)th knapsack
	int v2 = knapsack(n + 1, w + weight[n]) + value[n]; // when I choose (n+1)th knapsack
	return max(v1, v2);
}

int main(void) {
	cout << knapsack(0, 0) << endl;

	return 0;
}
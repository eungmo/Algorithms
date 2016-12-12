#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int weight[5] = { 3, 4, 1, 2, 3 };
	int value[5] = { 2, 3, 2, 3, 6 };
	int maxw = 10;
	int dp[6][11];
	int max_value = 0;

	// initialize whole matrix
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 11; j++) {
			dp[i][j] = 0;
		}
	}

	for (int i = 0; i < 5; i++) {
		// if I don't choose nth knapsack.
		for (int j = 0; j <= maxw; j++) {
			dp[i + 1][j] = dp[i][j];
		}
		// if I choose nth knapsack
		for (int j = 0; j <= maxw; j++) {
			if (j == 0 || dp[i][j] != 0 && j+weight[i] <= maxw) {
				dp[i + 1][j + weight[i]] = max(dp[i + 1][j + weight[i]], dp[i][j] + value[i]);
			}
		}
	}

	/*
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= maxw; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	*/

	for (int j = 0; j < 11; j++) {
		max_value = max(max_value, dp[5][j]);
	}

	cout << max_value << endl;

	return 0;
}
#include <iostream>

using namespace std;

const int h = 5, w = 4;
int dp[h + 1][w + 1];

int calc() {
	int i, j;
	dp[0][0] = 1;
	for (i = 0; i <= h; i++ ) {
		for (j = 0; j <= w; j++) {
			// Add bottom's number of method
			if (i != 0) dp[i][j] += dp[i - 1][j];
			// Add left's number of method
			if (j != 0) dp[i][j] += dp[i][j - 1];
		}
	}

	return dp[h][w];
}

int main(void) {

	cout << calc() << endl;

	return 0;
}
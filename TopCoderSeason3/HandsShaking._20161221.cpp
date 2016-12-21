#include <iostream>

using namespace std;

long dp[50] = { 0 };

class HandsShaking {
public:
	long countPerfect(int n) {
		dp[0] = 1;
		dp[2] = 1;

		return dfs(n);
	}

	long dfs(int n) {
		// If it is already calculated, use it.
		if (dp[n] != 0)
			return dp[n];

		int sum = 0, i;
		for (i = n-2; i >= 0; i -= 2) {
			sum += countPerfect(i) * countPerfect(n - 2 - i);
		}
		// save calculated value to dp array
		dp[n] = sum;

		return sum;
	}
};


int main(void) {
	HandsShaking hs;
	int n;
	//n = 2;
	//n = 4;
	//n = 6;
	//n = 8;
	//n = 10;
	n = 50;

	cout << hs.countPerfect(n) << endl;

	return 0;
}
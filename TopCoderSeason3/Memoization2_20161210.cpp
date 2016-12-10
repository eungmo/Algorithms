#include <iostream>

using namespace std;

const int h = 5, w = 4;
int dp[h + 1][w + 1];

int dfs(int nowh, int noww) {
	if (nowh > h || noww > w) return 0;
	if (nowh == h & noww == w) return 1;
	// if it is calculated before, just use it.
	if (dp[nowh][noww] != 0) return dp[nowh][noww];
	return dp[nowh][noww] = dfs(nowh + 1, noww) + dfs(nowh, noww + 1);
}

int main(void) {
	cout << dfs(0, 0) << endl;

	return 0;
}
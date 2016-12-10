#include <iostream>

using namespace std;

const int h = 5, w = 4;

int dfs(int nowh, int noww) {
	if (nowh > h || noww > w) return 0;
	if (nowh == h && noww == w) return 1;
	return dfs(nowh + 1, noww) + dfs(nowh, noww + 1);
}

int main(void) {
	cout << dfs(0, 0) << endl;

	return 0;
}
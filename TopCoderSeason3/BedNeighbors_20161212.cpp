#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 40;
int dp[MAXN][MAXN] = { 0 };

class BadNeighbor {
public:
	int maxDonations(vector<int> donations) {
		int v1 = 0, v2 = 0, len = donations.size();

		// calculate max sum of donations when I choose first house
		dp[0][0] = donations[0];
		for (int i = 1; i < len-1; i++) {
			// copy previous value
			for (int j = 0; j < i; j++) {
				dp[i][j] = dp[i - 1][j];
			}
			// caculate max value using previous index of array
			dp[i][i] = donations[i];
			for (int j = 0; j < i-1; j++) {
				dp[i][i] = max(dp[i][i], dp[i - 1][j] + donations[i]);
			}
		}
		for (int i = 0; i < len; i++) {
			v1 = max(v1, dp[len - 2][i]);
		}
		
		// initiate dp
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				dp[i][j] = 0;
			}
		}

		// calculate max sum of donations when I choose second house
		for (int i = 1; i < len; i++) {
			// copy previous value
			for (int j = 0; j < i; j++) {
				dp[i][j] = dp[i - 1][j];
			}
			// caculate max value using previous index of array
			dp[i][i] = donations[i];
			for (int j = 0; j < i - 1; j++) {
				dp[i][i] = max(dp[i][i], dp[i - 1][j] + donations[i]);
			}
		}
		for (int i = 0; i < len; i++) {
			v2 = max(v2, dp[len - 1][i]);
		}
		/*
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				cout << dp[i][j] << ' ';
			}
			cout << endl;
		}
		*/
		return max(v1, v2);
	}
};

int main(void) {
	BadNeighbor bn;
	vector<int> donations;
	/*
	donations.push_back(100); donations.push_back(2); donations.push_back(3);
	donations.push_back(101); donations.push_back(5); donations.push_back(6);
	*/
	/*
	donations.push_back(10); donations.push_back(3); donations.push_back(2);
	donations.push_back(5); donations.push_back(7); donations.push_back(8);
	*/
	//donations.push_back(11); donations.push_back(15);
	/*
	donations.push_back(7); donations.push_back(7); donations.push_back(7); donations.push_back(7);
	donations.push_back(7); donations.push_back(7); donations.push_back(7);
	*/
	/*
	donations.push_back(1); donations.push_back(2); donations.push_back(3); donations.push_back(4);
	donations.push_back(5); donations.push_back(1); donations.push_back(2); donations.push_back(3);
	donations.push_back(4); donations.push_back(5);
	*/
	donations.push_back(94); donations.push_back(40); donations.push_back(49); donations.push_back(65);
	donations.push_back(21); donations.push_back(21); donations.push_back(106); donations.push_back(80);
	donations.push_back(92); donations.push_back(81); donations.push_back(679); donations.push_back(4);
	donations.push_back(61); donations.push_back(6); donations.push_back(237); donations.push_back(12);
	donations.push_back(72); donations.push_back(74); donations.push_back(29); donations.push_back(95);
	donations.push_back(265); donations.push_back(35); donations.push_back(47); donations.push_back(1);
	donations.push_back(61); donations.push_back(397); donations.push_back(52); donations.push_back(72);
	donations.push_back(37); donations.push_back(51); donations.push_back(1); donations.push_back(81);
	donations.push_back(45); donations.push_back(435); donations.push_back(7); donations.push_back(36);
	donations.push_back(57); donations.push_back(86); donations.push_back(81); donations.push_back(72);

	cout << bn.maxDonations(donations) << endl;

	return 0;
}
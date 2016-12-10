#include <iostream>
#include <vector>
using namespace std;

class FriendScore {
public:
	int highestScore(vector<string> friends) {
		int maxNum = 0, len = friends.size(), tmpMaxNum;

		// check all friends
		for (int i=0; i<len; i++) {
			tmpMaxNum = 0;
			// one friend's 2-friends
			for (int j=0; j<len; j++) {
				// pass oneself
				if (i==j) continue;
				
				// add direct friend
				if (friends[i][j] == 'Y') {
					tmpMaxNum++;
				} 
				// check indirect friend
				else {
					// add friend's 2-friend
					for (int k=0; k<len; k++) {
						if (friends[k][j] == 'Y' && friends[k][i] == 'Y') {
							tmpMaxNum++;
							break;
						}
					}
				}
			}
			maxNum = max(maxNum, tmpMaxNum);
		}
		return maxNum;
	}
};

int main(void) {
	FriendScore fs;
	vector<string> friends;
	/*
	friends.push_back("NYNNN");
	friends.push_back("YNYNN");
	friends.push_back("NYNYN");
	friends.push_back("NNYNY");
	friends.push_back("NNNYN");
	*/
	friends.push_back("NYYNN");
	friends.push_back("YNYNN");
	friends.push_back("YYNYN");
	friends.push_back("NNYNY");
	friends.push_back("NNNYN");
	cout << fs.highestScore(friends) << endl;

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class FriendScore {
public:
	int highestScore(vector<string> friends) {
		int maxNum = 0, tmpMaxNum;
		int len = friends.size();

		// check all friends
		for (int i=0; i<len; i++) {
			tmpMaxNum = 0;
			// check one person's direct friends and indirect friends
			for (int j=0; j<len; j++) {
				// continue if same person
				if (i == j) continue;

				// check direct friends
				if (friends[i][j] == 'Y') {
					tmpMaxNum++;
				}
				// check indirect friends
				else {
					// check indirect friends has any common friend.
					for (int k=0; k<len; k++) {
						if (friends[k][i] == 'Y' && friends[k][j] == 'Y') {
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
	friends.push_back("NNN");
	friends.push_back("NNN");
	friends.push_back("NNN");
	*/
	/*
	friends.push_back("NYY");
	friends.push_back("YNY");
	friends.push_back("YYN");
	*/
	/*
	friends.push_back("NYNNN");
	friends.push_back("YNYNN");
	friends.push_back("NYNYN");
	friends.push_back("NNYNY");
	friends.push_back("NNNYN");
	*/
	/*
	friends.push_back("NNNNYNNNNN");
	friends.push_back("NNNNYNYYNN");
	friends.push_back("NNNYYYNNNN");
	friends.push_back("NNYNNNNNNN");
	friends.push_back("YYYNNNNNNY");
	friends.push_back("NNYNNNNNYN");
	friends.push_back("NYNNNNNYNN");
	friends.push_back("NYNNNNYNNN");
	friends.push_back("NNNNNYNNNN");
	friends.push_back("NNNNYNNNNN");
	*/

	friends.push_back("NNNNNNNNNNNNNNY");
	friends.push_back("NNNNNNNNNNNNNNN");
	friends.push_back("NNNNNNNYNNNNNNN");
	friends.push_back("NNNNNNNYNNNNNNY");
	friends.push_back("NNNNNNNNNNNNNNY");
	friends.push_back("NNNNNNNNYNNNNNN");
	friends.push_back("NNNNNNNNNNNNNNN");
	friends.push_back("NNYYNNNNNNNNNNN");
	friends.push_back("NNNNNYNNNNNYNNN");
	friends.push_back("NNNNNNNNNNNNNNY");
	friends.push_back("NNNNNNNNNNNNNNN");
	friends.push_back("NNNNNNNNYNNNNNN");
	friends.push_back("NNNNNNNNNNNNNNN");
	friends.push_back("NNNNNNNNNNNNNNN");
	friends.push_back("YNNYYNNNNYNNNNN");

	cout << fs.highestScore(friends) << endl;

	return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BatchSystem {
public:
	vector<int> schedule(vector<int> duration, vector<string> user) {
		int len = duration.size();
		vector<int> result, mDuration;
		vector<string> mUser;

		// merge same name of task O(n2)
		for (int i = 0; i < len; i++) {
			int curDuration = duration[i];
			string curUser = user[i];

			// If you already calculte and add the user
			if (std::find(mUser.begin(), mUser.end(), curUser) != mUser.end())
				continue;

			for (int j = i + 1; j < len; j++) {
				// If I find same name, add curDuration
				if (curUser.compare(user[j]) == 0) {
					curDuration += duration[j];
				}
			}
			mDuration.push_back(curDuration);
			mUser.push_back(curUser);
		}

		// sort by duration and name : bubble sort O(n2)
		int mLen = mDuration.size(), tempD;
		string tempU;
		for (int i = 0; i < mLen; i++) {
			for (int j = i + 1; j < mLen; j++) {
				if (mDuration[i] > mDuration[j]) {
					tempD = mDuration[i];
					mDuration[i] = mDuration[j];
					mDuration[j] = tempD;
					tempU = mUser[i];
					mUser[i] = mUser[j];
					mUser[j] = tempU;
				}
			}
		}

		// insert the index of person
		for (int i = 0; i < mLen; i++) {
			for (int j = 0; j < len; j++) {
				if (mUser[i].compare(user[j]) == 0) {
					result.push_back(j);
				}
			}
		}


		return result;
	}
};

int main(void) {
	BatchSystem bs;
	vector<int> duration;
	vector<string> user;

	/*
	duration.push_back(400); duration.push_back(100); duration.push_back(100); duration.push_back(100);
	user.push_back("Danny Messer"); user.push_back("Stella Bonasera"); user.push_back("Stella Bonasera"); user.push_back("Mac Taylor");
	*/
	/*
	duration.push_back(200); duration.push_back(200); duration.push_back(200);
	user.push_back("Gil"); user.push_back("Sarah"); user.push_back("Warrick");
	*/
	///*
	duration.push_back(100); duration.push_back(200); duration.push_back(50);
	user.push_back("Horatio Caine"); user.push_back("horatio caine"); user.push_back("YEAAAAAAH");
	//*/

	// print
	vector<int> ret = bs.schedule(duration, user);
	for (int i = 0; i < ret.size(); i++) {
		if (i != 0) cout << ", ";
		cout << ret[i];
	}
	cout << endl;

	return 0;
}
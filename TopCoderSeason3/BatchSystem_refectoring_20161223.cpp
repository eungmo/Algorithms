#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class BatchSystem {
public:
	vector<int> schedule(vector<int> duration, vector<string> user) {
		int n = duration.size();

		// merge same name of task : O(n)
		map<string, long long> jobTime;
		for (int i = 0; i < n; i++) jobTime[user[i]] += duration[i];

		vector<bool> done(n);
		vector<int> ans;

		while (ans.size() < n) {
			string next;
			// find the smallest duration of user in ramained user map
			for (int i = 0; i < n; i++) {
				if (!done[i] && (next.empty() 
					|| jobTime[user[i]] < jobTime[next])) {
					next = user[i];
				}
			}

			// insert the index of person
			for (int i = 0; i < n; i++) {
				if (user[i] == next) {
					done[i] = true;
					ans.push_back(i);
				}
			}
		}

		return ans;
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
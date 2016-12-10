#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class InterestingParty {
public:
	int bestInvitation (vector<string> first, vector<string> second) {
		int m = 0;

		map<string, int> scoretable;

		// initialize
		for (int i=0; i<first.size(); ++i) {
			scoretable[first[i]] = 0;
			scoretable[second[i]] = 0;
		}

		// calculate all count by subject
		for (int i=0; i<first.size(); ++i) {
			++scoretable[first[i]];
			++scoretable[second[i]];
		}

		// return max number of subjects
		map<string, int>::iterator iter;
		for (iter = scoretable.begin(); iter != scoretable.end(); ++iter) {
			m = max(m, iter->second);
		}

		return m;
	}
};

int main(void) {
	vector<string> first, second;
	InterestingParty ip;

/*
	first.push_back("fishing"); first.push_back("gardening");
	first.push_back("swimming"); first.push_back("fishing");
	second.push_back("hunting"); second.push_back("fishing");
	second.push_back("fishing"); second.push_back("biting");
*/
/*
	first.push_back("variety"); first.push_back("diversity");
	first.push_back("loquacity"); first.push_back("courtesy");
	second.push_back("talking"); second.push_back("speaking");
	second.push_back("discussion"); second.push_back("meeting");
*/
/*
	first.push_back("snakes"); first.push_back("programming");
	first.push_back("cobra"); first.push_back("monty");
	second.push_back("python"); second.push_back("python");
	second.push_back("anaconda"); second.push_back("python");
*/
///*
	first.push_back("t"); first.push_back("o"); first.push_back("p"); first.push_back("c");
	first.push_back("o"); first.push_back("d"); first.push_back("e"); first.push_back("r");
	first.push_back("s"); first.push_back("i"); first.push_back("n"); first.push_back("g");
	first.push_back("l"); first.push_back("e"); first.push_back("r"); first.push_back("o");
	first.push_back("u"); first.push_back("n"); first.push_back("d"); first.push_back("m");
	first.push_back("a"); first.push_back("t"); first.push_back("c"); first.push_back("h");
	first.push_back("f"); first.push_back("o"); first.push_back("u"); first.push_back("r");
	first.push_back("n"); first.push_back("i");
	second.push_back("n"); second.push_back("e"); second.push_back("f"); second.push_back("o");
	second.push_back("u"); second.push_back("r"); second.push_back("j"); second.push_back("a");
	second.push_back("n"); second.push_back("u"); second.push_back("a"); second.push_back("r");
	second.push_back("y"); second.push_back("t"); second.push_back("w"); second.push_back("e");
	second.push_back("n"); second.push_back("t"); second.push_back("y"); second.push_back("t");
	second.push_back("w"); second.push_back("o"); second.push_back("s"); second.push_back("a");
	second.push_back("t"); second.push_back("u"); second.push_back("r"); second.push_back("d");
	second.push_back("a"); second.push_back("y");
//*/
	cout << ip.bestInvitation(first, second) << endl;

	return 0;
}
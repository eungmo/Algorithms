#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

map<string, int> m;

class NumberMagicEasy {
public:
	int theNumber(string number) {

		makeAnswer();
		/*
		map<string, int> m;
		m["YYYY"] = 1;
		m["YYYN"] = 2;
		m["YYNY"] = 3;
		m["YYNN"] = 4;
		m["YNYY"] = 5;
		m["YNYN"] = 6;
		m["YNNY"] = 7;
		m["YNNN"] = 8;
		m["NYYY"] = 9;
		m["NYYN"] = 10;
		m["NYNY"] = 11;
		m["NYNN"] = 12;
		m["NNYY"] = 13;
		m["NNYN"] = 14;
		m["NNNY"] = 15;
		m["NNNN"] = 16;
		*/
		return m[number];
	}

	void makeAnswer() {
		set<int> cards[4] = {
			{ 1, 2, 3, 4, 5, 6, 7, 8 },
			{ 1, 2, 3, 4, 9, 10, 11, 12 },
			{ 1, 2, 5, 6, 9, 10, 13, 14 },
			{ 1, 3, 5, 7, 9, 11, 13, 15 }
		};
		string tmp = "";

		for (int i = 1; i < 16; ++i) {
			tmp = "";
			for (int j = 0; j < 4; j++) {
				if (cards[j].count(i) > 0) {
					tmp += "Y";
				}
				else {
					tmp += "N";
				}
			}
			//cout << i << " " << tmp << endl;
			m[tmp] = i;
		}

		
		//cout << s[0].count(10) << endl;
	}
};

int main(void) {
	NumberMagicEasy nme;

	string answer = "YNYY";
	//string answer = "YNNN";
	//string answer = "NNNN";
	//string answer = "YYYY";
	//string answer = "NYNY";

	cout << nme.theNumber(answer) << endl;

	return 0;
}
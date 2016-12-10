#include <iostream>
#include <vector>

using namespace std;

class KiwiJuiceEasy {
public:
	vector<int> thePouring(vector<int> capacities, vector<int> bottles, vector<int> fromId, vector<int> toId) {
		for (int i=0; i<fromId.size(); i++) {
			// calculate sum of from bottle and to bottle
			int sum = bottles[fromId[i]]+bottles[toId[i]];
			// calculate to bottle
			bottles[toId[i]] = min(sum, capacities[toId[i]]);
			// calculate from bottle
			bottles[fromId[i]] = sum - bottles[toId[i]];
		}

		return bottles;
	}
};

int main(void) {
	KiwiJuiceEasy kje;

	vector<int> capacities, bottles, fromId, toId, ret;
/*
	capacities.push_back(20); capacities.push_back(20);
	bottles.push_back(5); bottles.push_back(8);
	fromId.push_back(0);
	toId.push_back(1);
*/
/*
	capacities.push_back(10); capacities.push_back(10);
	bottles.push_back(5); bottles.push_back(8);
	fromId.push_back(0);
	toId.push_back(1);
*/
/*
	capacities.push_back(30); capacities.push_back(20); capacities.push_back(10);
	bottles.push_back(10); bottles.push_back(5); bottles.push_back(5);
	fromId.push_back(0); fromId.push_back(1); fromId.push_back(2);
	toId.push_back(1); toId.push_back(2); toId.push_back(0);
*/
/*
	capacities.push_back(14); capacities.push_back(35); capacities.push_back(86);
	capacities.push_back(58); capacities.push_back(25); capacities.push_back(62);
	bottles.push_back(6); bottles.push_back(34); bottles.push_back(27);
	bottles.push_back(38); bottles.push_back(9); bottles.push_back(60);
	fromId.push_back(1); fromId.push_back(2); fromId.push_back(4);
	fromId.push_back(5); fromId.push_back(3); fromId.push_back(3);
	fromId.push_back(1); fromId.push_back(0);
	toId.push_back(0); toId.push_back(1); toId.push_back(2);
	toId.push_back(4); toId.push_back(2); toId.push_back(5);
	toId.push_back(3); toId.push_back(1);
*/
	capacities.push_back(700000); capacities.push_back(800000);
	capacities.push_back(900000); capacities.push_back(1000000);
	bottles.push_back(478478); bottles.push_back(478478);
	bottles.push_back(478478); bottles.push_back(478478);
	fromId.push_back(2); fromId.push_back(3); fromId.push_back(2);
	fromId.push_back(0); fromId.push_back(1);
	toId.push_back(0); toId.push_back(1); toId.push_back(1);
	toId.push_back(3); toId.push_back(2);
	ret = kje.thePouring(capacities, bottles, fromId, toId);

	for (int i=0; i<ret.size(); i++) {
		cout << ret[i] << ' ';
	}

	return 0;
}
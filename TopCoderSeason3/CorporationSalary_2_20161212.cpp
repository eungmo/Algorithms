#include <iostream>
#include <vector>

using namespace std;

const int MAX_EMPLOYEE = 50;
int salary[MAX_EMPLOYEE];

class CorporationSalary {
public:
	int getSalary(int index, vector <string> relations) {

		// if salary was already calculated, use it.
		if (salary[index] > 0) return salary[index];

		int len = relations.size(), s = 0;

		// if he has subordinates, add subordinates' salary to get his salary
		for (int i = 0; i < len; i++) {
			if (relations[index][i] == 'Y') {
				s += getSalary(i, relations);
			}
		}
		// if he hasn't any subordinates, caculate 1
		if (s == 0)
			s = 1;

		salary[index] = s;

		return s;
	}

	long totalSalary(vector <string> relations) {
		long total = 0;
		int len = relations.size();

		// initialize salary array
		for (int i = 0; i < len; i++) {
			salary[i] = 0;
		}

		// repeat the number of employees
		for (int i = 0; i < len; i++) {
			// each employee's salary
			getSalary(i, relations);
		}
		// repeat and get sum of employees' salary
		for (int i = 0; i < len; i++) {
			total += salary[i];
		}

		return total;
	}
};

int main(void) {
	CorporationSalary cs;
	vector<string> relations;
	/*
	relations.push_back("NNYN");
	relations.push_back("NNYN");
	relations.push_back("NNNN");
	relations.push_back("NYYN");
	*/
	/*
	relations.push_back("NNNNNN");
	relations.push_back("YNYNNY");
	relations.push_back("YNNNNY");
	relations.push_back("NNNNNN");
	relations.push_back("YNYNNN");
	relations.push_back("YNNYNN");
	*/
	/*
	relations.push_back("NYNNYN");
	relations.push_back("NNNNNN");
	relations.push_back("NNNNNN");
	relations.push_back("NNYNNN");
	relations.push_back("NNNNNN");
	relations.push_back("NNNYYN");
	*/
	///*
	relations.push_back("NNNN");
	relations.push_back("NNNN");
	relations.push_back("NNNN");
	relations.push_back("NNNN");
	//*/

	cout << cs.totalSalary(relations) << endl;

	return 0;
}
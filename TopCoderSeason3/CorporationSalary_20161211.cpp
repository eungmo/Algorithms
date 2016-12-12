#include <iostream>
#include <vector>

using namespace std;

const int EMPLOYEES = 50;

class CorporationSalary{
public:
	long totalSalary(vector<string> relations) {
		long total = 0;
		int i, j, k, l, len = relations.size();
		int salary[EMPLOYEES];
		
		for (int i = 0; i < len; i++) {
			salary[i] = 0;
		}

		// repeat the number of employees
		for (i = 0; i < len; i++) {
			// repeat the number of employees
			for (j = 0; j < len; j++) {
				// find calculable person
				for (k = 0; k < len; k++) {
					if (salary[k] == 0 && relations[j][k] == 'Y') {
						break;
					}
				}
				// calculate one person's salary
				if (k == len && salary[j] == 0) {
					// if there is valuable subordinates
					for (l = 0; l < len; l++) {
						if (salary[l] != 0 && relations[j][l] == 'Y') {
							salary[j] += salary[l];
						}
					}
					// if there isn't valuable surbordinates
					if (salary[j] == 0)
						salary[j] = 1;
				}
			}
			// if all was already caculated, break.
			for (j = 0; j < len; j++) {
				if (salary[j] == 0)
					break;
			}
			if (j == len) {
				break;
			}
		}

		// calculate total salary
		for (int i = 0; i < len; i++) {
			//cout << salary[i] << ' ';
			total += salary[i];
		}
		//cout << endl;

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
	relations.push_back("NNNN");
	relations.push_back("NNNN");
	relations.push_back("NNNN");
	relations.push_back("NNNN");

	//relations.push_back("");
	cout << cs.totalSalary(relations) << endl;


	return 0;
}
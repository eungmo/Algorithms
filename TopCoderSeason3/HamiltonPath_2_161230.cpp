#include <iostream>
#include <vector>

using namespace std;

bool visited[50] = { false };
int connected[50] = { 0 };

class HamiltonPath {
public:
	vector<string> roads;

	int conutPaths(vector<string> roads) {
		int i, j, len = roads.size(), unit = 0, group = 0;
		long long sum = 1;

		this->roads = roads;

		// get each city's the number of connected links.
		for (i = 0; i < len; i++) {
			for (j = 0; j < len; j++) {
				if (roads[i].substr(j, 1) == "Y") {
					connected[i]++;
				}
			}
		}

		// get the number of units and groups
		for (i = 0; i < len; i++) {
			if (connected[i] == 0) {
				unit++;
				visited[i] = true;
			}
			else if (connected[i] > 0 && !visited[i]) {
				group++;
				dfs(i);
			}
		}

		// If there is unvsited city, return 0;
		for (i = 0; i < len; i++) {
			if (!visited[i]) return 0;
		}

		// multiply the factorial of units + groups
		for (i = 1; i <= unit + group; i++) {
			sum *= i % 1000000007;
		}

		// multiply 2 ^ the number of groups
		for (i = 0; i < group; i++) {
			sum *= 2 % 1000000007;
		}

		return (int)sum;
	}

	void dfs(int index) {
		visited[index] = true;

		// all cities of group has to be visited.
		for (int i = 0; i < roads.size(); i++) {
			if (roads[index].substr(i, 1) == "Y" && !visited[i]) {
				dfs(i);
			}
		}
	}

};

int main(void) {
	HamiltonPath hp;

	vector<string> roads;
	/*
	roads.push_back("NYN");
	roads.push_back("YNN");
	roads.push_back("NNN");
	*/
	/*
	roads.push_back("NYYY");
	roads.push_back("YNNN");
	roads.push_back("YNNN");
	roads.push_back("YNNN");
	*/
	/*
	roads.push_back("NYY");
	roads.push_back("YNY");
	roads.push_back("YYN");
	*/
	///*
	roads.push_back("NNNNNY");
	roads.push_back("NNNNYN");
	roads.push_back("NNNNYN");
	roads.push_back("NNNNNN");
	roads.push_back("NYYNNN");
	roads.push_back("YNNNNN");
	//*/

	cout << hp.conutPaths(roads) << endl;

	return 0;
}
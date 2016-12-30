#include <iostream>
#include <vector>

using namespace std;

bool visited[50] = { false };

class HamiltonPath{
public:
	vector <string> roads;

	int conutPaths(vector<string> roads) {
		int group = 0, free = 0;
		int connect[50] = { 0 };	// each city's the number of Y links

		long long sum = 1;

		this->roads = roads;

		// check each city's the number of Y links.
		for (int i = 0; i < roads.size(); i++) {
			int y = 0;
			for (int j = 0; j < roads[i].size(); j++) {
				if (roads[i].substr(j, 1) == "Y") {
					if (2 < ++y) return 0;
				}
			}
			connect[i] = y;
		}

		// If the city don't have any link, increment free.
		// If the city has one link, increment group. (the two city's status will be "visited")
		// O(n^2)
		for (int i = 0; i < roads.size(); i++) {
			if (connect[i] == 0) {
				visited[i] = true;
				free++;
			}
			else if (connect[i] == 1 && !visited[i]) {
				group++;
				dfs(i);
			}
		}

		// If there is not visted city, return 0.
		for (int i = 0; i < roads.size(); i++) {
			if (!visited[i]) return 0;
		}

		// calculate factorial
		for (int i = 0; i < group + free; i++) {
			sum = sum * (i + 1) & 1000000007;
		}
		// calculate group's number of cases
		for (int i = 0; i < group; i++) {
			sum = sum * 2 % 1000000007;
		}
		return (int)sum;
	}

	void dfs(int city) {
		visited[city] = true;
		// find the linked city and check visited. O(n)
		for (int i = 0; i < roads[city].size(); i++) {
			if (roads[city].substr(i, 1) == "Y" && !visited[i]) {
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
	roads.push_back("NNNNNY");
	roads.push_back("NNNNYN");
	roads.push_back("NNNNYN");
	roads.push_back("NNNNNN");
	roads.push_back("NYYNNN");
	roads.push_back("YNNNNN");

	cout << hp.conutPaths(roads) << endl;

	return 0;
}
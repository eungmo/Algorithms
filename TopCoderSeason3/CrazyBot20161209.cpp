#include <iostream>

using namespace std;

bool matrix[29][29] = {false, };
double dProb[4];
int vx[4] = {1, -1, 0, 0};
int vy[4] = {0, 0, -1, 1};

class CrazyBot {
public:
	double getProbability(int n, int east, int west, int south, int north) {
		double probaility = 0.0;

		// caculate direction's probabilities;
		dProb[0] = east / 100.0;
		dProb[1] = west / 100.0;
		dProb[2] = south / 100.0;
		dProb[3] = north / 100.0;

		// caculate all probability
		probaility = dfs(n, 14, 14);

		return probaility;
	}

	double dfs(int n, int x, int y) {
		double probability = 0.0;

		// fail condition
		if (x < 0 || y < 0 || x > 28 || y > 28
			|| matrix[y][x] == true) {			return 0;
		}
		
		// success condition
		if (n == 0) 
			return 1;

		// step current step
		matrix[y][x] = true;

		// sum 4 direction of probability
		for (int i=0; i<4; i++) {
			probability += dProb[i] * dfs(n-1, x + vx[i], y + vy[i]);
		}

		// remove step
		matrix[y][x] = false;

		return probability;
	}
};

int main(void) {
	int n, east, west, south, north;
	CrazyBot cb;

	//n = 1; east = 25, west = 25, south = 25, north = 25;
	//n = 2; east = 25, west = 25, south = 25, north = 25;
	//n = 7; east = 50, west = 0, south = 0, north = 50;
	//n = 14; east = 50, west = 50, south = 0, north = 0;
	n = 14; east = 25, west = 25, south = 25, north = 25;
	
	cout << cb.getProbability(n, east, west, south,north) << endl;

	return 0;
}
#include <iostream>
#include <queue>
#include <map>

using namespace std;

class BinaryFlips {
public:
	int minimalMoves(int A, int B, int K) {
		int curC = 0, N = A+B, curA, curB, nextA;
		map<int, int> nZero;
		queue<int> qA, qC;
		qA.push(A);
		qC.push(0);

		// IF it is already meet, return 0
		if (A == 0)
			return 0;

		// use BFS
		while (qA.size() > 0) {
			// check all possiblities in this phrase
			curA = qA.front(); qA.pop();
			curB = N - curA;
			curC = qC.front(); qC.pop();
			if (curA == 0) break;

			if (nZero[curA] == 0 || (nZero[curA] != 0 && nZero[curA] > curC))
				nZero[curA] = curC;

			// add other numbers of cases in queue;
			for (int i=0; i<=K; i++) {
				// If I can not flip the number, continue.
				if (i > curA || K-i > curB) continue;

				// Add in the queue if it is uncalculated.
				nextA = (curA-i) + (K-i);
				
				if (nZero[nextA] == 0 && nextA != A) {
					//cout << nextA << endl;
					qA.push(nextA);
					qC.push(curC + 1);
				}
			}
		}

		// return the shortest count of the goal.
		return nZero[0] == 0 ? -1 : nZero[0];
	}
};

int main(void) {
	BinaryFlips bf;
	int A, B, K;

	//A = 4; B = 0; K = 3;
	//A = 4; B = 1; K = 3;
	//A = 3; B = 2; K = 5;
	A = 100000; B = 100000; K = 578; // Fail - Timeout
	//A = 0; B = 0; K = 1;
	//A = 4; B = 44; K = 50;

	cout << bf.minimalMoves(A, B, K) << endl;

	return 0;
}

//nZero.insert(20);
//cout << (nZero.find(20) != nZero.end()) << endl;
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

class BinaryFlips {
public:
	int minimalMoves(int A, int B, int K) {
		int c = 0, checkC = -1, N, curA, curB, nextA, nextMaxA, nextMinA;
		map<int, int> nZero;
		queue<int> qA, qC;
		
		// minimize calculate.
		if (A > K * 2) {
			int divider = A / K - 1;
			A = A - K*divider;
			c = c + divider;
		}
		if (B > K * 2) {
			int divider = B / K - 1;
			B = B - K*divider;
		}

		N = A + B;

		qA.push(A);
		qC.push(c);

		// IF it is already meet, return 0
		if (A == 0)
			return 0;

		// use BFS
		while (qA.size() > 0) {
			// check all possiblities in this phrase
			curA = qA.front(); qA.pop();
			curB = N - curA;
			c = qC.front(); qC.pop();
			if (curA == 0) break;

			if (nZero[curA] == 0 || (nZero[curA] != 0 && nZero[curA] > c))
				nZero[curA] = c;
			
			// If I find shortest method, stop calculating using "checkC"
			if (curA % K == 0) {
				checkC = c; // save the level
				int divider = curA / K;
				if (nZero[0] == 0 || (nZero[0] != 0 && nZero[0] > divider + c))
				nZero[0] = divider + c;
			}

			// add other numbers of cases in queue;
			for (int i = 0; i <= K; i++) {
				// If I can not flip the number, continue.
				if (i > curA || K - i > curB) continue;

				// Add in the queue if it is uncalculated.
				nextA = (curA - i) + (K - i);

				if (nZero[nextA] == 0 && nextA != A) {
					qA.push(nextA);
					qC.push(c + 1);
				}
			}

			// check until this level has finished.
			if (checkC != -1 && c > checkC) break;

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
	A = 100000; B = 100000; K = 578;
	//A = 0; B = 0; K = 1;
	//A = 4; B = 44; K = 50;

	cout << bf.minimalMoves(A, B, K) << endl;

	return 0;
}
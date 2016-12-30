#include <iostream>
#include <vector>

using namespace std;

class CirclesCountry {
public:
	bool isInclude(int cX, int cY, int cR, int pX, int pY) {
		//(x-a)^2 + (y-b)^2 = r^2
		return (pX - cX)*(pX - cX) + (pY - cY)*(pY - cY) <= cR * cR;
	}

	int leastBorders(vector<int> X, vector<int> Y, vector<int> R,
		int x1, int y1, int x2, int y2) {
		int ret = 0;

		// O(n)
		for (int i = 0; i < X.size(); i++) {
			// If only one point is in the circle, add the number of border.
			if (isInclude(X[i], Y[i], R[i], x1, y1)
				^ isInclude(X[i], Y[i], R[i], x2, y2)) {
				ret++;
			}
		}

		return ret;
	}
};

int main(void) {
	CirclesCountry cc;
	vector<int> X, Y, R;
	int x1, y1, x2, y2;
	/*
	X.push_back(0);
	Y.push_back(0);
	R.push_back(2);
	x1 = -5; y1 = 1;
	x2 = 5; y2 = 1;
	*/
	/*
	X.push_back(0); X.push_back(-6); X.push_back(6);
	Y.push_back(0); Y.push_back(1); Y.push_back(2);
	R.push_back(2); R.push_back(2); R.push_back(2);
	x1 = -5; y1 = 1;
	x2 = 5; y2 = 1;
	*/
	/*
	X.push_back(1); X.push_back(-3); X.push_back(2); X.push_back(5);
	X.push_back(-4); X.push_back(12); X.push_back(12);
	Y.push_back(1); Y.push_back(-1); Y.push_back(2); Y.push_back(5);
	Y.push_back(5); Y.push_back(1); Y.push_back(1);
	R.push_back(8); R.push_back(1); R.push_back(2); R.push_back(1);
	R.push_back(1); R.push_back(1); R.push_back(2);
	x1 = -5; y1 = 1;
	x2 = 12; y2 = 1;
	*/
	/*
	X.push_back(-3); X.push_back(2); X.push_back(2); X.push_back(0);
	X.push_back(-4); X.push_back(12); X.push_back(12); X.push_back(12);
	Y.push_back(-1); Y.push_back(2); Y.push_back(3); Y.push_back(1);
	Y.push_back(5); Y.push_back(1); Y.push_back(1); Y.push_back(1);
	R.push_back(1); R.push_back(3); R.push_back(1); R.push_back(7);
	R.push_back(1); R.push_back(1); R.push_back(2); R.push_back(3);
	x1 = 2; y1 = 3;
	x2 = 13; y2 = 2;
	*/
	X.push_back(-107); X.push_back(-38); X.push_back(140); X.push_back(148);
	X.push_back(-198); X.push_back(172); X.push_back(-179); X.push_back(148);
	X.push_back(176); X.push_back(153); X.push_back(-56); X.push_back(-187);
	Y.push_back(175); Y.push_back(-115); Y.push_back(23); Y.push_back(-2);
	Y.push_back(-49); Y.push_back(-151); Y.push_back(-52); Y.push_back(42);
	Y.push_back(0); Y.push_back(68); Y.push_back(109); Y.push_back(-174);
	R.push_back(135); R.push_back(42); R.push_back(70); R.push_back(39);
	R.push_back(89); R.push_back(39); R.push_back(43); R.push_back(150);
	R.push_back(10); R.push_back(120); R.push_back(16); R.push_back(8);
	x1 = 102; y1 = 16;
	x2 = 19; y2 = -108;

	cout << cc.leastBorders(X, Y, R, x1, y1, x2, y2) << endl;

	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

class ColorfulBoexesAndBalls {
public:
	int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors) {
		int bScore = 0, sScore = 0;
		// when I choose bothColors
		if (numRed > numBlue) {
			bScore += 2 * bothColors * numBlue;
			bScore += onlyRed * (numRed - numBlue);
		}
		else {
			bScore += 2 * bothColors * numRed;
			bScore += onlyBlue * (numBlue - numRed);
		}

		// if I do NOT choose bothColors
		sScore = numRed * onlyRed + numBlue * onlyBlue;

		return max(bScore, sScore);
	}
};

int main(void) {
	ColorfulBoexesAndBalls cbab;

	//cout << cbab.getMaximum(2, 3, 100, 400, 300) << endl;
	//cout << cbab.getMaximum(5, 5, 464, 464, 464) << endl;
	//cout << cbab.getMaximum(1, 4, 20, -30, -10) << endl;
	cout << cbab.getMaximum(9, 1, -1, -10, 4) << endl;

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class InterestingDigits {
public:
	vector<int> digits(int base) {
		vector<int> result;
		int maxValue = base*base*base;
		int temp, firstNum, secondNum, thirdNum, second = base, third = base*base;
		// check all digit
		for (int i=2; i<base; i++) {
			// check the digit is applied in the rule until XXX
			
			for (int j=i*2;; j=j*i) {
				// get thirdNum, secondNum, firstNum
				temp = j;
				thirdNum = j/third;
				temp = temp - thirdNum*third;
				secondNum = j/second;
				temp = temp - secondNum*second;
				firstNum = temp;
				// check that value is over maxValue
				if (j/maxValue>1) {
					result.push_back(i);
					break;
				}
				// check it is multiple of i
				else if ((thirdNum + secondNum + firstNum) % i != 0)
					break;
			}
		}

		return result;
	}

	vector<int> digits_refectoring(int base) {
		vector<int> result;
		int main = base-1;
		for (int i=2; i<=main; i++) {
			if (main % i == 0) {
				result.push_back(i);
			}
		}

		return result;
	}
};

int main (void) {
	InterestingDigits id;
	vector<int> result;
	//result = id.digits(10);
	//result = id.digits(3);
	//result = id.digits(9);
	//result = id.digits(26);
	//result = id.digits(30);
	//result = id.digits(82);
	//result = id.digits_refectoring(10);
	//result = id.digits_refectoring(3);
	//result = id.digits_refectoring(9);
	//result = id.digits_refectoring(26);
	//result = id.digits_refectoring(30);
	result = id.digits_refectoring(82);

	// print result
	int len = result.size();
	cout << "{";
	for (int i=0; i<len; i++) {
		if (i == len-1) {
			cout << result[i] << "}" << endl;
		} else {
			cout << result[i] << ", ";
		}
	}


	return 0;
}
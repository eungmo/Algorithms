#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Cryptography {
public:
	long long ecrypt(vector<int> numbers) {
		// sort
		sort(numbers.begin(), numbers.end());
		// imcrement 1 to max value(the first value)
		long long result = numbers[0]+1;
		// get the project of numbers
		for(int i=1; i<numbers.size(); i++) {
			result *= numbers[i];
		}
		return result;
	}
};

int main(void) {
	/*
	cout << "sizeof(char) = " << sizeof(char) << endl;
	cout << "sizeof(short) = " << sizeof(short) << endl;
	cout << "sizeof(int) = " << sizeof(int) << endl;
	cout << "sizeof(long) = " << sizeof(long) << endl;
	cout << "sizeof(long long) = " << sizeof(long long) << endl;
*/

	vector <int> numbers;
	Cryptography c;
	//numbers.push_back(1); numbers.push_back(2); numbers.push_back(3);
	/*
	numbers.push_back(1); numbers.push_back(3); numbers.push_back(2);
	numbers.push_back(1); numbers.push_back(1); numbers.push_back(3);
	*/
	/*
	numbers.push_back(1000); numbers.push_back(999); numbers.push_back(998);
	numbers.push_back(997); numbers.push_back(996); numbers.push_back(995);
	*/
	numbers.push_back(1); numbers.push_back(1); numbers.push_back(1); numbers.push_back(1);

	cout << c.ecrypt(numbers) << endl;

	return 0;
}
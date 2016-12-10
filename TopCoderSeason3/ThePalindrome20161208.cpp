#include <iostream>
#include <string>

using namespace std;

class ThePalindrome {
public:
	int find(string s) {
		// max length/
		int len = s.size(), result = len*2;
		string rev = s;
		reverse(rev.begin(), rev.end());

		//cout << rev << endl;

		// check the same part
		for (int i=0; i<len ; i++) {
			//cout << s.substr(i, len) << ' ' << rev.substr(0, len-i) << endl;
			if (s.substr(i, len).compare(rev.substr(0, len-i)) == 0) {
				result = len+i;
				break;
			}
		}

		return result;
	}
};

int main(void) {
	ThePalindrome tp;
	//cout << tp.find("abab") << endl;
	//cout << tp.find("abacaba") << endl;
	//cout << tp.find("qwerty") << endl;
	cout << tp.find("abdfhdyrbdbsdfghjkllkjhgfds") << endl;

	return 0;
}
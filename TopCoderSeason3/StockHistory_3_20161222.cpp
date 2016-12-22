#include <iostream>
#include <vector>

using namespace std;

class StockHistory {
public:
	int maximumEarnings(int initialInvestment, int monthlyContribution, vector <string> stockPrices) {
		// change string vector to int array
		int month = stockPrices.size();
		int prices[50][999];
		int buy[50] = { false };
		double proportion[50];
		
		char *S = (char *)stockPrices[0].c_str();
		int cnt = 1;
		while (*S++) { if (*S == ' ') { cnt++; } }

		int index;
		for (int i = 0; i < month; i++) {
			string s = stockPrices[i];
			for (int j = 0; j < cnt; j++) {
				index = s.find(" ");
				if (index == -1) { // If it is last number
					prices[i][j] = atoi(s.c_str());
				}
				else {
					prices[i][j] = atoi(s.substr(0, index).c_str());
					s = s.substr(index + 1);
				}
			}
		}
		// find when I have to buy the stock
		// find max profit rate
		double max = 0.0, m_max, d;
		for (int i = month - 2; i >= 0; i--) {
			// find max profin rate in current month
			m_max = 0.0;
			for (int j = 0; j < cnt; j++) {
				d = 1.0 * prices[month - 1][j] / prices[i][j] - 1;
				if (m_max < d) m_max = d;
			}
			if (0 < m_max && max < m_max) { // if the rate is positive and bigger than max profit rate 
				buy[i] = true;
				proportion[i] = m_max;
				max = m_max;
			}
		}

		// calculate profit
		double profit = 0.0;
		int money = initialInvestment;
		for (int i = 0; i < month; i++) {
			if (buy[i]) {
				profit += money * proportion[i];
				money = 0;
			}

			money += monthlyContribution;
		}

		return (double)round(profit);
	}
};

int main(void) {

	StockHistory sh;

	int initialInvestment, monthlyContribution;
	vector<string> stockPrices;
	/*
	initialInvestment = 1000; monthlyContribution = 0;
	stockPrices.push_back("10 20 30");
	stockPrices.push_back("15 24 32");
	*/
	initialInvestment = 1000; monthlyContribution = 0;
	stockPrices.push_back("10");
	stockPrices.push_back("9");
	/*
	initialInvestment = 100; monthlyContribution = 20;
	stockPrices.push_back("40 50 60");
	stockPrices.push_back("37 48 55");
	stockPrices.push_back("100 48 50");
	stockPrices.push_back("105 48 47");
	stockPrices.push_back("110 50 52");
	stockPrices.push_back("110 50 52");
	stockPrices.push_back("110 51 54");
	stockPrices.push_back("109 49 53");
	*/

	cout << sh.maximumEarnings(initialInvestment, monthlyContribution, stockPrices) << endl;

	return 0;
}
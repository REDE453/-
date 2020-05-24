#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int package01(const int & total, vector<int>&weight, vector<int>&value) {
	vector<vector<int>>dp(weight.size() + 1, vector<int>(total + 1, 0));
	for (int i = 1; i < weight.size(); ++i) {
		for (int j = 1; j <= total; ++j) {

			if (weight[i] <= j)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[weight.size() - 1][total];
}
int main() {
	int total, number;
	char c;
	cin >> total >> c >> number >> c;
	vector<int>weight(number + 1, 0), values(number + 1, 0);
	for (unsigned int i = 0; i < number; ++i) {
		cin >> weight[i + 1];
	}
	cin >> c;
	for (unsigned int i = 0; i < number; ++i) {
		cin >> values[i + 1];
	}
	cout << package01(total, weight, values);
	system("pause");
	return 0;
}
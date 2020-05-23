#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool isPrime(int num) {
	if (num % 6 != 1 && num % 6 != 5) {
		return false;
	}
	for (int i = 6; i <= sqrt(num) + 1; i += 6) {
		if (num % (i - 1) == 0 || num % (i + 1) == 0)
			return false;
	}
	return true;
}
int main() {
	bool isPrime(int num);
	int eNum = 0;
	scanf("%d", &eNum);
	int** data = new int*[eNum];
	long res = -1;
	long min = 0;
	for (int i = 0; i < eNum; i++) {
		data[i] = new int[2];
		scanf("%d %d", &data[i][0], &data[i][1]);
		if (i == 0)
			min = data[i][0];
		min = min < data[i][0] ? min : data[i][0];
		min = min < data[i][1] ? min : data[i][1];
	}
	vector<int> prime = { 2,3 };
	for (int i = 6; i < min; i += 6) {
		if (isPrime(i - 1))
			prime.push_back(i - 1);
		if (isPrime(i + 1))
			prime.push_back(i + 1);
	}
	for (int i = 0; i < eNum; i++) {
		for (int j = 0; j < prime.size(); j++) {
			if (data[i][0] % prime[j] != 0 && data[i][1] % prime[j] != 0)
				prime.erase(prime.begin() + j);
		}
	}
	if (prime.size() == 0)
		cout << -1 << endl;
	else
		cout << prime[prime.size() - 1] << endl;
}

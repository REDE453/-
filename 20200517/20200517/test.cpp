#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <set>
using namespace std;
void DFS_SSP(string s, int k, int m, set<string> &strset) {
	if (k == m) {
		strset.insert(s);
	}
	else {
		for (int i = k; i < m; i++) {
			swap(s[i], s[k]);
			DFS_SSP(s, k + 1, m, strset);
			swap(s[i], s[k]);
		}
	}
}

void StringSullPermutation() {
	string s;
	cin >> s;
	int len = s.size();
	set<string> strset; //set自动排序和去重
	DFS_SSP(s, 0, len, strset);
	//输出
	set<string>::iterator it = strset.begin();
	cout << "[";
	while (it != strset.end())
	{
		cout << *it;
		if (++it != strset.end()) {
			cout << ", ";
		}
	}
	cout << "]" << endl;
}

int main() {
	StringSullPermutation();
	return 0;
}
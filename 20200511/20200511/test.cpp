#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() 
{
	string s;
	cin >> s;
	int max_len = 1, len = 1;
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i + 1] != s[i]) { len++; max_len = max(max_len, len); }
		else len = 1;
	}
	cout << max_len << endl;
	return 0;
}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(void) {
	string s;
	cin >> s;
	string temp;
	string ans;
	if (s[0] == '-') {
		temp = s.substr(1);
		reverse(temp.begin(), temp.end());
		ans = "-" + temp;
	}
	else {
		reverse(s.begin(), s.end());
		ans = s;
	}
	cout << ans << endl;
	return 0;
}
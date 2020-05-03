#include<iostream>
#include<Windows.h>
using namespace std;
int main() {
	int a;
	cin >> a;
	string s = "NESW";
	char c;
	int l = 0;
	int r = 0;
	while (a--) {
		cin >> c;
		if (c == 'L')
			l++;
		else
			r++;
	}
	int i = r - l;
	while (i < 0) {
		i += 4;
	}
	cout << s[i % 4];
	system("pause");
	return 0;
}
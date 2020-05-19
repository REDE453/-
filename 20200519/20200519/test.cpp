#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n, T;
	cin >> n >> T;
	string str;
	cin >> str;
	while (T--)
	{
		int x, type;
		cin >> type >> x;
		if (type == 2)
			cout << str[x] << endl;
		if (type == 1)
		{
			string str1 = str.substr(0, n - x);
			string str2 = str.substr(n - x);
			str = str2 + str1;
		}
	}
	return 0;
}
#include<iostream>
#include<string>
#include<Windows.h>
#include<vector>
//#include<algorithm>
using namespace std;
int main()
{
	string str1;
	while (getline(cin, str1))
	{
		vector<string> str;
		string str2;
		for (int i = 0; i < str1.size() - 1; ++i)
		{
			if (str1[i] >= 'a'&&str1[i] <= 'z' || str1[i] >= 'A'&&str1[i] <= 'Z')
			{
				str2 += str1[i];
				if ((str1[i + 1] < 'A') || str1[i + 1] > 'Z'&&str1[i + 1] < 'a' || (str1[i + 1] > 'z'))
				{
					str.push_back(str2);
					str2.clear();
				}
			}
		}
		for (int i = str.size() - 1; i > 0; i--)
		{
			cout << str[i] << endl;
		}
		system("pause");
		return 0;
	}
}
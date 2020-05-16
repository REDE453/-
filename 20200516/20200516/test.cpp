#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	string str, final_str;
	int sum;
	while (getline(cin, str)) //cin>>str会忽略输入的空格导致错误，getline保留空格
	{
		size_t len = str.size();
		for (int i = 0; i < len;)
		{
			sum = 0;
			for (int j = i; j < len; j++)
			{
				sum += str[i] == str[j];
				if (str[i] != str[j])
					break;
			}
			if (sum > 1)
				final_str += to_string(sum - 1) + str[i];
			else
				final_str += str[i];
			i = i + sum;
		}
	}
	cout << final_str;
}
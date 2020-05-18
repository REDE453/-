#include<string>
#include<iostream>
using namespace std;
bool FlagError = false;
int isHW(string str, int left, int right)//�������ж�
{
	while (left < right)
	{
		if (str[left] == str[right])
		{
			left++;
			right--;
		}
		else if (!FlagError)
		{
			FlagError = true;
			if (isHW(str, left + 1, right) != -2)
			{
				return left;
			}
			else if (isHW(str, left, right - 1) != -2)
			{
				return right;
			}
		}
		else
			return -2;//�޷�����
	}
	return -1;//����ԭ������һ�����Ĵ�
}
int main()
{
	int num = 0;
	string str;
	cin >> num;
	while (num--)
	{
		FlagError = false;
		cin >> str;
		cout << isHW(str, 0, str.size() - 1) << endl;
	}
	return 0;
}
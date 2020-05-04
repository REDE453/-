#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	int t;
	long int n, k, d1, d2, tmp, left;

	cin >> t;
	while (t > 0)
	{
		t--;
		cin >> n >> k >> d1 >> d2;

		tmp = k - d1 - d1 - d2; //球队1< 球队2，球队2<球队3       
		if (tmp >= 0 && tmp % 3 == 0) //球队1的得分有解是大前提
		{
			left = (n - k) - (d1 + d2 + d2);
			if (left >= 0 && left % 3 == 0)//剩下的场次不小于need，并且可以均分3场。
			{
				cout << "yes" << endl;
				continue;
			}
		}

		tmp = k - d1 - d1 + d2; //球队1< 球队2，球队2>球队3
		if (tmp >= 0 && tmp % 3 == 0)
		{
			left = (n - k) - (d1 + d2);
			if (left >= 0 && left % 3 == 0)
			{
				cout << "yes" << endl;
				continue;
			}
		}

		tmp = k + d1 + d1 + d2;//球队1> 球队2，球队2>球队3
		if (tmp >= 0 && tmp % 3 == 0)
		{
			left = (n - k) - (d1 + d1 + d2);
			if (left >= 0 && left % 3 == 0)
			{
				cout << "yes" << endl;
				continue;
			}
		}

		tmp = k + d1 + d1 - d2;//球队1>球队2，球队2<球队3
		if (tmp >= 0 && tmp % 3 == 0)
		{
			if (d1 >= d2)
			{
				left = (n - k) - (d1 + d1 - d2);
			}
			else
			{
				left = (n - k) - (d2 + d2 - d1);
			}
			if (left >= 0 && left % 3 == 0)
			{
				cout << "yes" << endl;
				continue;
			}
		}

		cout << "no" << endl;
	}

	return 0;
}
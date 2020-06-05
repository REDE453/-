#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main()
{
	int n;
	vector<int> arr;
	while (cin >> n)
	{
		arr.resize(n);
		int count1 = 0;
		int count2 = 0;
		double arv = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			if (arr[i] - 0 > 0.0000001)
			{
				count1++;
				arv += arr[i];
			}
			else if (arr[i] < 0)
			{
				count2++;
			}
		}
		printf("%d %0.1lf\n", count2, arv / count1);
	}
	return 0;
}
//class Solution {
//public:
//	/**
//	 *
//	 * @param number string×Ö·û´®
//	 * @return string×Ö·û´®
//	 */
//	string change(string number) {
//		// write code here
//		int left = 0;
//		int right = number.size() - 1;
//		while (left < right)
//		{
//			while ((number[left] - '0') % 2 != 0)
//			{
//				++left;
//			}
//			while ((number[right] - '0') % 2 != 0)
//			{
//				--right;
//			}
//			if (left < right)
//			{
//				swap(number[left], number[right]);
//				++left;
//				--right;
//			}
//		}
//		return number;
//	}
//};
#include<iostream>
using namespace std;
bool func(int n)
{
	for (int i = 2; i <= sqrt(n); ++i)
		if (n%i == 0)
			return 0;
	return 1;
}

int main()
{
	int n;
	int count = 0;
	while (cin >> n)
	{
		for (int i = 2; i < n; ++i)
		{
			if (func(i) && i % 10 == 1)
			{
				cout << i << " ";
				++count;
			}
		}
		cout << endl;
	}
	if (0 == count)
		cout << "-1" << endl;
	return 0;
}
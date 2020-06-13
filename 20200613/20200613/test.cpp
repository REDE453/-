#include<iostream>
#include<vector>
#include<Windows.h>
using namespace std;
//class Solution {
//public:
//	int cutRope(int number) {
//		if (number == 2)
//			return 1;
//		if (number == 3)
//			return 2;
//		vector<int>cur(number+1,-1);
//		for (int i = 1; i <= 4; ++i)
//		{
//			cur[i] = i;
//		}
//		for (int i = 5; i <= number; ++i)
//		{
//			for (int j = 1; j < i; ++j)
//			{
//				cur[i] = max(cur[i], j*cur[i - j]);
//			}
//		}
//		return cur[number];
//	}
//};
//int main()
//{
//	Solution s;
//	int number;
//	cin >> number;
//	cout << s.cutRope(number)<<endl;
//	system("pause");
//	return 0;
//
class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication)
	{
		for (int i = 0; i != length; ++i)
		{
			int index = numbers[i] % length;
			if (numbers[index] >= length)
			{
				*duplication = index;
				return 1;
			}
			numbers[index] += length;
		}
		return 0;
	}
};
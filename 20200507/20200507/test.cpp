#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int number;
	cin >> number;
	vector<int> vect;
	while (number--)
	{
		int temp = 0;
		cin >> temp;
		vect.push_back(temp);
	}
	long long sum_right = 0;
	long long sum_left = 0;
	int left = 0;
	int right = vect.size() - 1;
	long long result;
	while (left <= right)
	{
		if (sum_right == sum_left && left != right)
		{
			sum_left += vect[left];
			sum_right += vect[right];
			left++;
			right--;
		}
		else if (sum_left > sum_right)
		{
			sum_right += vect[right];
			right--;
		}
		else
		{
			sum_left += vect[left];
			left++;
		}
		if (sum_right == sum_left)
		{
			result = sum_right;
		}
	}
	cout << result << endl;
	return 0;
}
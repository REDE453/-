#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> input;
	int tmp;
	while (cin >> tmp)
	{
		input.push_back(tmp);
		if (cin.get() == '\n')
			break;
	}
	int n = input.size();
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (input[j] > input[j + 1])
			{
				tmp = input[j + 1];
				input[j + 1] = input[j];
				input[j] = tmp;
			}
		}
	}
	cout << input[n - 3];
}
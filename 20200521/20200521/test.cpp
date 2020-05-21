#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int temp_number = 0;
	vector <int> vect;
	for (int i = 0; i < 3; i++)
	{
		cin >> temp_number;
		vect.push_back(temp_number);
	}
	sort(vect.begin(), vect.end());
	cout << vect[2] * max(vect[0] + vect[1], vect[0] * vect[1]) << endl;
	return 0;
}
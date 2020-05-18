#include <iostream>
#include <algorithm>
using namespace std;

long Result[10001] = { 0 }; //存放各个n对应的结果


long NumOption(int n)
{
	long res = 0;
	if (n == 0) Result[0] = 1;
	if (n == 1) Result[1] = 1;
	if (n == 2) Result[2] = 2;
	int step = 0;
	if (Result[n] != 0) return Result[n]; // 若结果里已经有值，直接取出不用递归
	while (true)
	{
		if (n - pow(2, step) < 0) break; // 循环结束
		res += NumOption(n - pow(2, step));
		step++;
	}
	Result[n] = res % (1000000003);
	return Result[n];
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int in;
		cin >> in;
		long res = NumOption(in);
		cout << res << endl;
	}
	return 0;
}
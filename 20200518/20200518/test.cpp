#include <iostream>
#include <algorithm>
using namespace std;

long Result[10001] = { 0 }; //��Ÿ���n��Ӧ�Ľ��


long NumOption(int n)
{
	long res = 0;
	if (n == 0) Result[0] = 1;
	if (n == 1) Result[1] = 1;
	if (n == 2) Result[2] = 2;
	int step = 0;
	if (Result[n] != 0) return Result[n]; // ��������Ѿ���ֵ��ֱ��ȡ�����õݹ�
	while (true)
	{
		if (n - pow(2, step) < 0) break; // ѭ������
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
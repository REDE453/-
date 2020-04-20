//#include <iostream>
//#define MAX 83 //如果用公式计算，需要接下来两项的值
//using namespace std;
//void solve(long long num[])
//{
//	for (int i = 2; i < MAX; i++)
//	{
//		num[i] = num[i - 1] + num[i - 2];
//	}
//}
//long long sum_traversal(long long num[], int from, int to) 
//{
//	long long ans = 0;
//	for (int i = from - 1; i < to; i++) //让数组下标从from - 1遍历到to - 1
//	{
//		ans += num[i];
//	} 
//	return ans;
//}
//int main()
//{
//	int from, to;
//	long long num[MAX] = { 1, 1 };
//	//提前计算Fibonacci数列
//	solve(num);
//	while (cin >> from >> to)
//	{
//		cout << sum_formula(num, from, to) << std::endl;
//	}
//	return 0;
//}
#include<iostream>
#include<string>
using namespace std;
int main()
{
	std::string s, t;
	while (cin >> s >> t)
	{
		int res = 0;
		size_t pos = 0;
		//依次在 s 中查找 t 即可，直到再也找不到 t
		while ((pos = s.find(t, pos)) != string::npos)
		{
			pos += t.size(); //跳过t串整体的长度
			++res; //计数
		}
		cout << res << std::endl;
	} 
	return 0;
}
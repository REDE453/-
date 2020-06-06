//class Solution {
//public:
//	int Fibonacci(int n) {
//
//		int* f = new int[n + 1];
//		f[0] = 0;
//		//初始化
//		f[1] = f[2] = 1;
//		//转移方程
//		for (int i = 3; i <= n; ++i)
//		{
//			f[i] = f[i - 1] + f[i - 2];
//		}
//		int ret = f[n];
//		delete[]f;
//		//返回值
//		return ret;
//	}
//};
//class Solution {
//public:
//	int jumpFloorII(int number) {
//
//		if (number <= 0)
//			return 0;
//		int total = 1;
//		for (int i = 1; i < number; ++i)
//			total *= 2;
//		return total;
//	}
//};
//

class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		vector<bool>f(s.size(), false);
		for (int i = 0; i < s.size(); ++i)
		{
			//首先看整体是否可以在词典中找到
			if (dict.find(s.substr(0, i + 1)) != dict.end())
			{
				f[i] = true;
				continue;
			}
			for (int j = i - 1; j >= 0; --j)
			{
				//j<i
				//f[j]&&[j+1,i]是否可以找到
				if (f[j] && dict.find(s.substr(j + 1, i - j)) != dict.end())
				{
					f[i] = true;
					break;
				}
			}
		}
		return f[s.size() - 1];
	}
};
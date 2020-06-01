#include<iostream>
#include<cmath>
using namespace std;
int weishu(int a)  //计算x的位数
{
	int count = 0;
	while (a > 0) {
		a /= 10;
		count++;
	}
	return count;
}
void shuzu(int x, int w, int *n)  //将x存为数组
{
	//int num=weishu(x);
	int i;
	for (i = 0; i < w; i++)
	{
		n[i] = x / pow(10, w - 1 - i);
		x = x % (int)pow(10, w - 1 - i);
	}
}
int main() {
	int x1, x2, k1, k2, count = 0;
	cin >> x1 >> k1 >> x2 >> k2;
	int w1 = weishu(x1);
	int w2 = weishu(x2);
	if (w1*k1 > w2*k2) cout << "Greater" << endl;
	else if (w1*k1 < w2*k2) cout << "Less" << endl;
	else
	{
		int n1[9], n2[9];
		shuzu(x1, w1, n1); shuzu(x2, w2, n2);
		int i;
		for (i = 0; i < w1*k1; i++)
		{
			if (n1[i%w1] > n2[i%w2])
			{
				cout << "Greater" << endl;
				break;
			}
			else if (n1[i%w1] < n2[i%w2])
			{
				cout << "Less" << endl;
				break;
			}
			else count++;

			if (i != 0 && i%w1 == 0 && i%w2 == 0) break;
		}
		//cout<<count<<" "<<i<<endl;
		if (count == i + 1 || count == w1 * k1) cout << "Equal" << endl;
	}
	return 0;
}
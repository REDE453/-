#include <iostream>
using namespace std;
int main(void) {
	int n, k, y;
	cin >> n >> k;
	//注意溢出
	long long count = 0;
	for (y = k + 1; y <= n; y++) {
		if (n%y < k)
			count += (n / y)*(y - k);
		else
			//当k为0时出现x=y*0+0=0，不为正整数，所以要-1
			count += (n / y)*(y - k) + (n%y - k + 1) + (!k ? -1 : 0);
	}
	cout << count;
	return 0;
}
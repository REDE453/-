#include <iostream>
using namespace std;
int main(void) {
	int n, k, y;
	cin >> n >> k;
	//ע�����
	long long count = 0;
	for (y = k + 1; y <= n; y++) {
		if (n%y < k)
			count += (n / y)*(y - k);
		else
			//��kΪ0ʱ����x=y*0+0=0����Ϊ������������Ҫ-1
			count += (n / y)*(y - k) + (n%y - k + 1) + (!k ? -1 : 0);
	}
	cout << count;
	return 0;
}
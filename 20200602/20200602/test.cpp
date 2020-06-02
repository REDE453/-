#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
double quota, ans = 0;
vector<double> receipt;//存放每张有效发票的金额

void DFS(int index, double sum) {
	ans = max(ans, sum);
	if (index >= receipt.size()) return;
	if (sum + receipt[index] <= quota)
		DFS(index + 1, sum + receipt[index]);
	DFS(index + 1, sum);
}

int main() {
	while (scanf("%lf%d", &quota, &n) != EOF && n != 0) {
		receipt.clear();//初始化
		ans = 0;
		for (int i = 0; i < n; i++) {//输入每张发票的票面金额
			int num;//num是发票项数,sum是这张发票总金额
			double sum = 0;
			bool flag = true;//判断这张发票是否合法;
			scanf("%d", &num);
			getchar();
			for (int j = 0; j < num; j++) {//输入每张发票的每项金额
				double amount;
				char type;
				scanf("%c:%lf%*c", &type, &amount);
				if (amount <= 600 && type - 'A' <= 2) sum += amount;
				else flag = false;
			}
			if (sum <= 1000 && flag && sum <= quota)
				receipt.push_back(sum);
		}
		DFS(0, 0);
		printf("%.2f\n", ans);
	}
	return 0;
}
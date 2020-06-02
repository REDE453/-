#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
double quota, ans = 0;
vector<double> receipt;//���ÿ����Ч��Ʊ�Ľ��

void DFS(int index, double sum) {
	ans = max(ans, sum);
	if (index >= receipt.size()) return;
	if (sum + receipt[index] <= quota)
		DFS(index + 1, sum + receipt[index]);
	DFS(index + 1, sum);
}

int main() {
	while (scanf("%lf%d", &quota, &n) != EOF && n != 0) {
		receipt.clear();//��ʼ��
		ans = 0;
		for (int i = 0; i < n; i++) {//����ÿ�ŷ�Ʊ��Ʊ����
			int num;//num�Ƿ�Ʊ����,sum�����ŷ�Ʊ�ܽ��
			double sum = 0;
			bool flag = true;//�ж����ŷ�Ʊ�Ƿ�Ϸ�;
			scanf("%d", &num);
			getchar();
			for (int j = 0; j < num; j++) {//����ÿ�ŷ�Ʊ��ÿ����
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
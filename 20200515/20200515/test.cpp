#include<iostream>
using namespace std;
int main()
{
	int HP;
	cin >> HP;
	int nA, bA;
	cin >> nA;
	cin >> bA;
	int count = 0;
	if (HP <= nA) {
		cout << 1;
		return 0;
	}
	else {
		if (2 * nA >= bA) {//���������˺���������ͨ�˺��Ķ�����ʱ��ȫ����ͨ�˺�������
			while (HP > 0) {
				HP -= nA;
				count++;
			}
		}
		else {//���������˺�������ͨ�˺��Ķ�����ʱ��,�����ܶ�������˺����ж�����ǲ���ֻ���һ����ͨ�˺�������
			while (HP > nA) {
				HP -= bA;
				count += 2;
			}
			if (HP > 0) count++;
		}
	}
	cout << count;
	return 0;
}
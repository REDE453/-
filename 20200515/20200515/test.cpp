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
		if (2 * nA >= bA) {//当蓄力的伤害不高于普通伤害的二倍的时候，全用普通伤害就行了
			while (HP > 0) {
				HP -= nA;
				count++;
			}
		}
		else {//当蓄力的伤害高于普通伤害的二倍的时候,尽可能多打蓄力伤害，判断最后是不是只需打一次普通伤害就行了
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
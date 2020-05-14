#include <iostream>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	int *a = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	int *b = new int[N + 1];
	b[0] = 0;
	int *c = new int[N + 1];
	c[0] = 0;
	int sum = 0;
	for (int i = 1; i <= M; i++) {
		b[i] = b[i - 1] + a[i - 1];
		c[i] = b[i];
		for (int j = i + 1; j <= N - M + i; j++) {
			b[j] = b[j - 1] > c[j - 1] ? b[j - 1] + a[j - 1] : c[j - 1] + a[j - 1];
			sum = sum > b[j] ? sum : b[j];
		}
		for (int j = i + 1; j <= N - M + i; j++) {
			c[j] = c[j - 1] > b[j] ? c[j - 1] : b[j];
		}
	}
	cout << sum << endl;
	delete a, b, c;
	return 0;
}
#include<iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int Hi[105];
	int Mi[105];
	for (int i = 0; i < N; i++)
	{
		cin >> Hi[i] >> Mi[i];
	}
	int X;
	cin >> X;
	int A, B;
	cin >> A >> B;
	int re = 0;
	for (int i = 0; i < N; i++)
	{
		if ((Hi[i] * 60 + Mi[i] + X) <= (A * 60 + B))
		{
			if ((Hi[re] * 60 + Mi[re]) < (Hi[i] * 60 + Mi[i]))
			{
				re = i;
			}
		}
	}
	cout << Hi[re] << " " << Mi[re];
	return 0;
}
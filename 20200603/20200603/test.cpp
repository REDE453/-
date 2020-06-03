#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int> > res(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			res[i].push_back(0);
		}
	}
	int num = 1;
	int c = 0;
	int r = 0;
	for (; c < m; c++)
	{
		int tmp_c = c;
		int tmp_r = 0;
		while (tmp_r < n&&tmp_c >= 0)
		{
			res[tmp_r][tmp_c] = num;
			tmp_r++;
			tmp_c--;
			num++;
		}
	}
	for (r = 1; r < n; r++)
	{
		int tmp_c = m - 1;
		int tmp_r = r;
		while (tmp_r < n&&tmp_c >= 0)
		{
			res[tmp_r][tmp_c] = num;
			tmp_r++;
			tmp_c--;
			num++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
}
#include<bits/stdc++.h>
using namespace std;

const int N = 1010,INF = 1e9;

int r;
int a[N][N], f[N][N];

int main()
{
	cin >> r;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i <= r; i++)
	{
		for (int j = 0; j <= i + 1; j++)
		{
			f[i][j] = -INF;
		}
	}

	f[1][1] = a[1][1];

	for (int i = 2; i <= r; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			f[i][j] = max(f[i - 1][j] + a[i][j], f[i - 1][j - 1] + a[i][j]);
		}
	}

	int res = -INF;
	for (int i = 1; i <= r; i++)res = max(res, f[r][i]);

	cout << res;

	return 0;
}

//   要学会这个dfs怎么做的%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//   自己写不出来%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


#include<bits/stdc++.h>
using namespace std;

const int N = 6;
int n, a[N*N],sum, ans[N][N];
bool st[N * N];

bool check(int x, int y, int i)
{
	if (y == n)
	{
		int sum1 = a[i];
		for (int i = 1; i < n; i++)
		{
			sum1 += ans[x][i];
		}
		if (sum1 != sum)return false;
	}
	if (x == n)
	{
		int sum1 = a[i];
		for (int i = 1; i < n; i++)
		{
			sum1 += ans[i][y];
		}
		if (sum1 != sum)return false;
	}
	if (x == n && y == 1)
	{
		int sum1 = a[i];
		for (int i = 1; i < n; i++)
		{
			sum1 += ans[i][n - i + 1];
		}
		if (sum1 != sum)return false;
	}
	if (x == n && y == n)
	{
		int sum1 = a[i];
		for (int i = 1; i < n; i++)
		{
			sum1 += ans[i][i];
		}
		if (sum1 != sum)return false;
	}
	return true;
}

void dfs(int x, int y)
{
	if (x == n + 1)
	{
		cout << sum << endl;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cout << ans[i][j] << ' ';
			}
			cout << endl;
		}
		exit(0);                //   return会回溯很多层，直接exit(0)正常退出程序
	}
	for (int i = 1; i <= n * n; i++)
	{
		if (!st[i])
		{
			if (!check(x, y, i))
			{
				continue;
			}
			else
			{
				st[i] = 1;
				ans[x][y] = a[i];
				if (y == n)dfs(x + 1, 1);
				else dfs(x, y + 1);
				st[i] = 0;
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n * n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	sum = sum / n;
	sort(a + 1, a + 1 + n*n);
	dfs(1, 1);

	return 0;
}
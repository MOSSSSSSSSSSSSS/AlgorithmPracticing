

#include<bits/stdc++.h>
using namespace std;

const int N = 30;
int n, m;
int check[N][N];
bool record[N];
int ans;

void dfs(int x,int dis)
{
	record[x] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (check[x][i] && !record[i])
		{
			dis += check[x][i];
			dfs(i,dis);
			record[i] = 0;
			dis -= check[x][i];
		}
	}

	ans = max(ans, dis);
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		check[x][y] = z;
		check[y][x] = z;
	}
	for (int i = 1; i <= n; i++)
	{
		dfs(i, 0);
		record[i] = 0;
	}

	cout << ans;

	return 0;
}
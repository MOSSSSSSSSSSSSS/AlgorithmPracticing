

#include<bits/stdc++.h>
using namespace std;

const int N = 110,INF = 0x3f3f3f3f;
int n, m;
int g[N][N];
int d[N][N];
int ans;

void floyd()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}
void floyd2(int a,int b)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			g[i][j] = min(g[i][j], g[i][a] + g[a][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			g[i][j] = min(g[i][j], g[i][b] + g[b][j]);
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)g[i][j] = 0;
			else g[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = min(g[a][b], c);
		g[b][a] = g[a][b];
	}
	floyd();
	for (int i = 2; i <= n; i++)
		for (int j = 1; j < i; j++)
			ans += g[i][j];
	for (int k = 1; k <= n; k++)
		for (int l = 1; l <= n; l++)
			d[k][l] = g[k][l];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			g[i][j] = g[j][i] = 0;
			floyd2(i,j);
			int res = 0;
			for (int k = 2;k <= n; k++)
				for (int l = 1; l < k; l++)
					res += g[k][l];
			ans = min(ans, res);
			for (int k = 1; k <= n; k++)
				for (int l = 1; l <= n; l++)
					g[k][l] = d[k][l];
		}
	}
	cout << ans;

	return 0;
}
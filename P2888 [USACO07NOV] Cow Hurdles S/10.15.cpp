

#include<bits/stdc++.h>
using namespace std;

const int N = 310,INF = 1e8;
int g[N][N];
int n, m, t;

void floyd()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				g[i][j] = min(g[i][j], max(g[i][k], g[k][j]));
			}
		}
	}
}

int main()
{
	cin >> n >> m >> t;
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
	}
	floyd();
	while (t--)
	{
		int x, y;
		cin >> x >> y;
		if (g[x][y] == INF)cout << -1 << endl;
		else cout << g[x][y] << endl;
	}

	return 0;
}
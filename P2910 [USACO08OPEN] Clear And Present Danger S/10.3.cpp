

#include<bits/stdc++.h>
using namespace std;

const int N = 110,INF = 0x3f3f3f3f;
int n, m, path[N], g[N][N],ans,las = 1;

void floyd()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> path[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			g[i][j] = INF;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int x;
			cin >> x;
			g[i][j] = min(g[i][j], x);
		}
	}
	floyd();
	for (int i = 1; i <= m; i++)
	{
		ans += g[las][path[i]];
		las = path[i];
	}
	cout << ans;

	return 0;
}
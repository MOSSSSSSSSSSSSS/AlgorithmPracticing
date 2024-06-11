

#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 510, INF = 1e16;
int n, m;
int w[N][N];
bool va[N], vb[N];
int la[N], lb[N];
int d[N];
int match[N];
int ans;

bool dfs(int u)
{
	va[u] = true;
	for (int i = 1; i <= n; i++)
	{
		if (!vb[i])
		{
			if (la[u] + lb[i] == w[u][i])
			{
				vb[i] = true;
				if (!match[i] || dfs(match[i]))
				{
					match[i] = u;
					return 1;
				}
			}
			else
			{
				d[i] = min(d[i], la[u] + lb[i] - w[u][i]);
			}
		}
	}
	return 0;
}
void km()
{
	for (int i = 1; i <= n; i++)
	{
		la[i] = -INF;
		lb[i] = 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			la[i] = max(la[i], w[i][j]);
	for (int i = 1; i <= n; i++)
	{
		while (true)
		{
			for (int j = 1; j <= n; j++)
				va[j] = vb[j] = 0,d[j] = INF;
			if (dfs(i))break;
			int delta = INF;
			for (int j = 1; j <= n; j++)
				delta = min(delta, d[j]);
			for (int j = 1; j <= n; j++)
			{
				if (va[j])la[j] -= delta;
				if (vb[j])lb[j] += delta;
			}
		}
	}
}

signed main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			w[i][j] = -INF;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		w[a][b] = c;
	}
	km();
	for (int i = 1; i <= n; i++)
		ans += w[match[i]][i];
	cout << ans << '\n';
	for (int i = 1; i <= n; i++)
		cout << match[i] << ' ';

	return 0;
}
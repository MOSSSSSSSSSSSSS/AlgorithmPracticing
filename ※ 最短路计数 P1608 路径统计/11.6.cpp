
#include<bits/stdc++.h>
using namespace std;

const int N = 2010,INF = 0x3f3f3f3f;
int g[N][N];
int n, m;
int dist[N];
bool st[N];
int ans[N];

bool dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	ans[1] = 1;
	for (int i = 0; i < n; i++)
	{
		int t = -1;
		for (int j = 1; j <= n; j++)
			if (!st[j] && (t==-1||dist[t] > dist[j]))
				t = j;
		st[t] = true;
		for (int j = 1; j <= n; j++)
		{
			if (!st[j])
			{
				if (dist[j] == dist[t] + g[t][j])
				{
					ans[j] += ans[t];
				}
				else if (dist[j] > dist[t] + g[t][j])
				{
					ans[j] = ans[t];
					dist[j] = dist[t] + g[t][j];
				}
			}
		}
	}
	if (dist[n] == 0x3f3f3f3f)return false;
	else return true;
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
	}
	if (dijkstra())
	{
		cout << dist[n] << ' ' << ans[n];
	}
	else
	{
		cout << "No answer";
	}

	return 0;
}
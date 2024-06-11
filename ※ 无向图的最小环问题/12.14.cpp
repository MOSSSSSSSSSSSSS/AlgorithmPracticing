

//  无向图枸成环 ，至少需要三个点
//  有向图构成环，至少需要两个点
//  floyd算法

//  注意  如何 初始化，如何加边。

//  用了lambda表达式，（匿名函数）

#include<bits/stdc++.h>
using namespace std;

const int N = 110,INF = 5e8;
int g[N][N];
int dist[N][N];
int n, m;
int ans = INF;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)dist[i][j] = g[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = min(g[u][v], w);
		dist[u][v] = dist[v][u] = g[v][u] = g[u][v];
	}
	auto floyd = []() {
		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i < k; i++)
			{
				for (int j = i + 1; j < k; j++)
				{
					ans = min(ans, dist[i][j] + g[i][k] + g[k][j]);
				}
			}
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	};                                  //   注意  匿名函数后面加  分号
	floyd();
	if (ans != INF)cout << ans;
	else cout << "No solution.";

	return 0;
}
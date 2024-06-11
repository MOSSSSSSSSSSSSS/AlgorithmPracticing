





//   注意这题，邮递员从邮局到某地，又从某地会回邮局，不能走原路，因为所有路都是单向的
//   建原图的同时建一个    反图   ，与原题中的路方向相反，再求一次dijkstra()，就能求出回邮局的最短路





#include<bits/stdc++.h>
using namespace std;

const int N = 1010,INF = 0x3f3f3f3f;
int n, m;
int g[N*2][N*2];
int dist[N*2];
bool st[N*2];

void dijkstra(int k)
{
	for (int i = 1+k; i <= n+k; i++)dist[i] = INF;
	dist[1+k] = 0;
	for (int i = 0; i < n; i++)
	{
		int t = -1;                //  t记录最小的
		for (int j = 1+k; j <= n+k; j++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		st[t] = true;
		for (int j = 1+k; j <= n+k; j++)
			dist[j] = min(dist[j], dist[t] + g[t][j]);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= 2*n; i++)
	{
		for (int j = 1; j <= 2*n; j++)
		{
			if (i == j)g[i][j] = 0;
			else g[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		g[x][y] = min(g[x][y],z);                             //  题目没说，但有重边
		g[y+n][x+n] = min(g[y + n][x + n],z);
	}

	dijkstra(0);
	dijkstra(n);
	long long ans = 0;
	for (int i = 1; i <= 2*n; i++)ans += dist[i];
	cout << ans;

	return 0;
}
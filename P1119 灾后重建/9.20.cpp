

/*#include<bits/stdc++.h>
using namespace std;

const int N = 210, M = 20000,INF = 0x3f3f3f3f;
int n, m,q;
int t[N];
int g[N][N];
bool vis[N]; // ÐÞÃ»ÐÞºÃ
int u[M], v[M], w[M];

void floyd()
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)g[i][j] = 0;
			else g[i][j] = INF;
		}
	}
	for (int i = 0; i < n; i++)
		cin >> t[i];
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		u[i] = a;
		v[i] = b;
		w[i] = c;
	}
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int x, y, tt;
		cin >> x >> y >> tt;
		for (int j = 0; j < m; j++)
		{
			if (t[u[j]] <= tt && t[v[j]] <= tt)
			{
				g[u[j]][v[j]] = min(g[u[j]][v[j]], w[j]);
				g[v[j]][u[j]] = g[u[j]][v[j]];
			}
		}
		floyd();
		if (g[x][y] > INF / 2)cout << -1 << endl;
		else cout << g[x][y] << endl;
	}

	return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 210, INF = 0x3f3f3f3f;
int n, m, q;
int t[N];
int g[N][N];

void floyd(int k)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)g[i][j] = 0;
			else g[i][j] = INF;
		}
	}
	for (int i = 0; i < n; i++)
		cin >> t[i];
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = min(g[a][b], c);
		g[b][a] = g[a][b];
	}
	cin >> q;
	int now = 0;
	for (int i = 0; i < q; i++)
	{
		int x, y, tt;
		cin >> x >> y >> tt;
		for (int i = now; i < n; i++)
		{
			if (t[i] <= tt)
			{
				now++;
				floyd(i);
			}
			else
				break;
		}
		if (x >= now || y >= now)
		{
			cout << -1 << endl;
			continue;
		}
		if (g[x][y] > INF / 2)cout << -1 << endl;
		else cout << g[x][y] << endl;
	}

	return 0;
}
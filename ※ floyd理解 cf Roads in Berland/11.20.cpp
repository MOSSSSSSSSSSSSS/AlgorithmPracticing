

#include<bits/stdc++.h>
using namespace std;

const int N = 310,INF = 1e9;
int g[N][N];
int n,k;

int floyd(int a, int b)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			g[i][j] = min(g[i][a] + g[a][j], g[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			g[i][j] = min(g[i][b] + g[b][j], g[i][j]);
	int res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			res += g[i][j];
	return res;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> g[i][j];
	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = min(g[a][b],c);
		g[b][a] = g[a][b];
		cout << floyd(a, b) << ' ';
	}

	return 0;
}
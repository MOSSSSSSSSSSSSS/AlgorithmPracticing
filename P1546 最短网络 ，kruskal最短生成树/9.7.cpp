

#include<bits/stdc++.h>
using namespace std;

const int N = 110,INF = 0x3f3f3f3f;
int n, m;
int g[N][N];
int dist[N];
bool st[N];

int prim()
{
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		dist[i] = INF;
	}
	for (int i = 0; i < n; i++)
	{
		int t = -1;
		for (int j = 1; j <= n; j++)
		{
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
			{
				t = j;
			}
		}
		if (i && dist[t] == INF)return INF;
		if (i)res += dist[t];
		st[t] = 1;
		for (int j = 1; j <= n; j++)
		{
			dist[j] = min(dist[j], g[t][j]);
		}
	}
	return res;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> g[i][j];
		}
	}
	cout << prim() << endl;

	return 0;
}
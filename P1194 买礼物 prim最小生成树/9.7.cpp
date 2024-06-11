

#include<bits/stdc++.h>
using namespace std;

const int N = 1010,INF = 0x3f3f3f3f;
int a, b;
int g[N][N];
int dist[N];
bool st[N];

int prim()
{
	int res = 0;
	for (int i = 1; i <= b; i++)dist[i] = INF;
	for (int i = 0; i < b; i++)
	{
		int t = -1;
		for (int j = 1; j <= b; j++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		if (i && dist[t] == INF)return INF;
		if (i)res += dist[t];
		else res += a;
		for (int j = 1; j <= b; j++)
			dist[j] = min(dist[j], g[t][j]);
		st[t] = 1;
	}
	return res;
}

int main()
{
	cin >> a >> b;
	for (int i = 1; i <= b; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			cin >> g[i][j];
			if (i != j && g[i][j] == 0)g[i][j] = a;
			if (i != j && g[i][j] > a)g[i][j] = a;
		}
	}
	cout << prim() << endl;

	return 0;
}
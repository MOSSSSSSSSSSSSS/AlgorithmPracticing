

#include<bits/stdc++.h>
using namespace std;

const int N = 1510, M = 50010,INF = 0x3f3f3f3f;
int n, m;
int h[N], w[M], e[M], ne[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void spfa()
{
	queue<int> q;
	q.push(1);
	st[1] = 1;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = 0;
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > w[i] + dist[t])
			{
				dist[j] = w[i] + dist[t];
				if (!st[j])
				{
					st[j] = 1;
					q.push(j);
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		dist[i] = INF;
		h[i] = -1;
	}
	dist[1] = 0;
	
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u>> v>> w;
		w = 0 - w;
		add(u, v, w);
	}
	spfa();
	if (dist[n] == INF)cout << -1;
	else cout << dist[n]*(-1);

	return 0;
}
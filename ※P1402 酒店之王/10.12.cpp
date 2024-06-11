

//我们发现酒店的房间和菜都是和人有关的，所以我们把人和房间、菜分别连边，并且从原点s向 房间连边，菜向汇点连边

// 拆点

#include<bits/stdc++.h>
using namespace std;

const int N = 410, M = 40610,INF = 1e8;
int n, p, q;
int S = 0, T;
int h[N], e[M], ne[M], w[M], idx;
int d[N], cur[N], qq[N];

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
bool bfs()
{
	int hh = 0, tt = -1;
	memset(d, -1, sizeof d);
	qq[++tt] = S, d[S] = 0, cur[S] = h[S];
	while (hh <= tt)
	{
		int t = qq[hh++];
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if (d[j] == -1 && w[i])
			{
				d[j] = d[t] + 1;
				cur[j] = h[j];
				qq[++tt] = j;
				if (j == T)return true;
			}
		}
	}
	return false;
}
int find(int u, int limit)
{
	if (u == T)return limit;
	int flow = 0;
	for (int i = cur[u]; ~i && flow < limit; i = ne[i])
	{
		cur[u] = i;
		int j = e[i];
		if (d[j] == d[u] + 1 && w[i])
		{
			int t = find(j, min(w[i], limit - flow));
			if (!t)d[j] = -1;
			w[i] -= t, w[i ^ 1] += t, flow += t;
		}
	}
	return flow;
}
int dinic()
{
	int ans = 0, flow;
	while (bfs())while (flow = find(S, INF))ans += flow;
	return ans;
}

int main()
{
	cin >> n >> p >> q;
	T = 2*n + p + q + 1;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= p; i++)
		add(S, i, 1),add(i,S,0);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= p; j++)
		{
			int x;
			cin >> x;
			if (x) add(j, p + i, 1), add(p + i, j, 0);
		}
	}
	for (int i = p + 1; i <= p + n; i++)
		add(i, i + n, 1), add(i + n,i, 0);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= q; j++)
		{
			int x;
			cin >> x;
			if (x) add(p+n+i, p+2*n+j, 1), add(p + 2 * n + j, p + n + i, 0);
		}
	}
	for (int i = 2*n +p+ 1; i <= 2*n + p + q; i++)
		add(i, T, 1), add(T, i, 0);
	cout<<dinic();

	return 0;
}
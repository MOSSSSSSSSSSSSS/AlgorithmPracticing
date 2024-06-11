

#include<bits/stdc++.h>
using namespace std;

const int N = 610, M = 3000610,INF = 1e8;
int h[N], e[M], ne[M], w[M], idx;
int d[N], cur[N], q[N];
int m, n, S, T;
int last[2510];
int num[2510];

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
	q[++tt] = S, d[S] = 0, cur[S] = h[S];
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if (d[j] == -1 && w[i])
			{
				d[j] = d[t] + 1;
				cur[j] = h[j];
				q[++tt] = j;
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
	cin >> m >> n;
	memset(h, -1, sizeof h);
	S = 0, T = n + 1;
	for (int i = 1; i <= m; i++)
		cin >> num[i];
	for (int i = 1; i <= n; i++)
	{
		int a, b, c;
		cin >> a;
		for (int j = 1; j <= a; j++)
		{
			cin >> b;
			if (!last[b])add(S, i, num[b]), add(i, S, 0);
			else add(last[b], i, INF), add(i, last[b], 0);
			last[b] = i;
		}
		cin >> c;
		add(i, T, c), add(T, i, 0);
	}
	cout << dinic();

	return 0;
}
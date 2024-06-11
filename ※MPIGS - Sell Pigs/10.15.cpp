

#include<bits/stdc++.h>
using namespace std;
#define mm memset

const int N = 110, M = 2e5 + 10,INF = 1e8;
int h[N], e[M], ne[M], w[M], idx;
int d[N], cur[N], q[N];
int n, m, S, T;
int last[1010];
int num[1010];

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
	mm(d, -1, sizeof d);
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
	for (int i = cur[u]; ~i&&flow<limit; i = ne[i])
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
	S = 0, T = n + 1;
	mm(h, -1, sizeof h);
	for (int i = 1; i <= m; i++)
		cin >> num[i];
	for (int i = 1; i <= n; i++)
	{
		int a,c;
		cin >> a;
		for (int j = 1; j <= a; j++)
		{
			int b;
			cin >> b;
			if (!last[b]) add(S, i, num[b]), add(i, S, 0);
			else add(last[b], i, INF), add(i, last[b], 0);
			last[b] = i;
		}
		cin >> c;
		add(i, T, c), add(T, i, 0);
	}
	cout << dinic();

	return 0;
}
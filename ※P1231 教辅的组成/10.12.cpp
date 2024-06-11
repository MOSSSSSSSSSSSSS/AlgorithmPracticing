

#include<bits/stdc++.h>
using namespace std;

const int N = 40010, M = 140010,INF = 1e8;
int h[N], e[M], ne[M], w[M], idx;
int d[N], cur[N], q[N];
int n1, n2, n3, m1, m2, S, T;

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
	cin >> n1 >> n2 >> n3;
	T = 2 * n1 + n2 + n3 + 1;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= n3; i++)
		add(S, i, 1), add(i, S, 0);
	for (int i = n3 + 1; i <= n3 + n1; i++)
		add(i, i + n1, 1), add(i + n1, i, 0);
	for (int i = n3 + 2 * n1 + 1; i <= n3 + 2 * n1 + n2; i++)
		add(i, T, 1), add(T, i, 0);
	cin >> m1;
	for (int i = 1; i <= m1; i++)
	{
		int a, b;
		cin >> a >> b;
		add(n3 + n1 + a, n3 + 2 * n1 + b, 1), add(n3 + 2 * n1 + b, n3 + n1 + a, 0);
	}
	cin >> m2;
	for (int i = 1; i <= m2; i++)
	{
		int a, b;
		cin >> a >> b;
		add(b, n3 + a, 1), add(n3 + a, b, 0);
	}
	cout << dinic();

	return 0;
}
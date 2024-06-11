

#include<bits/stdc++.h>
using namespace std;

const int N = 410, M = 40610,INF = 1e8;
int h[N], e[M], ne[M], w[M], idx;
int d[N], cur[N], q[N];
int n, m, p, S, T;

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
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
int dinic()
{
	int ans = 0, flow;
	while (bfs())while (flow = find(S, INF))ans += flow;
	return ans;
}

int main()
{
	cin >> n >> m >> p;  // nÅ£mÊ³ÎïpÒûÁÏ
	T = 2 * n + m + p + 1;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= m; i++)
		add(S, i, 1), add(i, S, 0);
	for (int i = m + 1; i <= m + n; i++)
		add(i, i + n, 1), add(i + n, i, 0);
	for (int i = 2 * n + m + 1; i <= 2 * n + m + p; i++)
		add(i, T, 1), add(T, i, 0);
	for (int i = 1; i <= n; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;
		for (int j = 1; j <= num1; j++)
		{
			int x;
			cin >> x;
			add(x, m + i, 1), add(m + i, x, 0);
		}
		for (int j = 1; j <= num2; j++)
		{
			int x;
			cin >> x;
			add(m + n + i, 2 * n + m + x, 1), add(2 * n + m + x, m + n + i, 0);
		}
	}
	cout << dinic();

	return 0;
}
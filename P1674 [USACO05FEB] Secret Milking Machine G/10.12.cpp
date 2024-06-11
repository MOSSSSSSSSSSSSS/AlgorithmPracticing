

#include<bits/stdc++.h>
using namespace std;

const int N = 210, M = 80010, INF = 1e8;
int l = 0, r = 1e6;
int h[N], e[M], ne[M], w[M], c[M], idx;
int d[N], cur[N], q[N];
int n, p, t;

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
	q[++tt] = 1, d[1] = 0, cur[1] = h[1];
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if (d[j] == -1 && c[i])
			{
				d[j] = d[t] + 1;
				cur[j] = h[j];
				q[++tt] = j;
				if (j == n)return true;
			}
		}
	}
	return false;
}
int find(int u, int limit)
{
	if (u == n)return limit;
	int flow = 0;
	for (int i = cur[u]; ~i&&flow<limit; i = ne[i])
	{
		cur[u] = i;
		int j = e[i];
		if (d[j] == d[u] + 1 && c[i])
		{
			int t = find(j, min(c[i], limit - flow));
			if (!t)d[j] = -1;
			c[i] -= t, c[i ^ 1] += t, flow += t;
		}
	}
	return flow;
}
int dinic()
{
	int ans = 0, flow;
	while (bfs())while (flow = find(1, INF))ans += flow;
	return ans;
}
bool check(int mid)
{
	for (int i = 0; i < idx; i++)
	{
		if (w[i] > mid)c[i] = 0;
		else c[i] = 1;
	}
	return (dinic() >= t);
}
int main()
{
	cin >> n >> p >> t;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= p; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c),add(b,a,c);
	}
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	cout << l;

	return 0;
}
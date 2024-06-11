

//  多了l存正向边的下界，A,存每个点应该由源点流多少或应该向汇点流多少


#include<bits/stdc++.h>
using namespace std;

const int N = 210, M = 22000,INF = 1e8;
int n, m,tot;
int h[N], e[M], ne[M],w[M], l[M], idx;
int d[N], cur[N], q[N], A[N];

void add(int a, int b, int c, int d)
{
	w[idx] = c - d,l[idx] = d, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
	w[idx] = 0, e[idx] = a, ne[idx] = h[b], h[b] = idx++;
}

bool bfs()
{
	int hh = 0, tt = -1;
	memset(d, -1, sizeof d);
	q[++tt] = 0, d[0] = 0, cur[0] = h[0];
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
				if (j == n + 1)return true;
			}
		}
	}
	return false;
}

int find(int u, int limit)
{
	if (u == n + 1)return limit;
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
	while (bfs())while (flow = find(0, INF))ans += flow;
	return ans;
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= m; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		add(a, b, d, c);
		A[a] -= c, A[b] += c;
	}
	for (int i = 1; i <= n; i++)
	{
		if (A[i] > 0)add(0, i, A[i], 0),tot+=A[i];
		else if (A[i] < 0)add(i, n + 1, -A[i], 0);
	}
	if (dinic() != tot)cout << -1;
	else
	{
		int ans = 0;
		for (int i = 0; i < 2 * m; i+=2)
			ans += (w[i ^ 1] + l[i]);
		cout << ans;
	}

	return 0;
}
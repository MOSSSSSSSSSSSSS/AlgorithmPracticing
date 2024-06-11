

#include<bits/stdc++.h>
using namespace std;

const int N = 1030, M = 42050,INF = 1e8;
int h[N], e[M], ne[M], w[M], idx;
int d[N], cur[N], q[N];
int n, k, S, T,tot;

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
	memset(d,-1, sizeof d);
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
	cin >> k >> n;
	T = n + k + 1;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= n; i++)
		add(S, i, 1), add(i, S, 0);
	for (int i = 1; i <= k; i++)
	{
		int x;
		cin >> x;
		add(n + i, T, x), add(T, n + i, 0);
		tot += x;
	}
	for (int i = 1; i <= n; i++)
	{
		int p;
		cin >> p;
		for (int j = 1; j <= p; j++)
		{
			int x;
			cin >> x;
			add(i, n + x, 1),add(n+x,i,0);
		}
	}
	if (dinic() != tot)
	{
		
		cout << "No Solution!";
		return 0;
	}
	for (int i = 1; i <= k; i++)
	{
		cout << i << ": ";
		for (int j = h[n + i]; ~j; j = ne[j])
			if (w[j]) cout << e[j] << ' ';
		cout << endl;
	}

	return 0;
}
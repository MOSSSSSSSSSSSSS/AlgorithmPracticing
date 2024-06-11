

#include<iostream>
using namespace std;

const int N = 510, M = 10010,INF = 1e8;

int n, m;
int h[N], e[M], ne[M], w[M], idx;
int d[N], cur[N], q[N];
bool vis_s[N], vis_t[N];
int ans = 0;

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
				if (j == n - 1)return true;
			}
		}
	}
	return false;
}
int find(int u, int limit)
{
	if (u == n - 1)return limit;
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
void dinic()
{
	while (bfs())while (find(0, INF));
}
void dfs(int u,bool st[],int t)
{
	st[u] = true;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (!st[j] && w[i ^ t])
			dfs(j,st,t);
	}
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, 0);
	}
	dinic();
	dfs(0,vis_s,0);
	dfs(n - 1,vis_t,1);
	for (int i = 0; i < idx; i += 2)
		if (!w[i] && vis_s[e[i^1]] && vis_t[e[i]])
			ans++;
	cout << ans;

	return 0;
}
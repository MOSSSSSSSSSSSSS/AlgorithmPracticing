
#include<bits/stdc++.h>
using namespace std;

const int N = 210, M = 4010,INF = 1e8;
int h[N], e[M], ne[M], w[M], idx;
int d[N], cur[N], q[N];
int n, m, x,S,T;

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
	cin >> n >> m >> x;
	S = 1, T = n;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, 0);
	}
	int res = dinic();
	if (!res)
	{
		cout << "Orz Ni Jinan Saint Cow!";
		return 0;
	}
	cout << res << ' ';
	if (x % res)cout << x / res + 1;
	else cout << x / res;

	return 0;
}
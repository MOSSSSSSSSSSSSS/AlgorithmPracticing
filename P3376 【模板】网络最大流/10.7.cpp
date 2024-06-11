

//ek

/*#include<bits/stdc++.h>
using namespace std;

const int N = 210, M = 10010,INF = 0x3f3f3f3f;
int n, m, s, t;
int h[N], e[M], ne[M], c[M], idx;
int q[N], d[N], pre[N];
bool st[N];

void add(int a, int b, int w)
{
	c[idx] = w;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

bool bfs()
{
	memset(st, false, sizeof st);
	int hh = 0, tt = -1;
	q[++tt] = s,st[s] = true,d[s] = INF;
	while (hh <= tt)
	{
		int x = q[hh++];
		for (int i = h[x]; ~i; i = ne[i])
		{
			int j = e[i];
			if (!st[j] && c[i] > 0)
			{
				d[j] = min(d[x], c[i]);
				pre[j] = i;
				q[++tt] = j;
				st[j] = true;
				if (j == t)return true;
			}
		}
	}
	return false;
}

long long ek()
{
	long long ans = 0;
	while (bfs())
	{
		ans += d[t];
		for (int i = t; i != s; i = e[pre[i] ^ 1])
			c[pre[i]] -= d[t], c[pre[i] ^ 1] += d[t];
	}
	return ans;
}

int main()
{
	cin >> n >> m >> s >> t;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		add(a, b, w);
		add(b, a, 0);
	}
	cout << ek() << endl;

	return 0;
}*/

// dinic


#include<bits/stdc++.h>
using namespace std;

const int N = 210, M = 10010,INF = 1e8;
int h[N], e[M], ne[M],w[M], idx;
int n, m, s, t;
int d[N], cur[N];
int q[N];

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
	q[++tt] = s, d[s] = 0, cur[s] = h[s];
	while (hh <= tt)
	{
		int top = q[hh++];
		for (int i = h[top]; ~i; i = ne[i])
		{
			int j = e[i];
			if (d[j] == -1 && w[i] > 0)
			{
				d[j] = d[top] + 1;
				cur[j] = h[j];
				q[++tt] = j;
				if (j == t)return true;
			}
		}
	}
	return false;
}

int Find(int u,int limit)
{
	if (u == t)return limit;
	int flow = 0;
	for (int i = cur[u]; ~i&&flow<limit; i = ne[i])
	{
		cur[u] = i;
		int j = e[i];
		if (d[j] == d[u] + 1 && w[i] > 0)
		{
			int t = Find(j, min(w[i], limit - flow));
			if (!t)d[j] = -1;
			w[i] -= t, w[i ^ 1] += t, flow += t;
		}
	}
	return flow;
}

long long dinic()
{
	long long ans = 0,flow;
	while (bfs())while (flow = Find(s, INF))ans += flow;
	return ans;
}

int main()
{
	cin >> n >> m >> s >> t;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, 0);
	}
	cout << dinic();

	return 0;
}


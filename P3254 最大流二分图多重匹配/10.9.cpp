

//  二分图多重匹配

#include<bits/stdc++.h>
using namespace std;

const int N = 450, M = 82010,INF = 1e8;
int m, n,tot;
int h[N], e[M], ne[M], w[M], idx;
int d[N], cur[N], q[N];

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
			if (d[j] == -1 && w[i] > 0)
			{
				d[j] = d[t] + 1;
				cur[j] = h[j];
				q[++tt] = j;
				if (j == n + m + 1)return true;
			}
		}
	}
	return false;
}

int find(int u, int limit)
{
	if (u == n + m + 1)return limit;
	int flow = 0;
	for (int i = cur[u]; ~i&&flow<limit; i = ne[i])
	{
		cur[u] = i;
		int j = e[i];
		if (d[j] == d[u] + 1 && w[i] > 0)
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
	cin >> m >> n;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= m; i++)
	{
		int num;
		cin >> num;
		tot += num;
		add(0, i, num), add(i, 0, 0);
	}
	for (int i = m+1; i <= n+m; i++)
	{
		int num;
		cin >> num;
		add(i, n + m + 1, num), add(n + m + 1, i, 0);
	}
	for (int i = 1; i <= m; i++)
		for (int j = m + 1; j <= n + m; j++)
			add(i, j, 1), add(j, i, 0);
	int ans = dinic();
	cout << (ans == tot) << endl;
	if (ans != tot)return 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = h[i]; ~j; j = ne[j])
		{
			if (!w[j])
				cout << e[j] - m << ' ';
		}
		cout << endl;
	}


	return 0;
}
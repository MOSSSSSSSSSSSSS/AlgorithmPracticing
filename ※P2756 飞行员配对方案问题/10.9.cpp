

//   二分图，最大流，n根号m复杂度


#include<bits/stdc++.h>
using namespace std;

const int N = 110, M = 10000,INF = 1e8;
int h[N], e[M], ne[M],w[M], idx;
int n, m;
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
	q[++tt] = 0,cur[0] = h[0],d[0] = 0;
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
		add(0, i, 1), add(i, 0, 0);   //  建图
	for (int i = m + 1; i <= n; i++)
		add(i, n + 1, 1),add(n + 1, i, 0);
	while(1)
	{
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1)break;
		add(a, b, 1), add(b, a, 0);
	}
	cout << dinic() << endl;
	for (int i = 0; i < idx; i += 2)
		if (e[i] >= m + 1 && e[i] <= n && !w[i])  // 输出匹配
			cout << e[i ^ 1] << ' ' << e[i] << endl;

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const int N = 1000005, M = 1000005,INF = 1e8;                                                                                                                                                                                                                 
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int d[N], cur[N], q[N], A[N];
int s = 0, t,S,T;
int tot;

inline void add(int a, int b, int c)
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
	while (~scanf("%d%d", &n, &m))
	{
		t = n + m + 1;
		S = n + m + 2;
		T = n + m + 3;
		memset(h, -1, sizeof h),idx = 0;
		memset(A, 0, sizeof A);
		tot = 0;
		for (int i = n + 1; i <= n + m; i++)
		{
			int g;
			cin >> g;
			add(i, t, INF - g), add(t, i, 0);
			A[i] -= g, A[t] += g;
		}
		for (int i = 1; i <= n; i++)
		{
			int c, d;
			cin >> c >> d;
			add(s, i, d), add(i, s, 0);
			for (int j = 1; j <= c; j++)
			{
				int t, l, r;
				cin >> t >> l >> r;
				t++;
				add(i, t + n, r - l), add(t + n, i, 0);
				A[i] -= l, A[t + n] += l;
			}
		}
		for (int i = s; i <= t; i++)
		{
			if (A[i] > 0)add(S, i, A[i]), add(i, S, 0), tot += A[i];
			else if (A[i] < 0)add(i, T, -A[i]), add(T, i, 0);
		}
		add(t, s, INF), add(s, t, 0);
		if (dinic() < tot) cout << -1 << endl<<endl;
		else
		{
			int res = w[idx - 1];
			S = s, T = t;
			w[idx - 2] = w[idx - 1] = 0;
			cout << res + dinic() << endl<<endl;
		}
	}
	return 0;
}
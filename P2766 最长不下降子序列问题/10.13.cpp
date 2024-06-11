

#include<bits/stdc++.h>
using namespace std;

const int N1 = 510,N2 = 1010,M = 251010,INF = 1e8;
int length, w[N1], f[N1],s;
int h[N2], e[M], ne[M], c[M], idx;
int d[N2], cur[N2], q[N2];
int S, T;

void add(int a, int b, int cc)
{
	c[idx] = cc;
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
			if (d[j] == -1 && c[i])
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
	while (bfs())while (flow = find(S, INF))ans += flow;
	return ans;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> length;
	T = 2 * length + 1;
	for (int i = 1; i <= length; i++)
	{
		cin >> w[i];
		f[i] = 1;
	}
	for (int i = 1; i <= length; i++)
		add(i, length + i, 1), add(length + i, i, 0);
	for (int i = 1; i <= length; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (w[j] <= w[i])
			{
				f[i] = max(f[i], f[j] + 1);
				
			}
		}
		for(int j = 1;j<i;j++)
			if(w[j]<=w[i]&&f[j]+1==f[i])
				add(j + length, i, 1), add(i, j + length, 0);
		if (f[i] == 1)add(S, i, 1), add(i, S, 0);
		s = max(s, f[i]);
	}
	cout << s << endl;
	for (int i = 1; i <= length; i++)
		if (f[i] == s) add(i + length, T, 1), add(T, length + i, 0);
	int res = dinic();
	cout << res << endl;
	for (int i = 0; i < idx; i+=2)
	{
		if (e[i] == 1 && e[i ^ 1] == S)c[i] = INF;
		else if (e[i] == length + 1 && e[i ^ 1] == 1)c[i] = INF;
		else if(e[i] == 2*length && e[i ^ 1] == length)c[i] = INF;
		else if (e[i^1] == 2 * length && e[i] == T)c[i] = INF;
	}
	if (length == 1)cout << 1;///////////////////////////////////////////////////////////////////////////////////////////////
	else cout << res + dinic();

	return 0;
}
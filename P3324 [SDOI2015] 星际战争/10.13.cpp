

#include<bits/stdc++.h>
using namespace std;

const int N = 110, M = 5210,INF = 1e8;
int h[N], e[M], ne[M], idx;
double w[M];
int n, m, S = 0, T;
int d[N], cur[N], q[N];
int laser[N],def[N];
bool ok[N][N];
int tot;
double l = 0, r = 5e6;

void add(int a, int b, double c)
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
		//cout << hh << ' ' << tt << endl;
		int t = q[hh++];
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if (d[j] == -1 && w[i]>0)
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
double find(int u, double limit)
{
	if (u == T)return limit;
	double flow = 0;//////////////////////////////////////////////////////////////
	for (int i = cur[u]; ~i&&flow<limit; i = ne[i])
	{
		cur[u] = i;
		int j = e[i];
		if (d[j] == d[u] + 1 && w[i])
		{
			double t = find(j,min(w[i], double(limit - flow)));
			if (t==0)d[j] = -1;
			w[i] -= t, w[i ^ 1] += t, flow += t;//////////////////////////
		}
	}
	return flow;/////////////////////////////////////////////////////////////////
}
double dinic()////////////////////////////////////////////////////////////////
{
	double ans = 0, flow;
	while (bfs())while (flow = find(S, INF))ans += flow;
	return ans;
}
bool check(double mid)
{
	memset(h, -1, sizeof h);/////////////////////////////////////////////////////////////////////////////////////////////////
	idx = 0;/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	for (int i = m + 1; i <= m + n; i++)
		add(i, T, def[i - m]), add(T, i, 0);
	for (int i = 1; i <= m; i++)
		add(S, i, laser[i] * mid), add(i, S, 0);
	for (int i = 1; i <= m; i++)
		for (int j = m + 1; j <= m + n; j++)
			if (ok[i][j - m])add(i, j, laser[i] * mid), add(j, i, 0);
	return (dinic() == tot);
}

int main()
{
	cin >> n >> m;
	T = n + m + 1;
	for (int i = m + 1; i <= m + n; i++)
	{
		cin >> def[i - m];
		tot += def[i-m];
	}
	for (int i = 1; i <= m; i++)
		cin >> laser[i];
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> ok[i][j];
	while (r - l > 1e-5)
	{
		double mid = (l + r) / 2.0;
		//cout << l << ' ' << r << ' ' << mid << endl;
		if (check(mid))r = mid;
		else l = mid;
	}
	printf("%.6lf", l);

	return 0;
}
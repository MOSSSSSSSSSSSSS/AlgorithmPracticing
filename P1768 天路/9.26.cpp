
#include<bits/stdc++.h>
using namespace std;

const int N = 7010, M = 20010, INF = 0x3f3f3f3f;
int n, m;
int h[N], e[M], ne[M], v[M], p[M], idx;
double w[M];
double dist[N];
bool st[N];
int cnt[N];
double l, r;
int q[N * 5], hh, tt = -1;

void add(int a, int b, int c, int d)
{
	v[idx] = c;
	p[idx] = d;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
bool check(double mid)
{
	for (int i = 0; i < idx; i++)
		w[i] = mid * p[i] - v[i];
	for (int i = 1; i <= n; i++)
		q[++tt] = i, st[i] = true, cnt[i] = 0;
	while (hh <= tt)
	{
		int t = q[tt--];
		st[t] = false;
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if (cnt[j] >= n)return true;
				if (!st[j])
				{
					q[++tt] = j;
					st[j] = true;
				}
			}
		}
	}
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		add(a, b, c, d);
		double e = (double)c / d;
	}
	l = 0, r = 200;
	while (r - l >= 1e-3)
	{
		double mid = (l + r) / 2.0;
		if (check(mid))l = mid;
		else r = mid;
	}
	if (!l)cout << -1;
	else printf("%.1lf", l);

	return 0;
}
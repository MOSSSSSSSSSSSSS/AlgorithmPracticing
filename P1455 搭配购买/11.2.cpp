

#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int p[N];
int f[N];
int cnt;
int cost[N], value[N];
int cost2[N], value2[N];
int n, m, w;

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin >> n >> m >> w;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 1; i <= n; i++)
		cin >> cost[i] >> value[i];
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		int fa = find(a), fb = find(b);
		if (fa != fb)
		{
			p[fa] = fb;
			cost[fb] += cost[fa];
			value[fb] += value[fa];
		}
	}
	for (int i = 1; i <= n; i++)
		if (p[i] == i)
		{
			cnt++;
			cost2[cnt] = cost[i];
			value2[cnt] = value[i];
		}
	for (int i = 1; i <= cnt; i++)
		for (int j = w; j >= cost2[i]; j--)
			f[j] = max(f[j], f[j - cost2[i]] + value2[i]);
	cout << f[w];

	return 0;
}


#include<bits/stdc++.h>
using namespace std;

const int N = 300010, M = 300010;
char node[N];
int n, m;
int h[N], e[M], ne[M], idx;
int din[N];
int q[N];
int f[N][26];
int ans;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
bool toposort()
{
	int hh = 0, tt = -1;
	for (int i = 1; i <= n; i++)
		if (!din[i])
			q[++tt] = i;
	while (hh<=tt)
	{
		int t = q[hh++];
		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			din[j]--;
			if (!din[j])q[++tt] = j;
			for (int i = 0; i < 26; i++)
			{
				if (i == node[j] - 'a')
					f[j][i] = max(f[j][i], f[t][i] + 1);
				else
					f[j][i] = max(f[j][i], f[t][i]);
			}
		}
	}
	return (tt == n - 1);
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> node[i],f[i][node[i]-'a'] = 1;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		din[y]++;
	}
	if (!toposort())
	{
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 26; j++)
			ans = max(ans, f[i][j]);
	cout << ans;

	return 0;
}
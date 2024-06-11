

#include<bits/stdc++.h>

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int n;
int f[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dfs(int u)
{
	int cnt = 0,m = 0;
	for (int i = h[u]; ~i; i = ne[i])
	{
		cnt++;
		int j = e[i];
		dfs(j);
		f[j]++;
		m = std::max(m, f[j]);
	}
	if (cnt != 0)
	{
		f[u] += (cnt - 1);
		f[u] += m;
	}
}

int main()
{
	memset(h, -1, sizeof h);
	std::cin >> n;
	for (int i = 2; i <= n; i++)
	{
		int x;
		std::cin >> x;
		add(x, i);
	}
	dfs(1);
	std::cout << f[1];

	return 0;
}
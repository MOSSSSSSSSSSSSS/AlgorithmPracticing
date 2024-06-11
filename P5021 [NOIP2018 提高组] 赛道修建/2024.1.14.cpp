
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10, M = 1e5 + 10;
int h[N], e[M], ne[M], w[M], idx;
int n, m;
int l, r;

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
int dfs(int u,int fa,int &mx,int mid)
{
	int ans = 0;
	multiset<int> ms;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j != fa)
		{
			int k = 0;
			ans += dfs(j, u, k, mid);
			k += w[i];
			if (k >= mid)ans++;
			else ms.insert(k);
		}
	}
	while (ms.size())
	{
		int a = *ms.begin();
		ms.erase(ms.begin());
		auto b = ms.lower_bound(mid - a);
		if (b != ms.end())ans++, ms.erase(b);
		else mx = max(mx, a);
	}
	return ans;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	l = 1, r = 5e8;
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		int mx = 0;
		if (dfs(1, 0, mx, mid) >= m)l = mid;
		else r = mid - 1;
	}
	cout << l;

	return 0;
}*/
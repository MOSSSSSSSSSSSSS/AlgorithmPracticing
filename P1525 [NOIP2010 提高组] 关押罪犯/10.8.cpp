

#include<bits/stdc++.h>
using namespace std;

const int N = 20010, M = 200010;
int n, m;
int h[N], e[M], ne[M],idx;
int color[N];
struct hen {
	int a, b, w;
}hens[M];

bool cmp(hen a, hen b)
{
	if (a.w > b.w)return true;
	else return false;
}
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
bool dfs(int u, int c,int mid)
{
	color[u] = c;
	for (int i = h[u]; ~i; i = ne[i])
	{
		if (i > 2 * mid - 1)continue;
		int j = e[i];
		if (!color[j])
		{
			if (!dfs(j, 3 - c, mid))
				return false;
		}
		else if (color[j] == c)
			return false;
	}
	return true;
}
bool check(int mid)
{
	for (int i = 1; i <= n; i++)
		if (!color[i])
			if (!dfs(i, 1, mid))
				return false;
	return true;
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= m; i++)
		cin >> hens[i].a >> hens[i].b >> hens[i].w;
	sort(hens + 1, hens + 1 + m, cmp);
	for (int i = 1; i <= m; i++)
	{
		add(hens[i].a, hens[i].b);
		add(hens[i].b, hens[i].a);
	}
	int l = 1, r = m;
	while (l < r)
	{
		int mid = l + r + 1>> 1;
		memset(color, 0, sizeof color);
		if (check(mid))l = mid;
		else r = mid - 1;
	}
	if (l == m)
		cout << 0;
	else cout << hens[l+1].w;

	return 0;
}
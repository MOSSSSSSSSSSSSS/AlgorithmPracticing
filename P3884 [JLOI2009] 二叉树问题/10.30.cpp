
#include<bits/stdc++.h>
using namespace std;

const int N = 110, M = 210;
int h[N], e[M], ne[M], idx;
int fa[N], dep[N], son[N], top[N], sz[N];
int n, x, y;
int mdep;
int d[N];
int ans;

void dfs1(int u, int father)
{
	fa[u] = father, dep[u] = dep[father] + 1;
	mdep = max(mdep, dep[u]);
	d[dep[u]]++;
	ans = max(ans, d[dep[u]]);
	sz[u] = 1;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j != father)
		{
			dfs1(j, u);
			sz[u] += sz[j];
			if (sz[j] > sz[son[u]])son[u] = j;
		}
	}
}
void dfs2(int u, int t)
{
	top[u] = t;
	if (!son[u])return;
	dfs2(son[u], t);
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j != son[u] && j != fa[u])
		{
			dfs2(j, j);
		}
	}
}
int lca(int u, int v)
{
	while (top[u] != top[v])
	{
		if (dep[top[u]] < dep[top[v]])swap(u, v);
		u = fa[top[u]];
	}
	return dep[u] < dep[v] ? u : v;
}
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	cin >> x >> y;
	cout << mdep << endl << ans << endl << (dep[x] - dep[lca(x, y)]) * 2 + dep[y] - dep[lca(x, y)];

	return 0;
}


#include<bits/stdc++.h>
using namespace std;

const int N = 500010,M = 1000010;
int n, m, s;
int h[N], e[M], ne[M], idx;
int dep[N], fa[N][20];

int lca(int a, int b)
{
	if (dep[a] < dep[b])swap(a, b);
	while (dep[a] > dep[b])
		a = fa[a][(int)log2(dep[a]-dep[b])];
	if (a == b)return a;
	for (int i = log2(dep[a]); ~i; i--)
		if (fa[a][i] != fa[b][i])
			a = fa[a][i], b = fa[b][i];
	return fa[a][0];
}

void dfs(int u, int father)
{
	dep[u] = dep[father] + 1;
	fa[u][0] = father;
	for (int i = 1; i <= log2(dep[u])+1; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (j != father)
			dfs(j, u);
	}
}

void add(int x, int y)
{
	e[idx] = y;
	ne[idx] = h[x];
	h[x] = idx++;
}

int main()
{
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)h[i] = -1;
	for (int i = 1; i <= n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y), add(y, x);
	}
	dfs(s, 0);
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << endl;
	}


	return 0;
}
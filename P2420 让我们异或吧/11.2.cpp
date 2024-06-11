


#include<bits/stdc++.h>
using namespace std;

const int N = 100010, M = 2 * N;
int h[N], e[M], ne[M], w[M], idx;
int n, m;
int res[N];

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dfs(int u, int father,int edge)
{
	if(u!=1)res[u] = res[father] ^ w[edge];
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j != father)
			dfs(j, u,i);
	}
}
int main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	dfs(1, 0, 0);
	cin >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		cout << (res[x] ^ res[y]) << endl;
	}

	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

const int N = 100010,M = 2*N;
int h[N], e[M], ne[M], w[M], idx;
int dep[N], fa[N], son[N], sz[N], top[N];
int n, m;

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dfs1(int u,int father)
{
	dep[u] = dep[father] + 1, fa[u] = father;
	sz[u] = 1;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j != father)
		{
			dfs1(j, u);
			sz[u] += sz[j];
			if (sz[son[u]] < sz[j])son[u] = j;
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
		if (j != fa[u] && j != son[u])
			dfs2(j, j);
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

int main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	cin >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;

	}

	return 0;
}*/
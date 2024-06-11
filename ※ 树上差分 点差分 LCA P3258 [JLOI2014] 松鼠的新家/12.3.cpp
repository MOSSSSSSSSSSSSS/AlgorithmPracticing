

// 树上差分有点差分和边差分，分别用来解决点权值的增加和边权值的增加
// 例如点差分 要把 u，v路径上的所有点点权加1，o是lca，p是o的父节点 v[u]+1,v[v]+1,v[o]-1,v[p]-1 ，dfs求结果
// 例如边差分 要把 u，v路径上的所有边边权加1，o是lca，p是o的父节点 v[u]+1,v[v]+1,v[o]-1*2 ，dfs求结果

#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
int n,a[N];
int h[N], e[N*2], ne[N*2], idx;
int v[N];
int dep[N], fa[N][20];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dfs1(int u,int father)
{
	dep[u] = dep[father] + 1;
	fa[u][0] = father;
	for (int i = 1; i < 20; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j != father)dfs1(j, u);
	}
}
int lca(int a, int b)
{
	if (dep[a] < dep[b])swap(a, b);
	for (int i = 19; i >= 0; i--)
		if (dep[fa[a][i]] >= dep[b])
			a = fa[a][i];
	if (a == b)return a;
	for (int i = 19; i >= 0; i--)
		if (fa[a][i] != fa[b][i])
			a = fa[a][i], b = fa[b][i];
	return fa[a][0];
}
void dfs2(int u, int father)
{
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j != father)
		{
			dfs2(j, u);
			v[u] += v[j];
		}
	}
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	dfs1(1, 0);
	for (int i = 1; i < n; i++)
	{
		int c = a[i], d = a[i + 1];
		int o = lca(c, d);
		int p = fa[o][0];
		v[c] += 1,v[d]+=1, v[o] -= 1, v[p] -= 1;
	}
	dfs2(1, 0);
	for (int i = 2; i <= n; i++)
		v[a[i]] -= 1;
	for (int i = 1; i <= n; i++)
		cout << v[i] << '\n';

	return 0;
}
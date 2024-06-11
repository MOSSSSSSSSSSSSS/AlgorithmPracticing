

//  线段树合并通常是 动态开点的权值线段树
//  m次操作，每次4个线段树，每个线段树logn个点，是数据范围
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m, ans[N];
vector<int> edge[N];
int dep[N], fa[N][20];//村落
int idx, root[N];
int st[N];
struct node 
{
	int ls, rs, mx, tp;
}tr[N<<6];
void dfs1(int u, int father)
{
	st[u] = true;
	dep[u] = dep[father] + 1;
	fa[u][0] = father;
	for (int i = 1; i < 20; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (auto v : edge[u])
		if (v != father&&!st[v])
			dfs1(v, u);
}
int lca(int u, int v)
{
	if (dep[u] < dep[v])swap(u, v);
	for (int i = 19; i >= 0; i--)
		if (dep[fa[u][i]] >= dep[v])
			u = fa[u][i];
	if (u == v)return u;
	for (int i = 19; i >= 0; i--)
		if (fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}

void pushup(int u)
{
	tr[u].mx = max(tr[tr[u].ls].mx, tr[tr[u].rs].mx);
	if (tr[tr[u].ls].mx >= tr[tr[u].rs].mx)tr[u].tp = tr[tr[u].ls].tp;
	else tr[u].tp = tr[tr[u].rs].tp;
}
void modify(int &u, int l, int r, int p, int d)
{
	if (!u)u = ++idx;
	if (l == r)
	{
		tr[u].mx += d;
		tr[u].tp = p;
		return;
	}
	int mid = l + r >> 1;
	if (p <= mid)modify(tr[u].ls, l, mid, p, d);
	else if (p >= mid + 1)modify(tr[u].rs, mid + 1, r, p, d);
	pushup(u);
}
int merge(int x,int y,int l,int r)
{
	if (!x || !y)return x + y;
	if (l == r) { tr[x].mx += tr[y].mx; return x; }
	int mid = l + r >> 1;
	tr[x].ls = merge(tr[x].ls, tr[y].ls, l, mid);
	tr[x].rs = merge(tr[x].rs, tr[y].rs, mid + 1, r);
	pushup(x);
	return x;
}
void dfs2(int u, int father)
{
	for (auto v : edge[u])
	{
		if (v != father)
		{
			dfs2(v, u);
			root[u] = merge(root[u], root[v], 1, N);
		}
	}
	ans[u] = (tr[root[u]].mx ? tr[root[u]].tp : 0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs1(1,0);
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		modify(root[x], 1, N, z, 1);
		modify(root[y], 1, N, z, 1);
		int t = lca(x, y);
		modify(root[t], 1, N, z, -1);
		modify(root[fa[t][0]], 1, N, z, -1);
	}
	dfs2(1, 0);
	for (int i = 1; i <= n; i++)cout << ans[i] << '\n';

	return 0;
}

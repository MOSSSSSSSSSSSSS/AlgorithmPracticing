

//想到记录了每个非叶子节点的子树大小(含它自己)，并且每个子树的新编号都是连续的,于是直接线段树区间查询即可

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls u<<1
#define rs u<<1|1
const int N = 1e5 + 10;

int n, m, root, p;
int w[N];
vector<int> edge[N];
int dep[N], fa[N], sz[N], son[N];
int top[N], id[N], nw[N], idx;
struct node {
	int l, r, add, sum;
}tr[4 * N];

void dfs1(int u, int father)
{
	dep[u] = dep[father] + 1, fa[u] = father, sz[u] = 1;
	for (auto v : edge[u])
	{
		if (v != father)
		{
			dfs1(v, u);
			sz[u] += sz[v];
			if (sz[v] > sz[son[u]])son[u] = v;
		}
	}
}
void dfs2(int u, int t)
{
	top[u] = t, id[u] = ++idx, nw[idx] = w[u];
	if (!son[u])return;
	dfs2(son[u], t);
	for (auto v : edge[u])
		if (v != fa[u] && v != son[u])
			dfs2(v, v);
}
void pushup(int u)
{
	tr[u].sum = tr[ls].sum + tr[rs].sum;
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r)
	{
		tr[u].sum = nw[l];
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(u);
}
void pushdown(int u)
{
	if (tr[u].add == 0)return;
	tr[ls].add += tr[u].add;
	tr[ls].sum += tr[u].add * (tr[ls].r - tr[ls].l + 1);
	tr[rs].add += tr[u].add;
	tr[rs].sum += tr[u].add * (tr[rs].r - tr[rs].l + 1);
	tr[u].add = 0;
}
void modify(int u, int l, int r, int z)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		tr[u].add += z;
		tr[u].sum += (tr[u].r - tr[u].l + 1) * z;
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(ls, l, r, z);
	if (r >= mid + 1)modify(rs, l, r, z);
	pushup(u);
}
void modify(int u, int v,int z)
{
	while (top[u] != top[v])
	{
		if (dep[top[u]] < dep[top[v]])swap(u, v);
		modify(1, id[top[u]], id[u], z);
		u = fa[top[u]];
	}
	if (dep[u] < dep[v])swap(u, v);
	modify(1, id[v], id[u], z);
}
int query(int u, int l, int r)
{
	int sum = 0;
	if (l <= tr[u].l && tr[u].r <= r)
	{
		return tr[u].sum;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)sum = (sum + query(ls, l, r))%p;
	if (r >= mid + 1)sum = (sum + query(rs, l, r))%p;
	return sum;
}
int query(int u, int v)
{
	int sum = 0;
	while (top[u] != top[v])
	{
		if (dep[top[u]] < dep[top[v]])swap(u, v);
		sum = (sum + query(1, id[top[u]], id[u]))%p;
		u = fa[top[u]];
	}
	if (dep[u] < dep[v])swap(u, v);
	sum = (sum + query(1, id[v], id[u]))%p;
	return sum;
}

signed main()
{
	cin >> n >> m >> root >> p;
	for (int i = 1; i <= n; i++)cin >> w[i];
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs1(root,0);
	dfs2(root,root);
	build(1, 1, n);
	while (m--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int x, y,z;
			cin >> x >> y>>z;
			modify(x, y,z);
		}
		else if (op == 2)
		{
			int x, y;
			cin >> x >> y;
			cout << query(x, y)%p << '\n';
		}
		else if (op == 3)
		{
			int x, z;
			cin >> x >> z;
			modify(1,id[x],id[x]+sz[x]-1,z);
		}
		else
		{
			int x;
			cin >> x;
			cout << query(1,id[x],id[x]+sz[x]-1)%p << '\n';           //  加的时候取模，输出  也要记得取模
		}
	}

	return 0;
}
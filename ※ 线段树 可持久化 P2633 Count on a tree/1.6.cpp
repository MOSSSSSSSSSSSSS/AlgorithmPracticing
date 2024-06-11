

//  静态区间第k小的树上版本，求树上两个节点间的第k小

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m, a[N], last;
int dep[N], fa[N][20];
int root[N], idx;
vector<int> edge[N],all;
struct node
{
	int ls, rs, sum;
}tr[N*20];

void modify(int& u, int v, int l, int r, int p)
{
	u = ++idx;
	tr[u] = tr[v], tr[u].sum++;
	if (l == r)return;
	int mid = l + r >> 1;
	if (p <= mid)modify(tr[u].ls, tr[v].ls, l, mid, p);
	else modify(tr[u].rs, tr[v].rs, mid + 1, r, p);
}
int get(int x)
{
	return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
}
void dfs(int u, int father)
{
	modify(root[u], root[father], 1, n, get(a[u]));
	fa[u][0] = father, dep[u] = dep[father] + 1;
	for (int i = 1; i < 20; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (auto v : edge[u])
		if (v != father)
			dfs(v, u);
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
int query(int u, int v, int f, int ff, int l, int r, int k)
{
	if (l == r)return l;
	int mid = l + r >> 1;
	int s = tr[tr[u].ls].sum + tr[tr[v].ls].sum - tr[tr[f].ls].sum - tr[tr[ff].ls].sum;
	if (s >= k)return query(tr[u].ls, tr[v].ls, tr[f].ls, tr[ff].ls, l, mid, k);
	else return query(tr[u].rs, tr[v].rs, tr[f].rs, tr[ff].rs, mid + 1, r, k - s);
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i],all.push_back(a[i]);
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());
	for (int i = 1; i <= n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs(1, 0);
	while (m--)
	{
		int u, v, k;
		cin >> u >> v >> k;
		u = u ^ last;
		int f = lca(u, v);
		int ff = fa[f][0];
		last = all[query(root[u], root[v], root[f], root[ff], 1, n, k) - 1];
		cout << last << '\n';
	}

	return 0;
}

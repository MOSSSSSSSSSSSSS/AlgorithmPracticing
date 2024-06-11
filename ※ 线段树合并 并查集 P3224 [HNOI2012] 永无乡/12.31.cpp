

//  注意 并查集，线段树合并的方向相同

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m, q;
int rk[N],fa[N],ver[N];
int root[N], idx;
struct node
{
	int ls, rs, sum;
}tr[N<<5];

void pushup(int u)
{
	tr[u].sum = tr[tr[u].ls].sum + tr[tr[u].rs].sum;
}
void build(int &u, int l, int r, int p)
{
	if (!u)u = ++idx;
	if (l == r && l == p)
	{
		tr[u].sum = 1;
		return;
	}
	int mid = l + r >> 1;
	if (p <= mid)build(tr[u].ls, l, mid, p);
	else if (p >= mid + 1)build(tr[u].rs, mid + 1, r, p);
	pushup(u);
}
int find(int x)
{
	if (fa[x] != x)fa[x] = find(fa[x]);
	return fa[x];
}
int merge(int x, int y, int l, int r)
{
	if (!x || !y)return x + y;
	if (l == r) { tr[x].sum += tr[y].sum; return x; }
	int mid = l + r >> 1;
	tr[x].ls = merge(tr[x].ls, tr[y].ls, l, mid);
	tr[x].rs = merge(tr[x].rs, tr[y].rs, mid + 1, r);
	pushup(x);
	return x;
}
int query(int u, int l, int r, int rkk)
{
	if (tr[u].sum < rkk)return -1;
	if (l == r)return l;
	int mid = l + r >> 1;
	if (tr[tr[u].ls].sum >= rkk)
	{
		return query(tr[u].ls, l, mid, rkk);
	}
	else
	{
		rkk -= tr[tr[u].ls].sum;
		return query(tr[u].rs, mid + 1, r, rkk);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> rk[i], fa[i] = i,ver[rk[i]] = i;
	for (int i = 1; i <= n; i++)
	{
		build(root[i], 1, N, rk[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		int aa = find(a), bb = find(b);
		if (aa != bb)
		{
			fa[aa] = bb;
			root[bb] = merge(root[bb], root[aa], 1, N);
		}
	}
	cin >> q;
	while (q--)
	{
		char op;
		int x, y;
		cin >> op >> x >> y;
		if (op == 'Q')
		{
			int xx = find(x);
			int res = query(root[xx], 1, N, y);
			if (res == -1)cout << -1 << '\n';
			else cout << ver[res] << '\n';
		}
		else
		{
			int xx = find(x), yy = find(y);
			if (xx != yy)
			{
				fa[xx] = yy;
				root[yy] = merge(root[yy], root[xx], 1, N);
			}
		}
	}

	return 0;
}
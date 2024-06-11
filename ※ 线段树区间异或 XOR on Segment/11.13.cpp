

//如果是区间和和区间加，修改时只需要修改懒标记和区间和的值，但是是区间和和区间异或，不能不改变区间中每个数就直接得出异或后的区间和
//因为区间和和区间异或修改不兼容，所以需要拆位线段树。


#include<bits/stdc++.h>
using namespace std;
#define ls u<<1
#define rs u<<1|1
#define int long long

const int N = 1e5 + 10;
int n, m;
int a[N];
int num[4 * N][20];
int tag[4 * N][20];
struct node {
	int l, r;
}tr[4*N];

void pushup(int u)
{
	for (int i = 0; i < 20; i++)
		num[u][i] = num[ls][i] + num[rs][i];
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r)
	{
		for (int i = 0; i < 20; i++)
			if (((a[l] >> i) & 1) == 1)
				num[u][i] = 1;
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(u);
}
void pushdown(int u)
{
	for (int i = 0; i < 20; i++)
	{
		if (!tag[u][i])continue;
		tag[ls][i] = 1 - tag[ls][i];
		tag[rs][i] = 1 - tag[rs][i];
		num[ls][i] = tr[ls].r - tr[ls].l + 1 - num[ls][i];
		num[rs][i] = tr[rs].r - tr[rs].l + 1 - num[rs][i];
		tag[u][i] = 0;
	}
}
void modify(int u, int l, int r, int x)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		for(int i = 0;i<20;i++)
		{
			if (((x >> i) & 1) == 1)
			{
				tag[u][i] = 1 - tag[u][i];
				num[u][i] = tr[u].r - tr[u].l + 1 - num[u][i];
			}
		}
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(ls,l,r,x);
	if (r >= mid + 1)modify(rs,l,r,x);   // 要修改的还是这个区间不要写成 l和mid
	pushup(u);
}
int query(int u, int l, int r)
{
	int res = 0;
	if (l <= tr[u].l && tr[u].r <= r)
	{
		for (int i = 0; i < 20; i++)
			res += num[u][i] * (1LL << i);
		return res;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)res += query(ls,l,r);
	if (r >= mid + 1)res += query(rs,l,r);
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	cin >> m;
	build(1, 1, n);
	for (int i = 1; i <= m; i++)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int l, r;
			cin >> l >> r;
			cout << query(1, l, r) << '\n';
		}
		else
		{
			int l, r, x;
			cin >> l >> r >> x;
			modify(1, l, r, x);
		}
	}

	return 0;
}
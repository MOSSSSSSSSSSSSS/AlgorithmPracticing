

//  区间开方不便用懒标记维护，而是暴力单点修改，维护一个mx区间最大值

#include<bits/stdc++.h>
using namespace std;
#define ls u<<1
#define rs u<<1|1
#define int long long
const int N = 1e5 + 10;
int n, a[N], m;
struct node {
	int l, r, sum, mx;
}tr[N<<2];

void pushup(int u)
{
	tr[u].sum = tr[ls].sum + tr[rs].sum;
	tr[u].mx = max(tr[ls].mx, tr[rs].mx);
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r)
	{
		tr[u].sum = tr[u].mx = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(u);
}
void modify(int u, int l, int r)
{
	if (tr[u].mx == 1)return;//////////////////////////////  否则TLE
	if (tr[u].l == tr[u].r)
	{
		tr[u].mx = sqrt(tr[u].mx);
		tr[u].sum = sqrt(tr[u].sum);
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(ls, l, r);
	if (r >= mid + 1)modify(rs, l, r);
	pushup(u);
}
int query(int u, int l, int r)
{
	int res = 0;
	if (l <= tr[u].l && tr[u].r <= r)
	{
		return tr[u].sum;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)res += query(ls, l, r);
	if (r >= mid + 1)res += query(rs, l, r);
	return res;
}

signed main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	cin >> m;
	while (m--)
	{
		int k, l, r;
		cin >> k >> l >> r;
		if (l > r)swap(l, r);
		if (k == 0)modify(1, l, r);
		else cout << query(1, l, r) << '\n';
	}

	return 0;
}
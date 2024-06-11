
#include<bits/stdc++.h>
using namespace std;
#define ls u<<1
#define rs u<<1|1
#define int long long
const int N = 1e5 + 10;
int n, a[N], m;
struct node {
	int l, r, sum, mx;
}tr[N << 2];

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
void modify1(int u, int l, int r,int x)
{
	if (tr[u].mx < x)return;//////////////////////////////  ·ñÔòTLE
	if (tr[u].l == tr[u].r)
	{
		tr[u].mx = tr[u].mx % x;
		tr[u].sum = tr[u].sum % x;
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify1(ls, l, r,x);
	if (r >= mid + 1)modify1(rs, l, r,x);
	pushup(u);
}
void modify2(int u, int p, int x)
{
	if (tr[u].l == tr[u].r && tr[u].l == p)
	{
		tr[u].mx = x;
		tr[u].sum = x;
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if (p <= mid)modify2(ls, p, x);
	else if(p>=mid+1)modify2(rs, p, x);
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	while (m--)
	{
		int k;
		cin >> k;
		if (k == 1)
		{
			int l, r;
			cin >> l >> r;
			cout << query(1, l, r) << '\n';
		}
		else if (k == 2)
		{
			int l, r, x;
			cin >> l >> r >> x;
			modify1(1, l, r, x);
		}
		else
		{
			int p, x;
			cin >> p >> x;
			modify2(1, p, x);
		}
	}

	return 0;
}
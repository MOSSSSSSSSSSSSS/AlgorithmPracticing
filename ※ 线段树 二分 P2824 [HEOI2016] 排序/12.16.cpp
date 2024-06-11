
#include<bits/stdc++.h>
using namespace std;
#define ls u<<1
#define rs u<<1|1
const int N = 1e5 + 10;
int l = 1, r = N;
int n, m, q;
int backup[N];
int a[N];
struct opt {
	int op, l, r;
}opts[N];
struct node {
	int l, r;
	int sum;   //  1
	int cover; // -1  0  1
}tr[N<<2];

void pushup(int u)
{
	tr[u].sum = tr[ls].sum + tr[rs].sum;
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r, tr[u].cover = -1;
	if (l == r)
	{
		tr[u].sum = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(u);
}
void pushdown(int u)
{
	if (tr[u].cover == -1)return;
	tr[ls].cover = tr[rs].cover = tr[u].cover;
	if (tr[u].cover == 0)tr[ls].sum = tr[rs].sum = 0;
	else tr[ls].sum = tr[ls].r - tr[ls].l + 1, tr[rs].sum = tr[rs].r - tr[rs].l + 1;
	tr[u].cover = -1;
}
void modify(int u, int l, int r, int op)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		tr[u].cover = op;
		if (op == 0)tr[u].sum = 0;
		else tr[u].sum = tr[u].r - tr[u].l + 1;
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(ls, l, r, op);
	if(r >= mid + 1)modify(rs, l, r, op);
	pushup(u);
}
int query(int u, int l, int r)
{
	int res = 0;
	if (l <= tr[u].l && tr[u].r <= r)
	{
		return tr[u].sum;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)res += query(ls, l, r);
	if (r >= mid + 1)res += query(rs, l, r);
	return res;
}
int ask(int u, int p)
{
	if (tr[u].l == tr[u].r && tr[u].l == p)return tr[u].sum;
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (p <= mid)return ask(ls, p);
	else if (p >= mid + 1)return ask(rs, p);
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> backup[i];
	for (int i = 1; i <= m; i++)
		cin >> opts[i].op >> opts[i].l >> opts[i].r;
	cin >> q;
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		for (int i = 1; i <= n; i++)
		{
			if (backup[i] >= mid)a[i] = 1;
			else a[i] = 0;
		}
		build(1, 1, n);
		for (int i = 1; i <= m; i++)
		{
			int op = opts[i].op,ll = opts[i].l,rr = opts[i].r;
			if (op == 0)
			{
				int cnt = query(1, ll, rr);
				modify(1, ll,rr - cnt, 0), modify(1,rr + 1 - cnt, rr, 1);
			}
			else
			{
				int cnt = query(1, ll, rr);
				modify(1, ll, cnt + ll - 1, 1), modify(1, cnt + ll, rr, 0);
			}
		}
		if (ask(1,q) == 1)l = mid;
		else r = mid - 1;
	}
	cout << l;

	return 0;
}
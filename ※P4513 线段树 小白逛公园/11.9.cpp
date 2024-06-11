

#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n, m;
int sc[N];
struct node {
	int l, r;
	int lmax, rmax;
	int mmax;
	int sum;
}tr[4*N];
void push_up(node &u,node a,node b)
{
	u.sum = a.sum + b.sum;
	u.lmax = max(a.lmax, a.sum + b.lmax);
	u.rmax = max(b.rmax,a.rmax + b.sum);
	u.mmax = max(a.rmax + b.lmax, max(a.mmax, b.mmax));
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r)
	{
		tr[u].lmax = tr[u].mmax = tr[u].rmax = tr[u].sum = sc[l];
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	push_up(tr[u],tr[u<<1],tr[u<<1|1]);
}
void modify(int u, int x, int d)
{
	if (tr[u].l == x && tr[u].r == x)
	{
		tr[u].lmax = tr[u].mmax = tr[u].rmax = tr[u].sum = d;
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if (x <= mid)modify(u << 1, x, d);
	else modify(u << 1 | 1, x, d);
	push_up(tr[u], tr[u << 1], tr[u << 1 | 1]);
}
node query(int u, int l, int r)
{
	if (l <= tr[u].l && tr[u].r <= r)return tr[u];
	int mid = tr[u].l + tr[u].r >> 1;
	if (r <= mid)return query(u << 1, l, r);
	else if (l>= mid + 1)return query(u << 1 | 1, l, r);
	else
	{
		node res;
		push_up(res, query(u << 1, l, r), query(u << 1 | 1, l, r));
		return res;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> sc[i];
	build(1, 1, n);
	while (m--)
	{
		int op, a, b;
		cin >> op >> a >> b;
		if (op == 1)
		{
			if (a > b)swap(a, b);
			cout << query(1, a, b).mmax<< endl;
		}
		else
		{
			modify(1, a, b);
		}
	}

	return 0;
}

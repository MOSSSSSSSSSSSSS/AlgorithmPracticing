
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int tr11[N], tr22[N];
int n, m;

int lowbit(int x)
{
	return x & (-x);
}
void add(int p, int d,int tr[])
{
	while (p < N)
	{
		tr[p] += d;
		p += lowbit(p);
	}
}
int sum(int p,int tr[])
{
	int res = 0;
	while (p)
	{
		res += tr[p];
		p -= lowbit(p);
	}
	return res;
}
int main()
{
	cin >> n >> m;
	while (m--)
	{
		int q, l, r;
		cin >> q >> l >> r;
		if (q == 1)
		{
			add(l, 1, tr11);
			add(r, 1, tr22);
		}
		else
		{
			int ans = sum(r, tr11) - sum(l-1, tr22);
			cout << ans << endl;
		}
	}

	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m;
struct node {
	int l, r, add, MAX;
}tr[4*N];

void pushup(int u)
{
	tr[u].MAX = max(tr[u << 1].MAX, tr[u << 1 | 1].MAX);
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r, tr[u].add = 0;
	if (l == r)
	{
		tr[u].MAX = 0;
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void pushdown(int u)
{
	tr[u << 1].MAX += tr[u].add;
	tr[u << 1].add += tr[u].add;
	tr[u << 1|1].MAX += tr[u].add;
	tr[u << 1|1].add += tr[u].add;
	tr[u].add = 0;
}
void modify(int u, int l, int r, int add)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		tr[u].MAX += add;
		tr[u].add += add;
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(u << 1, l, r, add);
	if(r >= mid + 1)modify(u << 1 | 1, l, r, add);
	pushup(u);
}
int query(int u, int l, int r)
{
	int ans = 0;
	if (l <= tr[u].l && tr[u].r <= r)
	{
		return tr[u].MAX;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)ans = max(ans,query(u << 1, l, r));
	if (r >= mid + 1)ans = max(ans,query(u << 1 | 1, l, r));
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	build(1, 1, n);
	while (m--)
	{
		int q, l, r;
		cin >> q >> l >> r;
		if (q == 1)
		{
			modify(1, l, r, 1);
		}
		else
		{
			cout << query(1, l, r) << endl;
		}
	}

	return 0;
}*/
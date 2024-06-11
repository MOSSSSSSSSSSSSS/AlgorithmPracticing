

//赋值>乘>加=开方   因此赋值会影响到加法标记，使之为0，加标记不影响赋值标记
// pushdown和modify中先处理赋值再处理加法（顺序不同好像也没事）
// 当按加标记影响赋值标记做时，顺序不同是没事的，已实验。
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10, INF = 1e9 + 1;
int n, q, a[N];
struct node {
	int l, r, add, tag, mx;
}tr[4 * N];

void pushup(int u)
{
	tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r, tr[u].add = 0, tr[u].tag = INF;
	if (l == r)
	{
		tr[u].mx = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void pushdown(int u)
{
	if (tr[u].tag != INF || tr[u].add != 0)
	{
		if (tr[u].tag != INF)
		{
			tr[u << 1].add = 0;
			tr[u << 1].tag = tr[u].tag;
			tr[u << 1].mx = tr[u].tag;
			tr[u << 1 | 1].add = 0;
			tr[u << 1 | 1].tag = tr[u].tag;
			tr[u << 1 | 1].mx = tr[u].tag;
		}
		if (tr[u].add != 0)
		{
				tr[u << 1].add += tr[u].add;
				tr[u << 1].mx += tr[u].add;
				tr[u << 1 | 1].add += tr[u].add;
				tr[u << 1 | 1].mx += tr[u].add;
		}
		tr[u].add = 0, tr[u].tag = INF;
	}
}
void modify(int u, int l, int r, int add, int tag)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		if (tag != INF)
		{
			tr[u].add = 0;
			tr[u].tag = tag;
			tr[u].mx = tag;
			return;
		}
		else
		{
			tr[u].add += add;
			tr[u].mx += add;
			return;
		}
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(u << 1, l, r, add, tag);
	if (r >= mid + 1)modify(u << 1 | 1, l, r, add, tag);
	pushup(u);
}
int query(int u, int l, int r)
{
	int ans = -LLONG_MAX;
	if (l <= tr[u].l && tr[u].r <= r)
	{
		return tr[u].mx;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)ans = max(ans, query(u << 1, l, r));
	if (r >= mid + 1)ans = max(ans, query(u << 1 | 1, l, r));
	return ans;
}

signed main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	for (int i = 1; i <= q; i++)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int l, r, x;
			cin >> l >> r >> x;
			modify(1, l, r, 0, x);
		}
		else if (op == 2)
		{
			int l, r, x;
			cin >> l >> r >> x;
			modify(1, l, r, x, INF);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			cout << query(1, l, r) << '\n';
		}
	}

	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10, INF = 1e9 + 1;
int n, q, a[N];
struct node {
	int l, r, add, tag, mx;
}tr[4 * N];

void pushup(int u)
{
	tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r, tr[u].add = 0, tr[u].tag = INF;
	if (l == r)
	{
		tr[u].mx = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void pushdown(int u)
{
	if (tr[u].tag != INF || tr[u].add != 0)
	{
		if (tr[u].tag != INF)
		{
			tr[u << 1].add = 0;
			tr[u << 1].tag = tr[u].tag;
			tr[u << 1].mx = tr[u].tag;
			tr[u << 1 | 1].add = 0;
			tr[u << 1 | 1].tag = tr[u].tag;
			tr[u << 1 | 1].mx = tr[u].tag;
		}
		if(tr[u].add!=0)
		{
			if (tr[u << 1].tag != INF)
			{
				tr[u << 1].tag += tr[u].add;/////////////////////////////////////////////////
				tr[u << 1].mx = tr[u << 1].tag;////////////////////////////////////////////////
			}
			else
			{
				tr[u << 1].add += tr[u].add;
				tr[u << 1].mx += tr[u].add;
			}
			if (tr[u << 1 | 1].tag != INF)
			{
				tr[u << 1 | 1].tag += tr[u].add;/////////////////////////////////////////////////
				tr[u << 1 | 1].mx = tr[u << 1 | 1].tag;////////////////////////////////////////////////
			}
			else
			{
				tr[u << 1 | 1].add += tr[u].add;
				tr[u << 1 | 1].mx += tr[u].add;
			}
		}
		tr[u].add = 0, tr[u].tag = INF;
	}
}
void modify(int u, int l, int r, int add, int tag)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		if (tag != INF)
		{
			tr[u].add = 0;
			tr[u].tag = tag;
			tr[u].mx = tag;
			return;
		}
		else
		{
			if (tr[u].tag != INF)/////////////////////////////////////////////////
			{
				tr[u].tag += add;/////////////////////////////////////////////////
				tr[u].mx = tr[u].tag;/////////////////////////////////////////////
			}
			else
			{
				tr[u].add += add;
				tr[u].mx += add;
			}
			return;
		}
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(u << 1, l, r, add, tag);
	if (r >= mid + 1)modify(u << 1 | 1, l, r, add, tag);
	pushup(u);
}
int query(int u, int l, int r)
{
	int ans = -LLONG_MAX;
	if (l <= tr[u].l && tr[u].r <= r)
	{
		return tr[u].mx;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)ans = max(ans, query(u << 1, l, r));
	if (r >= mid + 1)ans = max(ans, query(u << 1 | 1, l, r));
	return ans;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	for (int i = 1; i <= q; i++)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int l, r, x;
			cin >> l >> r >> x;
			modify(1, l, r, 0, x);
		}
		else if (op == 2)
		{
			int l, r, x;
			cin >> l >> r >> x;
			modify(1, l, r, x, INF);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			cout << query(1, l, r) << '\n';
		}
	}

	return 0;
}*/
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10,INF = 1e9+1;
int n, q,a[N];
struct node {
	int l, r, add, tag, mx;
}tr[4*N];

void pushup(int u)
{
	tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r, tr[u].add = 0, tr[u].tag = INF;
	if (l == r)
	{
		tr[u].mx = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void pushdown(int u)
{
	if (tr[u].tag != INF || tr[u].add != 0)
	{
		if (tr[u].tag == INF)
		{
			if (tr[u << 1].tag != INF)
			{
				tr[u<<1].tag += tr[u].add;/////////////////////////////////////////////////
				tr[u<<1].mx = tr[u<<1].tag;////////////////////////////////////////////////
			}
			else
			{
				tr[u << 1].add += tr[u].add;
				tr[u << 1].mx += tr[u].add;
			}
			if (tr[u << 1 | 1].tag != INF)
			{
				tr[u << 1|1].tag += tr[u].add;/////////////////////////////////////////////////
				tr[u << 1|1].mx = tr[u << 1|1].tag;////////////////////////////////////////////////
			}
			else
			{
				tr[u << 1 | 1].add += tr[u].add;
				tr[u << 1 | 1].mx += tr[u].add;
			}
		}
		else
		{
			tr[u << 1].add = 0;
			tr[u << 1].tag = tr[u].tag;
			tr[u << 1].mx = tr[u].tag;
			tr[u << 1 | 1].add = 0;
			tr[u << 1 | 1].tag = tr[u].tag;
			tr[u << 1 | 1].mx = tr[u].tag;
		}
		tr[u].add = 0,tr[u].tag = INF;
	}
}
void modify(int u, int l, int r, int add, int tag)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		if (tag == INF)
		{
			if (tr[u].tag != INF)/////////////////////////////////////////////////
			{
				tr[u].tag += add;/////////////////////////////////////////////////
				tr[u].mx = tr[u].tag;/////////////////////////////////////////////
			}
			else
			{
				tr[u].add += add;
				tr[u].mx += add;
			}
			return;
		}
		else
		{
			tr[u].add = 0;
			tr[u].tag = tag;
			tr[u].mx = tag;
			return;
		}
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(u << 1, l, r, add, tag);
	if (r >= mid + 1)modify(u << 1 | 1, l, r, add, tag);
	pushup(u);
}
int query(int u, int l, int r)
{
	int ans = -LLONG_MAX;
	if (l <= tr[u].l && tr[u].r <= r)
	{
		return tr[u].mx;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)ans = max(ans,query(u << 1, l, r));
	if (r >= mid + 1)ans = max(ans,query(u << 1 | 1, l, r));
	return ans;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	for (int i = 1; i <= q; i++)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int l, r, x;
			cin >> l >> r >> x;
			modify(1, l, r, 0, x);
		}
		else if (op == 2)
		{
			int l, r, x;
			cin >> l >> r >> x;
			modify(1, l, r, x, INF);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			cout << query(1, l, r) << '\n';
		}
	}

	return 0;
}*/
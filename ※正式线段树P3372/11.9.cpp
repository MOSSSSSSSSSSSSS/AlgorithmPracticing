
//  单点修改，求区间最大数
/*#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int m, D, now, last;
struct node {
	int l, r, v;
}tr[4 * N];


void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r)return;
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}
void push_up(int u)
{
	tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}
void modify(int u, int x, int k)
{
	if (tr[u].l == x && tr[u].r == x)
	{
		tr[u].v = k;
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if (x <= mid)modify(u << 1, x, k);
	else modify(u << 1 | 1, x, k);
	push_up(u);
}
int query(int u, int l, int r)
{
	int v = 0;
	if (l <= tr[u].l && tr[u].r <= r)
	{
		return tr[u].v;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)v = query(u << 1, l, r);
	if (r >= mid + 1)v = max(v, query(u << 1 | 1, l, r));
	return v;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> D;
	build(1, 1, m);
	while (m--)
	{
		char op;
		int x;
		cin >> op >> x;
		if (op == 'Q')
		{
			last = query(1, now - x + 1, now);
			cout << last << endl;
		}
		else
		{
			now++;
			x = ((long long)x + last) % D;
			modify(1, now, x);
		}
	}

	return 0;
}*/
//   区间修改 区间加一个数 ，求 区间和
/*#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
struct node {
	int l, r;LL sum, add;
}tr[N*4];
int n, m;
int a[N];

void pushup(int u)
{
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r)
	{
		tr[u].sum = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void pushdown(int u)
{
	tr[u << 1].add += tr[u].add;////////////////////////////////////////////////////////////
	tr[u << 1].sum += tr[u].add * (tr[u << 1].r - tr[u << 1].l + 1);////////////////////////////////////////////////////////////////////////////
	tr[u << 1|1].add += tr[u].add;///////////////////////////////////////////////////////////
	tr[u << 1|1].sum += tr[u].add * (tr[u << 1|1].r - tr[u << 1|1].l + 1);////////////////////////////////////////////////////////////////////
	tr[u].add = 0;
}
void modify(int u, int l, int r, int d)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		tr[u].sum += (LL)d * (tr[u].r - tr[u].l + 1);
		tr[u].add += d;////////////////////////////////////////////////////////////////////
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(u << 1, l, r, d);
	if(r>=mid+1)modify(u << 1|1, l, r, d);
	pushup(u);
}
LL query(int u, int l, int r)
{
	LL ans = 0;
	if (l <= tr[u].l && tr[u].r <= r)
		return tr[u].sum;
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)ans = query(u << 1, l, r);
	if (mid + 1 <= r)ans += query(u << 1 | 1, l, r);
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1,1,n);
	while (m--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int x, y, k;
			cin >> x >> y >> k;
			modify(1, x, y, k);
		}
		else
		{
			int x, y;
			cin >> x >> y;
			cout << query(1, x, y) << endl;
		}
	}

	return 0;
}*/

// 扫描线

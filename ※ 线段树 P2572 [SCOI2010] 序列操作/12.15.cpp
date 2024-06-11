


//  下标从0 开始！！，当看了好几遍代码都没找出错，一定要看看是不是审错题！！！！

/*
#include<bits/stdc++.h>
using namespace std;
#define ls u<<1
#define rs u<<1|1
const int N = 1e5 + 10;
int n, m;
int a[N];
struct node {
	int l, r, sum, mx, lmx, rmx, cover, rev;  // cover 覆盖 的优先级大于rev取反,rev要受cover影响
	int mx0, lmx0, rmx0;
}tr[4 * N];

void pushup(node& u, node a, node b)
{
	u.sum = a.sum + b.sum;
	u.mx = max(a.mx, max(b.mx, a.rmx + b.lmx));
	if (a.lmx == a.r - a.l + 1)u.lmx = a.lmx + b.lmx;
	else u.lmx = a.lmx;
	if (b.rmx == b.r - b.l + 1)u.rmx = b.rmx + a.rmx;
	else u.rmx = b.rmx;
	u.mx0 = max(a.mx0, max(b.mx0, a.rmx0 + b.lmx0));
	if (a.lmx0 == a.r - a.l + 1)u.lmx0 = a.lmx0 + b.lmx0;
	else u.lmx0 = a.lmx0;
	if (b.rmx0 == b.r - b.l + 1)u.rmx0 = b.rmx0 + a.rmx0;
	else u.rmx0 = b.rmx0;
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r, tr[u].cover = -1, tr[u].rev = 0;
	if (l == r)
	{
		if (a[l] == 1)tr[u].lmx = tr[u].rmx = tr[u].mx = tr[u].sum = 1, tr[u].lmx0 = tr[u].rmx0 = tr[u].mx0 = 0;
		else tr[u].lmx = tr[u].rmx = tr[u].mx = tr[u].sum = 0, tr[u].lmx0 = tr[u].rmx0 = tr[u].mx0 = 1;
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(tr[u], tr[ls], tr[rs]);
}
void pushdown(int u)
{
	if (tr[u].cover == -1 && tr[u].rev == 0)return;
	else
	{
		if (tr[u].cover != -1)
		{
			if (tr[u].cover == 0)
			{
				tr[ls].cover = tr[rs].cover = 0;
				tr[ls].rev = tr[rs].rev = 0;////////////////////
				tr[ls].sum = tr[rs].sum = 0;
				tr[ls].mx = tr[rs].mx = 0;
				tr[ls].mx0 = tr[ls].r - tr[ls].l + 1;
				tr[rs].mx0 = tr[rs].r - tr[rs].l + 1;
				tr[ls].lmx = tr[rs].lmx = 0;
				tr[ls].lmx0 = tr[ls].r - tr[ls].l + 1;
				tr[rs].lmx0 = tr[rs].r - tr[rs].l + 1;
				tr[ls].rmx = tr[rs].rmx = 0;
				tr[ls].rmx0 = tr[ls].r - tr[ls].l + 1;
				tr[rs].rmx0 = tr[rs].r - tr[rs].l + 1;
			}
			else if (tr[u].cover == 1)
			{
				tr[ls].cover = tr[rs].cover = 1;
				tr[ls].rev = tr[rs].rev = 0;/////////////////////
				tr[ls].sum = tr[ls].r - tr[ls].l + 1;
				tr[rs].sum = tr[rs].r - tr[rs].l + 1;
				tr[ls].mx = tr[ls].r - tr[ls].l + 1;
				tr[rs].mx = tr[rs].r - tr[rs].l + 1;
				tr[ls].mx0 = tr[rs].mx0 = 0;
				tr[ls].lmx = tr[ls].r - tr[ls].l + 1;
				tr[rs].lmx = tr[rs].r - tr[rs].l + 1;
				tr[ls].lmx0 = tr[rs].lmx0 = 0;
				tr[ls].rmx = tr[ls].r - tr[ls].l + 1;
				tr[rs].rmx = tr[rs].r - tr[rs].l + 1;
				tr[ls].rmx0 = tr[rs].rmx0 = 0;
			}
			tr[u].cover = -1;
		}
		if (tr[u].rev != 0)
		{
			tr[ls].rev = 1 - tr[ls].rev;
			tr[rs].rev = 1 - tr[rs].rev;
			/////////////////////////////////////////////////
			tr[ls].sum = tr[ls].r - tr[ls].l + 1 - tr[ls].sum;
			tr[rs].sum = tr[rs].r - tr[rs].l + 1 - tr[rs].sum;
			swap(tr[ls].mx, tr[ls].mx0), swap(tr[rs].mx, tr[rs].mx0);
			swap(tr[ls].lmx, tr[ls].lmx0), swap(tr[rs].lmx, tr[rs].lmx0);
			swap(tr[ls].rmx, tr[ls].rmx0), swap(tr[rs].rmx, tr[rs].rmx0);
			tr[u].rev = 0;
		}
	}
}
void modify(int u, int l, int r, int op)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		if (op == 0 || op == 1)
		{
			tr[u].cover = op;
			tr[u].rev = 0;
			if (op == 0)
			{
				tr[u].sum = 0;
				tr[u].mx = 0;
				tr[u].mx0 = tr[u].r - tr[u].l + 1;
				tr[u].lmx = 0;
				tr[u].lmx0 = tr[u].r - tr[u].l + 1;
				tr[u].rmx = 0;
				tr[u].rmx0 = tr[u].r - tr[u].l + 1;
			}
			else
			{
				tr[u].sum = tr[u].r - tr[u].l + 1;
				tr[u].mx = tr[u].r - tr[u].l + 1;
				tr[u].mx0 = 0;
				tr[u].lmx = tr[u].r - tr[u].l + 1;
				tr[u].lmx0 = 0;
				tr[u].rmx = tr[u].r - tr[u].l + 1;
				tr[u].rmx0 = 0;
			}
		}
		else
		{
			tr[u].rev = 1 - tr[u].rev;//////////////////////////////////////////
			tr[u].sum = tr[u].r - tr[u].l + 1 - tr[u].sum;
			swap(tr[u].mx, tr[u].mx0);
			swap(tr[u].lmx, tr[u].lmx0), swap(tr[u].rmx, tr[u].rmx0);
		}
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(ls, l, r, op);
	if (r >= mid + 1)modify(rs, l, r, op);
	pushup(tr[u], tr[ls], tr[rs]);
}
int query1(int u, int l, int r)
{
	int res = 0;
	if (l <= tr[u].l && tr[u].r <= r)
	{
		return tr[u].sum;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)res += query1(ls, l, r);
	if (r >= mid + 1)res += query1(rs, l, r);
	return res;
}
node query2(int u, int l, int r)
{
	if (l <= tr[u].l && tr[u].r <= r)return tr[u];
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (r <= mid)return query2(ls, l, r);
	else if (l >= mid + 1)return query2(rs, l, r);
	else
	{
		node res;
		pushup(res, query2(ls, l, r), query2(rs, l, r));
		return res;
	}
}

int main()
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
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0)
			modify(1, b + 1, c + 1, 0);
		else if (a == 1)
			modify(1, b + 1, c + 1, 1);
		else if (a == 2)
			modify(1, b + 1, c + 1, -1);
		else if (a == 3)
			cout << query1(1, b + 1, c + 1) << '\n';  //  有多少1
		else if (a == 4)
			cout << query2(1, b + 1, c + 1).mx << '\n';  //  最多有多少连续的1
	}

	return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
#define ls u<<1
#define rs u<<1|1
const int N = 1e5 + 10;
int n, m;
int a[N];
struct node {
	int l, r, sum, mx, lmx, rmx, cover,rev;  // cover 覆盖 的优先级大于rev取反,rev要受cover影响
	int mx0, lmx0, rmx0;
}tr[4*N];

void pushup(node &u,node a,node b)
{
	u.sum = a.sum + b.sum;
	u.mx = max(a.mx, max(b.mx, a.rmx + b.lmx));
	if (a.lmx == a.r - a.l + 1)u.lmx = a.lmx + b.lmx;
	else u.lmx = a.lmx;
	if (b.rmx == b.r - b.l + 1)u.rmx = b.rmx + a.rmx;
	else u.rmx = b.rmx;
	u.mx0 = max(a.mx0, max(b.mx0, a.rmx0 + b.lmx0));
	if (a.lmx0 == a.r - a.l + 1)u.lmx0 = a.lmx0 + b.lmx0;
	else u.lmx0 = a.lmx0;
	if (b.rmx0 == b.r - b.l + 1)u.rmx0= b.rmx0 + a.rmx0;
	else u.rmx0 = b.rmx0;
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r,tr[u].cover = -1,tr[u].rev = 0;
	if (l == r)
	{
		if (a[l] == 1)tr[u].lmx = tr[u].rmx = tr[u].mx = tr[u].sum = 1,tr[u].lmx0 = tr[u].rmx0 = tr[u].mx0 = 0;
		else tr[u].lmx = tr[u].rmx = tr[u].mx = tr[u].sum = 0, tr[u].lmx0 = tr[u].rmx0 = tr[u].mx0 = 1;
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(tr[u], tr[ls], tr[rs]);
}
void pushdown(int u)
{
	if (tr[u].cover == -1 && tr[u].rev == 0)return;
	else
	{
		if (tr[u].cover != -1)
		{
			if (tr[u].cover == 0)
			{
				tr[ls].cover = tr[rs].cover = 0;
				tr[ls].rev = tr[rs].rev = 0;////////////////////
				tr[ls].sum = tr[rs].sum = 0;
				tr[ls].mx = tr[rs].mx = 0;
				tr[ls].mx0 = tr[ls].r - tr[ls].l + 1;
				tr[rs].mx0 = tr[rs].r - tr[rs].l + 1;
				tr[ls].lmx = tr[rs].lmx = 0;
				tr[ls].lmx0 = tr[ls].r - tr[ls].l + 1;
				tr[rs].lmx0 = tr[rs].r - tr[rs].l + 1;
				tr[ls].rmx = tr[rs].rmx = 0;
				tr[ls].rmx0 = tr[ls].r - tr[ls].l + 1;
				tr[rs].rmx0 = tr[rs].r - tr[rs].l + 1;
			}
			else if (tr[u].cover == 1)
			{
				tr[ls].cover = tr[rs].cover = 1;
				tr[ls].rev = tr[rs].rev = 0;/////////////////////
				tr[ls].sum = tr[ls].r - tr[ls].l + 1;
				tr[rs].sum = tr[rs].r - tr[rs].l + 1;
				tr[ls].mx = tr[ls].r - tr[ls].l + 1;
				tr[rs].mx = tr[rs].r - tr[rs].l + 1;
				tr[ls].mx0 = tr[rs].mx0 = 0;
				tr[ls].lmx = tr[ls].r - tr[ls].l + 1;
				tr[rs].lmx = tr[rs].r - tr[rs].l + 1;
				tr[ls].lmx0 = tr[rs].lmx0 = 0;
				tr[ls].rmx = tr[ls].r - tr[ls].l + 1;
				tr[rs].rmx = tr[rs].r - tr[rs].l + 1;
				tr[ls].rmx0 = tr[rs].rmx0 = 0;
			}
			tr[u].cover = -1;
		}
		if (tr[u].rev != 0)
		{
			if (tr[ls].cover != -1)tr[ls].cover = 1 - tr[ls].cover;
			else tr[ls].rev = 1 - tr[ls].rev;
			if (tr[rs].cover != -1)tr[rs].cover = 1 - tr[rs].cover;
			else tr[rs].rev = 1 - tr[rs].rev;
			/////////////////////////////////////////////////
			tr[ls].sum = tr[ls].r - tr[ls].l + 1 - tr[ls].sum;
			tr[rs].sum = tr[rs].r - tr[rs].l + 1 - tr[rs].sum;
			swap(tr[ls].mx, tr[ls].mx0), swap(tr[rs].mx, tr[rs].mx0);
			swap(tr[ls].lmx, tr[ls].lmx0), swap(tr[rs].lmx, tr[rs].lmx0);
			swap(tr[ls].rmx, tr[ls].rmx0), swap(tr[rs].rmx, tr[rs].rmx0);
			tr[u].rev = 0;
		}
	}
}
void modify(int u, int l, int r, int op)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		if (op == 0 || op == 1)
		{
			tr[u].cover = op;
			tr[u].rev = 0;
			if (op == 0)
			{
				tr[u].sum = 0;
				tr[u].mx = 0;
				tr[u].mx0 = tr[u].r - tr[u].l + 1;
				tr[u].lmx = 0;
				tr[u].lmx0 = tr[u].r - tr[u].l + 1;
				tr[u].rmx = 0;
				tr[u].rmx0 = tr[u].r - tr[u].l + 1;
			}
			else
			{
				tr[u].sum = tr[u].r - tr[u].l + 1;
				tr[u].mx = tr[u].r - tr[u].l + 1;
				tr[u].mx0 = 0;
				tr[u].lmx = tr[u].r - tr[u].l + 1;
				tr[u].lmx0 = 0;
				tr[u].rmx = tr[u].r - tr[u].l + 1;
				tr[u].rmx0 = 0;
			}
		}
		else
		{
			if (tr[u].cover != -1)tr[u].cover = 1 - tr[u].cover;//////////////////////////////////////////////
			else tr[u].rev = 1 - tr[u].rev;//////////////////////////////////////////
			tr[u].sum = tr[u].r - tr[u].l + 1 - tr[u].sum;
			swap(tr[u].mx, tr[u].mx0);
			swap(tr[u].lmx, tr[u].lmx0), swap(tr[u].rmx, tr[u].rmx0);
		}
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(ls, l, r, op);
	if (r >= mid + 1)modify(rs, l, r, op);
	pushup(tr[u],tr[ls],tr[rs]);
}
int query1(int u, int l, int r)
{
	int res = 0;
	if (l <= tr[u].l && tr[u].r <= r)
	{
		return tr[u].sum;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)res += query1(ls, l, r);
	if (r >= mid + 1)res += query1(rs, l, r);
	return res;
}
node query2(int u, int l, int r)
{
	if (l <= tr[u].l && tr[u].r <= r)return tr[u];
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (r <= mid)return query2(ls, l, r);
	else if (l >= mid + 1)return query2(rs, l, r);
	else
	{
		node res;
		pushup(res, query2(ls, l, r), query2(rs, l, r));
		return res;
	}
}

int main()
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
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0)
			modify(1, b + 1, c + 1, 0);
		else if (a == 1)
			modify(1, b + 1, c + 1, 1);
		else if (a == 2)
			modify(1, b + 1, c + 1, -1);
		else if (a == 3)
			cout << query1(1, b + 1, c + 1) << '\n';  //  有多少1
		else if (a == 4)
			cout << query2(1, b + 1, c + 1).mx << '\n';  //  最多有多少连续的1
	}

	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ls u<<1
#define rs u<<1|1
const int N = 200010;
int n, m;
struct node {
	int l, r;
	int mx0, lmx0, rmx0, num0;
	int cover; // cover-1无标记，0区间赋值0，1区间赋值1
}tr[N<<2];

void pushup(node& u, node a, node b)
{
	u.mx0 = max(a.rmx0 + b.lmx0, max(a.mx0, b.mx0));
	u.num0 = a.num0 + b.num0;
	if (a.lmx0 == a.r - a.l + 1)u.lmx0 = a.lmx0 + b.lmx0;
	else u.lmx0 = a.lmx0;
	if (b.rmx0 == b.r - b.l + 1)u.rmx0 = b.rmx0 + a.rmx0;
	else u.rmx0 = b.rmx0;
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r, tr[u].cover = -1;
	if (l == r)
	{
		tr[u].lmx0 = tr[u].rmx0 = tr[u].mx0 = tr[u].num0 = 0;
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(tr[u], tr[ls], tr[rs]);
}
void pushdown(int u)
{
	if (tr[u].cover == -1)return;
	tr[ls].cover = tr[rs].cover = tr[u].cover;
	if (tr[u].cover == 0)
	{
		tr[ls].lmx0 = tr[ls].rmx0 = tr[ls].mx0 = tr[ls].num0 = tr[ls].r - tr[ls].l + 1;
		tr[rs].lmx0 = tr[rs].rmx0 = tr[rs].mx0 = tr[rs].num0 = tr[rs].r - tr[rs].l + 1;
	}
	else
	{
		tr[ls].lmx0 = tr[ls].rmx0 = tr[ls].mx0 = tr[ls].num0 = 0;
		tr[rs].lmx0 = tr[rs].rmx0 = tr[rs].mx0 = tr[rs].num0 = 0;
	}
	tr[u].cover = -1;
}
void modify(int u, int l, int r, int op)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		tr[u].cover = op;
		if (op == 0)tr[u].lmx0 = tr[u].rmx0 = tr[u].mx0 = tr[u].num0 = tr[u].r - tr[u].l + 1;
		else tr[u].lmx0 = tr[u].rmx0 = tr[u].mx0 = tr[u].num0 = 0;
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(ls, l, r, op);
	if (r >= mid + 1)modify(rs, l, r, op);
	pushup(tr[u], tr[ls], tr[rs]);
}
node query(int u, int l, int r)
{
	if (l <= tr[u].l && tr[u].r <= r)return tr[u];
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (r <= mid)return query(ls, l, r);
	else if (l >= mid + 1)return query(rs, l, r);
	else
	{
		node res;
		pushup(res, query(ls, l, r), query(rs, l, r));
		return res;
	}
}
int ask(int u, int l, int r)
{
	int res = 0;
	if (l <= tr[u].l && tr[u].r <= r)return tr[u].num0;
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid) res+= ask(ls, l, r);
	if (r >= mid + 1)res += ask(rs, l, r);
	return res;
}
bool check(int l1,int mid,int num1)
{
	if (ask(1, l1, mid) < num1)return false;
	else return true;
}
int main()
{
	cin >> n >> m;
	build(1, 1, n);/////////////////////////////////////////别忘build
	while (m--)
	{
		int op;
		cin >> op;
		if (op == 0)
		{
			int l, r;
			cin >> l >> r;
			modify(1, l, r, 0);
		}
		else if (op == 1)
		{
			int l0, r0, l1, r1;
			cin >> l0 >> r0 >> l1 >> r1;
			int num1 = r0 - l0 + 1 - ask(1, l0, r0);
			if (num1 == 0)continue;                        ///  边界情况，不加就30分
			modify(1, l0, r0, 0);
			if (ask(1, l1, r1) <= num1) // l0,r0 1的个数
				modify(1, l1, r1, 1);
			else
			{
				int l = l1, r = r1;
				while (l<r)
				{
					int mid = l + r >> 1;
					if (check(l1, mid, num1))r = mid;
					else l = mid + 1;
				}
				modify(1, l1, l, 1);
			}
		}
		else
		{
			int l, r;
			cin >> l >> r;
			cout << query(1, l, r).mx0 << '\n';
		}
	}

	return 0;
}
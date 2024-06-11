

//  递归前 pushdown，更新后 pushup
//  为什么要递归前pushdown？，以query为例，如果询问区间是当前区间的子区间，那么需要当前区间分裂递归子区间，目的是得到子区间的值加到答案中
//  只有先把懒标记pushdown，更新子区间维护的信息，再递归子区间，得到的才是正确的结果

//  无论先加后乘还是先乘后加，正确性都是对的，但先加后乘不容易更新懒标记，所以先乘后加


//区间赋值>区间乘>区间加=区间开方（优先级低的标记不会影响优先级高的，优先级高的会影响低的的标记，使懒标记发生变化）


#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100010;
int n, p, m;
int a[N];
struct node{
	int l, r;
	int sum, add, mul;
}tr[4*N];

void pushup(int u)
{
	tr[u].sum = ((LL)tr[u << 1].sum + tr[u << 1 | 1].sum) % p; 
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r, tr[u].add = 0, tr[u].mul = 1;
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
	tr[u << 1].sum = (((LL)tr[u << 1].sum * tr[u].mul) % p + (LL)tr[u].add * (tr[u << 1].r - tr[u << 1].l + 1) % p)%p;
	tr[u << 1].mul = (LL)tr[u << 1].mul * tr[u].mul % p;
	tr[u << 1].add = ((LL)tr[u << 1].add * tr[u].mul % p + tr[u].add) % p;
	tr[u << 1|1].sum = (((LL)tr[u << 1|1].sum * tr[u].mul) % p + (LL)tr[u].add * (tr[u << 1|1].r - tr[u << 1|1].l + 1) % p)%p;
	tr[u << 1|1].mul = (LL)tr[u << 1|1].mul * tr[u].mul % p;
	tr[u << 1|1].add = ((LL)tr[u << 1|1].add * tr[u].mul % p + tr[u].add) % p;
	tr[u].add = 0, tr[u].mul = 1;
}
void modify(int u, int l, int r, int add, int mul)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		tr[u].sum = ((LL)tr[u].sum * mul) % p + (LL)add * (tr[u].r - tr[u].l + 1) % p;//更新时，区间和先乘mul，再加add * (tr[u].r - tr[u].l + 1)
		tr[u].mul = (LL)tr[u].mul * mul % p;
		tr[u].add = ((LL)tr[u].add * mul % p + add) % p;  //  先乘后加是说乘的优先级高，加法受乘法影响，乘法不被加法影响 
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(u << 1, l, r, add, mul);
	if (r >= mid + 1)modify(u << 1 | 1, l, r, add, mul);
	pushup(u);
}
int query(int u, int l, int r)
{
	int ans = 0;
	if (l <= tr[u].l && tr[u].r <= r)
	{
		return tr[u].sum;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)ans = query(u << 1, l, r);
	if (r >= mid + 1)ans = (ans + query(u << 1 | 1, l, r))%p;
	return ans;
}

int main()
{
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	cin >> m;
	while (m--)
	{
		int op, t, g;
		cin >> op >> t >> g;
		if (op == 1)
		{
			int c;
			cin >> c;
			modify(1, t, g, 0, c);
		}
		else if (op == 2)
		{
			int c;
			cin >> c;
			modify(1, t, g, c, 1);
		}
		else
		{
			cout << query(1, t, g) << endl;
		}
	}

	return 0;
}
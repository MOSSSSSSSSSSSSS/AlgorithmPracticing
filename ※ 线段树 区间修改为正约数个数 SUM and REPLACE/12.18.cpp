

// 无论是区间开方，区间取模，区间修改为正约数的个数，这种不能用懒标记维护的只能暴力修改的问题，最后都有一个边界，
// 例如区间修改为正约数的个数，当区间mx<=2时，再怎么修改，区间不会改变，因此此时可以return，保证时间复杂度

// 线性筛求约数个数
/*
#include<bits/stdc++.h>
using namespace std;
#define ls u<<1
#define rs u<<1|1
#define int long long
const int N = 3e5 + 10, M = 1e6 + 5;
int n, a[N], m;
struct node {
	int l, r, sum, mx;
}tr[N << 2];
bool is_pri[M];
int f[M], d[M];
int pri[M], cnt;

void make_d() {
	d[1] = f[1] = 1;
	for (int i = 2; i <= M - 5; i++) {
		if (!is_pri[i]) {
			pri[++cnt] = i;
			f[i] = 1; d[i] = 2;
		}
		for (int j = 1; j <= cnt && i * pri[j] <= M - 5; j++) {
			is_pri[i * pri[j]] = 1;
			if (i % pri[j] == 0) {
				f[i * pri[j]] = f[i] + 1;
				d[i * pri[j]] = (d[i]) * (f[i * pri[j]] + 1) / (f[i] + 1);
				break;
			}
			f[i * pri[j]] = 1;
			d[i * pri[j]] = d[i] * d[pri[j]];
		}
	}
}
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
	if (tr[u].mx <= 2)return;//////////////////////////////  否则TLE
	if (tr[u].l == tr[u].r)
	{
		tr[u].sum = tr[u].mx = d[tr[u].mx];
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	make_d();
	while (m--)
	{
		int k, l, r;
		cin >> k >> l >> r;
		if (k == 1)
		{
			modify(1, l, r);
		}
		else
		{
			cout << query(1, l, r) << '\n';
		}
	}

	return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
#define ls u<<1
#define rs u<<1|1
#define int long long
const int N = 3e5 + 10,M = 1e6+10;
int n, a[N], m;
struct node {
	int l, r, sum, mx;
}tr[N << 2];
bool mark[M];
int num[M], d[M];
vector<int> prims;

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
	if (tr[u].mx <= 2)return;//////////////////////////////  否则TLE
	if (tr[u].l == tr[u].r)
	{
		tr[u].sum = tr[u].mx = d[tr[u].mx];
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	d[1] = 1,num[1] = 1;
	for (int i = 2; i <= M - 10; i++)  //  要减10，否则崩
	{
		if (!mark[i])
		{
			prims.push_back(i);
			d[i] = 2;
			num[i] = 1;
		}
		for (int j = 0;prims[j] <= ( M - 10 )/ i; j++)   //  要减10，否则崩
		{
			mark[i * prims[j]] = true;
			if (i%prims[j] == 0)
			{
				num[i * prims[j]] = num[i] + 1;
				d[i * prims[j]] = (d[i]) * (num[i * prims[j]] + 1) / (num[i] + 1);
				break;
			}
			d[i * prims[j]] = d[i] * d[prims[j]];
			num[i * prims[j]] = 1;
		}
	}
	while (m--)
	{
		int k,l,r;
		cin >> k >> l >> r;
		if (k == 1)
		{
			modify(1, l, r);
		}
		else
		{
			cout<<query(1,l,r)<<'\n';
		}
	}

	return 0;
}
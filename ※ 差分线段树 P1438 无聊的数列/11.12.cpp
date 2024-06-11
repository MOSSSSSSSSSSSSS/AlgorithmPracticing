
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1e5 + 10;
int n, m;
int sum[N], a[N];
struct node {
	int l, r;
	LL add, sum;
}tr[4*N];

void insert(int l, int r, int d)
{
	a[l] += d;
	a[r + 1] -= d;
}
void pushup(int u)
{
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r, tr[u].add = 0;
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
	tr[u << 1].sum += tr[u].add * (tr[u << 1].r - tr[u << 1].l + 1);
	tr[u << 1].add += tr[u].add;
	tr[u << 1|1].sum += tr[u].add * (tr[u << 1|1].r - tr[u << 1|1].l + 1);
	tr[u << 1|1].add += tr[u].add;
	tr[u].add = 0;
}
void modify(int u, int l, int r, int add)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		tr[u].sum += add * (tr[u].r - tr[u].l + 1);
		tr[u].add += add;
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(u << 1, l, r, add);
	if (r >= mid + 1)modify(u << 1 | 1, l, r, add);
	pushup(u);
}
LL query(int u, int l,int r)
{
	LL ans = 0;
	if (l<=tr[u].l&& tr[u].r<=r)return tr[u].sum;
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)ans = query(u << 1,l,r);
	if(r>=mid+1) ans += query(u << 1 | 1, l,r);
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> sum[i];
	for (int i = 1; i <= n; i++)
		insert(i, i, sum[i]);
	build(1, 1, n);
	while (m--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int l, r, k, d;
			cin >> l >> r >> k >> d;
			modify(1, l, l, k);
			if(l+1<=n)modify(1, l + 1, r, d);
			if(r+1<=n)modify(1, r + 1, r + 1, -(k + (r - l) * d));/////////////////////////////////////////////////////////////////////////////////////////////////////
		}
		else
		{
			int p;
			cin >> p;
			cout << query(1, 1,p) << endl;
		}
	}

	return 0;
}
*/
//P4231 三步必杀   线段树超空间：

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1e7 + 10;
int n, m;
struct node {
	int l, r;
	LL add, sum;
}tr[4 * N];
LL ans1,ans2;

void pushup(int u)
{
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r, tr[u].add = 0;
	if (l == r)
	{
		tr[u].sum = 0;
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void pushdown(int u)
{
	tr[u << 1].sum += tr[u].add * (tr[u << 1].r - tr[u << 1].l + 1);
	tr[u << 1].add += tr[u].add;
	tr[u << 1 | 1].sum += tr[u].add * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1);
	tr[u << 1 | 1].add += tr[u].add;
	tr[u].add = 0;
}
void modify(int u, int l, int r, int add)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		tr[u].sum += add * (tr[u].r - tr[u].l + 1);
		tr[u].add += add;
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(u << 1, l, r, add);
	if (r >= mid + 1)modify(u << 1 | 1, l, r, add);
	pushup(u);
}
LL query(int u, int l, int r)
{
	LL ans = 0;
	if (l <= tr[u].l && tr[u].r <= r)return tr[u].sum;
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)ans = query(u << 1, l, r);
	if (r >= mid + 1) ans += query(u << 1 | 1, l, r);
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
		int l, r, k, d;
		cin >> l >> r >> k >> d;
		modify(1, l, l, k);
		if (l + 1 <= n)modify(1, l + 1, r, (d-k)/(r-l));
		if (r + 1 <= n)modify(1, r + 1, r + 1, -d);/////////////////////////////////////////////////////////////////////////////////////////////////////
	}
	for (int i = 1; i <= n; i++)
	{
		LL res = query(1, 1, i);
		ans1 ^= res;
		ans2 = max(ans2, res);
	}
	cout << ans1 << ' ' << ans2;

	return 0;
}

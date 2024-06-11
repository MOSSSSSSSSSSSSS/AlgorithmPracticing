
#include<bits/stdc++.h>
using namespace std;
#define ls u<<1
#define rs u<<1|1
const int N = 1e6 + 10;
int n, m;
int a[N], last[N], ans[N];
struct q {
	int l, id;
};
vector<q> qs[N];
struct node {
	int l, r, sum;
}tr[N << 2];

void pushup(int u)
{
	tr[u].sum = tr[ls].sum + tr[rs].sum;
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r)
	{
		tr[u].sum = 1;
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(u);
}
void modify(int u, int p)
{
	if (tr[u].l == tr[u].r && tr[u].l == p) { tr[u].sum = 0; return; }
	int mid = tr[u].l + tr[u].r >> 1;
	if (p <= mid)modify(ls, p);
	else if (p >= mid + 1)modify(rs, p);
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int l, r;
		cin >> l >> r;
		qs[r].push_back({ l,i });
	}
	build(1, 1, n);
	for (int i = 1; i <= n; i++)
	{
		if (last[a[i]] != 0)modify(1, last[a[i]]);
		last[a[i]] = i;
		for (auto q : qs[i])ans[q.id] = query(1, q.l, i);
	}
	for (int i = 1; i <= m; i++)cout << ans[i] << '\n';

	return 0;
}

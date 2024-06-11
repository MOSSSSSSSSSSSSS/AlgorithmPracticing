

// 为尽可能满足更多奶牛 ，贪心策略 ：按 结束时间为第一关键词从小到大排序，开始时间为第二关键词从小到大

//  这是线段覆盖问题，但是是乘车，线段树维护的不是站点，是区间，所以是n-1，奶牛的结束站点也要减一

#include<bits/stdc++.h>
using namespace std;

const int N = 50010,M = 20010;
int k, n, c;
struct cow {
	int l, r, num;
}cows[N];
struct node {
	int l, r, mx, add;
}tr[4*M];
int ans;

bool cmp(cow a, cow b)
{
	if (a.r < b.r)return true;
	else if (a.r == b.r)
	{
		if (a.l < b.l)return true;
		else return false;
	}
	else return false;
}
void pushup(int u)
{
	tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r, tr[u].add = 0;
	if (l == r)
	{
		tr[u].mx = 0;
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void pushdown(int u)
{
	if (tr[u].add)
	{
		tr[u << 1].add += tr[u].add;
		tr[u << 1].mx += tr[u].add;
		tr[u << 1|1].add += tr[u].add;
		tr[u << 1|1].mx += tr[u].add;
		tr[u].add = 0;
	}
}
void modify(int u, int l, int r, int c)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		tr[u].mx += c;
		tr[u].add += c;
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(u << 1, l, r, c);
	if (r >= mid + 1)modify(u << 1 | 1, l, r, c);
	pushup(u);
}
int query(int u, int l, int r)
{
	int M = 0;
	if (l <= tr[u].l && tr[u].r <= r)
	{
		return tr[u].mx;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)M = max(M,query(u << 1, l, r));
	if (r >= mid + 1)M = max(M, query(u << 1|1, l, r));
	return M;
}

int main()
{
	cin >> k >> n >> c;
	for (int i = 1; i <= k; i++)
		cin >> cows[i].l >> cows[i].r >> cows[i].num;
	sort(cows + 1, cows + 1 + k, cmp);
	build(1, 1, n - 1);
	for (int i = 1; i <= k; i++)
	{
		int l = cows[i].l, r = cows[i].r - 1, num = cows[i].num;
		int res = query(1, l, r);
		if (res == c)continue;
		else if (c - res < num)
			modify(1, l, r, c - res),ans+=(c-res);
		else if (c - res >= num)
			modify(1, l, r, num),ans+=num;
	}
	cout << ans;

	return 0;
}
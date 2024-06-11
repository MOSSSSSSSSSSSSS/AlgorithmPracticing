
#include<bits/stdc++.h>
using namespace std;
#define ls u<<1
#define rs u<<1|1
const int N = 100010,INF = 1e9;
int n, s[N], a[N];
int ans[N],tot;
int ne[N], last[N];
struct node {
	int l, r, mn,p;     //  p 也要作为一个，当区间包含时直接返回，如果不作为一个，只能走到叶子节点，这样就T了
}tr[N<<2];

void pushup(int u)
{
	if (tr[ls].mn < tr[rs].mn)
	{
		tr[u].mn = tr[ls].mn;
		tr[u].p = tr[ls].p;
	}
	else if (tr[ls].mn > tr[rs].mn)
	{
		tr[u].mn = tr[rs].mn;
		tr[u].p = tr[rs].p;
	}
	else
	{
		tr[u].mn = tr[ls].mn;
		tr[u].p = tr[ls].p;
	}
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r)
	{
		tr[u].mn = a[l];
		tr[u].p = l;
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(u);
}
pair<int, int> query(int u, int l, int r)
{
	int mn = INF, p = INF;
	if (l <= tr[u].l && tr[u].r <= r)return{tr[u].mn,tr[u].p};   //  不要和动态开点弄混，是tr[u].l == tr[u].r 而不是 l == r,l和r是查询区间，是不变的   
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)
	{
		pair<int, int> res = query(ls, l, r);
		if (mn > res.first)
		{
			mn = res.first;
			p = res.second;
		}
		else if (mn == res.first)
		{
			p = min(p, res.second);
		}
	}
	if (r >= mid + 1)
	{
		pair<int, int> res = query(rs, l, r);
		if (mn > res.first)
		{
			mn = res.first;
			p = res.second;
		}
		else if (mn == res.first)
		{
			p = min(p, res.second);
		}
	}
	return {mn, p};
}
void modify(int u, int p)
{
	if (tr[u].l == tr[u].r)
	{
		tr[u].mn = INF;
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if (p <= mid)modify(ls, p);
	else modify(rs, p);
	pushup(u);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	int l = 1, r = n;
	for (register int i = 1; i <= n; i++)cin >> s[i];
	for (register int i = 1; i <= n; i++)cin >> a[i],tot+=a[i],ne[i] = i+1,last[i] = i-1;
	ans[n] = tot + s[n] * 2;
	build(1, 1, n);
	for (register int i = n - 1; i >= 1; i--)
	{
		pair<int, int> res = query(1, l, last[r]);
		int temp1 = ans[i + 1] - res.first;
		int p = res.second;
		int temp2 = ans[i + 1] - a[r] - 2 * s[r] + 2 * s[last[r]];
		if (temp1 < temp2)
		{
			ans[i] = temp2;
			int ss = r;
			r = last[r];
			ne[last[ss]] = ne[ss];
			last[ne[ss]] = last[ss];
		}
		else
		{
			ans[i] = temp1;
			modify(1, p);
			ne[last[p]] = ne[p];
			last[ne[p]] = last[p];
		}
	}
	for (register int i = 1; i <= n; i++)cout << ans[i] << '\n';

	return 0;
}

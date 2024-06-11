

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, m, last,a[N];
vector<int> all;
int root[N], idx;
struct node
{
	int ls, rs, sum;
}tr[N*22];

int get(int x)
{
	return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
}
void build(int& u, int l, int r)
{
	u = ++idx;
	if (l == r)return;
	int mid = l + r >> 1;
	build(tr[u].ls, l, mid), build(tr[u].rs, mid + 1, r);
}
void insert(int& u,int v, int l, int r, int p)
{
	u = ++idx;
	tr[u] = tr[v], tr[u].sum++;
	if (l == r)return;
	int mid = l + r >> 1;
	if (p <= mid)insert(tr[u].ls, tr[v].ls, l, mid, p);
	else insert(tr[u].rs, tr[v].rs, mid + 1, r, p);
}
int query(int x, int y, int l, int r, int k)
{
	if (l == r)return l;
	int s = tr[tr[x].ls].sum - tr[tr[y].ls].sum;
	int mid = l + r >> 1;
	if (s >= k)return query(tr[x].ls, tr[y].ls, l, mid, k);
	else return query(tr[x].rs, tr[y].rs, mid + 1, r, k - s);
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		all.push_back(x);
		a[i] = x;
	}
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());
	build(root[0], 1, n);
	for (int i = 1; i <= n; i++)insert(root[i], root[i - 1], 1, n, get(a[i]));
	for (int i = 1; i <= m; i++)
	{
		int l, r, k;
		cin >> l >> r >> k;
		cout << all[query(root[r], root[l - 1], 1, n, k) - 1] << '\n';
	}
	return 0;
}

// 动态开点

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n, m;
int a[N];
int cnt;
int root[N],idx;
struct node {
	int ls, rs, val;
}tr[25*N];

void build(int& u, int l, int r)
{
	u = ++idx;
	if (l == r)
	{
		tr[u].val = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(tr[u].ls, l, mid), build(tr[u].rs, mid + 1, r);
}
void modify(int& u, int v, int l, int r, int p, int x)
{
	u = ++idx;
	tr[u].ls = tr[v].ls, tr[u].rs = tr[v].rs, tr[u].val = tr[v].val;
	if (l == r)
	{
		tr[u].val = x;
		return;
	}
	int mid = l + r >> 1;
	if (p <= mid)modify(tr[u].ls, tr[v].ls, l, mid, p, x);
	else modify(tr[u].rs, tr[v].rs, mid + 1, r, p, x);
}
int query(int u, int l, int r, int p)
{
	if (l == r)
	{
		return tr[u].val;
	}
	int mid = l + r >> 1;
	if (p <= mid)return query(tr[u].ls, l, mid, p);
	else return query(tr[u].rs, mid + 1, r, p);
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];
	build(root[0],1,n);
	while (m--)
	{
		cnt++;
		int ver,op;
		cin >>ver>>op;
		if (op == 1)
		{
			int p, x;
			cin >> p >> x;
			modify(root[cnt], root[ver], 1, n, p, x);
		}
		else
		{
			root[cnt] = root[ver];////////////////////新建树\.
			int p;
			cin >> p;
			cout << query(root[ver], 1, n, p) << '\n';
		}
	}

	return 0;
}
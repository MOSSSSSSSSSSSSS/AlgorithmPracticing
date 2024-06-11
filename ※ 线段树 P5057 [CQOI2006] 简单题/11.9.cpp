#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
struct node {
	int l, r;
	bool tag;
	bool x;
}tr[4*N];
int n, m;

void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r)return;
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}
void push_down(int u)
{
	if (tr[u].tag)
	{
		tr[u << 1].tag ^= 1;
		tr[u << 1 | 1].tag ^= 1;
		tr[u].tag = 0;
	}
}
void modify(int u, int l, int r)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		tr[u].tag ^= 1;
		return; ///////////////////////////////////////////   记得return，否则死循环
	}
	push_down(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(u << 1, l, r);
	if (r >= mid + 1)modify(u << 1 | 1, l, r);
}
int query(int u, int x)
{
	if (tr[u].l == x && tr[u].r == x)
	{
		if (tr[u].tag)
			tr[u].x ^= 1,tr[u].tag = 0;
		return tr[u].x;
	}
	push_down(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (x <= mid)return query(u << 1, x);
	else return query(u << 1 | 1, x);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	build(1, 1, n);
	while (m--)
	{
		int t, l;
		cin >> t >> l;
		if (t == 1)
		{
			int r;
			cin >> r;
			modify(1, l, r);
		}
		else
		{
			cout << query(1, l) << endl;
		}
	}
	
	return 0;
}
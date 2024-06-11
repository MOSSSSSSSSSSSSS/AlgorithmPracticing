

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int m, D, now, last;
struct node {
	int l, r, v;
}tr[4*N];


void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r)return;
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}
void push_up(int u)
{
	tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}
void modify(int u, int x, int k)
{
	if (tr[u].l == x && tr[u].r == x)
	{
		tr[u].v = k;
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if (x <= mid)modify(u << 1, x, k);
	else modify(u << 1 | 1, x, k);
	push_up(u);
}
int query(int u, int l, int r)
{
	int v = 0;
	if (l <= tr[u].l && tr[u].r <= r)
	{
		return tr[u].v;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if(l<=mid)v = query(u << 1, l, r);
	if(r>=mid+1)v = max(v, query(u << 1 | 1, l, r));
	return v;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> D;
	build(1, 1, m);
	while (m--)
	{
		char op;
		int x;
		cin >> op >> x;
		if (op == 'Q')
		{
			last = query(1, now - x + 1, now);
			cout << last << endl;
		}
		else
		{
			now++;
			x = ((long long)x+last)%D;
			modify(1, now, x);
		}
	}

	return 0;
}
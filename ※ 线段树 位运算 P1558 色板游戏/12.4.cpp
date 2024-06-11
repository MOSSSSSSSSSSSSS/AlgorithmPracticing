

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10,M = 35;
int L, T, O;
struct node {
	int l, r;
	bitset<M> bs;
	int lz;
}tr[4*N];

void pushup(int u)
{
	tr[u].bs = tr[u << 1].bs | tr[u << 1 | 1].bs;
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r)
	{
		tr[u].bs[1] = 1;
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void pushdown(int u)
{
	if (tr[u].lz)
	{
		tr[u << 1].bs.reset();
		tr[u << 1].lz = tr[u].lz;
		tr[u << 1].bs[tr[u].lz] = 1;
		tr[u << 1|1].bs.reset();
		tr[u << 1|1].lz = tr[u].lz;
		tr[u << 1|1].bs[tr[u].lz] = 1;
		tr[u].lz = 0;
	}
}
void modify(int u, int l, int r,int C)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		tr[u].bs.reset();
		tr[u].lz = C;
		tr[u].bs[C] = 1;
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(u << 1, l,r,C);
	if (r >= mid + 1)modify(u << 1 | 1,l, r,C);
	pushup(u);
}
bitset<M> query(int u, int l, int r)
{
	bitset<M> bs;
	if (l <= tr[u].l && tr[u].r <= r)
	{
		return tr[u].bs;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)bs |= query(u << 1, l, r);
	if (r >= mid + 1)bs |= query(u << 1 | 1, l, r);
	return bs;
}

int main()
{
	cin >> L >> T >> O;
	build(1, 1, L);
	while (O--)
	{
		char op;
		cin >> op;
		if (op == 'C')
		{
			int a, b, c;
			cin >> a >> b >> c;
			if (a > b)swap(a, b);
			modify(1, a, b, c);
		}
		else
		{
			int a, b;
			cin >> a >> b;
			if (a > b)swap(a, b);
			bitset<M> bs = query(1, a, b);
			cout << bs.count() << '\n';
		}
	}

	return 0;
}


#include<bits/stdc++.h>
using namespace std;

const int N = 60010,INF = 1e9;
int c, s, r;
struct node {
	int l, r, m,add;
}tr[4*N];

void push_up(int u)
{
	tr[u].m = min(tr[u << 1].m, tr[u << 1 | 1].m);
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r)
	{
		tr[u].m = s;
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	push_up(u);
}
void push_down(int u)
{
	if (tr[u].add) //////////////////////////////////////////////////////////////////////////////    TLE 
	{
		tr[u << 1].add += tr[u].add;////////////////////////////////////////////////////
		tr[u << 1].m -= tr[u].add;/////////////////////////////////////////////////////
		tr[u << 1 | 1].add += tr[u].add;///////////////////////////////////////////////
		tr[u << 1 | 1].m -= tr[u].add;///////////////////////////////////////////////////
		tr[u].add = 0;//////////////////////////////////////////////////////////////////
	}
}
void modify(int u, int l, int r,int d)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		tr[u].m -= d;
		tr[u].add += d;
		return;
	}
	push_down(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(u << 1, l, r, d);
	if (r >= mid + 1)modify(u << 1 | 1, l, r, d);
	push_up(u);
}
int query(int u, int l, int r)
{
	int ans = INF;
	if (l <= tr[u].l && tr[u].r <= r)
	{
		return tr[u].m;
	}
	push_down(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)ans = query(u << 1, l, r);
	if (r >= mid + 1)ans = min(ans, query(u << 1 | 1, l, r));
	return ans;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> s >> r;
	build(1,1,c-1);
	while (r--)
	{
		int o, d, n;
		cin >> o >> d >> n;
		if (query(1, o, d-1) < n)
		{
			cout << "N" << endl;
		}
		else
		{
			cout << "T" << endl;
			modify(1, o, d-1, n);
		}
	}

	return 0;
}
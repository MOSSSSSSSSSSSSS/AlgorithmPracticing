#include<bits/stdc++.h>
using namespace std;
#define ls u<<1
#define rs u<<1|1
const int N = 1e5 + 10;
struct node {
	int l, r, sum;
	double mx;
}tr[N<<2];
int n, m;

int dfs(int u,double mx)
{
	if (tr[u].mx <= mx)return 0;///////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (tr[u].l == tr[u].r)return tr[u].mx > mx;///////////////////////////////////////////////////////////////////////////////////////////
	if (mx >= tr[ls].mx)return dfs(rs, mx);
	else return dfs(ls, mx) + tr[u].sum - tr[ls].sum;//////////////////////////////////////////////////////////////////////////////////////
}
void pushup(int u)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
{
	tr[u].mx = max(tr[ls].mx, tr[rs].mx);
	tr[u].sum = tr[ls].sum + dfs(rs, tr[ls].mx);
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r)
	{
		tr[u].mx = 0, tr[u].sum = 0;
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(u);
}
void modify(int u, int x, double y)
{
	if (tr[u].l == tr[u].r && tr[u].l == x)
	{
		tr[u].mx = y, tr[u].sum = 1;
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if (x <= mid)modify(ls, x, y);
	else if (x >= mid + 1)modify(rs, x, y);
	pushup(u);
}                                         

int main()
{
	cin >> n >> m;
	build(1, 1, n);
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		modify(1, x, (double)y/x);
		cout << tr[1].sum << '\n';                 
	}

	return 0;
}
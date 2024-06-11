

//  注意 口味 ci的值域不是小于n的，是到5e4的ci值域为[1, 5e4] 而非[1, n]

#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;
int root[N], idx;
int n, m, a[N];
struct node
{
	int ls, rs, sum;
}tr[N * 18];

void modify(int& u, int v, int l, int r, int p)
{
	u = ++idx;
	tr[u] = tr[v], tr[u].sum++;
	if (l == r)return;
	int mid = l + r >> 1;
	if (p <= mid)modify(tr[u].ls, tr[v].ls, l, mid, p);
	else modify(tr[u].rs, tr[v].rs, mid + 1, r, p);
}
int query(int u, int v, int l, int r, int len)
{
	if (l == r)return l;
	int mid = l + r >> 1;
	if (tr[tr[u].ls].sum - tr[tr[v].ls].sum > len)
		return query(tr[u].ls, tr[v].ls, l, mid, len);
	if(tr[tr[u].rs].sum - tr[tr[v].rs].sum > len)
		return query(tr[u].rs, tr[v].rs, mid+1, r, len);
	return 0;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i],modify(root[i],root[i-1],1,N,a[i]);
	while (m--)
	{
		int s, t;
		cin >> s >> t;
		cout << query(root[t], root[s - 1], 1, N, (t - s + 1) / 2) << '\n';    //  不是1，n，是大写N
	}

	return 0;
}

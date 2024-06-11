

//  ע�� ��ζ ci��ֵ����С��n�ģ��ǵ�5e4��ciֵ��Ϊ[1, 5e4] ����[1, n]

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
		cout << query(root[t], root[s - 1], 1, N, (t - s + 1) / 2) << '\n';    //  ����1��n���Ǵ�дN
	}

	return 0;
}

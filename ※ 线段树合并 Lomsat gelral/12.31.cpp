

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int n, w[N],ans[N];
int root[N], idx;
vector<int> edge[N];
struct node {
	int ls, rs, sum, mx; // mx������ɫ����sum������ɫ��ź�
}tr[N<<5];  //  ÿ����һ���߶�����ÿ����һ����ɫ������ÿ������logn����

void pushup(int u)
{
	if (tr[tr[u].ls].mx > tr[tr[u].rs].mx)
		tr[u].mx = tr[tr[u].ls].mx, tr[u].sum = tr[tr[u].ls].sum;
	else if(tr[tr[u].ls].mx < tr[tr[u].rs].mx)
		tr[u].mx = tr[tr[u].rs].mx, tr[u].sum = tr[tr[u].rs].sum;
	else 
		tr[u].mx = tr[tr[u].rs].mx, tr[u].sum = tr[tr[u].rs].sum + tr[tr[u].ls].sum;
}
void modify(int &u, int l, int r, int p, int d)   //  ע�������ã������¿���
{
	if (!u)u = ++idx;
	if (l == r && l == p)
	{
		tr[u].mx += d, tr[u].sum = p;
		return;
	}
	int mid = l + r >> 1;
	if (p <= mid)modify(tr[u].ls, l, mid, p, d);
	else if (p >= mid + 1)modify(tr[u].rs, mid + 1, r, p, d);
	pushup(u);    //  modify����Ҫ��pushup���ϸ���
}
int merge(int x, int y, int l, int r)
{
	if (!x || !y)return x + y;
	if (l == r) { tr[x].mx += tr[y].mx;return x; }
	int mid = l + r >> 1;
	tr[x].ls = merge(tr[x].ls, tr[y].ls, l, mid);
	tr[x].rs = merge(tr[x].rs, tr[y].rs, mid+1, r);
	pushup(x);
	return x;
}
void dfs(int u, int father)
{
	for (auto v : edge[u])
	{
		if (v != father)
		{
			dfs(v, u);
			root[u] = merge(root[u], root[v], 1, N);
		}
	}
	modify(root[u], 1, N, w[u], 1);
	ans[u] = tr[root[u]].sum;// ��ʱ���£���ֹ֮���ƻ���ȷ��
}

signed main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> w[i];
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)cout << ans[i] << ' ';

	return 0;
}
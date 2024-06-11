


//  还有一种题型：求某个区间，某种类珍珠的个数，是按珍珠种类作为版本编号，区间作为每个版本线段树的l和r。与这道题不同。
//  这道题是求一个区间中是否有一种珍珠个数大于一半，是按区间下标作为版本编号，种类权值作为线段树的l和r，维护sum，利用前缀和思想：r版本中1~2的数的个数减
//  l-1版本中1~2的个数等于 l到r区间中1~2的个数。


#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n, m, a[N];
int root[N], idx;
struct node
{
	int ls, rs, sum;
}tr[N*20];

void modify(int& u, int v,int l, int r, int p)
{
	u = ++idx;                                                            //  没有if(!U),必须新加节点，否则会进入之前版本的节点，然后改变之前版本的信息
	tr[u].ls = tr[v].ls, tr[u].rs = tr[v].rs, tr[u].sum = tr[v].sum + 1;
	if (l == r)return;
	int mid = l + r >> 1;
	if (p <= mid)modify(tr[u].ls,tr[v].ls, l, mid, p);
	else modify(tr[u].rs, tr[v].rs,mid + 1, r, p);
}
int query(int u, int v, int l, int r,int len)
{
	if (l == r)return l;
	int mid = l + r >> 1;
	if (tr[tr[u].ls].sum - tr[tr[v].ls].sum > len)
		return query(tr[u].ls, tr[v].ls, l, mid, len);
	if (tr[tr[u].rs].sum - tr[tr[v].rs].sum > len)
		return query(tr[u].rs, tr[v].rs, mid + 1, r, len);
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i], modify(root[i], root[i-1],1, n, a[i]);
	while (m--)
	{
		int l, r;
		cin >> l >> r;
		cout << query(root[r], root[l - 1], 1, n,(r-l+1)/2) << '\n';
	}

	return 0;
}



//  ����һ�����ͣ���ĳ�����䣬ĳ��������ĸ������ǰ�����������Ϊ�汾��ţ�������Ϊÿ���汾�߶�����l��r��������ⲻͬ��
//  ���������һ���������Ƿ���һ�������������һ�룬�ǰ������±���Ϊ�汾��ţ�����Ȩֵ��Ϊ�߶�����l��r��ά��sum������ǰ׺��˼�룺r�汾��1~2�����ĸ�����
//  l-1�汾��1~2�ĸ������� l��r������1~2�ĸ�����


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
	u = ++idx;                                                            //  û��if(!U),�����¼ӽڵ㣬��������֮ǰ�汾�Ľڵ㣬Ȼ��ı�֮ǰ�汾����Ϣ
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
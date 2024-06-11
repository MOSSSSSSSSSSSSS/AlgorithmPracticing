

//  �ݹ�ǰ pushdown�����º� pushup
//  ΪʲôҪ�ݹ�ǰpushdown������queryΪ�������ѯ�������ǵ�ǰ����������䣬��ô��Ҫ��ǰ������ѵݹ������䣬Ŀ���ǵõ��������ֵ�ӵ�����
//  ֻ���Ȱ������pushdown������������ά������Ϣ���ٵݹ������䣬�õ��Ĳ�����ȷ�Ľ��

//  �����ȼӺ�˻����ȳ˺�ӣ���ȷ�Զ��ǶԵģ����ȼӺ�˲����׸�������ǣ������ȳ˺��


//���丳ֵ>�����>�����=���俪�������ȼ��͵ı�ǲ���Ӱ�����ȼ��ߵģ����ȼ��ߵĻ�Ӱ��͵ĵı�ǣ�ʹ����Ƿ����仯��


#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100010;
int n, p, m;
int a[N];
struct node{
	int l, r;
	int sum, add, mul;
}tr[4*N];

void pushup(int u)
{
	tr[u].sum = ((LL)tr[u << 1].sum + tr[u << 1 | 1].sum) % p; 
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r, tr[u].add = 0, tr[u].mul = 1;
	if (l == r)
	{
		tr[u].sum = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void pushdown(int u)
{
	tr[u << 1].sum = (((LL)tr[u << 1].sum * tr[u].mul) % p + (LL)tr[u].add * (tr[u << 1].r - tr[u << 1].l + 1) % p)%p;
	tr[u << 1].mul = (LL)tr[u << 1].mul * tr[u].mul % p;
	tr[u << 1].add = ((LL)tr[u << 1].add * tr[u].mul % p + tr[u].add) % p;
	tr[u << 1|1].sum = (((LL)tr[u << 1|1].sum * tr[u].mul) % p + (LL)tr[u].add * (tr[u << 1|1].r - tr[u << 1|1].l + 1) % p)%p;
	tr[u << 1|1].mul = (LL)tr[u << 1|1].mul * tr[u].mul % p;
	tr[u << 1|1].add = ((LL)tr[u << 1|1].add * tr[u].mul % p + tr[u].add) % p;
	tr[u].add = 0, tr[u].mul = 1;
}
void modify(int u, int l, int r, int add, int mul)
{
	if (l <= tr[u].l && tr[u].r <= r)
	{
		tr[u].sum = ((LL)tr[u].sum * mul) % p + (LL)add * (tr[u].r - tr[u].l + 1) % p;//����ʱ��������ȳ�mul���ټ�add * (tr[u].r - tr[u].l + 1)
		tr[u].mul = (LL)tr[u].mul * mul % p;
		tr[u].add = ((LL)tr[u].add * mul % p + add) % p;  //  �ȳ˺����˵�˵����ȼ��ߣ��ӷ��ܳ˷�Ӱ�죬�˷������ӷ�Ӱ�� 
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(u << 1, l, r, add, mul);
	if (r >= mid + 1)modify(u << 1 | 1, l, r, add, mul);
	pushup(u);
}
int query(int u, int l, int r)
{
	int ans = 0;
	if (l <= tr[u].l && tr[u].r <= r)
	{
		return tr[u].sum;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)ans = query(u << 1, l, r);
	if (r >= mid + 1)ans = (ans + query(u << 1 | 1, l, r))%p;
	return ans;
}

int main()
{
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	cin >> m;
	while (m--)
	{
		int op, t, g;
		cin >> op >> t >> g;
		if (op == 1)
		{
			int c;
			cin >> c;
			modify(1, t, g, 0, c);
		}
		else if (op == 2)
		{
			int c;
			cin >> c;
			modify(1, t, g, c, 1);
		}
		else
		{
			cout << query(1, t, g) << endl;
		}
	}

	return 0;
}


// 想法一：模拟+高精，空间上不可行
// 想法二：逆元，一路取模，然而M不一定是质数，就算是还要判断是否存在整除
// 除了除法以外，其他无时无刻都取模，除法要有逆元转换成乘法才能随便取模
// 做法三：线段树我们以时间为轴，建立线段树，叶子结点维护该操作时间的乘数，非叶子结点维护
//区间乘，叶子结点一开始都为1然后每次乘，进行单点修改，将该次操作时间的位置修改为该乘数，最后输出
//tr[1]每次除的话，就将询问的操作位置的乘数改为1。最后输出tr[1]

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int t,q,mod;
struct node {
	int l, r, mul;
}tr[4*N];

void pushup(int u)
{
	tr[u].mul = (long long)tr[u << 1].mul * tr[u << 1 | 1].mul % mod;
}
void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r)
	{
		tr[u].mul = 1;
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void modify(int u, int p,int m) //乘m m若是0则变1
{
	if (tr[u].l == p && tr[u].r == p)
	{
		if (m == 0)
		{
			tr[u].mul = 1;
			return;
		}
		else
		{
			tr[u].mul = m;
			return;
		}
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if (p <= mid)modify(u << 1, p, m);
	else modify(u << 1 | 1, p, m);
	pushup(u);
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> q >> mod;
		build(1, 1, q);
		for (int i = 1; i <= q; i++)
		{
			int op;
			cin >> op;
			if (op == 1)
			{
				int m;
				cin >> m;
				modify(1, i, m);
				cout << tr[1].mul << '\n';
			}
			else
			{
				int p;
				cin >> p;
				modify(1, p, 0);
				cout << tr[1].mul << '\n';
			}
		}
	}

	return 0;
}
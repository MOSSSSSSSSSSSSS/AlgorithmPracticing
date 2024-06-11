

// �뷨һ��ģ��+�߾����ռ��ϲ�����
// �뷨������Ԫ��һ·ȡģ��Ȼ��M��һ���������������ǻ�Ҫ�ж��Ƿ��������
// ���˳������⣬������ʱ�޿̶�ȡģ������Ҫ����Ԫת���ɳ˷��������ȡģ
// ���������߶���������ʱ��Ϊ�ᣬ�����߶�����Ҷ�ӽ��ά���ò���ʱ��ĳ�������Ҷ�ӽ��ά��
//����ˣ�Ҷ�ӽ��һ��ʼ��Ϊ1Ȼ��ÿ�γˣ����е����޸ģ����ôβ���ʱ���λ���޸�Ϊ�ó�����������
//tr[1]ÿ�γ��Ļ����ͽ�ѯ�ʵĲ���λ�õĳ�����Ϊ1��������tr[1]

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
void modify(int u, int p,int m) //��m m����0���1
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
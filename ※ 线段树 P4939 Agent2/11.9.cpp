 


//   ����ӣ����� ѯ�ʣ�����ѯ��ҲҪ��һ��  sum �����
//   ���� 1e7 ��״���鿪 4e7 �Ͳ���������
//   ��״���� + ��֣�

#include<bits/stdc++.h>
using namespace std;

const int N = 1e7;
int cf[N],tr[N];
int n, m;

int lowbit(int x)
{
	return x & (-x);
}
void add(int x, int b)
{
	while (x < N)
	{
		tr[x] += b;
		x += lowbit(x);
	}
}
int sum(int p)
{
	int res = 0;
	while (p)
	{
		res += tr[p];
		p -= lowbit(p);
	}
	return res;
}

int main()
{
	cin >> n >> m;
	while (m--)
	{
		int op, a;
		cin >> op >> a;
		if (op == 0)
		{
			int b;
			cin >> b;
			add(a, 1), add(b + 1, -1);
		}
		else
		{
			cout << sum(a) << endl;
		}
	}

	return 0;
}
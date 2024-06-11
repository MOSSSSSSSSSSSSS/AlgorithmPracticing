


#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, m;
int a[N];
int tr[N];

int lowbit(int x)
{
	return x & (-x);
}
void modify(int p, int d)
{
	while (p < N)
	{
		tr[p] = max(tr[p], d);
		p += lowbit(p);
	}
}
int query(int l,int r)
{
	if (l < r)
	{
		if (l <= r - lowbit(r))return max(query(l, r - lowbit(r)), tr[r]);
		else return max(query(l, r - 1), a[r]);
	}
	return a[l];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		modify(i, a[i]);
	}
	while (m--)
	{
		char op;
		int c, b;
		cin >> op >> c >> b;
		if (op == 'Q')
		{
			cout << query(c, b) << '\n';
		}
		else
		{
			if (a[c] < b)
			{
				a[c] = b;
				modify(c, b);
			}
		}
	}

	return 0;
}
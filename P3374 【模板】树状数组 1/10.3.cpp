

#include<bits/stdc++.h>
using namespace std;

const int N = 500010;
int n, m;
int a[N];
int tr[N];

int lowbit(int x)
{
	return x & (-x);
}

int sum(int x)
{
	int res = 0;
	while (x)
	{
		res += tr[x];
		x -= lowbit(x);
	}
	return res;
}

void add(int x, int c)
{
	while (x <= n)
	{
		tr[x] += c;
		x += lowbit(x);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i],add(i,a[i]);
	for (int i = 1; i <= m; i++)
	{
		int flag, x,y;
		cin >> flag >> x>>y;
		if (flag == 1)
			add(x, y);
		else
		{
			cout << sum(y) - sum(x - 1) << endl;
		}
	}

	return 0;
}
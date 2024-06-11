

#include<bits/stdc++.h>
using namespace std;

const int N = 500010;
int n, m;
int sum[N];
int a[N];
int tr[N];

void insert(int l,int r,int c)
{
	a[l] += c;
	a[r + 1] -= c;
}

int lowbit(int x)
{
	return (x & -x);
}
void add(int x, int c)
{
	while (x <= n)
	{
		tr[x] += c;
		x += lowbit(x);
	}
}
int count(int x)
{
	int res = 0;
	while (x)
	{
		res += tr[x];
		x -= lowbit(x);
	}
	return res;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> sum[i];
	for (int i = 1; i <= n; i++)
		insert(i, i, sum[i]);
	for (int i = 1; i <= n; i++)
		add(i, a[i]);
	while (m--)
	{
		int flag, x;
		cin >> flag >> x;
		if (flag == 1)
		{
			int y, k;
			cin >> y >> k;
			add(x, k), add(y + 1, -k);
		}
		else
			cout << count(x) << endl;
	}

	return 0;
}


#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 100010;
int n, w;
int tr[N];

int lowbit(int x)
{
	return (x & -x);
}
void add(int a, int b)
{
	while (a <= n)
	{
		tr[a] += b;
		a += lowbit(a);
	}
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

signed main()
{
	cin >> n >> w;
	while (w--)
	{
		char flag;
		int a, b;
		cin >> flag >> a >> b;
		if (flag == 'x')
			add(a, b);
		else
			cout << sum(b) - sum(a - 1) << endl;
	}

	return 0;
}
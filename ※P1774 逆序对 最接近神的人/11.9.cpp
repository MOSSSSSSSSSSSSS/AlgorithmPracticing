

#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 10;
struct node {
	int v, order;
}a[N];
int b[N];
int n;
int tr[N];
int ans;

bool cmp(node a, node b)
{
	return a.v < b.v;
}
int lowbit(int x)
{
	return x & (-x);
}
void add(int x, int d)
{
	while (x < N)
	{
		tr[x] += d;
		x += lowbit(x);
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].v, a[i].order = i;
	sort(a + 1, a + 1 + n,cmp);
	for (int i = 1; i <= n; i++)
		b[a[i].order] = i;
	add(b[1], 1);
	for (int i = 2; i <= n; i++)
	{
		add(b[i], 1);
		ans += (i-sum(b[i]));
	}
	cout << ans;

	return 0;
}
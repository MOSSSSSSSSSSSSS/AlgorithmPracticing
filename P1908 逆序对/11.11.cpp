//stable_sort

#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int tr[N];
struct node {
	int v, order;
}a[N];
int b[N];
int n;
long long ans;

bool cmp(node a, node b)
{
	return a.v < b.v;
}
int lowbit(int p)
{
	return p & (-p);
}
void add(int p, int x)
{
	while (p < N)
	{
		tr[p] += x;
		p += lowbit(p);
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].v;
		a[i].order = i;
	}
	stable_sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i++)
	{
		b[a[i].order] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		add(b[i], 1);
		ans += i-sum(b[i]);
	}
	cout << ans;

	return 0;
}
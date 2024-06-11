

#include<bits/stdc++.h>
using namespace std;

const int N = 5000010,INF = 0x3f3f3f3f;
int n, p;
int sum[N],a[N],ans = INF;

void insert(int l, int r, int c)
{
	a[l] += c;
	a[r + 1] -= c;
}

int main()
{
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
		cin >> sum[i];
	for (int i = 1; i <= n; i++)
		insert(i, i, sum[i]);
	for (int i = 1; i <= p; i++)
	{
		int l, r, c;
		cin >> l >> r >> c;
		insert(l, r, c);
	}
	for (int i = 1; i <= n; i++)
	{
		a[i] = a[i - 1] + a[i];
		ans = min(ans, a[i]);
	}
	cout << ans;

	return 0;
}
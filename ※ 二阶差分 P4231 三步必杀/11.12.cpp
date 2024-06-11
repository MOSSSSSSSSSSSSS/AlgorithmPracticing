

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e7 + 10;
LL a[N];
LL b[N];
LL c[N];
int n, m;
LL ans1, ans2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n>>m;
	while (m--)
	{
		int l, r, s, e;
		cin >> l >> r >> s >> e;
		int d = (e - s) / (r - l);
		c[l] += s;
		if(l+1<=n)c[l + 1] += ( d - s);
		if (r + 1 <= n)c[r + 1] += (-e - d);
		if (r + 2 <= n)c[r + 2] += e;
	}
	for (int i = 1; i <= n; i++)
		b[i] = b[i - 1] + c[i];
	for (int i = 1; i <= n; i++)
	{
		a[i] = a[i - 1] + b[i];
		ans1 ^= a[i];
		ans2 = max(ans2, a[i]);
	}
	cout << ans1 << ' ' << ans2;

	return 0;
}
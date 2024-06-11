

#include<bits/stdc++.h>
using namespace std;

const int N = 1010,mod = 1e9+7;
int n, m;
int a[N];
int dp[N][N];

int main()
{
	cin >> n >> m;
	m = n - m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)dp[i][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (a[i] % a[j])continue;
			for (int k = 2;k<=m;k++)
			{
				dp[i][m] += dp[j][k - 1];
				dp[i][m] %= mod;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + dp[i][m]) % mod;
	cout << ans;

	return 0;
}
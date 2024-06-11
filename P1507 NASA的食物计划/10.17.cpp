

#include<bits/stdc++.h>
using namespace std;

const int N = 60, M = 410;
int dp[M][M];
int h, t, n;
struct food {
	int h, t, k;
}foods[N];

int main()
{
	cin >> h >> t >> n;
	for (int i = 1; i <= n; i++)
		cin >> foods[i].h >> foods[i].t >> foods[i].k;
	for (int i = 1; i <= n; i++)
		for (int j = h; j >= foods[i].h; j--)
			for (int k = t; k >= foods[i].t; k--)
				dp[j][k] = max(dp[j][k], dp[j - foods[i].h][k - foods[i].t] + foods[i].k);
	cout << dp[h][t];

	return 0;
}
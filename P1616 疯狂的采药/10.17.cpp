

#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e4 + 10, M = 1e7 + 10;
int num, t;
int dp[M];
struct cy {
	int t, v;
}cys[N];

signed main()
{
	cin >> t >> num;
	for (int i = 1; i <= num; i++)
		cin >> cys[i].t >> cys[i].v;
	for (int i = 1; i <= num; i++)
		for (int j = cys[i].t; j <= t; j++)
			dp[j] = max(dp[j], dp[j-cys[i].t] + cys[i].v);
	cout << dp[t];

	return 0;
}
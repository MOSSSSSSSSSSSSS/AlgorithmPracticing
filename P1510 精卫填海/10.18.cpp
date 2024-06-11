
#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int v, n, c;
struct shi {
	int v, c;
}shis[N];
int dp[N];

int main()
{
	cin >> v >> n >> c;
	for (int i = 1; i <= n; i++)
		cin >> shis[i].v >> shis[i].c;
	for (int i = 1; i <= n; i++)
		for (int j = c; j >= shis[i].c; j--)
			dp[j] = max(dp[j], dp[j - shis[i].c] + shis[i].v);
	if (dp[c] >= v)
	{
		int ans = 0;
		for (int i = 0; i <= v; i++)
			if (dp[i] >= v)
			{
				ans = i;
				break;
			}
		cout << c - ans;

	}
	else cout << "Impossible";

	return 0;
}
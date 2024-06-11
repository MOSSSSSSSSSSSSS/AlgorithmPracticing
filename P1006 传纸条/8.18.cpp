

#include<bits/stdc++.h>
using namespace std;

const int N = 60,INF = 0x3f3f3f3f;
int n, m, Map[N][N];
int dp[2 * N][N][N];

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> Map[i][j];
	for (int i = 1; i <= (m - 1) + (n - 1); i++)
	{
		for (int j = 0; j <= min(i, m - 1); j++)
		{
			for (int k = 0; k <= min(j, m - 1); k++)
			{
				if (j != k)
				{
					if(j>0&&k>0)
						dp[i][j][k] = max(dp[i - 1][j - 1][k], max(dp[i - 1][j][k - 1], max(dp[i - 1][j][k], dp[i - 1][j - 1][k - 1]))) + Map[1 + j][1 + i - j] + Map[1 + k][1 + i - k];
					else if(j>0)
						dp[i][j][k] = max(dp[i - 1][j - 1][k], dp[i - 1][j][k]) + Map[1 + j][1 + i - j] + Map[1 + k][1 + i - k];
					else if(k>0)
						dp[i][j][k] = max(dp[i - 1][j][k - 1],dp[i - 1][j][k]) + Map[1 + j][1 + i - j] + Map[1 + k][1 + i - k];
					else
						dp[i][j][k] = dp[i - 1][j][k] + Map[1 + j][1 + i - j] + Map[1 + k][1 + i - k];
				}
				else
					dp[i][j][k] = -INF;
			}
		}
	}

	cout << dp[(m - 1) + (n - 1)-1][m - 1][m - 2];

	return 0;
}
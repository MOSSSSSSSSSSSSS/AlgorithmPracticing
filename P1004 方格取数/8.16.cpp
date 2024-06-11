

//����̰���⣬���������߶�άDP����һ���������͵����ֵ
// f[i][j][k]�ǵ�һ��͵ڶ��鶼����i������һ������j�����ڶ�������k��,�洢�������ֵ
#include<bits/stdc++.h>
using namespace std;

const int N = 20, M = 10;
int dp[N][M][M];
int Map[M][M];
int n;

int main()
{
	cin >> n;
	while (1)
	{
		int i, j, num;
		cin >> i >> j >> num;
		if (i == 0 && j == 0 && num == 0)break;
		Map[i][j] = num;
	}
	dp[0][0][0] = Map[1][1];
	for (int i = 1; i <= 2*(n - 1); i++)
	{
		for (int j = 0; j <= min(i,n-1); j++)
		{
			for (int k = 0; k <= min(i, n - 1); k++)
			{
				if (j > 0 && k > 0)
				{
					dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i - 1][j - 1][k], max(dp[i - 1][j][k - 1], dp[i - 1][j - 1][k - 1])));
				}
				else if (j == 0 && k > 0)
				{
					dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j][k - 1]);
				}
				else if (k == 0 && j > 0)
				{
					dp[i][j][k] = max(dp[i - 1][j][k],dp[i - 1][j - 1][k]);
				}
				else
				{
					dp[i][j][k] = dp[i - 1][j][k];
				}
				dp[i][j][k] += (Map[1 + j][1 + i - j] + Map[1 + k][1 + i - k]);
				if (j == k)dp[i][j][k] -= Map[1 + j][1 + i - j];
			}
		}
	}

	cout << dp[(n - 1)*2][n - 1][n - 1];

	return 0;
}
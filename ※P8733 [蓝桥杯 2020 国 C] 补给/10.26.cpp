

#include<bits/stdc++.h>
using namespace std;

const int N = 25,M = 1050000,INF = 1e8;
typedef pair<int, int> PII;
double eps = 1e-8;
int n, D;
PII v[N];
double g[N][N];
double f[N][M];
double ans = INF;

void floyd()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}
int main()
{
	memset(f, 127, sizeof f);
	cin >> n>>D;
	for (int i = 1; i <= n; i++)
		cin >> v[i].first >> v[i].second;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			g[i][j] = sqrt((v[i].first - v[j].first) * (v[i].first - v[j].first) + (v[i].second - v[j].second) * (v[i].second - v[j].second));
			if (g[i][j] >= D + eps)g[i][j] = INF;
		}
	}
	floyd();
	f[1][1] = 0;
	for (int i = 3; i < 1 << n; i+=2)
	{
		for (int j = 2; j <= n; j++)
		{
			if ((i >> (j - 1)) & 1)
			{
				for (int k = 1; k <= n; k++)
				{
					if ((i >> (k - 1) & 1) && j != k)
					{
						f[j][i] = min(f[j][i], f[k][i-(1<<(j-1))] + g[k][j]);
					}
				}
			}
		}
	}
	for (int i = 2; i <= n; i++)
		ans = min(ans, f[i][(1 << n) - 1]+g[i][1]);
	//ans += 0.005;
	printf("%.2lf", ans);
	return 0;
}


//double    赋极大值是memset(,127,)


#include<bits/stdc++.h>
using namespace std;

const int N = 20,M = 32800;
double f[N][M];
int n;
double dist[N][N];               //   预处理，否则可能同一个值用多次，每次都去求，浪费时间
double x[N];
double y[N];
double ans = 127127127127127127127127.0;

double getDist(int i,int j)
{
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

int main()
{
	memset(f, 127, sizeof f);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = getDist(i,j);
	for (int i = 1; i <= n; i++)
		f[i][1 << (i - 1)] = sqrt(x[i] * x[i] + y[i] * y[i]);
	for (int i = 1; i < (1 << n); i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!((i >> (j - 1)) & 1))continue;
			for (int k = 1; k <= n; k++)
			{
				if (j != k && ((i >> (k - 1)) & 1))
				{
					f[j][i] = min(f[j][i], f[k][i - (1 << (j - 1))]+dist[j][k]);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
		ans = min(ans, f[i][(1<<n)-1]);
	printf("%.2lf", ans);

	return 0;
}

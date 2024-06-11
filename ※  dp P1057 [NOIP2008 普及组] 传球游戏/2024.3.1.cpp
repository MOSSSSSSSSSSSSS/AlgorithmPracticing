
#include<bits/stdc++.h>
using namespace std;

const int  N = 50;
int n, m;
int f[N][N];

int main()
{
	cin >> n >> m;
	f[2][1] = 1, f[n][1] = 1;
	for (int i = 2; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j == 1)f[j][i] = f[2][i - 1] + f[n][i - 1];
			else if (j == n)f[j][i] = f[n - 1][i - 1] + f[1][i - 1];
			else f[j][i] = f[j + 1][i - 1] + f[j - 1][i - 1];
		}
	}
	cout << f[1][m];

	return 0;
}
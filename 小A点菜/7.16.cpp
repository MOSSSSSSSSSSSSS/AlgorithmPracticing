//f[i][j] = f[i-1][j]+f[i-1][j-x]
#include<iostream>
using namespace std;

const int N = 110,M = 10010;

int n, m;
int a[N];
int f[N][M];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);

	for (int i = 0; i <= n; i++)f[i][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (j >= a[i])f[i][j] = f[i - 1][j] + f[i - 1][j - a[i]];
			else f[i][j] = f[i - 1][j];
		}
	}

	cout << f[n][m];

	return 0;
}
//**************************************************************************************
//¿Õ¼äÓÅ»¯
#include<iostream>
using namespace std;

const int N = 110, M = 10010;

int n, m;
int a[N];
int f[M];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);

	f[0] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = m; j >= a[i]; j--)
			f[j] = f[j] + f[j - a[i]];

	cout << f[m];

	return 0;
}
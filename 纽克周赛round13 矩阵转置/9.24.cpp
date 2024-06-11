

#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int n;
int a[N][N];
int temp[N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n / 2; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			temp[j] = a[n + 1 - i][j];
		}
		for (int j = 1; j <= n; j++)
		{
			a[n + 1 - i][j] = a[i][j];
		}
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = temp[j];
		}
	}
	for (int i = 1; i <= n / 2; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			temp[j] = a[j][n + 1 - i];
		}
		for (int j = 1; j <= n; j++)
		{
			a[j][n + 1 - i] = a[j][i];
		}
		for (int j = 1; j <= n; j++)
		{
			a[j][i] = temp[j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
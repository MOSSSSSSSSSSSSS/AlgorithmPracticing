
#include<bits/stdc++.h>
using namespace std;

const int N = 360,M = 50;
int n, m;
int score[N];
int a, b, c, d;
int f[M][M][M][M];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> score[i];
	for (int i = 1; i <= m; i++)
	{
		int x;
		cin >> x;
		if (x == 1)a++;
		else if (x == 2)b++;
		else if (x == 3)c++;
		else d++;
	}
	f[a][b][c][d] = score[1];
	for (int i = a; i >= 0; i--)
	{
		for (int j = b; j >= 0; j--)
		{
			for (int k = c; k >= 0; k--)
			{
				for (int l = d; l >= 0; l--)
				{
					if (i != a)f[i][j][k][l] = max(f[i][j][k][l], f[i + 1][j][k][l] + score[a - i + 2 * (b - j) + 3 * (c - k) + 4 * (d - l)+1]);
					if(j!=b)f[i][j][k][l] = max(f[i][j][k][l], f[i][j+1][k][l] + score[a - i + 2 * (b - j) + 3 * (c - k) + 4 * (d - l)+1]);
					if(k!=c)f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k+1][l] + score[a - i + 2 * (b - j) + 3 * (c - k) + 4 * (d - l)+1]);
					if(l!=d)f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k][l+1] + score[a - i + 2 * (b - j) + 3 * (c - k) + 4 * (d - l)+1]);
				}
			}
		}
	}
	cout << f[0][0][0][0];
	return 0;
}
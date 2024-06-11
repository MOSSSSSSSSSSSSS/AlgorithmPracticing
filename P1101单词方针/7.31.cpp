

#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int n;
char a[N][N];
int dx[8] = { -1,0,1,1,1,0,-1,-1 };
int dy[8] = { 1,1,1,0,-1,-1,-1,0 };
char str[7] = { 'y','i','z','h','o','n','g' };
bool b[N][N];

void dfs(int x, int y)
{
	if (a[x][y] != 'y')return;
	for (int i = 0,j = 1; i < 8; i++)
	{
		for (; j < 7; j++)
		{
			if (x + j * dx[i] >=1&& x + j * dx[i] <=n&& y + j * dy[i] >=1&& y + j * dy[i] <=n&&a[x + j*dx[i]][y + j*dy[i]] == str[j])continue;
			else break;
		}
		if (j == 7)
			for (int k = 0; k < 7; k++)
				b[x + k * dx[i]][y + k * dy[i]] = 1;
		j = 1;
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dfs(i, j);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (b[i][j])cout << a[i][j];
			else cout << '*';
		}
		cout << endl;
	}

	return 0;
}
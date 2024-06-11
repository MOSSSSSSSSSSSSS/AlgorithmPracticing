

#include<bits/stdc++.h>
using namespace std;

const int N = 10;
int a, b;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
bool st[N][N];
long long ans;

void dfs(int x, int y)
{
	st[x][y] = 1;
	if (x == 0 || x == a || y == 0 || y == b)
	{
		ans++;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!st[x + dx[i]][y + dy[i]])
		{
			dfs(x + dx[i], y + dy[i]);
			st[x + dx[i]][y + dy[i]] = 0;
		}
	}
}

int main()
{
	cin >> a >> b;
	for (int i = 1; i <= a - 1; i++)
	{
		st[i][0] = 1;
		dfs(i, 1);
		st[i][0] = 0, st[i][1] = 0;
	}
	for (int i = 1; i <= b - 1; i++)
	{
		st[0][i] = 1;
		dfs(1, i);
		st[0][i] = 0, st[1][i] = 0;
	}
	cout << ans;

	return 0;
}


#include<bits/stdc++.h>
using namespace std;

const int N = 110,mod = 1000007;
int n, m, a[N];
int backup[N][N];

int dfs(int x, int cnt)
{
	if (cnt > m)return backup[x][cnt] = 0;
	else if (cnt == m)return backup[x][cnt] = 1;
	else if (x == n + 1)return backup[x][cnt] = 0;
	else if (backup[x][cnt])return backup[x][cnt];//////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i <= a[x]; i++)
	{
		backup[x][cnt] = ( dfs(x+1,cnt+i) + backup[x][cnt]) % mod;
	}
	return backup[x][cnt];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];
	cout << dfs(1, 0);

	return 0;
}
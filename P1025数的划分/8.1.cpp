

#include<bits/stdc++.h>
using namespace std;

const int N = 7;
int n, k,cnt;
int path[N];
long long ans;

void dfs(int n)
{
	if (cnt == k - 1 && n >= path[cnt])
	{
		ans++;
		return;
	}

	for (int i = path[cnt]; i < n; i++)
	{
		if (i<=(n-i)/(k-cnt-1))
		{
			path[++cnt] = i;
			dfs(n - i);
			path[cnt--] = 0;
		}
	}
}

int main()
{
	cin >> n >> k;
	path[0] = 1;
	dfs(n);
	cout << ans;

	return 0;
}
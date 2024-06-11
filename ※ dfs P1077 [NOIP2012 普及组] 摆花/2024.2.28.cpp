
#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int n, m;
int a[N];
int cnt;

void dfs(int num) 
{
	if (num >= m)
	{
		cnt++;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		num += a[i];
		dfs(num);
		num--;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];
	dfs(0);
	cout << cnt;

	return 0;
}
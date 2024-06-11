

#include<bits/stdc++.h>
using namespace std;

const int N = 110,INF = 0x3f3f3f3f;
int n;
int a[N], sum[N],ans = INF;
bool record[N];

void dfs(int num,int cnt,int now)
{
	if (cnt == num)
	{
		int MAX = 0, MIN = INF,LAST = 0;
		for (int i = 1; i <= n; i++)
		{
			if (record[i] == 1)
			{
				MAX = max(MAX, sum[i] - sum[LAST]);
				MIN = min(MIN, sum[i] - sum[LAST]);
				LAST = i;
			}
		}
		MAX = max(MAX, sum[n] - sum[LAST]);
		MIN = min(MIN, sum[n] - sum[LAST]);
		ans = min(ans, MAX - MIN);
		return;
	}


	for (int i = 1+now; i < n; i++)
	{
		record[i] = 1;
		cnt++;
		dfs(num, cnt, i);
		cnt--;
		record[i] = 0;
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i-1] + a[i];
	for (int i = 2; i <= n; i++)   //  划分几个区间
	{
		dfs(i, 1,0);
	}
	cout << ans;

	return 0;
}
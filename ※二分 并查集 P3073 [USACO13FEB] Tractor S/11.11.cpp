
// 汽车拉力比赛

#include<bits/stdc++.h>
using namespace std;

const int N = 510;
int l = 0, r = 1000000;
int p[N*N];
int n;
int h[N][N];
int num[N * N];

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}
bool check(int mid)
{
	memset(num, 0, sizeof num);
	int ans = 0;
	for (int i = 1; i <= n * n; i++) // 编号从1到n方  i 记得 - 1 从0开始
		p[i] = i;
	for(int i = 1;i<=n;i++)
		for (int j = 1; j <= n; j++)
		{
			if (j + 1 <= n && abs(h[i][j + 1] - h[i][j]) <= mid)
			{
				int fa = find((i-1) * n + j);
				int fb = find((i -1)* n + j + 1);
				if(fa!=fb)p[fa] = fb;
			}
			if (i + 1 <= n && abs(h[i+1][j] - h[i][j]) <= mid)
			{
				int fa = find((i-1) * n + j);
				int fb = find(i* n + j);
				if (fa != fb)p[fa] = fb;
			}
		}
	for (int i = 1; i <= n * n; i++)
	{
		int f = find(i);
		num[f]++;
		ans = max(ans, num[f]);
	}
	return ans * 2 >= n * n;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> h[i][j];
	while (l < r)
	{
		int mid = l + r>> 1;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	cout << l;

	return 0;
}
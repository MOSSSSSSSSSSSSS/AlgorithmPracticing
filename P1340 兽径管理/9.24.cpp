
#include<bits/stdc++.h>
using namespace std;
const int N = 210,M = 6010;
int p[N];
int n, w;
int ans[M];
struct edge {
	int a, b, w,week;
}edges[M];
bool vis[M];
int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}
bool cmp(edge a, edge b)
{
	if (a.w < b.w)return true;
	else return false;
}
int main()
{
	cin >> n >> w;
	for (int i = 1; i <= w; i++)
	{
		cin >> edges[i].a >> edges[i].b >> edges[i].w;
		edges[i].week = i;
	}
	sort(edges + 1, edges + 1 + w,cmp);
	while (!ans[1])
	{
		for (int i = 1; i <= n; i++)
			p[i] = i;
		int tot = 0, cnt = 0, Max = 0;
		for (int i = 1; i <= w; i++)
		{
			if (!vis[edges[i].week])
			{
				int a = find(edges[i].a), b = find(edges[i].b), w = edges[i].w, week = edges[i].week;
				if (a != b)
				{
					p[a] = b;
					tot += w;
					cnt++;
					Max = max(Max, week);
				}
				if (cnt == n - 1)break;
			}
		}
		if (cnt == n - 1)
		{
			for (int i = Max; i <= w; i++)
				if (!ans[i])
					ans[i] = tot, vis[i] = true;
		}
		else
		{
			for (int i = 1; i <= w; i++)
				if (!ans[i])ans[i] = -1;
		}
	}
	for (int i = 1; i <= w; i++)
		cout << ans[i] << endl;

	return 0;
}